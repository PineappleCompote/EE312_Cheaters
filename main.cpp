/* main.cpp
 * Driver for the Cheaters program
 * Created by Dilya Anvarbekova and Teddy Hsieh
 * Date Last Modified: 05/06/2020
 */

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "files.h"
#include <utility>
#include "LinkedList.h"
#include "HashMap.h"
#include<bits/stdc++.h>


using namespace std;


int main(int argc, char* argv[])
{
//********************************************************************************
// To use on Linux servers
//
//    string dir = argv[1];
//    int n = std::stoi(argv[2]);
//    int threshold = std::stoi(argv[3]);
//********************************************************************************


//****************************************************************************////
// Needed for testing on CLion, will change back for Linux testing
    string dir = string("big_doc_set");
    int n = 6;
    int threshold = 200;
//***************************************************************************////

    vector<string> files = vector<string>();

    getDir(dir, files);
    int max = files.size();

    vector <vector <int> > collisionTable(max, vector <int> (max, 0));

    HashMap myMap = HashMap(1153199);

    for(int i = 0; i < max; i++){
        ifstream in;

        in.open((dir +'/'+ files[i]));

        if(!in.is_open())
            cout << "Failed to open.\n";

        hashIntoTable(n, in, i, myMap, collisionTable);

        in.close();
    }

    for (int i = 0; i < 1153199; i++){
        countCollisions(i, collisionTable, myMap);
    }

    vector<vector<int> > allCollisions;
    vector< pair< int, pair<int, int> > > collisions;

    for(int i = 1; i < max; i++){
        for(int j = 0; j < i; j++){
            collisions.emplace_back(collisionTable[i][j], make_pair(j, i));
        }
    }

    sort(collisions.begin(), collisions.end(), greater<>());

    int i = 0;
    while(collisions[i].first > threshold){
        cout << collisions[i].first << ": " << files[collisions[i].second.first] << ", " << files[collisions[i].second.second] << endl;
        i++;
    }

//TODO: Fix the hash table size - find a good way to decide on the size
//TODO: Get command line arguments and check if it works on Linux
//TODO: write the makefile

    return 0;
}


