#include "functions.h"
#include <iostream>
#include <fstream>
#include <sstream>

sp_coord generateRandomCoordinates() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<long int> dist(-1000, 1000); 

    sp_coord randomCoords;
    randomCoords.x = dist(gen);
    randomCoords.y = dist(gen);
    randomCoords.z = dist(gen);

    return randomCoords;
}

std::map<std::string, sp_coord> createPlanets(std::map<std::string, sp_coord> planets)
{
    planets["Earth"] = generateRandomCoordinates();
    planets["Venus"] = generateRandomCoordinates();
    planets["Sun"] = generateRandomCoordinates();
    planets["Pluton"] = generateRandomCoordinates();
    return planets;
}

std::string formatCoordinates(const sp_coord &coord)
{
    std::string returning_string = "(" + std::to_string(coord.x) + "," + std::to_string(coord.y) +  "," + std::to_string(coord.z) + ")";
    return returning_string;
}

void displayPlanets(const std::map<std::string, sp_coord> &planets)
{
    // 1st option
    for (const auto& n : planets)
        std::cout << "Planet " << n.first << " located at " << formatCoordinates(n.second) << std::endl;
    // Other option => more custom
    for (auto it = planets.begin(); it != planets.end(); ++it) {
        const std::string& planetName = it->first;
        const sp_coord& planetCoordinates = it->second;
        std::cout << "Planet named " << planetName << " at coordinates " << formatCoordinates(planetCoordinates) << std::endl;
    }
}

int countLines(std::string fileName)
{
    std::ifstream inputFile;
    inputFile.open(fileName);
    int numberOfLines = 0;
    if (!inputFile.is_open()) {
        std::cout << "Unable to open file." << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(inputFile, line)) {
        numberOfLines++;
    }
    inputFile.close();
    return numberOfLines;
}