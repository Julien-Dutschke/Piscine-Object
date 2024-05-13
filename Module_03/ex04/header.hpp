#ifndef __HEADER_HPP__
#define __HEADER_HPP__

#include <string>
#include <iostream>
#include <ctime>

class Header
{

    public:
    virtual ~Header() {}
    virtual std::string get() = 0;
};

class DateHeader : public Header
{
    public:
    std::string get() 
    {
        time_t now = time(0);
        char* dt = ctime(&now);
        return dt;
    }
};




class StringHeader : public Header
{
private:
    std::string _header;

public:
    StringHeader(const std::string& header) : _header(header) {}

    std::string get()
    {
        return _header;
    }
};

#endif // __HEADER_HPP__