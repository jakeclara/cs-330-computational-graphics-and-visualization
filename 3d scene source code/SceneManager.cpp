///////////////////////////////////////////////////////////////////////////////
// scenemanager.cpp
// ============
// manage the preparing and rendering of 3D scenes - textures, materials, lighting
//
//  AUTHOR: Brian Battersby - SNHU Instructor / Computer Science
//	Created for CS-330-Computational Graphics and Visualization, Nov. 1st, 2023
///////////////////////////////////////////////////////////////////////////////


#include "SceneManager.h"
// class for drawing my custom objects
#include "MyObjects.h"

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#endif

#include <glm/gtx/transform.hpp>

// declaration of global variables
namespace
{
	const char* g_ModelName = "model";
	const char* g_ColorValueName = "objectColor";
	const char* g_TextureValueName = "objectTexture";
	const char* g_UseTextureName = "bUseTexture";
	const char* g_UseLightingName = "bUseLighting";
}


/***********************************************************
 *  SceneManager()
 *
 *  The constructor for the class
 ***********************************************************/
SceneManager::SceneManager(ShaderManager *pShaderManager)
{
	m_pShaderManager = pShaderManager;
	m_basicMeshes = new ShapeMeshes();
}

/***********************************************************
 *  ~SceneManager()
 *
 *  The destructor for the class
 ***********************************************************/
SceneManager::~SceneManager()
{
	m_pShaderManager = NULL;
	delete m_basicMeshes;
	m_basicMeshes = NULL;
}

// public getter method to access basic meshes externally
ShapeMeshes* SceneManager::getBasicMeshes() const {
	return m_basicMeshes;
}

/***********************************************************
 *  CreateGLTexture()
 *
 *  This method is used for loading textures from image files,
 *  configuring the texture mapping parameters in OpenGL,
 *  generating the mipmaps, and loading the read texture into
 *  the next available texture slot in memory.
 ***********************************************************/
bool SceneManager::CreateGLTexture(const char* filename, std::string tag)
{
	int width = 0;
	int height = 0;
	int colorChannels = 0;
	GLuint textureID = 0;

	// indicate to always flip images vertically when loaded
	stbi_set_flip_vertically_on_load(true);

	// try to parse the image data from the specified image file
	unsigned char* image = stbi_load(
		filename,
		&width,
		&height,
		&colorChannels,
		0);

	// if the image was successfully read from the image file
	if (image)
	{
		std::cout << "Successfully loaded image:" << filename << ", width:" << width << ", height:" << height << ", channels:" << colorChannels << std::endl;

		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);

		// set the texture wrapping parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		// set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		// if the loaded image is in RGB format
		if (colorChannels == 3)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
		// if the loaded image is in RGBA format - it supports transparency
		else if (colorChannels == 4)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
		else
		{
			std::cout << "Not implemented to handle image with " << colorChannels << " channels" << std::endl;
			return false;
		}

		// generate the texture mipmaps for mapping textures to lower resolutions
		glGenerateMipmap(GL_TEXTURE_2D);

		// free the image data from local memory
		stbi_image_free(image);
		glBindTexture(GL_TEXTURE_2D, 0); // Unbind the texture

		// register the loaded texture and associate it with the special tag string
		m_textureIDs[m_loadedTextures].ID = textureID;
		m_textureIDs[m_loadedTextures].tag = tag;
		m_loadedTextures++;

		return true;
	}

	std::cout << "Could not load image:" << filename << std::endl;

	// Error loading the image
	return false;
}

/***********************************************************
 *  BindGLTextures()
 *
 *  This method is used for binding the loaded textures to
 *  OpenGL texture memory slots.  There are up to 16 slots.
 ***********************************************************/
void SceneManager::BindGLTextures()
{
	for (int i = 0; i < m_loadedTextures; i++)
	{
		// bind textures on corresponding texture units
		glActiveTexture(GL_TEXTURE0 + i);
		glBindTexture(GL_TEXTURE_2D, m_textureIDs[i].ID);
	}
}

