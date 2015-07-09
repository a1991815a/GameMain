#ifndef __VECTOR__
#define __VECTOR__
#include <vector>

template<typename dType>
class Vector{
public:
	typedef typename std::vector<dType>::value_type value_type;
	typedef typename std::vector<dType>::iterator iterator;
	typedef typename std::vector<dType>::const_iterator const_iterator;
	typedef typename std::vector<dType>::pointer pointer;
	typedef typename std::vector<dType>::const_pointer const_pointer;
	typedef typename std::vector<dType>::reference reference;
	typedef typename std::vector<dType>::const_reference const_reference;
	typedef typename std::vector<dType>::size_type size_type;
public:
	~Vector();
	inline typename Vector<dType>::iterator begin();
	inline typename Vector<dType>::const_iterator begin() const;
	inline typename Vector<dType>::iterator end();
	inline typename Vector<dType>::const_iterator end() const;
	inline typename Vector<dType>::size_type size() const;
	inline typename Vector<dType>::reference at(int key);
	inline typename Vector<dType>::const_reference at(int key) const;
	inline typename Vector<dType>::iterator find(typename Vector<dType>::const_reference data);
	inline typename Vector<dType>::const_iterator find(typename Vector<dType>::const_reference data) const;
	inline void insert(int index, typename Vector<dType>::value_type& data);
	inline void erase(int key);
	inline void push_back(typename Vector<dType>::const_reference data);
	inline void pop_back();
	inline typename Vector<dType>::reference front();
	inline typename Vector<dType>::const_reference front() const;
	inline typename Vector<dType>::reference back();
	inline typename Vector<dType>::const_reference back() const;
	inline void clear();
private:
	std::vector<dType> m_vector;
};

template<typename dType>
Vector<dType>::~Vector()
{
	clear();
}

template<typename dType>
void Vector<dType>::clear()
{
	auto itor = m_vector.begin();
	for (; itor != m_vector.end(); ++itor)
		(*itor)->release();
	m_vector.clear();
}

template<typename dType>
typename Vector<dType>::const_reference
Vector<dType>::back() const
{
	return m_vector.back();
}

template<typename dType>
typename Vector<dType>::reference Vector<dType>::back()
{
	return m_vector.back();
}

template<typename dType>
typename Vector<dType>::const_reference Vector<dType>::front() const
{
	return m_vector.front();
}

template<typename dType>
typename Vector<dType>::reference Vector<dType>::front()
{
	return m_vector.front();
}

template<typename dType>
void 
Vector<dType>::pop_back()
{
	m_vector.back()->release();
	m_vector.pop_back();
}

template<typename dType>
void
Vector<dType>::push_back(typename Vector<dType>::const_reference data)
{
	data->retain();
	m_vector.push_back(data);
}

template<typename dType>
void 
Vector<dType>::erase(int key)
{
	m_vector.at(key)->release();
	m_vector.erase(m_vector.begin() + key);
}

template<typename dType>
void 
Vector<dType>::insert(int index, typename Vector<dType>::value_type& data)
{
	data->retain();
	m_vector.insert(m_vector.begin() + index, data);
}

template<typename dType>
typename Vector<dType>::const_iterator
Vector<dType>::find(typename Vector<dType>::const_reference data) const
{
	auto itor = m_vector.begin();
	for (; itor != m_vector.end() && *itor != data; ++itor)
	{}
	return itor;
}

template<typename dType>
typename Vector<dType>::iterator 
Vector<dType>::find(typename Vector<dType>::const_reference data)
{
	auto itor = m_vector.begin();
	for (; itor != m_vector.end() && *itor != data; ++itor)
	{}
	return itor;
}

template<typename dType>
typename Vector<dType>::const_reference
Vector<dType>::at(int key) const
{
	return m_vector.at(key);
}

template<typename dType>
typename Vector<dType>::reference
Vector<dType>::at(int key)
{
	return m_vector.at(key);
}

template<typename dType>
typename Vector<dType>::size_type
Vector<dType>::size() const
{
	return m_vector.size();
}

template<typename dType>
typename Vector<dType>::const_iterator
Vector<dType>::end() const
{
	return m_vector.end();
}

template<typename dType>
typename Vector<dType>::iterator
Vector<dType>::end()
{
	return m_vector.end();
}

template<typename dType>
typename Vector<dType>::const_iterator
Vector<dType>::begin() const
{
	return m_vector.begin();
}

template<typename dType>
typename Vector<dType>::iterator
Vector<dType>::begin()
{
	return m_vector.begin();
}

#endif