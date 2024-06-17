#ifndef __LIST_PRINTER_HPP__
#define __LIST_PRINTER_HPP__

#include <iostream>
#include <list>

class ListPrinter
{
    public:
        template <typename T>
        static void printList(std::list<T*> list)
        {
            for (auto it = list.begin(); it != list.end(); it++)
            {
                std::cout << **it << std::endl;
            }
        }
};

#endif