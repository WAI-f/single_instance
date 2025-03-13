#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

using std::cout;
using std::endl;

class Singleton
{
public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&)=delete;

    static Singleton& getInstance()
    {
        static Singleton instance;
        return instance;
    }

private:
    Singleton() { std::cout << "Singleton()" << std::endl; }
    ~Singleton() { std::cout << "~Singleton()" << std::endl; }
};

int main()
{
    Singleton& p1 = Singleton::getInstance();
    Singleton& p2 = Singleton::getInstance();

    printf("p1 = %p\n", &p1);
    printf("p2 = %p\n", &p2);

    return 0;
}