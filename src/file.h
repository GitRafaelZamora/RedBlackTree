#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

class File {
private:
	fstream file;

public:
	File(string filename, string IO);
	void openFile(string filename);
	int getNumberOfNodes();
	void printData(int n, double A[]);
	void write(string inString);
	string getLine();
	void close();
	bool end();
};

#endif