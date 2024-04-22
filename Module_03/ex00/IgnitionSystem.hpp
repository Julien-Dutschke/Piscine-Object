#ifndef __IGNITIONSYSTEM_HPP__
#define __IGNITIONSYSTEM_HPP__

class IgnitionSystem
{
    private:
    bool _status;

    public:
    IgnitionSystem() : _status(false){}
    bool getStatus();
    void start();
    void stop();
};

#endif