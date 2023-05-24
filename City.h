#pragma once
#include "myString.h"

struct City
{
    myString name;
    int positionX;
    int positionY;
};

int findCityIDByName(City* cities, int numCities, const myString& cityName);
