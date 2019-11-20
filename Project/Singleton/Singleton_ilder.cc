#include<iostream>
#include<pthread.h>
using namespace std;


//thread not safe
template<typename T>
class Singleton_1
{
	private:
		static T* inst;
	public:
		static T* GetInstance()
		{
			if(inst == NULL)
				inst = new T();
			return inst;
		}

};


//thread is safe
template<typename T>
class Singleton_2
{
	private:
		volatile static T* inst;
		static mutex lock;
	public:
		static T* GetInstance()
		{
			if(inst == NULL)
			{
				lock.lock();
				if(inst == NULL)
				{
					inst = new T();
				}
				lock.unlock();
			}
			return inst;
		}
};
