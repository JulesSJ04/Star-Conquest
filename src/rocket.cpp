#include "datas.h"
#include "rocket.h"
#include "engine.h"
#include "math.h"


Rocket::Rocket(sp_coord coord, dim di, std::string na, int n, std::string r_na)
    :Spacecraft(coord, di, na), m_motor_number(n)
{
    for (unsigned int i=0;i<m_motor_number;i++)
    {
        m_engines.push_back(new Engine((double)std::rand(),r_na));
    }
}

Rocket::~Rocket()
{
    for (unsigned int i = 0; i < m_engines.size(); i++)
    {
        delete m_engines[i]; 
    }
    m_engines.clear();
}

void Rocket::displayRocket()
{
    Spacecraft::displaySpacecraft();
    std::cout << "Engine number : " << m_motor_number << std::endl;
    for (unsigned int i;i<m_engines.size();i++)
    {
        m_engines[i]->displayEngine();
    }
    std::cout << std::endl;
}

Rocket & Rocket::operator =(const Rocket & source)
{
    if (this!= &source){   // make sure we are not copying from itself

        //We assign every value from the source to the one assign the value to
        m_coordinates = source.getCoordinates();
        m_dimension = source.getDimension();
        for (unsigned int i=0;i<source.getMotorNumber();i++)
        {
            m_engines.push_back(new Engine((double)std::rand(),source.getMotorName()));
        }
        m_name = source.getName();
        m_motor_number = source.getMotorNumber();
        m_motor_name = source.getMotorName();
    }
    return *this; //We return the value
}

void Rocket::getDistanceTowardGoal()
{
    sp_coord current_location = getCoordinates();
    sp_coord goal = m_goal;
    long long int distance = (long long int)sqrt(
        pow((goal.x - current_location.x),2) + 
        pow((goal.y - current_location.y),2) +
        pow((goal.z - current_location.z),2)
        );
    std::cout << "Since we are currently located at ("
        << current_location.x << ","
        << current_location.y << ","
        << current_location.z << ")" << std::endl;
    std::cout << "and that we are going to ("
        << goal.x << ","
        << goal.y << ","
        << goal.z << ")" << std::endl;
    std::cout << "Current distance to objective is : " << distance << " kilometers" << std::endl; 
}
