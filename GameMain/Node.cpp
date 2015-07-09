#include "Node.h"
#include <stdexcept>

Node::Node()
	:m_tag(0), m_enable(true), m_visiable(true), 
	m_anchorPoint(Vec2(0, 0)), m_position(Vec2(0, 0)), m_contentSize(Vec2(0, 0)),
	m_NodeZorder(0), m_GlobalZorder(0), m_VertexZ(0), 
	m_parent(nullptr), m_parentVectorIndex(-1)
{
	
}

Node::~Node()
{
	releaseAllChild();
}

void Node::pushRenderComand()
{
	if (isEnable() && isVisiable())
		this->visit();
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
