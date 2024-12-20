#pragma once
#include <glm/gtx/transform.hpp>

// forward declare SceneManager
class SceneManager;

/***class containing code to draw custom shapes***/
class MyObjects {
public:
	// constructor
	MyObjects(SceneManager* sceneManager);
	// public draw methods
	void DrawSandWaterAndSky(float planeWidth);
	void DrawLowWall(float planeWidth);
	void DrawBeachUmbrella();
	void DrawLantern(float startingPosX, float startingPosY, float startingPosZ);
	void DrawBeachChair(float startingPosX, float startingPosY, float startingPosZ);

private:
	// pointer to SceneManager class
	SceneManager* m_pSceneManager;

	// transformation variables
	glm::vec3 scaleXYZ;
	float XrotationDegrees = 0.0f;
	float YrotationDegrees = 0.0f;
	float ZrotationDegrees = 0.0f;
	glm::vec3 positionXYZ;

	// private methods used within the public draw methods 
	void DrawLanternLegs(
		float startingPosX,
		float startingPosY,
		float startingPosZ,
		float width,
		float depth);
	void DrawVerticalLanternBars(
		float startingPosX,
		float startingPosY,
		float startingPosZ,
		float spacing,
		bool isFrontOrBack);
	void DrawHorizontalLanternBars(
		float startingPosX,
		float startingPosY,
		float startingPosZ,
		float spacing,
		bool isFrontOrBack);
	void DrawLanternTop(float startingPosX, float startingPosY, float startingPosZ);
	void DrawLanternLight(float startingPosX, float startingPosY, float startingPosZ);
};
