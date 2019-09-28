// analysis.hh --- 
// 
// Filename: analysis.hh
// Description: 
// Author: Li Hui,李会
// Maintainer: 
// Created: 六 9月 28 11:30:39 2019 (+0800)
// Version: 
// Package-Requires: ()
// Last-Updated: 六 9月 28 18:03:13 2019 (+0800)
//           By: Li Hui,李会
//     Update #: 14
// URL: https://github.com/Hubery-Lee
// Doc URL: 
// Keywords: 
// Compatibility: 
// 

// Change Log:
// 
// reference: examples/extend/analyse
// Code:
#ifndef analysis_h
#define analysis_h 1

#include "globals.hh"
#include "fstream"
#include "iostream"

using namespace std;

class analysis
{

public:
  analysis();
  ~analysis();

  void Book();
  void Save();

  void RecordValue(G4double a,G4String name);

private:
  ofstream output;
};

#endif

// 
// analysis.hh ends here
