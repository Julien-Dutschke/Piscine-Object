#include "Graph.hpp"


int main(){
    Graph graph(Vector2(10, 10));
    graph.addNode(Vector2(0, 0));
    graph.addNode(Vector2(1, 1));
    graph.addNode(Vector2(2, 2));
    graph.addNode(Vector2(3, 3));
    graph.addNode(Vector2(4, 4));
    graph.addNode(Vector2(5, 5));
    graph.addNode(Vector2(6, 6));
    graph.addNode(Vector2(7, 7));
    graph.addNode(Vector2(8, 8));
    graph.addNode(Vector2(9, 9));
    graph.addNode(Vector2(10, 10));
    graph.printGraph();
    return 0;
}