#include <iostream>
#include <memory>
#include <mutex>

class Singleton
{
public:
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

    static std::shared_ptr<Singleton> getInstance()
    {
        std::call_once(initFlag, []()
                       { instance_ = std::shared_ptr<Singleton>(new Singleton()); });
        return instance_;
    }

    // static void deleter(Singleton *ptr) { delete ptr; } // 定义静态删除器
    ~Singleton() { std::cout << "~Singleton()" << std::endl; } // 仍然是 private
private:
    Singleton() { std::cout << "Singleton()" << std::endl; }

    static std::shared_ptr<Singleton> instance_;
    static std::once_flag initFlag;
};

// 初始化静态成员变量
std::shared_ptr<Singleton> Singleton::instance_;
std::once_flag Singleton::initFlag;

int main()
{
    try
    {
        auto s1 = Singleton::getInstance();
        auto s2 = Singleton::getInstance();
        printf("p1 = %p\n", s1.get());
        printf("p2 = %p\n", s2.get());
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0; // `shared_ptr` 释放 Singleton
}
