#include "planet.h"

int Planet::s_id = 0;

Planet::Planet()
    :m_name("Planet"), m_coordinates({0, 0, 0}), m_planet_type(DEFAULT)
{
    s_id ++;
}


Planet::Planet(std::string n, sp_coord c, int t)
    :m_name(n), m_coordinates(c)
{
    s_id ++;
    setPlanetType(t);
}


std::string Planet::getPlanetType() const
{
    switch (m_planet_type)
    {
    case 0 :
        return "EARTH";
        break;
    case 1 :
        return "CARBON";
        break;
    case 2 :
        return "TELLURIQUE";
        break;
    case 3 :
        return "ICE GIANT";
        break;
    case 4 :
        return "GAS GIANT";
        break;
    case 5 :
        return "HELIUM";
        break;
    default:
        return "Unknown";
        break;
    }
}


void Planet::displayPlanet() const
{
    std::cout << "Planet " << m_name << " at " << formatCoordinates(m_coordinates)
        << " of the type " << getPlanetType() << std::endl;
}

