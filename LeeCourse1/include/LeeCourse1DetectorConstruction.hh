// LeeCourse1DetectorConstruction.hh --- 
// 
// Filename: LeeCourse1DetectorConstruction.hh
// Description: 
// Author: Li Hui,李会
// Maintainer: 
// Created: 一 9月 16 22:05:12 2019 (+0800)
// Version: 
// Package-Requires: ()
// Last-Updated: 一 9月 16 22:25:32 2019 (+0800)
//           By: Li Hui,李会
//     Update #: 2
// URL: https://github.com/Hubery-Lee
// Doc URL: 
// Keywords: 
// Compatibility: 
// 

// Change Log:
// 

// Code:
#ifndef LeeCourse1DetectorConstruction_h
#define LeeCourse1DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;

/////////////////////////////////////////////
class LeeCourse1DetectorConstruction : public G4VUserDetectorConstruction
{
public:
  LeeCourse1DetectorConstruction();
  virtual ~LeeCourse1DetectorConstruction();

  virtual G4VPhysicalVolume* Construct();

};
#endif
// 
// LeeCourse1DetectorConstruction.hh ends here
