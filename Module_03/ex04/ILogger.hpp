#ifndef __ILOGGER_HPP__

#define __ILOGGER_HPP__

#include <iostream>

#include "header.hpp"

// strict interface
class ILogger
{
    protected:
    ILogger(){}

    public:
    virtual void write(std::string message) = 0;
    virtual ~ILogger() {}    
};

class StreamLogger : public ILogger
{
    private:
    Header* _header;
    std::ostream& _stream;
    StreamLogger() : _stream(std::cout), _header(NULL) {}

    public:
    StreamLogger(std::ostream& stream) : _stream(stream), _header(NULL) {}
    StreamLogger(std::ostream& stream, Header* header) : _stream(stream), _header(header) {}
    
    void write(std::string message)
    {
        if (_header != NULL)
            _stream << _header->get();
        _stream << message << std::endl;
    }


    void setHeader(Header* header)
    {
        _header = header;
    }

    void removeHeader()
    {
        if (_header != NULL)
        {
            delete _header;
            _header = NULL;
        }
    }
};


#endif // __ILOGGER_HPP__