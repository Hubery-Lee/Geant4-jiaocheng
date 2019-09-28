// LeeCourse4SteppingAction.hh --- 
// 
// Filename: LeeCourse4SteppingAction.hh
// Description: 
// Author: Li Hui,李会
// Maintainer: 
// Created: 六 9月 28 09:19:53 2019 (+0800)
// Version: 
// Package-Requires: ()
// Last-Updated: 六 9月 28 17:14:36 2019 (+0800)
//           By: Li Hui,李会
//     Update #: 5
// URL: https://github.com/Hubery-Lee
// Doc URL: 
// Keywords: 
// Compatibility: 
// 

// Change Log:
// 

// Code:
#ifndef LeeCourse4SteppingAction_h
#define LeeCourse4SteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"

class LeeCourse3EventAction;
class G4LogicalVolume;
class analysis;
////////////////////////////////////
class LeeCourse4SteppingAction:public G4UserSteppingAction
{
public:
  LeeCourse4SteppingAction(LeeCourse3EventAction* EventAction,analysis* A_analy);
  virtual ~LeeCourse4SteppingAction();

  //
  virtual void UserSteppingAction(const G4Step*);

private:
  LeeCourse3EventAction* fEventAction;
  G4LogicalVolume* fScoringVolume;
  analysis * Analysis;
};

#endif


// 
// LeeCourse4SteppingAction.hh ends here
