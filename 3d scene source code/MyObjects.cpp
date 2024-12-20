#include "MyObjects.h"
#include "SceneManager.h"

// constructor injecting SceneManager
MyObjects::MyObjects(SceneManager* sceneManager) {
	m_pSceneManager = sceneManager;
}

// draws the 3 planes that set the scene
void MyObjects::DrawSandWaterAndSky(float planeWidth) {
	/*****sand plane*****/

	// set the XYZ scale for the mesh
	scaleXYZ = glm::vec3(planeWidth, 1.0f, 8.0f);

	// set the XYZ rotation for the mesh
	XrotationDegrees = 0.0f;
	YrotationDegrees = 0.0f;
	ZrotationDegrees = 0.0f;

	// set the XYZ position for the mesh
	positionXYZ = glm::vec3(0.0f, 0.0f, 0.0f);

	// set the transformations into memory to be used on the drawn meshes
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);

	// Set shader texture and UV scale
	m_pSceneManager->ApplyShaderTexture("sand");
	m_pSceneManager->ApplyShaderMaterial("sand");
	m_pSceneManager->ApplyTextureUVScale(10.0, 2.0);

	// draw the mesh with transformation values
	m_pSceneManager->getBasicMeshes()->DrawPlaneMesh();
	/****************************************************************/

	/*****water plane*****/

	// set the XYZ scale for the mesh
	scaleXYZ = glm::vec3(planeWidth, 1.0f, 25.0f);

	// set the XYZ rotation for the mesh
	XrotationDegrees = 0.0f;
	YrotationDegrees = 0.0f;
	ZrotationDegrees = 0.0f;

	// set the XYZ position for the mesh
	positionXYZ = glm::vec3(0.0f, 0.0f, -33.0f);

	// set the transformations into memory to be used on the drawn meshes
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);

	m_pSceneManager->ApplyShaderTexture("water");
	m_pSceneManager->ApplyShaderMaterial("water");
	m_pSceneManager->ApplyTextureUVScale(10.0, 4.0);

	// draw the mesh with transformation values
	m_pSceneManager->getBasicMeshes()->DrawPlaneMesh();
	///****************************************************************/

	/*****sky plane*****/

	// set the XYZ scale for the mesh
	scaleXYZ = glm::vec3(planeWidth, 1.0f, 30.0f);

	// set the XYZ rotation for the mesh
	XrotationDegrees = 90.0f;
	YrotationDegrees = 0.0f;
	ZrotationDegrees = 0.0f;

	// set the XYZ position for the mesh
	positionXYZ = glm::vec3(0.0f, 30.0f, -58.0f);

	// set the transformations into memory to be used on the drawn meshes
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);

	m_pSceneManager->ApplyShaderTexture("sky");
	m_pSceneManager->ApplyShaderMaterial("sky");
	m_pSceneManager->ApplyTextureUVScale(1.0, 1.0);

	// draw the mesh with transformation values
	m_pSceneManager->getBasicMeshes()->DrawPlaneMesh();
	/****************************************************************/
}

/*****draws the low wall box with width matching the sand water and sky planes*****/
void MyObjects::DrawLowWall(float planeWidth) {
	// set the XYZ scale for the mesh
	scaleXYZ = glm::vec3(planeWidth * 2, 1.0f, 2.0f);

	// set the XYZ rotation for the mesh
	XrotationDegrees = 90.0f;
	YrotationDegrees = 0.0f;
	ZrotationDegrees = 0.0f;

	// set the XYZ position for the mesh
	positionXYZ = glm::vec3(0.0f, 1.0f, -8.0f);

	// set the transformations into memory to be used on the drawn meshes
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);

	m_pSceneManager->ApplyShaderTexture("wall");
	m_pSceneManager->ApplyShaderMaterial("stone");
	m_pSceneManager->ApplyTextureUVScale(25.0, 0.5);

	// draw the mesh with transformation values
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
	/****************************************************************/
}

