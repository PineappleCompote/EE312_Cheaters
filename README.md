EE312_Cheaters
Created by Dilya Anvarbekova and Teddy Hsieh

GitHub repo is at 
https://github.com/PineappleCompote/EE312_Cheaters 

To compile the files:
	1. Go to the directory with all the files
	2. Make sure the makefile is there
	3. Run the command "make"

To run the code:
Run the command ./plagiarismCatcher path/to/text/files 1 2
	- "path/to/text/files" is the directory where the files to check are stored
		- if the document set is in this directory, ./doc_set_name works
		- otherwise the full path should work
	- 1 is the length of the sequence to check (e.g. to check every 6 word sequence use 6)
	- 2 is the cutoff threshold for plagiarism in terms of collisions
