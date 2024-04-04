

#ifndef __WORKER_HPP__
#define __WORKER_HPP__

#include <iostream>
#include "../Tool/Tool.hpp"
#include <vector>
#include <algorithm>

class Workshop;

struct Position
{
    Position() : x(0), y(0) {}
    Position(int x, int y) : x(x), y(y) {}
    int x;
    int y;
};

struct Statistic
{
    int level;
    int exp;

    Statistic() : level(1), exp(0) {}
    Statistic(int level, int exp) : level(level), exp(exp){}
};



class Worker {
public:
    // Constructeurs
    Worker();
    Worker(int x, int y, int level, int exp);
    // Destructeur
    ~Worker();
    
    // Méthodes
    int getX(){ return position.x;}
    int getY(){ return position.y;}
    int getLevel(){ return statistic.level;}
    int getExp(){ return statistic.exp;}
    void setX(int x){ position.x = x;}
    void setY(int y){ position.y = y;}
    void setLevel(int level){ statistic.level = level;}
    void setExp(int exp){ statistic.exp = exp;}
    void work();
    void addTool(Tool* tool);
    void addWorkshop(Workshop* workshop);
    void removeTool();
    void removeWorkshop(Workshop* workshop);

    

private:
    struct Position position;
    struct Statistic statistic;
    Tool* tool;
    std::vector<Workshop*> workshops;
};

#endif 