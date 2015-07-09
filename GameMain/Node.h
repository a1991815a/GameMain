#ifndef __NODE__
#define __NODE__
#include "Ref.h"
#include "Vec2.h"
#include <string>
#include "Vector.h"
#include "HeaderMacro.h"

class Node: public Ref{
//构造函数
public:
	Node();
	~Node();

//虚函数
public:
	virtual void visit() const = 0;
	void pushRenderComand();
//getter, setter
public:
	void setTagName(const std::string& name);
	void setTag(int tag);
	void setEnable(bool enable);
	void setVisiable(bool visiable);
	void setAnchorPoint(const Vec2& anchorPoint);
	void setAnchorPoint(float ap_x, float ap_y);
	void setPosition(const Vec2& pos);
	void setPosition(float x, float y);
	void setPositionX(float x);
	void setPositionY(float y);
	void setContentSize(const Vec2& size);
	void setContentSize(float width, float height);
	void setContentSizeWidth(float width);
	void setContentSizeHeight(float height);
	void setNodeZorder(int z_order);
	void setGlobalZorder(int z_order);
	void setVertexZ(int vertex_z);

	const std::string& getTagName() const;
	int getTag() const;
	bool isEnable() const;
	bool isVisiable() const;
	const Vec2& getAnchorPoint() const;
	const Vec2& getPosition() const;
	float getPositionX() const;
	float getPositionY() const;
	const Vec2& getContentSize() const;
	float getContentSizeWidth() const;
	float getContentSizeHeight() const;
	int getNodeZorder() const;
	int getGlobalZorder() const;
	int getVertexZ() const;

public:
	void addChild(Node* child, int Zorder = 0);
	void releaseChild(Node* child);
	void releaseChildByName(const std::string& name);
	void releaseChildByTag(int tag);
	void releaseAllChild();
	Node* searchChildByName(const std::string& name) const;
	Node* searchChildByTag(int tag) const;
	const Vector<Node*>& getChilds() const;
	Node* getParent() const;
	NodeTypes getNodeType() const;
private:
	std::string m_tagName;
	int m_tag;
	bool m_enable;
	bool m_visiable;
	Vec2 m_anchorPoint;
	Vec2 m_position;
	Vec2 m_contentSize;
	int m_NodeZorder;
	int m_GlobalZorder;
	int m_VertexZ;
	Node* m_parent;
	int m_parentVectorIndex;
	Vector<Node*> m_childList;
	NodeTypes m_nodeType;
protected:
	void setNodeType(NodeTypes type);
};
#endif