/*****draws the beach umbrella*****/
// this method could be improved by making values relative to make drawing additional umbrella objects easier
void MyObjects::DrawBeachUmbrella() {
	/*****table top*****/
	unsigned int numOfTopToruses = 8;
	float tableTopScaleX = 0.3f;
	float tableTopScaleY = 0.3f;
	float tableTopIncrement = 0.1f;

	// draws number of toruses defined above with incrementing scale
	for (unsigned int i = 0; i < numOfTopToruses; i++) {
		// set the XYZ scale for the mesh
		scaleXYZ = glm::vec3(tableTopScaleX, tableTopScaleY, 0.75f);

		// set the XYZ rotation for the mesh
		XrotationDegrees = 90.0f;
		YrotationDegrees = 90.0f;
		ZrotationDegrees = 0.0f;

		// set the XYZ position for the mesh
		positionXYZ = glm::vec3(-4.0f, 1.5f, 3.0f);

		// set the transformations into memory to be used on the drawn meshes
		m_pSceneManager->ApplyTransformations(
			scaleXYZ,
			XrotationDegrees,
			YrotationDegrees,
			ZrotationDegrees,
			positionXYZ);

		m_pSceneManager->ApplyShaderTexture("dark-metal");
		m_pSceneManager->ApplyShaderMaterial("metal");
		m_pSceneManager->ApplyTextureUVScale(1.0, 1.0);

		// draw the mesh with transformation values
		m_pSceneManager->getBasicMeshes()->DrawTorusMesh();

		tableTopScaleX += tableTopIncrement;
		tableTopScaleY += tableTopIncrement;
		/****************************************************************/
	}

	/*****table bottom*****/
	// set the XYZ scale for the mesh
	scaleXYZ = glm::vec3(1.5, 0.1, 1.5f);

	// set the XYZ rotation for the mesh
	XrotationDegrees = 0.0f;
	YrotationDegrees = 10.0f;
	ZrotationDegrees = 0.0f;

	// set the XYZ position for the mesh
	positionXYZ = glm::vec3(-4.0f, 0.5f, 3.0f);

	// set the transformations into memory to be used on the drawn meshes
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	
	m_pSceneManager->ApplyShaderMaterial("metal");
	m_pSceneManager->ApplyTextureUVScale(1.0, 1.0);

	// draw the mesh with transformation values
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
	/****************************************************************/

	/***beach umbrella table front left leg***/
	// set the XYZ scale for the mesh
	scaleXYZ = glm::vec3(0.05f, 1.45f, 0.05f);

	// set the XYZ rotation for the mesh
	XrotationDegrees = 0.0f;
	YrotationDegrees = 0.0f;
	ZrotationDegrees = 0.0f;

	// set the XYZ position for the mesh
	positionXYZ = glm::vec3(-4.605f, 0.0f, 3.89f);

	// set the transformations into memory to be used on the drawn meshes
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);

	m_pSceneManager->ApplyShaderTexture("dark-metal");
	m_pSceneManager->ApplyShaderMaterial("metal");
	m_pSceneManager->ApplyTextureUVScale(1.0, 1.0);

	// draw the mesh with transformation values
	m_pSceneManager->getBasicMeshes()->DrawCylinderMesh();
	/****************************************************************/

	/***beach umbrella table front right leg***/
	// set the XYZ scale for the mesh
	scaleXYZ = glm::vec3(0.05f, 1.45f, 0.05f);

	// set the XYZ rotation for the mesh
	XrotationDegrees = 0.0f;
	YrotationDegrees = 0.0f;
	ZrotationDegrees = 0.0f;

	// set the XYZ position for the mesh
	positionXYZ = glm::vec3(-3.15f, 0.0f, 3.65f);

	// set the transformations into memory to be used on the drawn meshes
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);

	// continue with shader texture set for last object

	// draw the mesh with transformation values
	m_pSceneManager->getBasicMeshes()->DrawCylinderMesh();
	/****************************************************************/

	/***beach umbrella table back left leg***/
	// set the XYZ scale for the mesh
	scaleXYZ = glm::vec3(0.05f, 1.45f, 0.05f);

	// set the XYZ rotation for the mesh
	XrotationDegrees = 0.0f;
	YrotationDegrees = 0.0f;
	ZrotationDegrees = 0.0f;

	// set the XYZ position for the mesh
	positionXYZ = glm::vec3(-4.85f, 0.0f, 2.35f);

	// set the transformations into memory to be used on the drawn meshes
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);

	// continue with shader texture set for last object

	// draw the mesh with transformation values
	m_pSceneManager->getBasicMeshes()->DrawCylinderMesh();
	/****************************************************************/

	/***beach umbrella table back right leg***/
	// set the XYZ scale for the mesh
	scaleXYZ = glm::vec3(0.05f, 1.45f, 0.05f);

	// set the XYZ rotation for the mesh
	XrotationDegrees = 0.0f;
	YrotationDegrees = 0.0f;
	ZrotationDegrees = 0.0f;

	// set the XYZ position for the mesh
	positionXYZ = glm::vec3(-3.40f, 0.0f, 2.10f);

	// set the transformations into memory to be used on the drawn meshes
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);

	// continue with shader texture set for last object

	// draw the mesh with transformation values
	m_pSceneManager->getBasicMeshes()->DrawCylinderMesh();
	/****************************************************************/

	/***beach umbrella pole***/

	// set the XYZ scale for the mesh
	scaleXYZ = glm::vec3(0.08f, 6.0f, 0.08f);

	// set the XYZ rotation for the mesh
	XrotationDegrees = 0.0f;
	YrotationDegrees = 0.0f;
	ZrotationDegrees = 0.0f;

	// set the XYZ position for the mesh
	positionXYZ = glm::vec3(-4.0f, 1.0f, 3.0f);

	// set the transformations into memory to be used on the drawn meshes
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);

	m_pSceneManager->ApplyShaderTexture("metal");
	m_pSceneManager->ApplyShaderMaterial("metal");
	m_pSceneManager->ApplyTextureUVScale(1.0, 1.0);

	// draw the mesh with transformation values
	m_pSceneManager->getBasicMeshes()->DrawCylinderMesh();
	/****************************************************************/

	/***pole catch at bottom***/
	// set the XYZ scale for the mesh
	scaleXYZ = glm::vec3(0.1f, 0.1f, 2.0f);

	// set the XYZ rotation for the mesh
	XrotationDegrees = 90.0f;
	YrotationDegrees = 90.0f;
	ZrotationDegrees = 0.0f;

	// set the XYZ position for the mesh
	positionXYZ = glm::vec3(-4.0f, 0.9f, 3.0f);

	// set the transformations into memory to be used on the drawn meshes
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);

	m_pSceneManager->ApplyShaderTexture("dark-metal");
	m_pSceneManager->ApplyShaderMaterial("metal");
	m_pSceneManager->ApplyTextureUVScale(1.0, 1.0);

	// draw the mesh with transformation values
	m_pSceneManager->getBasicMeshes()->DrawTorusMesh();
	/****************************************************************/

	/***beach umbrella***/
	// set the XYZ scale for the mesh
	scaleXYZ = glm::vec3(0.4f, 3.5f, 0.4f);

	// set the XYZ rotation for the mesh
	XrotationDegrees = 0.0f;
	YrotationDegrees = 0.0f;
	ZrotationDegrees = 0.0f;

	// set the XYZ position for the mesh
	positionXYZ = glm::vec3(-4.0f, 4.0f, 3.0f);

	// set the transformations into memory to be used on the drawn meshes
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);

	m_pSceneManager->ApplyShaderColor(1, 0.922, 0.804, 1);
	m_pSceneManager->ApplyShaderMaterial("plastic");

	// draw the mesh with transformation values
	m_pSceneManager->getBasicMeshes()->DrawTaperedCylinderMesh();
	/****************************************************************/

	/***beach umbrella top of umbrella finish 1***/
	// set the XYZ scale for the mesh
	scaleXYZ = glm::vec3(0.1f, 0.1f, 0.25f);

	// set the XYZ rotation for the mesh
	XrotationDegrees = 90.0f;
	YrotationDegrees = 0.0f;
	ZrotationDegrees = 0.0f;

	// set the XYZ position for the mesh
	positionXYZ = glm::vec3(-4.0f, 7.55f, 3.0f);

	// set the transformations into memory to be used on the drawn meshes
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);

	m_pSceneManager->ApplyShaderTexture("metal");
	m_pSceneManager->ApplyShaderMaterial("metal");
	m_pSceneManager->ApplyTextureUVScale(1.0, 1.0);


	// draw the mesh with transformation values
	m_pSceneManager->getBasicMeshes()->DrawTorusMesh();
	/****************************************************************/

	/***beach umbrella top of umbrella finish 2***/
	// set the XYZ scale for the mesh
	scaleXYZ = glm::vec3(0.1f, 0.2f, 0.1f);

	// set the XYZ rotation for the mesh
	XrotationDegrees = 0.0f;
	YrotationDegrees = 0.0f;
	ZrotationDegrees = 0.0f;

	// set the XYZ position for the mesh
	positionXYZ = glm::vec3(-4.00f, 7.57f, 3.0f);

	// set the transformations into memory to be used on the drawn meshes
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);

	// continue with shader texture set for last object

	// draw the mesh with transformation values
	m_pSceneManager->getBasicMeshes()->DrawTaperedCylinderMesh();
	/****************************************************************/
}

