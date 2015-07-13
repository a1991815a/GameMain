#ifndef __NODE__
#define __NODE__
#include "Ref.h"
#include "Vec2.h"
#include <string>
#include "Vector.h"
#include "HeaderMacro.h"
#include "Vec3.h"

class Node: public Ref{
//构造函数
public:
	Node();
	~Node();

//虚函数
public:
	virtual void visit() const = 0;
	void pushRenderComand();

public:
//setter
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

	void setScale(const Vec2& scale);
	void setScale(float scale_x, float scale_y);
	void setScaleX(float scale_x);
	void setScaleY(float scale_y);
	void setRotate(const Vec3& rotate);
	void setRotate(float rotate_x, float rotate_y, float rotate_z);
	void setRotateX(float rotate_x);
	void setRotateY(float rotate_y);
	void setRotateZ(float rotate_z);

	void setContentSize(const Vec2& size);
	void setContentSize(float width, float height);
	void setContentSizeWidth(float width);
	void setContentSizeHeight(float height);

	void setNodeZorder(int z_order);
	void setGlobalZorder(int z_order);
	void setVertexZ(int vertex_z);

//getter
	const std::string& getTagName() const;
	int getTag() const;
	bool isEnable() const;
	bool isVisiable() const;
	const Vec2& getAnchorPoint() const;
	const Vec2& getPosition() const;
	float getPositionX() const;
	float getPositionY() const;

	const Vec2& getScale() const;
	float getScaleX() const;
	float getScaleY() const;
	const Vec3& getRotate() const;
	float getRotateX() const;
	float getRotateY() const;
	float getRotateZ() const;

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
	Vec2 m_scale;
	Vec3 m_rotate;
	Vec2 m_contentSize;

	int m_NodeZorder;
	int m_GlobalZorder;
	int m_VertexZ;
	Node* m_parent;
	int m_parentVectorIndex;
	Vector<Node*> m_childList;
	NodeTypes m_nodeType;
	D3DXMATRIX m_mMatrix;									//模型矩阵
protected:
	void setNodeType(NodeTypes type);
	void visitChilds() const;
private:
	void resetMatrix();
	void initMatrix();
};
#endif