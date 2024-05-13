#ifndef __FILELOGGER_HPP__
#define __FILELOGGER_HPP__


#include <iostream>
#include "header.hpp"
#include <fstream>
#include "ILogger.hpp"

//first class that will write the string into a file

class FileLogger : public ILogger
{
    private:
    FileLogger() : _header(NULL){}
    std::fstream file;
    Header* _header;

    public:


    FileLogger(std::string filename) : file() , _header(NULL)
    {
        file.open(filename.c_str(), std::ios::app | std::ios::out);
        if (file.is_open() == false)
        {
            std::cerr << "Error opening file" << std::endl;
            throw std::exception();
        }
        std::cout << "FILE "<< filename << " OPEN"<< std::endl;
    }
    
    FileLogger(std::string filename, Header* header) : file() , _header(header)
    {
        file.open(filename.c_str(), std::ios::app | std::ios::out);
        if (file.is_open() == false)
        {
            std::cerr << "Error opening file" << std::endl;
            throw std::exception();
        }
        std::cout << "FILE "<< filename << " OPEN"<< std::endl;
    }

    void write(std::string message)
    {
        if (file.good())
        {
            if (_header != NULL)
                file << _header->get();
            file << message << std::endl;
        }
        else
            std::cerr << "Error writing to file" << std::endl;
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


#endif // __FILELOGGER_HPP__