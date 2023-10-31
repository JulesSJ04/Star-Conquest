#include "engine.h"

long int Engine::s_nextId = 10000;

Engine::Engine()
{
    m_id = s_nextId;
    s_nextId++;
    m_fuel_load = std::rand();
    m_name = "Default";
}

Engine::Engine(double f, std::string n)
{
    m_id = s_nextId;
    s_nextId++;
    m_fuel_load = f;
    m_name = n;
}

void Engine::displayEngine()
{
    std::cout << "Engine : " << m_name << "\t" <<m_id << " with fuel load of " << m_fuel_load << std::endl;
}