//  Don Vu
//  
//  This is a multithreaded program that implements
//  the banker's algorithm.

#include <iostream>
#include <fstream>
using namespace std;

#define NUMBER_OF_CUSTOMERS 5
#define NUMBER_OF_RESOURCES 4

//  the available amount of resources
int available[NUMBER_OF_RESOURCES];

//  the maximum demand for each customer
int maximum[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];

//  the amount currently allocated to each customer
int allocation[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];

//  the remaining need of each customer
int need[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];

//  threads request the resources
int RequestResources(int customernum, int request[]);

//  threads release the resources
int ReleaseResources(int customernum, int release[]);

void PrintTable(int table[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES]);

int main (int argc, char *argv[]) {
  if (argc != 6) {
    cerr << "Usage of the program is: " << argv[0] 
      << " resourcenum1 resourcenum2 resourcenum3" <<
      " resourcenum4 customerneedsfilename\n";

    return 1;
  }

  ifstream customerfile (argv[6]);

  if (!customerfile.is_open()) {
    cerr << "Error opening file\n";
    return 1;
  }

  //  fill the maximum array for each customer
  int fileinput;
  int rowcounter = 0;
  int inputcounter = 0; 
  while (customerfile >> fileinput) {
    if (inputcounter == 3) {
      ++rowcounter;
      inputcounter = 0;
    }
    
    maximum[rowcounter][inputcounter] = fileinput;
    ++inputcounter;
  }

  customerfile.close();
}

int RequestResources(int customernum, int request[]) {

  return 0;
}

int ReleaseResources(int customernum, int release[]) {

  return 0;
}

void PrintTable(int table[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES]) {

}
