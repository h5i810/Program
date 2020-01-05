#include <iostream>

//单线程
template <typename T>
class Singleton
{
private:
    static T* _value;
public:
    static T& getInstance(){
        if(_value==NULL)
            _value=new T();
        return _value;
    }

private:
    Singleton();
    ~Singleton();
};

template<typename T>
T* Singleton<T>::_value=NULL;

//<effective C++>中的写法
template<typename T>
class Singleton
{
public:
    static T& getInstance(){
        staic T value;
        return value;
    }
private:
    Singleton();
    ~Singleton();
};




//多线程
template<typename T>
class Singleton
{
private:
    static pthread_once_t _once_control;
    static T* _value;
public:
    static T& getInstance()
    {
        pthread_once(&_once_control, init);
        return *_value;
    }
private:
    static void init()
    {
        _value=new T();
    }
    Singleton();
    ~Singleton();
};

template<typename T>
pthread_once_t Singleton<T>::_once_control=PTHREAD_ONCE_INIT;
template<typename T>
T *Singleton<T>::_value=NULL;


