#include "Node.h"
#include <stdexcept>
#include <d3dx9math.h>
#include <d3dx9math.h>

Node::Node()
	:m_tagName(), m_tag(0), m_enable(true), m_visiable(true), 
	m_anchorPoint(0, 0), m_position(0, 0),
	m_scale(1, 1), m_rotate(0, 0, 0), 
	m_contentSize(0, 0),
	m_NodeZorder(0), m_GlobalZorder(0), m_VertexZ(0), 
	m_parent(nullptr), m_parentVectorIndex(-1)
{
	resetMatrix();
}

Node::~Node()
{
	releaseAllChild();
}

void Node::pushRenderComand()
{
	if (isEnable() && isVisiable())
	{
		initMatrix();
		this->visit();
	}
}

void Node::setTagName(const std::string& name)
{
	m_tagName = name;
}

void Node::setTag(int tag)
{
	m_tag = tag;
}

void Node::setEnable(bool enable)
{
	m_enable = enable;
}

void Node::setVisiable(bool visiable)
{
	m_visiable = visiable;
}

void Node::setAnchorPoint(const Vec2& anchorPoint)
{

	m_anchorPoint = anchorPoint;
}

void Node::setAnchorPoint(float ap_x, float ap_y)
{
	m_anchorPoint.x = ap_x;
	m_anchorPoint.y = ap_y;
}

void Node::setPosition(const Vec2& pos)
{
	m_position = pos;
}

void Node::setPosition(float x, float y)
{
	m_position.x = x;
	m_position.y = y;
}

void Node::setPositionX(float x)
{
	m_position.x = x;
}

void Node::setPositionY(float y)
{
	m_position.y = y;
}

void Node::setScale(const Vec2& scale)
{
	m_scale = scale;
	m_contentSize.width *= m_scale.x;
	m_contentSize.height *= m_scale.y;
}

void Node::setScale(float scale_x, float scale_y)
{
	m_scale.x = scale_x;
	m_scale.y = scale_y;
	m_contentSize.width *= m_scale.x;
	m_contentSize.height *= m_scale.y;
}

void Node::setScaleX(float scale_x)
{
	m_scale.x = scale_x;
	m_contentSize.width *= m_scale.x;
}

void Node::setScaleY(float scale_y)
{
	m_scale.y = scale_y;
	m_contentSize.height *= m_scale.y;
}

void Node::setRotate(const Vec3& rotate)
{
	m_rotate = rotate;
}

void Node::setRotate(float rotate_x, float rotate_y, float rotate_z)
{
	m_rotate.x = rotate_x;
	m_rotate.y = rotate_y;
	m_rotate.z = rotate_z;
}

void Node::setRotateX(float rotate_x)
{
	m_rotate.x = rotate_x;
}

void Node::setRotateY(float rotate_y)
{
	m_rotate.y = rotate_y;
}

void Node::setRotateZ(float rotate_z)
{
	m_rotate.z = rotate_z;
}

void Node::setContentSize(const Vec2& size)
{
	m_contentSize = size;
}

void Node::setContentSize(float width, float height)
{
	m_contentSize.width = width;
	m_contentSize.height = height;
}

void Node::setContentSizeWidth(float width)
{
	m_contentSize.width = width;
}

void Node::setContentSizeHeight(float height)
{
	m_contentSize.height = height;
}

void Node::setNodeZorder(int z_order)
{
	m_NodeZorder = z_order;
}

void Node::setGlobalZorder(int z_order)
{
	m_GlobalZorder = z_order;
}

void Node::setVertexZ(int vertex_z)
{
	m_VertexZ = vertex_z;
}

const std::string& Node::getTagName() const
{
	return m_tagName;
}

int Node::getTag() const
{
	return m_tag;
}

bool Node::isEnable() const
{
	return m_enable;
}

bool Node::isVisiable() const
{
	return m_visiable;
}

const Vec2& Node::getAnchorPoint() const
{
	return m_anchorPoint;
}

const Vec2& Node::getPosition() const
{
	return m_position;
}

float Node::getPositionX() const
{
	return m_position.x;
}

float Node::getPositionY() const
{
	return m_position.y;
}

const Vec2& Node::getScale() const
{
	return m_scale;
}

float Node::getScaleX() const
{
	return m_scale.x;
}

