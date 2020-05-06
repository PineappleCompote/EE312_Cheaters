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
#include "LinkedList.h"
#include "HashMap.h"

using namespace std;


int main(int argc, char* argv[])
{
////    string dir = argv[1];
////    int n = std::stoi(argv[2]);
//


////****************************************************************************////
//// Needed for testing on CLion, will change back for Linux testing
//    string dir = string("sm_doc_set");
//    int n = 6;
////***************************************************************************////

//    vector<string> files = vector<string>();
//
//    getDir(dir, files);
//
//	//TEST READING FILE NAMES
////    for (unsigned int i = 0;i < files.size();i++) {
////        cout << i << ":  " << files[i] << endl;
////    }
//
//    vector <vector <string> > seq;
//    for(int i = 0; i < 1; i++){//files.size(); i++){
//        vector<string> currSeq;
//        ifstream in;
//
//        in.open((dir +'/'+ files[i]));
////        in.open(files[i].c_str());
//
//        cout << "opening file: " << files[i] << endl;
//        if(!in.is_open())
//            cout << "Failed to open.\n";
//
//        makeSequences(n, in, currSeq);
//        seq.push_back(currSeq);
//        in.close();
//    }
//
//    //test first file
//    for(int i = 0; i < seq[0].size(); i++){
//        cout << seq[0][i] << endl;
//    }


////****************************************************************************////
// Testing Linked List and Hash Map
////***************************************************************************////

    int nums[16] = {0,1,2,3,4,5,6,7,8,9,9,9,8,7,5,3};
    LinkedList myList = LinkedList();
    for (int i = 0; i < 10; i++){
        myList.push(i);
    }
    myList.showList();
    cout << "Head: " << myList.getHead() << endl;
    cout << "Tail: " << myList.getTail() << endl;

    cout << "Testing Hash Map to see if its okay" << endl;

    HashMap myMap = HashMap(10);
    string str = "a";
    for (int i = 0; i < 16; i++){
        myMap.hash(nums[i], str);
        str += "a";
    }

    myMap.showMap();


    return 0;
}