/***********************************************************
 *  DestroyGLTextures()
 *
 *  This method is used for freeing the memory in all the
 *  used texture memory slots.
 ***********************************************************/
void SceneManager::DestroyGLTextures()
{
	for (int i = 0; i < m_loadedTextures; i++)
	{
		glGenTextures(1, &m_textureIDs[i].ID);
	}
}

/***********************************************************
 *  FindTextureID()
 *
 *  This method is used for getting an ID for the previously
 *  loaded texture bitmap associated with the passed in tag.
 ***********************************************************/
int SceneManager::FindTextureID(std::string tag)
{
	int textureID = -1;
	int index = 0;
	bool bFound = false;

	while ((index < m_loadedTextures) && (bFound == false))
	{
		if (m_textureIDs[index].tag.compare(tag) == 0)
		{
			textureID = m_textureIDs[index].ID;
			bFound = true;
		}
		else
			index++;
	}

	return(textureID);
}

/***********************************************************
 *  FindTextureSlot()
 *
 *  This method is used for getting a slot index for the previously
 *  loaded texture bitmap associated with the passed in tag.
 ***********************************************************/
int SceneManager::FindTextureSlot(std::string tag)
{
	int textureSlot = -1;
	int index = 0;
	bool bFound = false;

	while ((index < m_loadedTextures) && (bFound == false))
	{
		if (m_textureIDs[index].tag.compare(tag) == 0)
		{
			textureSlot = index;
			bFound = true;
		}
		else
			index++;
	}

	return(textureSlot);
}

/***********************************************************
 *  FindMaterial()
 *
 *  This method is used for getting a material from the previously
 *  defined materials list that is associated with the passed in tag.
 ***********************************************************/
bool SceneManager::FindMaterial(std::string tag, OBJECT_MATERIAL& material)
{
	if (m_objectMaterials.size() == 0)
	{
		return(false);
	}

	int index = 0;
	bool bFound = false;
	while ((index < m_objectMaterials.size()) && (bFound == false))
	{
		if (m_objectMaterials[index].tag.compare(tag) == 0)
		{
			bFound = true;
			material.diffuseColor = m_objectMaterials[index].diffuseColor;
			material.specularColor = m_objectMaterials[index].specularColor;
			material.shininess = m_objectMaterials[index].shininess;
		}
		else
		{
			index++;
		}
	}

	return(true);
}

/***********************************************************
 *  SetTransformations()
 *
 *  This method is used for setting the transform buffer
 *  using the passed in transformation values.
 ***********************************************************/
void SceneManager::SetTransformations(
	glm::vec3 scaleXYZ,
	float XrotationDegrees,
	float YrotationDegrees,
	float ZrotationDegrees,
	glm::vec3 positionXYZ)
{
	// variables for this method
	glm::mat4 modelView;
	glm::mat4 scale;
	glm::mat4 rotationX;
	glm::mat4 rotationY;
	glm::mat4 rotationZ;
	glm::mat4 translation;

	// set the scale value in the transform buffer
	scale = glm::scale(scaleXYZ);
	// set the rotation values in the transform buffer
	rotationX = glm::rotate(glm::radians(XrotationDegrees), glm::vec3(1.0f, 0.0f, 0.0f));
	rotationY = glm::rotate(glm::radians(YrotationDegrees), glm::vec3(0.0f, 1.0f, 0.0f));
	rotationZ = glm::rotate(glm::radians(ZrotationDegrees), glm::vec3(0.0f, 0.0f, 1.0f));
	// set the translation value in the transform buffer
	translation = glm::translate(positionXYZ);

	modelView = translation * rotationZ * rotationY * rotationX * scale;

	if (NULL != m_pShaderManager)
	{
		m_pShaderManager->setMat4Value(g_ModelName, modelView);
	}
}

