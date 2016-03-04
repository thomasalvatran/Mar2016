#ifndef PARTS_H
#define PARTS_H
#pragma once

//---------------------------------------------------------------------------
struct CarPart
{
    long     PartNumber;
    char     PartName[40];
    double   UnitPrice;
    CarPart* Next;
};

//---------------------------------------------------------------------------
class ListOfParts
{
//////private:
    int size;

// List Builder
public:
    ListOfParts();
    int Count();
    CarPart* Head;

// List Operations

    int Add(CarPart* Item);
    CarPart *Retrieve(int pos);
    bool Delete();
};
//---------------------------------------------------------------------------
#endif // PARTS_H

