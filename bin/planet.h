#ifndef PLANET_H_
#define PLANET_H_

#include "main.h"

class Planet
{
private:
    static int s_id;
    std::string m_name;
    sp_coord m_coordinates;
    Planet_type m_planet_type;
public:
    Planet();
    Planet(std::string n, sp_coord c, int t);
    ~Planet() {std::cout << "Planet with ID " << s_id << " disapeared" << std::endl;}

    //Getters and setters
    std::string getName() const {return m_name;}
    sp_coord getCoordinates() const {return m_coordinates;}
    std::string getPlanetType() const;
    void setName(const std::string &n) {m_name=n;}
    void setCoordinates(const sp_coord &c) {m_coordinates=c;}
    void setPlanetType(const Planet_type &p) {m_planet_type=p;}
    void setPlanetType(int value) {
        if (value >= EARTH && value <= HELIUM) {
            m_planet_type = static_cast<Planet_type>(value);
        } else {
            std::cout << "Invalid value for planet type." << std::endl;
        }
    }

    //Methods
    void displayPlanet() const;
};


#endif