// public wrapper method for external classes to call the private method above
void SceneManager::ApplyTransformations(
	glm::vec3 scaleXYZ,
	float XrotationDegrees,
	float YrotationDegrees,
	float ZrotationDegrees,
	glm::vec3 positionXYZ) {

	SetTransformations(scaleXYZ, XrotationDegrees, YrotationDegrees, ZrotationDegrees, positionXYZ);
}

/***********************************************************
 *  SetShaderColor()
 *
 *  This method is used for setting the passed in color
 *  into the shader for the next draw command
 ***********************************************************/
void SceneManager::SetShaderColor(
	float redColorValue,
	float greenColorValue,
	float blueColorValue,
	float alphaValue)
{
	// variables for this method
	glm::vec4 currentColor;

	currentColor.r = redColorValue;
	currentColor.g = greenColorValue;
	currentColor.b = blueColorValue;
	currentColor.a = alphaValue;

	if (NULL != m_pShaderManager)
	{
		m_pShaderManager->setIntValue(g_UseTextureName, false);
		m_pShaderManager->setVec4Value(g_ColorValueName, currentColor);
	}
}

// public wrapper method for external classes to call the private method above
void SceneManager::ApplyShaderColor(
	float redColorValue,
	float greenColorValue,
	float blueColorValue,
	float alphaValue) {
	
	SetShaderColor (redColorValue, greenColorValue, blueColorValue, alphaValue);
}
/***********************************************************
 *  SetShaderTexture()
 *
 *  This method is used for setting the texture data
 *  associated with the passed in ID into the shader.
 ***********************************************************/
void SceneManager::SetShaderTexture(
	std::string textureTag)
{
	if (NULL != m_pShaderManager)
	{
		m_pShaderManager->setIntValue(g_UseTextureName, true);

		int textureID = -1;
		textureID = FindTextureSlot(textureTag);
		m_pShaderManager->setSampler2DValue(g_TextureValueName, textureID);
	}
}

// public wrapper method for external classes to call the private method above
void SceneManager::ApplyShaderTexture(std::string textureTag) {
	SetShaderTexture(textureTag);
}

/***********************************************************
 *  SetTextureUVScale()
 *
 *  This method is used for setting the texture UV scale
 *  values into the shader.
 ***********************************************************/
void SceneManager::SetTextureUVScale(float u, float v)
{
	if (NULL != m_pShaderManager)
	{
		m_pShaderManager->setVec2Value("UVscale", glm::vec2(u, v));
	}
}

// public wrapper method for external classes to call the private method above
void SceneManager::ApplyTextureUVScale(float u, float v) {
	SetTextureUVScale(u, v);
}

/***********************************************************
 *  SetShaderMaterial()
 *
 *  This method is used for passing the material values
 *  into the shader.
 ***********************************************************/
void SceneManager::SetShaderMaterial(
	std::string materialTag)
{
	if (m_objectMaterials.size() > 0)
	{
		OBJECT_MATERIAL material;
		bool bReturn = false;

		bReturn = FindMaterial(materialTag, material);
		if (bReturn == true)
		{
			m_pShaderManager->setVec3Value("material.diffuseColor", material.diffuseColor);
			m_pShaderManager->setVec3Value("material.specularColor", material.specularColor);
			m_pShaderManager->setFloatValue("material.shininess", material.shininess);
		}
	}
}

// public wrapper method for external classes to call the private method above
void SceneManager::ApplyShaderMaterial(std::string materialTag) {
	SetShaderMaterial(materialTag);
}

/***********************************************************
  *  DefineObjectMaterials()
  *
  *  This method is used for configuring the various material
  *  settings for all of the objects within the 3D scene.
  ***********************************************************/
