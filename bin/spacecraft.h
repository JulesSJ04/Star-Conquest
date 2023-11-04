#ifndef SPACECRAFT_H
#define SPACECRAFT_H

#include "main.h"
#include "datas.h"

class Spacecraft
{
protected:
    sp_coord m_coordinates, m_goal;
    dim m_dimension;
    std::string m_name;
    Type m_type;

public :
    //Constructors
    Spacecraft();
    Spacecraft(sp_coord coord, dim di, std::string na);
    virtual ~Spacecraft(){
        std::cout << "Spacecraft named " << m_name << " has been destroyed" << std::endl; };

    //Getters and setters
    sp_coord getCoordinates() const { return m_coordinates;}
    void setCoordinates(sp_coord coordinates) { m_coordinates = coordinates;}
    const sp_coord getGoal() const { return m_goal; }
    void setGoal(const sp_coord goal) { m_goal = goal; }
    dim getDimension() const { return m_dimension; }
    void setDimension(dim dimension) { m_dimension = dimension; }
    std::string getName() const { return m_name; }
    void setName(const std::string name) { m_name = name; }

    //Methods
    void displaySpacecraft() const;
    virtual void display() const; //Polymorphism

    //Abstract method
    virtual void getDistanceTowardGoal() = 0;


};

#endif

