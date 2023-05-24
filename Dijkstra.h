#pragma once
#include "City.h"
#include "myString.h"
#include <iostream>
#include <climits>

int minDistance(bool* visited, int* shortestDistance, int numberOfCities);
void printPath(int endCityID, int* parent, City* cities);
void dijkstra(int originCityID, int endCityID, int** adjacencyMatrix, int numberOfCities, bool type, City* cities);