void SceneManager::DefineObjectMaterials()
{
	OBJECT_MATERIAL plasticMaterial;
	plasticMaterial.diffuseColor = glm::vec3(0.4f, 0.4f, 0.4f);
	plasticMaterial.specularColor = glm::vec3(0.2f, 0.2f, 0.2f);
	plasticMaterial.shininess = 2.0;
	plasticMaterial.tag = "plastic";
	m_objectMaterials.push_back(plasticMaterial);

	OBJECT_MATERIAL metalMaterial;
	metalMaterial.diffuseColor = glm::vec3(0.3f, 0.3f, 0.2f);
	metalMaterial.specularColor = glm::vec3(0.7f, 0.7f, 0.8f);
	metalMaterial.shininess = 8.0;
	metalMaterial.tag = "metal";
	m_objectMaterials.push_back(metalMaterial);

	OBJECT_MATERIAL glassMaterial;
	glassMaterial.diffuseColor = glm::vec3(0.3f, 0.3f, 0.2f);
	glassMaterial.specularColor = glm::vec3(0.9f, 0.9f, 0.8f);
	glassMaterial.shininess = 10.0;
	glassMaterial.tag = "glass";
	m_objectMaterials.push_back(glassMaterial);

	OBJECT_MATERIAL stoneMaterial;
	stoneMaterial.diffuseColor = glm::vec3(0.5f, 0.5f, 0.5f);
	stoneMaterial.specularColor = glm::vec3(0.4f, 0.3f, 0.3f);
	stoneMaterial.shininess = 6.0;
	stoneMaterial.tag = "stone";
	m_objectMaterials.push_back(stoneMaterial);

	OBJECT_MATERIAL waterMaterial;
	waterMaterial.diffuseColor = glm::vec3(0.8f, 0.5f, 0.2f);
	waterMaterial.specularColor = glm::vec3(1.0f, 0.8f, 0.4f); 
	waterMaterial.shininess = 9.0f;
	waterMaterial.tag = "water";
	m_objectMaterials.push_back(waterMaterial);

	OBJECT_MATERIAL sandMaterial;
	sandMaterial.diffuseColor = glm::vec3(0.8f, 0.7f, 0.5f); 
	sandMaterial.specularColor = glm::vec3(0.1f, 0.1f, 0.1f);  
	sandMaterial.shininess = 2.0f;
	sandMaterial.tag = "sand";
	m_objectMaterials.push_back(sandMaterial);

	OBJECT_MATERIAL skyMaterial;
	skyMaterial.diffuseColor = glm::vec3(1.0f, 1.0f, 1.0f);
	skyMaterial.specularColor = glm::vec3(0.0f, 0.0f, 0.0f); 
	skyMaterial.shininess = 1.0f;
	skyMaterial.tag = "sky";
	m_objectMaterials.push_back(skyMaterial);
}

/***********************************************************
 *  SetupSceneLights()
 *
 *  This method is called to add and configure the light
 *  sources for the 3D scene.  There are up to 4 light sources.
 ***********************************************************/
