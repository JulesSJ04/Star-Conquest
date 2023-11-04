/*
Entrainement au C++ => deux niveaux de classe : Spacecraft => Shuttle / Rocket
*/

#include "main.h"
#include "spacecraft.h"
#include "rocket.h"
#include "universe.h"

int main()
{
    sp_coord coordinates;
    coordinates.x = 58000;
    coordinates.y = 99988;
    coordinates.z = -52000;
    dim dimension;
    dimension.height = 100.45;
    dimension.width = 25.89;
    dimension.length = 56.8;
    
    // Classe declaration
    Rocket my_ship = Rocket(coordinates, dimension, "A345", 10, "RAPTOR");
    my_ship.displayRocket();
    coordinates.x += 5841; coordinates.y -=33333; coordinates.z = 0; 
    my_ship.setGoal(coordinates);
    my_ship.getDistanceTowardGoal();
    
    // Overloading operator
    /*
    Rocket my_second_ship = my_ship;
    my_second_ship.setName("BlackJet");
    my_second_ship.displayRocket();*/
    
    /* Map de coordonnées de planète */
    /*
    std::map<std::string, sp_coord> planets;
    planets = createPlanets(planets);
    displayPlanets(planets);
    */
   Universe universe = Universe("Galaxia");
    
    /* Abstract class
    my_ship.display();
    Spacecraft my_space = Spacecraft();
    my_space.display();
    */
    return 0;
}