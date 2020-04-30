#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int getdir (string dir, vector<string> &files)
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

/* Retrieve all sequences of size n from a string and store it
 * @param n number of words per sequences
 * @param in stream to the main body of text to retrieve from
 * @param &seq where sequences are to be stored
 */
int makeSequences (int n, ifstream& in, vector<string> &seq)
{
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
		//cout << w << endl;
		seq.push_back(w);
		//cout << "PUSHED\n";
	}
	
}


int main(int argc, char* argv[])
{
    string dir = argv[1];
	int n = std::stoi(argv[2]);
    vector<string> files = vector<string>();

    getdir(dir, files);

/*	//TEST READING FILE NAMES
    for (unsigned int i = 0;i < files.size();i++) {
        cout << i << ":  " << files[i] << endl;
    }
*/
	vector<vector<string>> seq = vector<vector<string>>();
	for(int i = 0; i < 1; i++){//files.size(); i++){
		vector<string> currSeq  = vector<string>();
		ifstream in;

		in.open(dir+files[i]);
		if(!in.is_open())
			cout << "Failed to open.\n";

		makeSequences(n, in, currSeq);
		seq.push_back(currSeq);
		in.close();
	}

	//test first file
	for(int i = 0; i < seq[0].size(); i++)
	{
		cout << seq[0][i] << endl;
 	}

	return 0;
}