// draws the lanter object by calling a series of internal methods
void MyObjects::DrawLantern(float startingPosX, float startingPosY, float startingPosZ) {
	// variables to set width and depth of lantern legs and spacing of grid bars
	float width = 1.0;
	float depth = -0.75;
	float spacing = 0.15f;
	DrawLanternLegs(startingPosX, startingPosY, startingPosZ, width, depth);
	DrawVerticalLanternBars(startingPosX, startingPosY, startingPosZ, spacing, true);
	DrawVerticalLanternBars(startingPosX, startingPosY, startingPosZ + depth, spacing, true);
	DrawVerticalLanternBars(startingPosX, startingPosY, startingPosZ - spacing, spacing, false);
	DrawVerticalLanternBars(startingPosX + width, startingPosY, startingPosZ - spacing, spacing, false);
	DrawHorizontalLanternBars(startingPosX + (width / 2), startingPosY, startingPosZ, spacing, true);
	DrawHorizontalLanternBars(startingPosX + (width / 2), startingPosY, startingPosZ + depth, spacing, true);
	DrawHorizontalLanternBars(startingPosX + width, startingPosY, startingPosZ + (depth / 2), spacing, false);
	DrawHorizontalLanternBars(startingPosX, startingPosY, startingPosZ + (depth / 2), spacing, false);
	DrawLanternTop(startingPosX + (width / 2), startingPosY + (width * 1.25), startingPosZ + (depth / 2));
	DrawLanternLight(startingPosX + (width / 2), startingPosY + (width / 4), startingPosZ - (spacing * 2.5));
}

