/*
 * parts.cpp
 *
 *  Created on: Jul 11, 2012
 *      Author: HP
 */

#include <iostream>
#include <string.h>
#include <stdio.h>

#include "parts.h"

using namespace std;

//---------------------------------------------------------------------------
int main() {
  ListOfParts *Parts = new ListOfParts; // class
  CarPart *Part; // struct

  // Visual C++ 6 can't "scope" a variable in a for loop
  int i;

  Part = new CarPart;
  Part->PartNumber = 9743;
  strcpy(Part->PartName, "Air Filter");
  Part->UnitPrice = 8.75;
  Parts->Add(Part);

  Part = new CarPart;
  Part->PartNumber = 27487;
  strcpy(Part->PartName, "Clutch Disk");
  Part->UnitPrice = 47.15;
  Parts->Add(Part);

  Part = new CarPart;
  Part->PartNumber = 87873;
  strcpy(Part->PartName, "Brake Disk");
  Part->UnitPrice = 35.15;
  Parts->Add(Part);

  Part = new CarPart;
  Part->PartNumber = 27644;
  strcpy(Part->PartName, "A/C Filter Drier");
  Part->UnitPrice = 55.55;
  Parts->Add(Part);

  cout << "Number of Parts: " << Parts->Count() << endl;

  cout << "\n-=- List of Parts -=-";
  for (i = 0; i < Parts->Count(); i++) {
    CarPart *One = Parts->Retrieve(i);

    cout << "\nCar Part Information";
    cout << "\nPart #:      " << One->PartNumber;
    cout << "\nDescription: " << One->PartName;
    cout << "\nUnit Price: $" << One->UnitPrice << endl;
  }

  Parts->Delete();

  cout << "\nNumber of Parts: " << Parts->Count() << endl;

  cout << "\n-=- List of Parts -=-";
  for (i = 0; i < Parts->Count(); i++) {
    CarPart *One = Parts->Retrieve(i);

    cout << "\nCar Part Information";
    cout << "\nPart #:      " << One->PartNumber;
    cout << "\nDescription: " << One->PartName;
    cout << "\nUnit Price: $" << One->UnitPrice << endl;
  }

  return 0;
}
//---------------------------------------------------------------------------
