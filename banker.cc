//  Don Vu
//  
//  This is a multithreaded program that implements
//  the banker's algorithm.

#include <iostream>
#include <fstream>
#include <string>
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

  //  populate the available resources from command line 
  available[0] = stoi(argv[1]);
  available[1] = stoi(argv[2]);
  available[2] = stoi(argv[3]);
  available[3] = stoi(argv[4]);

  ifstream customerfile (argv[5]);

  if (!customerfile.is_open()) {
    cerr << "Error opening file\n";
   
    return 1;
  }

  //  fill the maximum array for each customer
  int fileinput;
  int rowcounter = 0;
  int inputcounter = 0; 
  while (customerfile >> fileinput) {
    if (inputcounter == NUMBER_OF_RESOURCES) {
      ++rowcounter;
      inputcounter = 0;
    }

    maximum[rowcounter][inputcounter] = fileinput;
    ++inputcounter;
  }

  customerfile.close();
  PrintTable(maximum); 
}

int RequestResources(int customernum, int request[]) {

  return 0;
}

int ReleaseResources(int customernum, int release[]) {

  return 0;
}

void PrintTable(int table[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES]) {
  cout  << "Table is: \n"; 

  for (int i = 0; i < NUMBER_OF_CUSTOMERS; ++i) {
    for (int j = 0; j < NUMBER_OF_RESOURCES; ++j)
      cout << table[i][j] << " ";
    
    cout << endl; 
  }
}