void SceneManager::SetupSceneLights()
{
	m_pShaderManager->setBoolValue(g_UseLightingName, true);

	// directional light coming from a sunset-horizon-like angle
	m_pShaderManager->setVec3Value("directionalLight.direction", 1.0f, -0.1f, -0.1f);
	// blueish hue to the ambient light
	m_pShaderManager->setVec3Value("directionalLight.ambient", 0.2f, 0.3f, 0.3f);
	// neutral diffuse light
	m_pShaderManager->setVec3Value("directionalLight.diffuse", 0.5f, 0.5f, 0.5f);
	// low specular light to mimick weak sun
	m_pShaderManager->setVec3Value("directionalLight.specular", 0.1f, 0.1f, 0.1f);
	// light is active
	m_pShaderManager->setBoolValue("directionalLight.bActive", true);

	// point light to help illuminate the sky plane
	m_pShaderManager->setVec3Value("pointLights[0].position", 30.0f, 80.0f, -60.0f);
	m_pShaderManager->setVec3Value("pointLights[0].ambient", 0.001f, 0.001f, 0.001f);
	// reddish hue from sunset
	m_pShaderManager->setVec3Value("pointLights[0].diffuse", 0.9f, 0.5f, 0.5f);
	m_pShaderManager->setVec3Value("pointLights[0].specular", 0.0f, 0.0f, 0.0f);
	m_pShaderManager->setBoolValue("pointLights[0].bActive", true);

	// point light "in" lantern
	m_pShaderManager->setVec3Value("pointLights[1].position", -4.5f, 3.0f, -8.0f);
	m_pShaderManager->setVec3Value("pointLights[1].ambient", 0.001f, 0.001f, 0.001f);
	// reddish hue
	m_pShaderManager->setVec3Value("pointLights[1].diffuse", 0.5f, 0.25f, 0.25f);
	m_pShaderManager->setVec3Value("pointLights[1].specular", 0.5f, 0.25f, 0.25f);
	m_pShaderManager->setBoolValue("pointLights[1].bActive", true);
}

 /***********************************************************
  *  LoadSceneTextures()
  *
  *  This method is used for preparing the 3D scene by loading
  *  the shapes, textures in memory to support the 3D scene
  *  rendering
  ***********************************************************/
void SceneManager::LoadSceneTextures()
{
	// load texture images and assign string identifiers
	bool bReturn = false;
	CreateGLTexture("textures/metal.jpg", "metal");				// 1
	CreateGLTexture("textures/sand.jpg", "sand");				// 2
	CreateGLTexture("textures/brick-wall.jpg", "wall");			// 3
	CreateGLTexture("textures/water.jpg", "water");				// 4
	CreateGLTexture("textures/sky.jpg", "sky");					// 5
	CreateGLTexture("textures/bronze-metal.jpg", "dark-metal");	// 6
																// 7
																// 8
																// 9
																// 10
																// 11
																// 12
																// 13
																// 14
																// 15
	// 16 available slots for scene textures					// 16
	
	// bound loaded textures to texture slots
	BindGLTextures();
}

/***********************************************************
 *  PrepareScene()
 *
 *  This method is used for preparing the 3D scene by loading
 *  the shapes, textures in memory to support the 3D scene 
 *  rendering
 ***********************************************************/
void SceneManager::PrepareScene()
{
	// call to load scene textures
	LoadSceneTextures();
	// define the materials for objects in the scene
	DefineObjectMaterials();
	// add and define the light sources for the scene
	SetupSceneLights();

	// load meshes into memory
	m_basicMeshes->LoadPlaneMesh();
	m_basicMeshes->LoadCylinderMesh();
	m_basicMeshes->LoadTorusMesh();
	m_basicMeshes->LoadBoxMesh();
	m_basicMeshes->LoadTaperedCylinderMesh();
	m_basicMeshes->LoadPyramid4Mesh();
}

/***********************************************************
 *  RenderScene()
 *
 *  This method is used for rendering the 3D scene by 
 *  transforming and drawing the basic 3D shapes 
 *	through the MyObject class method
 ***********************************************************/
void SceneManager::RenderScene()
{
	// instantiate MyObjects and pass current instance of SceneManager
	MyObjects myObjects(this);

	// set width of planes that "setup" the scene
	float planeWidth = 75.0f;

	// call methods to draw objects
	myObjects.DrawSandWaterAndSky(planeWidth);
	myObjects.DrawLowWall(planeWidth);
	myObjects.DrawBeachUmbrella();

	// methods below accept xyz position as parameters
	myObjects.DrawLantern(-5.0, 2.5, -7.6);
	myObjects.DrawBeachChair(-0.5, 1.0, 0.25);
	myObjects.DrawBeachChair(-8.0, 1.0, 0.25);
	myObjects.DrawBeachChair(8.0, 1.0, 0.25);
	myObjects.DrawBeachChair(13.0, 1.0, 0.25);

}
// end
