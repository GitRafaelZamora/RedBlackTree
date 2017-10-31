#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#include "file.h"

using namespace std;

File::File(string filename, string IO) {
  if (IO == "in") {
    this->file.open(filename.c_str());
    if (this->file) {
        // cout << "Input File Open." << endl;
    } else {
      cout << "Error Opening File." << endl;
    }
  } else if (IO == "out") {
    this->file.open(filename.c_str(), fstream::out);
    if (this->file) {
        // cout << "Out File Open." << endl;
    } else {
      cout << "Error Opening out File." << endl;
    }
  }
}
// Goes through an open file's data line by line inorder to store data in an array.
//    Returns pointer to the array.
string File::getLine() {
  string str;
  if (this->file.eof()) { 
    return "END OF FILE!!"; 
  } else {
    getline(this->file, str);
  }
  
  return str;
}

bool File::end() {
  if (this->file.eof()) {
    return true;
  } else {
    return false;
  }
}

int File::getNumberOfNodes() {
  string length;
  if (this->file) {
        // Get the length of the File.
        length = getLine();
    }
  return stoi(length);
}

// Closes THIS instance file.
void File::close() {
  this->file.close();
  // cout << "File closed..." << endl;
}

// Print data takes an array and writes it out.
void File::printData(int n, double A[]) {
  for (int i = 0; i < n+4; i++) {
    cout << i << ":  " << A[i] << endl;
  }
  cout << endl;
}


void File::write(string inString) {
  this->file << inString;
}
