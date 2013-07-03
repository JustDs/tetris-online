#ifndef SINGLETON_H
#define SINGLETON_H
template<typename T>
class Singleton
{
public:
	static T& instance()
	{
		if(_value == 0)
		{
			_value = new T();
		}
		return _value;
	}
private:
	Singleton();
	~Singleton();
	static T* _value;
};

template<typename T>
T* Singleton<T>::_value = 0;
#endif

