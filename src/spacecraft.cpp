#include "spacecraft.h"
#include "datas.h"

// Default constructor
Spacecraft::Spacecraft()
    :m_name("Spacecraft"), m_coordinates({0, 0, 0}), m_dimension({DEFAULT_DIM, DEFAULT_DIM, DEFAULT_DIM})
{
    m_goal = m_coordinates;
}

// Constructor
Spacecraft::Spacecraft(sp_coord coord, dim di, std::string na)
    : m_name(na), m_coordinates(coord), m_dimension(di)
{
    m_goal = m_coordinates;
}

void Spacecraft::displaySpacecraft() const
{
    /* Display informations about a spacecraft */
    std::cout << "Spacecraft : " << getName() << std::endl;
    sp_coord coordinates = getCoordinates(); 
    std::cout << "Coordinates: X: " << coordinates.x << ", Y: " 
        << coordinates.y << ", Z: " << coordinates.z << std::endl;
    std::cout << "Objectif: X: " << m_goal.x << ", Y: " 
        << m_goal.y << ", Z: " << m_goal.z << std::endl;
    dim dimension = getDimension();
    std::cout << "Dimension: Length: " << dimension.length << ", Width :" 
        << dimension.width << ", Height :" << dimension.height << std::endl;
}

void Spacecraft::display() const
{
    displaySpacecraft();
}
