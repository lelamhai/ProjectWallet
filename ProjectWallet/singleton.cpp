#include "Singleton.h"

Singleton* Singleton::instance = 0;
Singleton::Singleton()
{
}

Singleton::~Singleton()
{
}

Singleton* Singleton::getInstance()
{
	if (instance == 0)
	{
		instance = new Singleton();
	}
	return instance;
}