#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"

bool readFromFile(std::string& inFilename);

LinkedList myList;

int main(int argc, char* argv[]) {

  // grab command line argument for filename
  std::string execName = argv[0];
  std::string inFilename;
  std::string outFilename;

  if (argc == 3) {
    inFilename = argv[1];
    outFilename = argv[2];
  }
  else
    std::cout << "Syntax error, input and output file names required\n";

  // read numbers from filename provided
  if (readFromFile(inFilename)) {
    myList.sort();
    myList.printToFile(outFilename);
  }
  else
    std::cout << "Couldn't open file for reading\n";
}

/*
 * Reads all the text from the specified input file names
 * returns true if successful
 */
bool readFromFile(std::string& inFilename) {
  std::ifstream numFile(inFilename);
  if(numFile.is_open()) {
    std::string line;
    while(getline(numFile, line)) {
      myList.add(std::stoi(line));
    }
    numFile.close();
    return true;
  }
  else
    return false;
}
