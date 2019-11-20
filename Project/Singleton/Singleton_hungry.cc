#include<iostream>
using namespace std;

template<typename T>
class Singleton
{
	private:
		static T data;
		Singleton() = delete;
		Singleton(const Singleton<T>&) = delete;
		Singleton& operatoe=(const Singleton<T>& ) = delete;
	public:
		static T* GetInstance()
		{
			return &data;
		}
};
