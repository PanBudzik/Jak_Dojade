#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include "myString.h"
#include "Queue.h"
#include "Dijkstra.h"
#include "City.h"

int readMapFromInput(int height, int width, char **map) {
    char symbol;
    int numberOfCities = 0;
    for (int col = 0; col < height; col++) {
        getchar();
        for (int row = 0; row < width; row++) {
            symbol = getchar();
            if (symbol == '*') numberOfCities++;
            map[col][row] = symbol;
        
}
        map[col][width] = '\0';
    
}
    return numberOfCities;
}

myString extratCityName(int positionOfStarY, int positionOfStarX, int height, int width, char** map) {
    myString cityName = "";
    myString cityNameLeft = "";
    myString cityNameRight = "";
    for (int i = positionOfStarY - 1; i <= positionOfStarY+1; i++) {
        for (int j = positionOfStarX - 1; j <= positionOfStarX + 1; j++) {

            if (i >= 0 && j >= 0 && i <= height && j <= width)
            {
                if (isalpha(map[i][j])||isdigit(map[i][j])) {
                    int iterator = j;
                    
                     cityNameRight = cityNameRight + map[i][iterator];
                    //name goes to right
                    if (j + 1 <= width)
                    {
                        if (isalpha(map[i][j + 1]) || isdigit(map[i][j+1])) {
                            iterator++;
                            while (isalpha(map[i][iterator]) || isdigit(map[i][iterator])) {
                                cityNameRight = cityNameRight + map[i][iterator];
                                iterator++;
                                if (iterator == width) break;
                            
}
                        
}
                    
} 
                    
                    iterator = j;
                    //name goes to left
                    if (j - 1 >= 0)
                    {
                        if (isalpha(map[i][j - 1]) || isdigit(map[i][j - 1])) {
                            while (isalpha(map[i][iterator - 1]) || isdigit(map[i][iterator - 1])) {
                                iterator--;
                                if (iterator == 0) break;
                            
}
                            for (iterator; iterator < j; iterator++)
                            {
                                cityNameLeft = cityNameLeft + map[i][iterator];
                            
}
                        
}
                    
}
                    cityName = cityNameLeft + cityNameRight;
                    return cityName;
                
}
            
}
        
}
    
}
    return cityName;
}



void extractConnectionsFromCity(int positionOfStarY, int positionOfStarX, int height, int width, char** map, int** adjacencyMatrix, int numberOfCities, City* cities, int originCityID) {
    
    int directionsColumn[4] = { 0, 0, 1, -1 
};
    int directionsRow[4] = {-1, 1, 0, 0
};
    
    int newY = 0;
    int newX = 0;

    Queue* rowQueue = new Queue(numberOfCities);
    Queue* columnQueue = new Queue(numberOfCities);


    int distance = 0;
    int nodesLeftInLayer = 1;
    int nodesInNextLayer = 0;

    bool** visitedMatrix = new bool* [height];
    for (int i = 0; i < height; ++i) {
        visitedMatrix[i] = new bool[width];
        memset(visitedMatrix[i], false, sizeof(bool) * width);
    
}

    rowQueue->push(positionOfStarX);
    columnQueue->push(positionOfStarY);
    visitedMatrix[positionOfStarY][positionOfStarX] = true;
    
    while (!(rowQueue->isEmpty())) {
        int x = rowQueue->pop();
        int y = columnQueue->pop();

        for (int i = 0; i < 4; i++) {
            newX = x + directionsRow[i];
            newY = y + directionsColumn[i];

            if (newX >= 0 && newY >= 0 && newX < width && newY < height)
            {
                if (!visitedMatrix[newY][newX] && map[newY][newX] == '*') {
                    myString endCityName = extratCityName(newY, newX, height, width, map);
                    int endCityID = findCityIDByName(cities,numberOfCities,endCityName);
                    adjacencyMatrix[originCityID][endCityID]=distance+1;
                    visitedMatrix[newY][newX] = true;
                
}
                if (!visitedMatrix[newY][newX] && map[newY][newX]=='#')
                {
                    rowQueue->push(newX);
                    columnQueue->push(newY);
                    visitedMatrix[newY][newX] = true;
                    nodesInNextLayer++;
                
}
            
}
        
}
        nodesLeftInLayer--;
        if (nodesLeftInLayer == 0) {
            nodesLeftInLayer = nodesInNextLayer;
            nodesInNextLayer = 0;
            distance++;
        
}
    
}

    for (int i = 0; i < height; ++i) {
        delete[] visitedMatrix[i];
    
}

    delete[] visitedMatrix;
}

void extractCity(int height, int width, char** map, int** adjacencyMatrix, City* cities, int numberOfCities) {

    char symbol = '.';
    int cityID = 0;
    myString cityName = "";

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            symbol = map[i][j];
            if (symbol == '*')
            {
               cities[cityID].name = extratCityName(i, j, height, width, map);
               cityID++;
            
}
        
}
    
}
    cityID = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            symbol = map[i][j];
            if (symbol == '*')
            {
                extractConnectionsFromCity(i, j, height, width, map, adjacencyMatrix, numberOfCities, cities, cityID);
                cityID++;
            
}
        
}
    
}
}

void printadjacencyMatrix(int** adjacencyMatrix, int numberOfCities) {
    for (int i = 0; i < numberOfCities; ++i) {
        for (int j = 0; j < numberOfCities; ++j) {
            cout << adjacencyMatrix[i][j] << " ";
        
}
        cout << endl;
    
}
}

void addPlane(int originCityID, int endCityID, int distance, int** adjacencyMatrix) {
    if (adjacencyMatrix[originCityID][endCityID]>distance || adjacencyMatrix[originCityID][endCityID] == 0) {
        adjacencyMatrix[originCityID][endCityID] = distance;
    
}
}

int main()
{
    int h=20, w=20 ; //width and height
    int k; //air connections
    int q; //queues numer

    cin >> w >> h;

    char** map = new char* [h];
    for (int i = 0; i < h; i++) {
        map[i] = new char[w];
        memset(map[i], '.', w);
    
}

    int numberOfCities = readMapFromInput(h, w, map);

    City* cities = new City[numberOfCities];

    int** adjacencyMatrix = new int* [numberOfCities];
    for (int i = 0; i < numberOfCities; ++i) {
        adjacencyMatrix[i] = new int[numberOfCities];
        memset(adjacencyMatrix[i], 0, sizeof(int) * numberOfCities);
    
}
    
    extractCity(h,w,map,adjacencyMatrix,cities,numberOfCities);

    cin >> k;

    for (int i = 0; i < k; i++)
    {
        myString originCity, endCity;
        int distance;
        cin >> originCity >> endCity >> distance;

        int originCityID = findCityIDByName(cities, numberOfCities, originCity);
        int endCityID = findCityIDByName(cities, numberOfCities, endCity);
        addPlane(originCityID, endCityID, distance, adjacencyMatrix);
    
}
    //cout << numberOfCities;
    //printadjacencyMatrix(adjacencyMatrix, numberOfCities);

    cin >> q;

    for (int i = 0; i < q; i++)
    {
        myString originCity, endCity;
        bool type;
        cin >> originCity >> endCity >> type;
        
        int originCityID = findCityIDByName(cities, numberOfCities, originCity);
        int endCityID = findCityIDByName(cities, numberOfCities, endCity);
        dijkstra(originCityID, endCityID, adjacencyMatrix, numberOfCities, type, cities);
    
}
    
    for (int i = 0; i < h; i++) {
        delete[] map[i];
    
}
    delete[] map;
    
    return 0;
}
