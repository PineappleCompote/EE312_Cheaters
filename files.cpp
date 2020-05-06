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

int makeSequences (int n, ifstream& in, vector<string> &seq){
    vector<string> words = vector<string>();
    string s;
    while(in){
        in >> s;
        words.push_back(s);
    }

    for(int i = 0; i < words.size() - n; i++){
        string w;
        for(int j = i; j < i + n; j++){
            w += words[j] + " ";
        }
        seq.push_back(w);
    }

}