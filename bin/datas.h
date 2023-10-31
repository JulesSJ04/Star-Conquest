#ifndef DATAS_H_
#define DATAS_H_

#define DEFAULT_DIM 1000.0

typedef struct Spatial_coordinates{
    long int x, y, z;
}sp_coord;

typedef struct Dimension{
    double width, length, height;
}dim;

enum Type {OVNI, SHUTTLE, ROCKET};

enum Planet_type 
{
    EARTH = 0,
    CARBON = 1,
    MESOPLANET = 2,
    ICE_GIANT = 3,
    GAS_GIANT = 4,
    HELIUM = 5,
    DEFAULT 
};

#endif