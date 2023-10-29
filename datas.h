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

#endif