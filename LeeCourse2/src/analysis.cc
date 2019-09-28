// analysis.cc --- 
// 
// Filename: analysis.cc
// Description: 
// Author: Li Hui,李会
// Maintainer: 
// Created: 六 9月 28 16:46:30 2019 (+0800)
// Version: 
// Package-Requires: ()
// Last-Updated: 六 9月 28 17:35:58 2019 (+0800)
//           By: Li Hui,李会
//     Update #: 8
// URL: https://github.com/Hubery-Lee
// Doc URL: 
// Keywords: 
// Compatibility: 
// 

// Change Log:
// 

// Code:

#include "analysis.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

/////////////////////
analysis::analysis()
{}

analysis::~analysis()
{}

void analysis::Book()
{
  output.open("test.txt");
}

void analysis::Save()
{
  output.close();
}

void analysis::RecordValue(G4double a,G4String name)
{

  output<<name<<"\t"<<a<<endl;
}


// 
// analysis.cc ends here
