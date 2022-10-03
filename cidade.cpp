#ifndef CIDADE_CPP
#define CIDADE_CPP
typedef float latitude;
typedef float longitude;

struct cidade {
    unsigned int id;
    char *estado;
    char *cidade;
};

struct gps {
    unsigned int id;
    latitude la;
    longitude lo;
};

struct dataItem {
    int key;
    cidade city;
    gps GPS;
};
#endif