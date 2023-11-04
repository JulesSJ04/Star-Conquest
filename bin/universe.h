#ifndef UNIVERSE_H_
#define UNIVERSE_H_

#include "main.h"
#include "planet.h"

class Universe
{
private :
    // 1st option : array of planets
    Planet * m_array_planets = nullptr;
    // 2nd option : map of id and planeys
    std::map<int, Planet> m_map_planets;
    std::string m_name;
    int m_nb_planet;
    // File settings
    std::ifstream m_input_file;
    std::string m_f_name = "/home/jules/Documents/CPP/Star-Conquest/src/txt/planets.txt";

public :
    Universe();
    Universe(std::string n);
    ~Universe() {std::cout << "Universe has come to an end ..." << std::endl;
        delete[] m_array_planets; // Clean up memory in case of an exception
        m_array_planets = nullptr;
    }

    //Getters and setters
    Planet* getPlanets() const { return m_array_planets; }
    void setPlanets(Planet* planets) { m_array_planets = planets; }
    std::map<int, Planet> getPlanetMap() const { return m_map_planets; }
    std::string getName() const { return m_name; }
    void setName(const std::string& name) { m_name = name; }
    int getNumberOfPlanets() const { return m_nb_planet; }
    void setNumberOfPlanets(int num) { m_nb_planet = num; }

    //Methods
    void displayUniverse() const;
    void displayUniverseMap() const;
    void loadPlanets();
    void loadMapPlanets();

};

#endif