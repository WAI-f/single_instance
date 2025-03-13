#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

using std::cout;
using std::endl;

class Singleton
{
public:
    static Singleton *getInstance()
    {
        pthread_once(&_once, init);
        return _pInstance;
    }

    static void init()
    {
        _pInstance = new Singleton();
        atexit(destroy);
    }

    static void destroy()
    {
        if(_pInstance)
            delete _pInstance;
    }

private:
    Singleton(){std::cout<<"Singleton()"<<std::endl;}
    ~Singleton(){std::cout<<"~Singleton()"<<std::endl;}

private:
    static Singleton *_pInstance;
    static pthread_once_t _once;
};

Singleton *Singleton::_pInstance = nullptr;
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

int main()
{
    Singleton *p1 = Singleton::getInstance();
    Singleton *p2 = Singleton::getInstance();

    printf("p1 = %p\n", p1);
    printf("p2 = %p\n", p2);

    return 0;
}