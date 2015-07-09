#ifndef __MAP__
#define __MAP__
#include <unordered_map>

template<typename kType, typename T>
class Map{
public:
	typedef typename std::unordered_map<kType, T>::value_type value_type;
	typedef typename std::unordered_map<kType, T>::iterator iterator;
	typedef typename std::unordered_map<kType, T>::const_iterator const_iterator;
	typedef typename std::unordered_map<kType, T>::pointer pointer;
	typedef typename std::unordered_map<kType, T>::const_pointer const_pointer;
	typedef typename std::unordered_map<kType, T>::reference reference;
	typedef typename std::unordered_map<kType, T>::const_reference const_reference;
	typedef typename std::unordered_map<kType, T>::mapped_type mapped_type;
	typedef typename std::unordered_map<kType, T>::key_type key_type;
	typedef typename std::unordered_map<kType, T>::size_type size_type;
public:
	~Map();
	inline typename Map<kType, T>::iterator begin();
	inline typename Map<kType, T>::const_iterator begin() const;
	inline typename Map<kType, T>::iterator end();
	inline typename Map<kType, T>::const_iterator end() const;
	inline typename Map<kType, T>::size_type size() const;
	inline typename Map<kType, T>::mapped_type& at(typename const Map<kType, T>::key_type& key);
	inline typename const Map<kType, T>::mapped_type& at(typename const Map<kType, T>::key_type& key) const;
	inline typename Map<kType, T>::iterator find(typename const Map<kType, T>::key_type& key);
	inline typename Map<kType, T>::const_iterator find(typename const Map<kType, T>::key_type& key) const;
	inline void insert(typename const Map<kType, T>::key_type& key, typename Map<kType, T>::mapped_type& data);
	inline void erase(typename const Map<kType, T>::key_type& key);
	inline void clear();

private:
	std::unordered_map<kType, T> m_map;
};

template<typename kType, typename T>
Map<kType, T>::~Map()
{
	clear();
}

template<typename kType, typename T>
void Map<kType, T>::clear()
{
	auto itor = m_map.begin();
	for (; itor != m_map.end(); ++itor)
		itor->second->release();
	m_map.clear();
}

template<typename kType, typename T>
typename Map<kType, T>::const_iterator
Map<kType, T>::find(typename const Map<kType, T>::key_type& key) const
{
	return m_map.find(key);
}

template<typename kType, typename T>
typename Map<kType, T>::iterator
Map<kType, T>::find(typename const Map<kType, T>::key_type& key)
{
	return m_map.find(key);
}

template<typename kType, typename T>
void 
Map<kType, T>::erase(typename const Map<kType, T>::key_type& key)
{
	m_map.erase(key);
	m_map.at(key)->release();
}

template<typename kType, typename T>
void 
Map<kType, T>::insert(typename const Map<kType, T>::key_type& key, typename Map<kType, T>::mapped_type& data)
{
	data->retain();
	m_map[key] = data;
}

template<typename kType, typename T>
typename const Map<kType, T>::mapped_type&
Map<kType, T>::at(typename const Map<kType, T>::key_type& key) const
{
	return m_map.at(key);
}

template<typename kType, typename T>
typename Map<kType, T>::mapped_type&
Map<kType, T>::at(typename const Map<kType, T>::key_type& key)
{
	return m_map.at(key);
}

template<typename kType, typename T>
typename Map<kType, T>::size_type
Map<kType, T>::size() const
{
	return m_map.size();
}

template<typename kType, typename T>
typename Map<kType, T>::const_iterator
Map<kType, T>::end() const
{
	return m_map.end();
}

template<typename kType, typename T>
typename Map<kType, T>::iterator
Map<kType, T>::end()
{
	return m_map.end();
}

template<typename kType, typename T>
typename Map<kType, T>::const_iterator
Map<kType, T>::begin() const
{
	return m_map.begin();
}

template<typename kType, typename T>
typename Map<kType, T>::iterator
Map<kType, T>::begin()
{
	return m_map.begin();
}

#endif