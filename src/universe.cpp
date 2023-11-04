#include "universe.h"

Universe::Universe()
    : m_name("Default")
{
    m_nb_planet = countLines(m_f_name);
    loadPlanets();
}

Universe::Universe(std::string n)
    : m_name(n)
{
    m_nb_planet = countLines(m_f_name);
    loadPlanets();
    loadMapPlanets();
}

void Universe::displayUniverse() const
{
    std::cout << "Universe " << m_name << " has " << m_nb_planet 
        << " planets which are :" << std::endl; 
    for (int i = 0; i < m_nb_planet ; i++)
    {
        m_array_planets[i].displayPlanet();
    }
}

void Universe::displayUniverseMap() const
{
    std::cout << "Universe " << m_name << " has " << m_nb_planet 
        << " planets which are :" << std::endl; 
    for (const auto& n : m_map_planets)
    {
        std::cout << "Planet ID " << n.first << " : ";
        n.second.displayPlanet();
    }
        
}

void Universe::loadPlanets() {
    try {
        m_input_file.open(m_f_name);
        if (!m_input_file.is_open()) {
            throw std::runtime_error("Unable to open file.");
        }
        m_array_planets = new Planet[m_nb_planet];
        int i = 0;
        sp_coord coordinates;
        std::string line;

        while (std::getline(m_input_file, line)) {
            std::istringstream iss(line);
            std::string data;

            std::getline(iss, data, ',');
            m_array_planets[i].setName(data);

            std::getline(iss, data, ',');
            coordinates.x = std::stoi(data);
            std::getline(iss, data, ',');
            coordinates.y = std::stoi(data);
            std::getline(iss, data, ',');
            coordinates.z = std::stoi(data);
            m_array_planets[i].setCoordinates(coordinates);

            std::getline(iss, data);
            m_array_planets[i].setPlanetType(std::stoi(data));

            i++;
        }
        m_input_file.close();
        std::cout << "Planets successfully loaded" << std::endl;
        displayUniverse();
    } catch (const std::exception& e) {
        std::cout << "An error occurred: " << e.what() << std::endl;
        delete[] m_array_planets; // Clean up memory in case of an exception
        m_array_planets = nullptr;
    } catch (...) {
        std::cout << "An unknown error occurred" << std::endl;
        delete[] m_array_planets; // Clean up memory in case of an exception
        m_array_planets = nullptr;
    }
}

void Universe::loadMapPlanets()
{
    try
    {
        m_input_file.open(m_f_name);
        if (!m_input_file.is_open())
            throw std::runtime_error("Unable to open file to load map");
        
        int i = 0;
        sp_coord coordinates;
        std::string planet_name;
        int planet_type;
        std::string line;
        
        while (std::getline(m_input_file, line))
        {
            std::istringstream iss(line);
            std::string data;

            std::getline(iss, data, ',');
            planet_name = data;

            std::getline(iss, data, ',');
            coordinates.x = std::stoi(data);
            std::getline(iss, data, ',');
            coordinates.y = std::stoi(data);
            std::getline(iss, data, ',');
            coordinates.z = std::stoi(data);

            std::getline(iss, data, ',');
            planet_type = std::stoi(data);

            m_map_planets[i] = Planet(planet_name, coordinates, planet_type);
            i++;
        }
        m_input_file.close();
        std::cout << "Planets successfully loaded into the map" << std::endl;
        displayUniverseMap();
    } catch(const std::exception& e) {
        std::cout << "Error occured while loading file :" << e.what() << std::endl;
    } catch(...){
        std::cout << "Unknown error occured" << std::endl;
    }
}
