#ifndef __MANAGERTEMPLATE__
#define __MANAGERTEMPLATE__
#include <map>
#include <vector>
#include "Vector.h"
#include "Map.h"

template<typename T>
class ManagerMapTemplate{
public:
	void pushMap(T* obj){
		m_managerList.insert(obj, obj);
	};
	void popMap(T* obj){
		m_managerList.erase(obj);
	};

	void clearMap(){
		m_managerList.clear();
	};

	int sizeMap() const{
		return m_managerList.size();
	};
protected:
	typename Map<T*, T*>::iterator beginMap(){ return m_managerList.begin(); };
	typename Map<T*, T*>::iterator endMap(){ return m_managerList.end(); };
	typename Map<T*, T*>::const_iterator beginMap() const{ return m_managerList.begin(); };
	typename Map<T*, T*>::const_iterator endMap() const{ return m_managerList.end(); };
private:
	Map<T*, T*> m_managerList;
};

template<typename T>
class ManagerVectorTemplate{
public:
	void pushVector(T* obj){
		m_managerList.push_back(obj);
	};

	void popVector(int index){
		m_managerList.erase(index);
	};

	void clearVector(){
		m_managerList.clear();
	};

	int sizeVector() const{
		return m_managerList.size();
	};
protected:
	typename Vector<T*>::iterator beginVector() { return m_managerList.begin(); };
	typename Vector<T*>::iterator endVector() { return m_managerList.end(); };
	typename Vector<T*>::const_iterator beginVector() const { return m_managerList.begin(); };
	typename Vector<T*>::const_iterator endVector() const { return m_managerList.end(); };
private:
	Vector<T*> m_managerList;
};
#endif