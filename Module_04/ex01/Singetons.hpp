#ifndef __SINGETONS_HPP__
#define __SINGETONS_HPP__

#include <math.h>

template <typename T>
class Singetons
{
    protected:
    Singetons() {}
    Singetons(const Singetons&) = delete;
    void operator=(const Singetons&) = delete;
    
    public:
    static T* getInstance()
    {
        static T instance;
        return &instance;
    }
};

#endif