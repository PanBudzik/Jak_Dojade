#include "City.h"

int findCityIDByName(City* cities, int numCities, const myString& cityName)
{
    for (int i = 0; i < numCities; i++)
    {
        if (cities[i].name == cityName)
        {
            return i;
        
}
    
}
    return -1;
