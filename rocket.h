#ifndef ROCKET_H_
#define ROCKET_H_

#include "main.h"
#include "datas.h"
#include "spacecraft.h"

class Engine;

class Rocket : public Spacecraft
{
private :
    int m_motor_number;
    std::string m_motor_name;
    std::vector<Engine*> m_engines;

public : 
    Rocket(sp_coord coord, dim di, std::string na, int n, std::string r_na);
    virtual ~Rocket();

    int getMotorNumber() const { return m_motor_number; }
    void setMotorNumber(int number) { m_motor_number = number; }
    const std::string& getMotorName() const { return m_motor_name; }
    void setMotorName(const std::string& name) { m_motor_name = name; }
    const std::vector<Engine*>& getEngines() const { return m_engines; }

    //Overloading operator
    Rocket & operator = (const Rocket & source);

    void displayRocket();
    void display() const override {std::cout << "Rocket" << std::endl;}
    
    // Abstract method
    void getDistanceTowardGoal() override;
};

#endif

