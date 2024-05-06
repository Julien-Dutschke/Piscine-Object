#include "IgnitionSystem.hpp"

void IgnitionSystem::start()
{
    _status = true;
}

void IgnitionSystem::stop()
{
    _status = false;
}

bool IgnitionSystem::getStatus()
{
    return _status;
}

// Path: IgnitionSystem.hpp