// draws the four lantern legs
void MyObjects::DrawLanternLegs(
	float startingPosX, 
	float startingPosY, 
	float startingPosZ, 
	float width, 
	float depth) {
	
	float scaleX = 0.15f;
	float scaleY = 1.5f;
	float scaleZ = 0.15f;

	float Xrotation = 0.0f;
	float Yrotation = 0.0f;
	float Zrotation = 0.0f;

	// set the XYZ scale for first leg
	scaleXYZ = glm::vec3(scaleX, scaleY, scaleZ);
	// set the XYZ rotation for first mesh
	XrotationDegrees = Xrotation;
	YrotationDegrees = Yrotation;
	ZrotationDegrees = Zrotation;
	// set the XYZ position for the first mesh
	positionXYZ = glm::vec3(startingPosX, startingPosY, startingPosZ);
	// set the transformations into memory
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	m_pSceneManager->ApplyShaderTexture("dark-metal");
	m_pSceneManager->ApplyShaderMaterial("plastic");
	// draw the first mesh
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
	/***********************************************/

	// set the XYZ scale for second leg
	scaleXYZ = glm::vec3(scaleX, scaleY, scaleZ);
	// set the XYZ rotation for second mesh
	XrotationDegrees = Xrotation;
	YrotationDegrees = Yrotation;
	ZrotationDegrees = Zrotation;
	// set the XYZ position for the second mesh
	positionXYZ = glm::vec3(startingPosX + width, startingPosY, startingPosZ);
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// draw the second mesh
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
	/***********************************************/

	// set the XYZ scale for third leg
	scaleXYZ = glm::vec3(scaleX, scaleY, scaleZ);
	// set the XYZ rotation for third mesh
	XrotationDegrees = Xrotation;
	YrotationDegrees = Yrotation;
	ZrotationDegrees = Zrotation;
	// set the XYZ position for the third mesh
	positionXYZ = glm::vec3(startingPosX + width, startingPosY, startingPosZ + depth);
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// draw the third mesh
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
	/***********************************************/

	// set the XYZ scale for fourth leg
	scaleXYZ = glm::vec3(scaleX, scaleY, scaleZ);
	// set the XYZ rotation for fourth mesh
	XrotationDegrees = Xrotation;
	YrotationDegrees = Yrotation;
	ZrotationDegrees = Zrotation;
	// set the XYZ position for the fourth mesh
	positionXYZ = glm::vec3(startingPosX, startingPosY, startingPosZ + depth);
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// draw the fourth mesh
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
	/***********************************************/
}

