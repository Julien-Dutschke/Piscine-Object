#include "ILogger.hpp"
#include "FileLogger.hpp"
#include <vector>
#include "header.hpp"

int main()
{
    std::vector<ILogger*> loggers;
    loggers.push_back(new StreamLogger(std::cout));
    loggers.push_back(new StreamLogger(std::cerr, new DateHeader()));
    loggers.push_back(new FileLogger("log.txt", new StringHeader("ERROR: ")));

    while (true)
    {
        std::string message;
        std::cout << "Enter message: ";
        std::getline(std::cin, message);
        if (message == "exit")
            break;
        for (std::vector<ILogger*>::iterator it = loggers.begin(); it != loggers.end(); ++it)
        {
            (*it)->write(message);
        }
    }
}  