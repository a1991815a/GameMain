#include "Scene.h"

Scene::Scene()
{
	setNodeType(SCENE);
	
}

Scene::~Scene()
{
	
}

bool Scene::init()
{
	m_camera = Camera::create();
	
	return true;
}

Camera* Scene::getCamera() const
{
	return m_camera;
}

void Scene::visit() const
{
	visitChilds();
}
