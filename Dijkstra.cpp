#include "Dijkstra.h"


using namespace std;

int minDistance(bool* visited, int* shortestDistance, int numberOfCities) {
    int min_distance = INT_MAX, min_index = -1;

    for (int city = 0; city < numberOfCities; city++) {
        if (!visited[city] && shortestDistance[city] <= min_distance) {
            min_distance = shortestDistance[city];
            min_index = city;
        
}
    
}

    return min_index;
}

void printPath(int endCityID, int* parent, City* cities) {
    if (parent[endCityID] == -1) {
        return; // don't print the last node
    
}

    printPath(parent[endCityID], parent, cities);

    if (parent[parent[endCityID]] != -1) { // don't print the first node
        cout << " " << cities[parent[endCityID]].name;
    
}
}

void dijkstra(int originCityID, int endCityID, int** adjacencyMatrix, int numberOfCities, bool type, City* cities) {
    int* shortestDistance = new int[numberOfCities]; // distance array
    bool* visited = new bool[numberOfCities]; // visited array
    int* parent = new int[numberOfCities]; // parent array

    for (int cityNumber = 0; cityNumber < numberOfCities; cityNumber++) {
        shortestDistance[cityNumber] = INT_MAX;
        visited[cityNumber] = false;
        parent[cityNumber] = -1;
    
}

    shortestDistance[originCityID] = 0;

    for (int i = 0; i < numberOfCities - 1; i++) {
        int currentCityID = minDistance(visited, shortestDistance, numberOfCities);

        visited[currentCityID] = true;

        for (int neighborCityID = 0; neighborCityID < numberOfCities; neighborCityID++) {
            if (!visited[neighborCityID] && adjacencyMatrix[currentCityID][neighborCityID] && shortestDistance[currentCityID] != INT_MAX && (shortestDistance[currentCityID] + adjacencyMatrix[currentCityID][neighborCityID]) < shortestDistance[neighborCityID]) {
                shortestDistance[neighborCityID] = shortestDistance[currentCityID] + adjacencyMatrix[currentCityID][neighborCityID];
                parent[neighborCityID] = currentCityID;
            
}
        
}
    
}

    if (!type)
    {
        cout << shortestDistance[endCityID] << endl;
    
}
    else {
        cout << shortestDistance[endCityID];
        printPath(endCityID, parent, cities);
        cout << endl;
    
}
    delete[] shortestDistance;
    delete[] visited;
    delete[] parent;
}
