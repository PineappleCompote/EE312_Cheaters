/* files.cpp
 * Defines functions used in main.cpp to open and read files and make sequences
 * Created by Dilya Anvarbekova and Teddy Hsieh
 * Last Modified: 05/06/2020
 */

#include "files.h"
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "HashMap.h"

int getDir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    int i = 0;
    while ((dirp = readdir(dp)) != NULL) {
        i++;
        if(i > 2){
            //if(name.compare(".") != 0 && name.compare("..")
            string name = string(dirp->d_name);
            files.push_back(name);
        }
    }

    closedir(dp);
    return 0;
}

int hashIntoTable(int n, ifstream& in, int fileIdx, HashMap &myMap, vector <vector <int> > &table){
    // s is one word
    vector<string> words = vector<string>();
    string s;
    string str;
    int count = 0;
    while(in){
        in >> s;
        if (count < n){
            words.push_back(s);
            count += 1;
        }
        else{
            str = "";
            for (int i = 0; i < n; i++){
                str += words[i] + " ";
            }
            myMap.hash(fileIdx, str);
            words.erase(words.begin());
            words.push_back(s);
        }
    }
}

int countCollisions(int idx, vector< vector <int> > &table, HashMap &myMap){
    LinkedList myList = myMap.getList(idx);
    if(myList.getSize() > 1){
        Node* prev = myList.getHead();
        Node* curr;
        while(prev != myList.getTail()){
            curr = prev->next;
            while(curr != NULL){
                table[prev->data][curr->data] += 1;
                curr = curr->next;
            }
            prev = prev->next;
        }
    }
}

void sortList(vector< pair< int, pair<int, int> > > &collisions){
    int maxIdx;
    for( int i = 0; i < collisions.size()-1; i++){
        maxIdx = i;
        for( int j = i + 1; j < collisions.size(); j++){
            if(collisions[j].first > collisions[maxIdx].first){
                maxIdx = j;
            }
        }
        swap(collisions[maxIdx], collisions[i]);
    }
}

