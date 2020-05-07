/*
 * files.h
 * Created by Dilya Anvarbekova and Teddy Hsieh
 * Holds all the functions to open files and store them in a vector
 * Has functions to find all possible sequences of size n given by the user in each file
 */

#ifndef CHEATERS_FILES_H
#define CHEATERS_FILES_H

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "HashMap.h"

using namespace std;

/*
 * int getDir (string dir, vector<string> &files)
 * Gets the directory of the files needed to open and stores all the file names in a vector
 * Inputs:
 *      - path to the folder with the files
 *      - vector to store the file names
 * Outputs:
 *      - None unless there's an error
 */

int getDir (string dir, vector<string> &files);

/*
 * int hashIntoTable (int n, ifstream& in, int fileIdx, HashMap &myMap)
 * Retrieves all sequences from a file and hashes it into the hash map
 * Inputs:
 *      - n: size of the sequences
 *      - in: file stream
 *      - fileIdx: index of the file to store in the hash map
 *      - myMap: hash map to store the file indices in
 * Outputs:
 *      - file index hashed into the hash map using the sequences as the key
 */
int hashIntoTable (int n, ifstream& in, int fileIdx, HashMap &myMap, vector <vector <int> > &table);

/*
 * int countCollisions(int idx, vector <vector <int> > &table, HashMap &myMap)
 * Goes through the hash table and logs all collisions
 * Inputs:
 *      - idx: index of the hash table to check
 *      - table: 2D vector to store the collision counts
 *      - myMap: hash map to check
 * Outputs:
 *      - None, just updates the table of collisions
 */
int countCollisions(int idx, vector <vector <int> > &table, HashMap &myMap);


/*
 * void sortList(vector< pair< int, pair<int, int> > > &collisions)
 * Sorts the list of collisions in descending order using selection sort
 * Inputs:
 *      - collisions: vector of all collisions
 * Outputs:
 *      - None, just sorts it in place
 */
void sortList(vector< pair< int, pair<int, int> > > &collisions);

#endif //CHEATERS_FILES_H

