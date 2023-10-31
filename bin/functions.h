#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <map>
#include "datas.h"
#include <random>

sp_coord generateRandomCoordinates();
std::map<std::string, sp_coord> createPlanets(std::map<std::string, sp_coord> planets);
std::string formatCoordinates(const sp_coord &coord);
void displayPlanets(const std::map<std::string, sp_coord> &planets);

#endif