// draws vertical grid bars using a for loop
void MyObjects::DrawVerticalLanternBars(
	float startingPosX,
	float startingPosY,
	float startingPosZ,
	float spacing,
	bool isFrontOrBack) {

	float scaleX = 0.05f;
	float scaleY = 1.0f;
	float scaleZ = 0.05f;

	float Xrotation = 0.0f;
	float Yrotation = 0.0f;
	float Zrotation = 0.0f;

	if (isFrontOrBack) {
		int numOfVerticalBars = 6;
		for (int i = 0; i < numOfVerticalBars; i++) {
			// set the XYZ scale
			scaleXYZ = glm::vec3(scaleX, scaleY, scaleZ);
			// set the XYZ rotation
			XrotationDegrees = Xrotation;
			YrotationDegrees = Yrotation;
			ZrotationDegrees = Zrotation;
			// set the XYZ position
			positionXYZ = glm::vec3(startingPosX + spacing, startingPosY + (spacing * 1.5), startingPosZ);
			// set the transformations into memory 
			m_pSceneManager->ApplyTransformations(
				scaleXYZ,
				XrotationDegrees,
				YrotationDegrees,
				ZrotationDegrees,
				positionXYZ);
			// set the mesh color
			m_pSceneManager->ApplyShaderTexture("dark-metal");
			m_pSceneManager->ApplyShaderMaterial("plastic");
			// draw the mesh
			m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
			startingPosX += spacing;
		}
	}
	// bar traits adjust slightly if on the sides instead of front or back
	else {
		int numOfVerticalBars = 4;
		for (int i = 0; i < numOfVerticalBars; i++) {
			// set the XYZ scale
			scaleXYZ = glm::vec3(scaleX, scaleY, scaleZ);
			// set the XYZ rotation
			XrotationDegrees = Xrotation;
			YrotationDegrees = Yrotation;
			ZrotationDegrees = Zrotation;
			// set the XYZ position
			positionXYZ = glm::vec3(startingPosX, startingPosY + (spacing * 1.5), startingPosZ);
			// set the transformations into memory 
			m_pSceneManager->ApplyTransformations(
				scaleXYZ,
				XrotationDegrees,
				YrotationDegrees,
				ZrotationDegrees,
				positionXYZ);
			// set the mesh color
			m_pSceneManager->ApplyShaderTexture("dark-metal");
			m_pSceneManager->ApplyShaderMaterial("plastic");
			// draw the mesh
			m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
			startingPosZ -= spacing;
		}
	}
}

// draws horizontal grid bars using a for loop
void MyObjects::DrawHorizontalLanternBars(
	float startingPosX,
	float startingPosY,
	float startingPosZ,
	float spacing,
	bool isFrontOrBack) {

	float scaleX = 0.05f;
	float scaleY = 1.0f;
	float scaleZ = 0.05f;

	float Xrotation = 0.0f;
	float Yrotation = 0.0f;
	float Zrotation = 0.0f;

	int numOfHorizontalBars = 7;

	if (isFrontOrBack) {
		for (int i = 0; i < numOfHorizontalBars; i++) {
			// set the XYZ scale
			scaleXYZ = glm::vec3(scaleX, scaleY - (spacing / 4), scaleZ);
			// set the XYZ rotation
			XrotationDegrees = Xrotation + 90.0f;
			YrotationDegrees = Yrotation + 90.0f;
			ZrotationDegrees = Zrotation;
			// set the XYZ position
			positionXYZ = glm::vec3(startingPosX, startingPosY - (spacing * 1.5), startingPosZ);
			// set the transformations into memory 
			m_pSceneManager->ApplyTransformations(
				scaleXYZ,
				XrotationDegrees,
				YrotationDegrees,
				ZrotationDegrees,
				positionXYZ);
			// set the mesh color
			m_pSceneManager->ApplyShaderTexture("dark-metal");
			m_pSceneManager->ApplyShaderMaterial("plastic");
			// draw the mesh
			m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
			startingPosY += spacing;
		}
	}
	// bar traits adjust slightly if on the sides instead of front or back
	else {
		for (int i = 0; i < numOfHorizontalBars; i++) {
			// set the XYZ scale
			scaleXYZ = glm::vec3(scaleX, scaleY - (spacing * 2), scaleZ);
			// set the XYZ rotation
			XrotationDegrees = Xrotation + 90.0f;
			YrotationDegrees = Yrotation;
			ZrotationDegrees = Zrotation;
			// set the XYZ position
			positionXYZ = glm::vec3(startingPosX, startingPosY - (spacing * 1.5), startingPosZ);
			// set the transformations into memory 
			m_pSceneManager->ApplyTransformations(
				scaleXYZ,
				XrotationDegrees,
				YrotationDegrees,
				ZrotationDegrees,
				positionXYZ);
			// set the mesh color
			m_pSceneManager->ApplyShaderTexture("dark-metal");
			m_pSceneManager->ApplyShaderMaterial("plastic");
			// draw the mesh
			m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
			startingPosY += spacing;
		}
	}
}

// draws the pyramid mesh on top of the lantern
void MyObjects::DrawLanternTop(float startingPosX, float startingPosY, float startingPosZ) {
	float scaleX = 1.3f;
	float scaleY = 1.0f;
	float scaleZ = 1.3f;

	float Xrotation = 0.0f;
	float Yrotation = 0.0f;
	float Zrotation = 0.0f;

	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX, scaleY, scaleZ);
	// set the XYZ rotation
	XrotationDegrees = Xrotation;
	YrotationDegrees = Yrotation;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX, startingPosY, startingPosZ);
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// set the mesh color
	m_pSceneManager->ApplyShaderTexture("metal");
	m_pSceneManager->ApplyShaderMaterial("metal");
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawPyramid4Mesh();
}

