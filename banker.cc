//  Don Vu
//  
//  This is a multithreaded program that implements
//  the banker's algorithm.

#include <iostream>
using namespace std;

#define NUMBER_OF_CUSTOMERS 5
#define NUMBER_OF_RESOURCES 3

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

int main (int argc, char *argv[]) {
  if (argc != 4) {
    cerr << "Usage of the program is: " << argv[0] 
      << " resourcenum1 resourcenum2 resourcenum3\n";
  }
}

int RequestResources(int customernum, int request[]) {

  return 0;
}

int ReleaseResources(int customernum, int release[]) {

  return 0;
}
