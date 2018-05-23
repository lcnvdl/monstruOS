#include "common.h"
#include "process.h"

static int lastProcessID = 0;

Process::Process()
{
    id = ++lastProcessID;
}

int Process::getID() 
{
    return id;
}