// draws a transparent cube to mimick a bulb like reflection and look
void MyObjects::DrawLanternLight(float startingPosX, float startingPosY, float startingPosZ) {
	float scaleX = 0.5f;
	float scaleY = 0.5f;
	float scaleZ = 0.5f;

	float Xrotation = 0.0f;
	float Yrotation = 0.0f;
	float Zrotation = 0.0f;

	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX, scaleY, scaleZ);
	// set the XYZ rotation
	XrotationDegrees = Xrotation;
	YrotationDegrees = Yrotation;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX, startingPosY, startingPosZ);
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// set the mesh color
	m_pSceneManager->ApplyShaderColor(1, 0, 0, 0.25);
	m_pSceneManager->ApplyShaderMaterial("glass");
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
}

// draws a beach lounge chair
void MyObjects::DrawBeachChair(float startingPosX, float startingPosY, float startingPosZ) {
	float scaleX = 3.0f;
	float scaleY = 0.1f;
	float scaleZ = 6.0f;

	float Xrotation = 0.0f;
	float Yrotation = 0.0f;
	float Zrotation = 0.0f;

	// flat chair section
	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX, scaleY, scaleZ);
	// set the XYZ rotation
	XrotationDegrees = Xrotation;
	YrotationDegrees = Yrotation;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX, startingPosY, startingPosZ);
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// set the mesh texture
	m_pSceneManager->ApplyShaderTexture("dark-metal");
	m_pSceneManager->ApplyShaderMaterial("metal");
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
	/***********************************************/

	// rotated head rest section
	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX, scaleY, scaleZ / 2.5);
	// set the XYZ rotation
	XrotationDegrees = Xrotation - 60.0f;
	YrotationDegrees = Yrotation;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX, startingPosY + 1.05, startingPosZ + 3.52);
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
	/***********************************************/

	// offset variables for leg placement
	float legOffsetX = 1.55f;
	float legOffsetY = 0.25f;
	float legOffsetZ = 1.62f;
	float legXrotation = 50.0f;

	// right side rotated leg piece 1
	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX * 0.0333f, scaleY * 22.0f, scaleZ * 0.01667f);
	// set the XYZ rotation
	XrotationDegrees = Xrotation + legXrotation;
	YrotationDegrees = Yrotation;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX + legOffsetX, startingPosY - legOffsetY, startingPosZ);
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
	/***********************************************/

	// right side rotated piece 2
	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX * 0.0333f, scaleY * 22.0f, scaleZ * 0.01667f);
	// set the XYZ rotation
	XrotationDegrees = Xrotation - legXrotation;
	YrotationDegrees = Yrotation;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX + legOffsetX, startingPosY - legOffsetY, startingPosZ + legOffsetZ);
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
	/***********************************************/

	// right side ground level leg piece 3
	float bottomBarOffsetX = 0.0f;
	float bottomBarOffsetY = 0.51f;
	float bottomBarOffsetZ = 1.32f;
	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX * 0.0333f, scaleY * 20.0f, scaleZ * 0.01667f);
	// set the XYZ rotation
	XrotationDegrees = Xrotation - 90.0f;
	YrotationDegrees = Yrotation;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX + legOffsetX, startingPosY * .05, startingPosZ - bottomBarOffsetZ * 1.37);
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
	/***********************************************/

	// right side vertical leg piece 4 
	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX * 0.0333f, scaleY * 9.0f, scaleZ * 0.01667f);
	// set the XYZ rotation
	XrotationDegrees = Xrotation;
	YrotationDegrees = Yrotation;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX + legOffsetX, startingPosY * .5, startingPosZ - bottomBarOffsetZ * 2.09);
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
	/***********************************************/

	// left side rotated leg piece 1
	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX * 0.0333f, scaleY * 22.0f, scaleZ * 0.01667f);
	// set the XYZ rotation
	XrotationDegrees = Xrotation + legXrotation;
	YrotationDegrees = Yrotation;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX - legOffsetX, startingPosY - legOffsetY, startingPosZ);
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
	/***********************************************/

	// left side rotated leg piece 2
	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX * 0.0333f, scaleY * 22.0f, scaleZ * 0.01667f);
	// set the XYZ rotation
	XrotationDegrees = Xrotation - legXrotation;
	YrotationDegrees = Yrotation;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX - legOffsetX, startingPosY - legOffsetY, startingPosZ + legOffsetZ);
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
	/***********************************************/

	// left side ground level leg piece 3
	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX * 0.0333f, scaleY * 20.0f, scaleZ * 0.01667f);
	// set the XYZ rotation
	XrotationDegrees = Xrotation - 90.0f;
	YrotationDegrees = Yrotation;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX - legOffsetX, startingPosY * .05, startingPosZ - bottomBarOffsetZ * 1.37);
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
	/***********************************************/

	// left side vertical leg piece 4
	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX * 0.0333f, scaleY * 9.0f, scaleZ * 0.01667f);
	// set the XYZ rotation
	XrotationDegrees = Xrotation;
	YrotationDegrees = Yrotation;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX - legOffsetX, startingPosY * .5, startingPosZ - bottomBarOffsetZ * 2.09);
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
	/***********************************************/

	// front support bar for legs (goes under the chair section and conects both sides)
	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX * 0.0333f, scaleY * 32.0f, scaleZ * 0.01667f);
	// set the XYZ rotation
	XrotationDegrees = Xrotation - 90.0f;
	YrotationDegrees = Yrotation - 90.0f;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX, startingPosY - bottomBarOffsetY/5, startingPosZ - bottomBarOffsetZ * 2.09);
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
	/***********************************************/

	// left side back support bar for chair (extends from back section of chair)
	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX * 0.0333f, scaleY * 15.0f, scaleZ * 0.01667f);
	// set the XYZ rotation
	XrotationDegrees = Xrotation + 90.0f;
	YrotationDegrees = Yrotation;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX - (legOffsetX - scaleX * 0.0333f), startingPosY, startingPosZ + (bottomBarOffsetZ * 2.84));
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
	/***********************************************/

	// right side back support bar for chair (extends from back section of chair)
	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX * 0.0333f, scaleY * 15.0f, scaleZ * 0.01667f);
	// set the XYZ rotation
	XrotationDegrees = Xrotation + 90.0f;
	YrotationDegrees = Yrotation;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX + (legOffsetX - scaleX * 0.0333f), startingPosY, startingPosZ + (bottomBarOffsetZ * 2.84));
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
	/***********************************************/

	// right side back support vertical bar
	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX * 0.0333f, scaleY * 10.0f, scaleZ * 0.01667f);
	// set the XYZ rotation
	XrotationDegrees = Xrotation;
	YrotationDegrees = Yrotation;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX + legOffsetX, startingPosY * 0.5, startingPosZ + (bottomBarOffsetZ * 3.37));
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
	/***********************************************/

	// left side back support vertical bar
	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX * 0.0333f, scaleY * 10.0f, scaleZ * 0.01667f);
	// set the XYZ rotation
	XrotationDegrees = Xrotation;
	YrotationDegrees = Yrotation;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX - legOffsetX, startingPosY * 0.5, startingPosZ + (bottomBarOffsetZ * 3.37));
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
	/***********************************************/

	// left side back support vertical bar ground level
	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX * 0.0333f, scaleY * 20.7f, scaleZ * 0.01667f);
	// set the XYZ rotation
	XrotationDegrees = Xrotation - 90.0f;
	YrotationDegrees = Yrotation;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX - legOffsetX, startingPosY * 0.05, startingPosZ + (bottomBarOffsetZ * 2.625));
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
	/***********************************************/

	// right side back support vertical bar ground level
	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX * 0.0333f, scaleY * 20.7f, scaleZ * 0.01667f);
	// set the XYZ rotation
	XrotationDegrees = Xrotation - 90.0f;
	YrotationDegrees = Yrotation;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX + legOffsetX, startingPosY * 0.05, startingPosZ + (bottomBarOffsetZ * 2.625));
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
	/***********************************************/

	// connects vertical support bars on back of chair
	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX * 0.0333f, scaleY * 32.0f, scaleZ * 0.01667f);
	// set the XYZ rotation
	XrotationDegrees = Xrotation - 90.0f;
	YrotationDegrees = Yrotation - 90.0f;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX, startingPosY, startingPosZ + bottomBarOffsetZ * 3.37);
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
	/***********************************************/

	// adjustable head rest piece 1 left side
	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX * 0.02f, scaleY * 18.5f, scaleZ * 0.01f);
	// set the XYZ rotation
	XrotationDegrees = Xrotation - 22.0f;
	YrotationDegrees = Yrotation;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX - (legOffsetX - scaleX * 0.0999f), startingPosY + 0.5, startingPosZ + bottomBarOffsetZ * 3.1);
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// set the mesh color
	m_pSceneManager->ApplyShaderTexture("metal");
	m_pSceneManager->ApplyShaderMaterial("metal");
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
	/***********************************************/

	// adjustable head rest piece 2 right side
	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX * 0.02f, scaleY * 18.5f, scaleZ * 0.01f);
	// set the XYZ rotation
	XrotationDegrees = Xrotation - 22.0f;
	YrotationDegrees = Yrotation;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX + (legOffsetX - scaleX * 0.0999f), startingPosY + 0.5, startingPosZ + bottomBarOffsetZ * 3.1);
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
	/***********************************************/

	// adjustable head rest notch to raise/lower chair (first from bottom)
	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX * 0.0067f, scaleY * 25.6f, scaleZ * 0.0033f);
	// set the XYZ rotation
	XrotationDegrees = Xrotation - 90.0f;
	YrotationDegrees = Yrotation - 90.0f;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX - (legOffsetX - scaleX * 0.09f), startingPosY - 0.33, startingPosZ + bottomBarOffsetZ * 3.356);
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawCylinderMesh();
	/***********************************************/

	// adjustable head rest notch to raise/lower chair (second from bottom)
	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX * 0.0067f, scaleY * 25.6f, scaleZ * 0.0033f);
	// set the XYZ rotation
	XrotationDegrees = Xrotation - 90.0f;
	YrotationDegrees = Yrotation - 90.0f;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX - (legOffsetX - scaleX * 0.09f), startingPosY - 0.1, startingPosZ + bottomBarOffsetZ * 3.282);
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawCylinderMesh();
	/***********************************************/

	// adjustable head rest notch to raise/lower chair (third from bottom)
	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX * 0.0067f, scaleY * 25.6f, scaleZ * 0.0033f);
	// set the XYZ rotation
	XrotationDegrees = Xrotation - 90.0f;
	YrotationDegrees = Yrotation - 90.0f;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX - (legOffsetX - scaleX * 0.09f), startingPosY + 0.14, startingPosZ + bottomBarOffsetZ * 3.2135);
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawCylinderMesh();
	/***********************************************/

	// adjustable head rest notch to raise/lower chair (fourth from bottom)
	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX * 0.0067f, scaleY * 25.6f, scaleZ * 0.0033f);
	// set the XYZ rotation
	XrotationDegrees = Xrotation - 90.0f;
	YrotationDegrees = Yrotation - 90.0f;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX - (legOffsetX - scaleX * 0.09f), startingPosY + 0.35, startingPosZ + bottomBarOffsetZ * 3.145);
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawCylinderMesh();
	/***********************************************/

	// adjustable head rest notch to raise/lower chair (fifth from bottom and final notch)
	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX * 0.0067f, scaleY * 25.6f, scaleZ * 0.0033f);
	// set the XYZ rotation
	XrotationDegrees = Xrotation - 90.0f;
	YrotationDegrees = Yrotation - 90.0f;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX - (legOffsetX - scaleX * 0.09f), startingPosY + 0.6, startingPosZ + bottomBarOffsetZ * 3.068);
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// set the mesh color
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawCylinderMesh();
	/***********************************************/

	// flat chair section cushion
	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX * 0.9333f, scaleY * 1.5f, scaleZ * 0.9667f);
	// set the XYZ rotation
	XrotationDegrees = Xrotation;
	YrotationDegrees = Yrotation;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX, startingPosY + 0.1, startingPosZ);
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// set the mesh color
	m_pSceneManager->ApplyShaderColor(1, 0.922, 0.804, 1);
	m_pSceneManager->ApplyShaderMaterial("plastic");
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
	/***********************************************/

	// rotated head rest section cushion
	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX * 0.9333f, scaleY * 1.5f, scaleZ * 0.3833f);
	// set the XYZ rotation
	XrotationDegrees = Xrotation - 60.0f;
	YrotationDegrees = Yrotation;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX, startingPosY + 1.10, startingPosZ + 3.43);
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
	/***********************************************/

	// adjustable head rest piece to hold position
	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX * 0.02f, scaleY, scaleZ * 0.01f);
	// set the XYZ rotation
	XrotationDegrees = Xrotation;
	YrotationDegrees = Yrotation;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX, startingPosY - 0.1, startingPosZ + bottomBarOffsetZ * 3.355);
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// set the mesh color
	m_pSceneManager->ApplyShaderTexture("dark-metal");
	m_pSceneManager->ApplyShaderMaterial("metal");
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
	/***********************************************/

	// adjustable head rest piece to hold position 2
	// set the XYZ scale
	scaleXYZ = glm::vec3(scaleX * 0.02f, scaleY * 1.4f, scaleZ * 0.005f);
	// set the XYZ rotation
	XrotationDegrees = Xrotation - 90.0f;
	YrotationDegrees = Yrotation;
	ZrotationDegrees = Zrotation;
	// set the XYZ position
	positionXYZ = glm::vec3(startingPosX, startingPosY - 0.135, startingPosZ + bottomBarOffsetZ * 3.32);
	// set the transformations into memory 
	m_pSceneManager->ApplyTransformations(
		scaleXYZ,
		XrotationDegrees,
		YrotationDegrees,
		ZrotationDegrees,
		positionXYZ);
	// draw the mesh
	m_pSceneManager->getBasicMeshes()->DrawBoxMesh();
	/***********************************************/
}
// end