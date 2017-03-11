#include <iostream>
#include <fstream>
#include <string>
//#include <random>
#include "LinkedList.h"

int main(int argc, char* argv[]) {
  // std::random_device rd; // device for seeding generator
  // std::mt19937 rng(rd()); // seed random gen with device
  // std::uniform_int_distribution<int> dist(0, 100000); // create distribution

  // grab command line argument for filename
  std::string execName = argv[0];
  std::string filename;
  if (argc > 1)
    filename = argv[1];
  else
    std::cout << "Syntax error, file name required\n";

  // read numbers from filename provided
  std::ifstream numFile(filename);
  if(numFile.is_open()) {
    LinkedList myList;
    std::string line;
    while(getline(numFile, line)) {
      myList.add(std::stoi(line));
    }
    numFile.close();

    myList.sort();          // calls embedded insertion sort
    // myList.printForward();  // print sorted
    myList.printToFile();

  }
  else
    std::cout << "Couldn't open file for reading\n";
  // for(int i=0; i < 1500000; i++)
    //myList.add(dist(rng));      // populate list with random values

  //myList.printForward();  // print unsorted
}
