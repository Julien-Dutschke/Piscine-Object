#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <vector>
#include <algorithm>
#include <iostream>
#include "Vector2.hpp"

class Graph
{
    private:
        Vector2 _size;
        std::vector<Vector2> _nodes;
        std::vector<Vector2> getNodes() const;
        void setNodes(std::vector<Vector2> nodes);
    public:
        Graph(Vector2 size);
        Vector2 getSize() const;
        void setSize(Vector2 size);
        void addNode(Vector2 node);
        void removeNode(Vector2 node);
        void printGraph() const;
};

#endif