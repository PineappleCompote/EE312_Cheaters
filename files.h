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

/* Retrieve all sequences of size n from a string and store it
 * @param n number of words per sequences
 * @param in stream to the main body of text to retrieve from
 * @param &seq where sequences are to be stored
 */
int makeSequences (int n, ifstream& in, vector<string> &seq);

#endif //CHEATERS_FILES_H

