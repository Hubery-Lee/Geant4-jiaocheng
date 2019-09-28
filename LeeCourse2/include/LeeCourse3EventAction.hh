// LeeCourse3EventAction.hh --- 
// 
// Filename: LeeCourse3EvenAction.hh
// Description: 
// Author: Li Hui,李会
// Maintainer: 
// Created: 二 9月 24 21:01:48 2019 (+0800)
// Version: 
// Package-Requires: ()
// Last-Updated: 二 9月 24 21:19:31 2019 (+0800)
//           By: Li Hui,李会
//     Update #: 3
// URL: https://github.com/Hubery-Lee
// Doc URL: 
// Keywords: 
// Compatibility: 
// 

// Change Log:
// 

// Code:
#ifndef LeeCourse3EventAction_h
#define LeeCourse3EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"

class LeeCourse3EventAction:public G4UserEventAction
{
public:
  LeeCourse3EventAction();
  virtual ~LeeCourse3EventAction();

  virtual void BeginOfEventAction(const G4Event*);
  virtual void EndOfEventAction(const G4Event*);

};

#endif


// 
// LeeCourse3EventAction.hh ends here
