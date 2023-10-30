#ifndef PLANET_H_
#define PLANET_H_

#include "main.h"

class Planet
{
private:
    static int m_id;
    std::string m_name;
    sp_coord m_coordinates;
    Planet_type m_planet_type;
public:
    Planet();
    Planet(std::string n, sp_coord c, Planet_type t);
    ~Planet() {std::cout << "Planet with ID " + std::to_string(m_id) + " disapeared" << std::endl;}

    //Getters and setters
    std::string getName() const {return m_name;}
    sp_coord getCoordinates() const {return m_coordinates;}
    std::string getPlanetType() const;
    void setName(const std::string &n) {m_name=n;}
    void setCoordinates(const sp_coord &c) {m_coordinates=c;}
    void setPlanetType(const Planet_type &p) {m_planet_type=p;}

    //Methods
    void displayPlanet() const;
};


#endif