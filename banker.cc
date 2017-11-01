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

//  determines if the system is in a safe state
//  for allocating resources
bool IsSystemSafe();

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
  IsSystemSafe(); 
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


//  continually loops around until
//  it cannot find a process to 
//  allocate resources 
bool IsSystemSafe() {
  int work[NUMBER_OF_RESOURCES];

  for (int i = 0; i < NUMBER_OF_RESOURCES; ++i)
    work[i] = available[i];

  bool finish[NUMBER_OF_CUSTOMERS];
  for (int i = 0; i < NUMBER_OF_CUSTOMERS; ++i)
    finish[i] = false;
  
  bool workdone = true;
  while (workdone) {
    workdone = false;
    for (int i = 0; i < NUMBER_OF_CUSTOMERS; ++i) {
      bool enoughresources = true;
     
      for (int j = 0; j < NUMBER_OF_RESOURCES; ++i) {
        if (need[i][j] > work[j])
          enoughresources = false;
      }
      
      //  check if a process can be satisfied with 
      //  resources available to the system and 
      //  simulate assigning resources and freeing up
      //  allocated resources
      if (finish[i] == false && enoughresources) {
        for (int k = 0; k < NUMBER_OF_CUSTOMERS; ++k)
          work[k] += allocation[i][k];

        finish[i] = true;
        workdone = true;
      }
    }
  }

  bool IsSafe = true;
  for (int i = 0; i < NUMBER_OF_CUSTOMERS; ++i)
    if (finish[i] == false)
      IsSafe = false;

  return IsSafe;   
}