float Node::getScaleY() const
{
	return m_scale.y;
}

const Vec3& Node::getRotate() const
{
	return m_rotate;
}

float Node::getRotateX() const
{
	return m_rotate.x;
}

float Node::getRotateY() const
{
	return m_rotate.y;
}

float Node::getRotateZ() const
{
	return m_rotate.z;
}

const Vec2& Node::getContentSize() const
{
	return m_contentSize;
}

float Node::getContentSizeWidth() const
{
	return m_contentSize.width;
}

float Node::getContentSizeHeight() const
{
	return m_contentSize.height;
}

int Node::getNodeZorder() const
{
	return m_NodeZorder;
}

int Node::getGlobalZorder() const
{
	return m_GlobalZorder;
}

int Node::getVertexZ() const
{
	return m_VertexZ;
}

void Node::addChild(Node* child, int Zorder /*= 0*/)
{
	m_childList.push_back(child);
	child->m_parentVectorIndex = m_childList.size();
	child->setNodeZorder(Zorder);
	child->m_parent = this;
}

void Node::releaseChild(Node* child)
{
	int index = child->m_parentVectorIndex;
	if (index == -1)
		throw std::logic_error("this child is not exist in the vector!");
	m_childList.erase(index);
	child->m_parentVectorIndex = -1;
	for (size_t i = (size_t)index; i < m_childList.size(); i++)
		m_childList.at(i)->m_parentVectorIndex--;
}

void Node::releaseChildByName(const std::string& name)
{
	releaseChild(searchChildByName(name));
}

void Node::releaseChildByTag(int tag)
{
	releaseChild(searchChildByTag(tag));
}

void Node::releaseAllChild()
{
	for (size_t index = 0; index < m_childList.size(); index++)
		m_childList.at(index)->m_parentVectorIndex = -1;
	m_childList.clear();
}

Node* Node::searchChildByName(const std::string& name) const
{
	for(size_t i = 0; i < m_childList.size(); i++){
		Node* node = m_childList.at(i);
		if (node->m_tagName == name)
			return node;
	}
	return nullptr;
}

Node* Node::searchChildByTag(int tag) const
{
	for (size_t i = 0; i < m_childList.size(); i++){
		Node* node = m_childList.at(i);
		if (node->m_tag == tag)
			return node;
	}
	return nullptr;
}

const Vector<Node*>& Node::getChilds() const
{
	return m_childList;
}

Node* Node::getParent() const
{
	return m_parent;
}

NodeTypes Node::getNodeType() const
{
	return m_nodeType;
}

void Node::setNodeType(NodeTypes type)
{
	m_nodeType = type;
}

void Node::visitChilds() const
{
	for (size_t i = 0; i < m_childList.size(); i++)
		m_childList.at(i)->visit();
}

void Node::resetMatrix()
{
	D3DXMatrixTranslation(&m_mMatrix, 0, 0, 0);
}

void Node::initMatrix()
{
	resetMatrix();
	D3DXMATRIX matrix;
	if(m_rotate.x != 0)
		D3DXMatrixRotationX(&matrix, m_rotate.x * D3DX_PI);
	m_mMatrix =  m_mMatrix * matrix;
	if(m_rotate.y != 0)
		D3DXMatrixRotationY(&matrix, m_rotate.y * D3DX_PI);
	m_mMatrix =  m_mMatrix * matrix;
	if(m_rotate.z != 0)
		D3DXMatrixRotationZ(&matrix, m_rotate.z * D3DX_PI);
	m_mMatrix =  m_mMatrix * matrix;

	//执行完自身旋转再进行父亲旋转缩放平移
	if (m_parent != nullptr)
		m_mMatrix = m_mMatrix * m_parent->m_mMatrix;

	if(m_scale.x != 1 || m_scale.y != 1)
		D3DXMatrixScaling(&matrix, m_scale.x, m_scale.y, 1);
	m_mMatrix =  m_mMatrix * matrix;
	D3DXMatrixTranslation(&matrix, m_position.x, m_position.y, 0);
	m_mMatrix =  m_mMatrix * matrix;

	for(size_t i = 0; i < m_childList.size(); i++){
		auto& child = m_childList.at(i);
		child->initMatrix();
	}
}
