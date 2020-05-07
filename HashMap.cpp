/* HashMap.cpp
 * Defines methods of the HashMap class
 * Created by Dilya Anvarbekova and Teddy Hsieh
 * Date Last Modified: 05/06/2020
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

int HashMap::hash(int fileIdx, string phrase) {
    int idx = hashFunction(phrase) % mapSize;
    if (table[idx].isEmpty() || ((table[idx].getHead()->data) != fileIdx)){
        table[idx].push(fileIdx);
    }
    return idx;
}

int HashMap::hashFunction(string phrase) {
    int hashVal = 0;
    int pow = 1;
    int c;
    for(char i : phrase){
        if(isalnum(i)){
            c = toupper(i);
            hashVal = (hashVal + (c - int('0') + 1) * pow) % BOUNDS;
            pow = (pow * MULT) % BOUNDS;
        }
    }
    return hashVal;
}

LinkedList HashMap::getList(int idx){
    return table[idx];
}

void HashMap::showMap() {
    for(int i = 0; i < mapSize; i++){
        cout << "At index " << i << " we have these values:" << endl;
        table[i].showList();
    }
}

HashMap::~HashMap() {
    delete [] table;
}