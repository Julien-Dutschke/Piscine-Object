#ifndef __ALIST_HPP__
#define __ALIST_HPP__

#include <iostream>

#include "Singetons.hpp"
#include <vector>

//! T is the type of the elements in the list
template<class T, class U>
class AList : public Singetons<U>
{
    protected:
    AList(std::string name) : _name(name) {}
    AList();
    void operator=(const AList&) = delete;
    AList(const AList&) = delete;

    std::string _name;
    std::vector<T> _listContent;
    
    public:
    void add(T element)
    {
        std::cout << "Adding " << element.getName() << std::endl;
        _listContent.push_back(element);
    }
    void remove(T element)
    {
        typename std::vector<T>::iterator it = 
        std::find(_listContent.begin(), _listContent.end(), element);

        if (it != _listContent.end())
        {
            std::cout << "Removing " << element.getName() << std::endl;
            _listContent.erase(it);
        }
        else
            std::cout << "Element not found" << std::endl;
    }
    void print()
    {
        std::cout << "Printing list " << _name << std::endl;
        for (T element : _listContent)
            std::cout << element.getName() << std::endl;
        std::cout << "End of list" << std::endl;
    }
    virtual std::string getName() const = 0;
};

#endif