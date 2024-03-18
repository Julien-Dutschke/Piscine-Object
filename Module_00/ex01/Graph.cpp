#include "Graph.hpp"

Graph::Graph(Vector2 size) : _size(size){
}

Vector2 Graph::getSize() const{
    return _size;
}

void Graph::setSize(Vector2 size){
    _size = size;
}

std::vector<Vector2> Graph::getNodes() const{
    return _nodes;
}

void Graph::setNodes(std::vector<Vector2> nodes){
    _nodes = nodes;
}

void Graph::addNode(Vector2 node)
{
    std::vector<Vector2>::iterator it = std::find(_nodes.begin(), _nodes.end(), node);
    if (it != _nodes.end())
    {
        return;
    }
    _nodes.push_back(node);
}

void Graph::removeNode(Vector2 node)
{
    std::vector<Vector2>::iterator it = std::find(_nodes.begin(), _nodes.end(), node);
    if (it != _nodes.end())
    {
        _nodes.erase(it);
    }
}

void Graph::printGraph() const
{
    int x  = _size.getX();
    int y = _size.getY();

    for(; y >= 0; y--)
    {
        std::cout << y << " ";
        for (int i = 0; i <= x; i++)
        {
            Vector2 node(i, y);
            std::vector<Vector2>::const_iterator it = std::find(_nodes.begin(), _nodes.end(), node);
            if (it != _nodes.end())
            {
                std::cout << "X";
            }
            else
            {
                std::cout << ".";
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "  ";
    for (int i = 0; i <= x; i++)
        std::cout << i << " ";
    std::cout << std::endl;
}


// Path: Vector2.cpp

