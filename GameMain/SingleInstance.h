#ifndef __SINGLEINSTANCE__
#define __SINGLEINSTANCE__

#define DEFINE_INSTANCE_PRIVATE(A)		\
private:								\
	friend class SingleInstance<A>;		\
	A();								\
	~A();								

template<typename T>
class SingleInstance{
public:
	static T* getInstance();
	static void destroyInstance();
private:
	static T* m_instance;
};

template<typename T>
T* SingleInstance<T>::m_instance = nullptr;

template<typename T>
void SingleInstance<T>::destroyInstance()
{
	if (m_instance != nullptr){
		delete m_instance;
		m_instance = nullptr;
	}
}

template<typename T>
T* SingleInstance<T>::getInstance()
{
	if (m_instance == nullptr)
		m_instance = new T();
	return m_instance;
}

#endif