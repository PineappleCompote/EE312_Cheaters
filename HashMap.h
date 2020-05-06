/* HashMap.h
 * Header file for the HashMap class
 * Created by Dilya Anvarbekova and Teddy Hsieh
 * Last Modified: 05/06/2020
 */

#ifndef CHEATERS_HASHMAP_H
#define CHEATERS_HASHMAP_H

#include <iostream>
#include <string>
#include <vector>
#include "LinkedList.h"

using namespace std;

class HashMap {

private:
    static const int MAX_SIZE = 1000000;
    static const int NOT_FOUND = -1;

    LinkedList *table;
    int mapSize;

public:
    HashMap();

    HashMap(int size);

//    int find(int fileIdx, string phrase);


/* Hash function used to obtain the index to hash the value at
 * Inputs:
 *      - a string to be hashed
 * Outputs:
 *      - index to hash the phrase to
 */
    int hashFunction(string phrase);


/* Entering a value into the hash table
 * Inputs:
 *      - Index of the file from which the phrase is taken
 *      - Phrase to be hashed
 * Outputs:
 *      - None
 *      - The index of the file is hashed into the table if it wasn't hashed to the same place before
 */
    void hash(int fileIdx, string phrase);


/* Shows the hash map and which values are stored at each table index
 * FOR DEBUGGING
 */
    void showMap();


/* Destructor
 */
    ~HashMap();

};


#endif //CHEATERS_HASHMAP_H
