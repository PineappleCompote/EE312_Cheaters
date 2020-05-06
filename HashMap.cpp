/* HashMap.cpp
 * Defines methods of the HashMap class
 * Created by Dilya Anvarbekova and Teddy Hsieh
 * Date Last Modfied: 05/06/2020
 */

#include "HashMap.h"
#include <iostream>
#include <string>
#include <vector>
#include "LinkedList.h"

using namespace std;

HashMap::HashMap() {
    mapSize = MAX_SIZE;
    table = new LinkedList[mapSize];
}

HashMap::HashMap(int size) {
    mapSize = size;
    table = new LinkedList[mapSize];
}

void HashMap::hash(int fileIdx, string phrase) {
    int idx = hashFunction(phrase) % mapSize;
    if (table[idx].isEmpty() || (table[idx].getHead() != fileIdx)){
        table[idx].push(fileIdx);
    }
}

int HashMap::hashFunction(string phrase) {
    return phrase.length();
}

void HashMap::showMap() {
    for(int i = 0; i < mapSize; i++){
        cout << "At index " << i << " we have these values:" << endl;
        table[i].showList();
    }
}

HashMap::~HashMap() {
}