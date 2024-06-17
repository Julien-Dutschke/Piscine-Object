#ifndef __SINGLETONS_HPP__
#define __SINGLETONS_HPP__

template <class T>
class Singletons
{
    protected:
        static T* _currentInstance;

    protected:
        Singletons() {}
        Singletons(const Singletons& other) = delete;
        Singletons& operator=(const Singletons& other) = delete;

    public:
    static T* getInstance()
    {
        if (_currentInstance == nullptr)
            _currentInstance = new T;
        return _currentInstance;
    }

    void destroyInstance()
    {
        if (_currentInstance != nullptr)
        {
            delete _currentInstance;
            _currentInstance = nullptr;
        }
    }
};

template <class T>
T* Singletons<T>::_currentInstance = nullptr;

#endif