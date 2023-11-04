#ifndef ENGINE_H_
#define ENGINE_H_

#include "main.h"

class Engine
{
private :
    static long int s_nextId;
    long int m_id;
    double m_fuel_load;
    std::string m_name;

public :
    Engine();
    Engine(double f, std::string n);
    virtual ~Engine(){ std::cout << "Engine " << m_name << " with id " 
        << m_id << " has stopped working" << std::endl; };
    
    long int getId() { return m_id;}
    double getFuel() { return m_fuel_load; }
    std::string getName() { return m_name; }
    void setId(long int i) { m_id = i;}
    void setFuel(double f) { m_fuel_load = f;}
    void setName(std::string n) { m_name = n;}

    void displayEngine();

    static long int getNextId() {return s_nextId;}
};

#endif