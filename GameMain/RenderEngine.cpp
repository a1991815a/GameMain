#include "RenderEngine.h"

RenderEngine::~RenderEngine()
{

}

RenderEngine::RenderEngine()
{

}

void RenderEngine::init()
{
	m_globalRenderList.reserve(25);
	m_localRenderList.reserve(160);
	for (int i = 0; i < 25; i++)
	{
		QuadCommand* qc = new QuadCommand();
		m_globalRenderList.push_back(qc);
	}
	for (int i = 0; i < 160; i++)
	{
		QuadCommand* qc = new QuadCommand();
		m_localRenderList.push_back(qc);
	}
}

void RenderEngine::reset()
{
	for (size_t i = 0; i < m_globalRenderList.size(); i++)
	{
		m_globalRenderList.at(i)->enable = false;
		m_globalRenderList.at(i)->zOrder = 0;
	}

	for (size_t i = 0; i < m_localRenderList.size(); i++)
	{
		m_localRenderList.at(i)->enable = false;
		m_localRenderList.at(i)->zOrder = 0;
	}
}

void RenderEngine::render()
{

	reset();
}

void RenderEngine::pushQuadCommand(
	IDirect3DTexture9* render_texture, 
	const Rect* render_rect, 
	const Vec2* anchorPoint, 
	const D3DXMATRIX* final_matrix,
	int localzOrder, int GlobalzOrder /*=0 */)
{
	if(GlobalzOrder != 0)
	{
		size_t index = 0;
		for (; index < m_globalRenderList.size(); index++)
		{
			auto& obj = m_globalRenderList.at(index);
			if(obj->enable || GlobalzOrder > obj->zOrder)
				break;
		}
		if(index == m_globalRenderList.size())
			return;
		dragBack(m_globalRenderList, index);
		auto& obj = m_globalRenderList.at(index);
		obj->render_texture = render_texture;
		obj->render_rect = render_rect;
		obj->anchorPoint = anchorPoint;
		obj->final_matrix = final_matrix;
		obj->zOrder = GlobalzOrder;
		obj->enable = true;
		return;
	}


	size_t index = 0;
	for (; index < m_localRenderList.size(); index++)
	{
		auto& obj = m_localRenderList.at(index);
		if(obj->enable || localzOrder > obj->zOrder)
			break;
	}
	if(index == m_localRenderList.size())
		return;
	dragBack(m_localRenderList, index);
	auto& obj = m_localRenderList.at(index);
	obj->render_texture = render_texture;
	obj->render_rect = render_rect;
	obj->anchorPoint = anchorPoint;
	obj->final_matrix = final_matrix;
	obj->zOrder = localzOrder;
	obj->enable = true;
}

void RenderEngine::dragBack(Vector<QuadCommand*>& list, int index)
{
	for (int i = list.size() - 2; i >= index; --i)
		*list.at(i + 1) = *list.at(i);
}
