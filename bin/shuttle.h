#include "main.h"
#include "spacecraft.h"

class Engine;

class Shuttle : public Spacecraft
{
private :


public : 
    Shuttle(sp_coord coord, dim di, std::string na);
    virtual ~Shuttle();
};