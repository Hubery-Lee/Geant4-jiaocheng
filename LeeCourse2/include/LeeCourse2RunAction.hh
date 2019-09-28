// LeeCourse2RunAction.hh --- 
// 
// Filename: LeeCourse2RunAction.hh
// Description: 
// Author: Li Hui,李会
// Maintainer: 
// Created: 二 9月 24 20:29:39 2019 (+0800)
// Version: 
// Package-Requires: ()
// Last-Updated: 六 9月 28 17:17:45 2019 (+0800)
//           By: Li Hui,李会
//     Update #: 26
// URL: https://github.com/Hubery-Lee
// Doc URL: 
// Keywords: 
// Compatibility: 
// 

// Change Log:
// 

// Code:
#ifndef LeeCourse2RunAction_h
#define LeeCourse2RunAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"

/////////////////////////////
class G4Run;
class analysis;
class LeeCourse2RunAction: public G4UserRunAction
{
public:
  LeeCourse2RunAction(analysis* A_analy);
  virtual ~LeeCourse2RunAction();

  virtual void BeginOfRunAction(const G4Run* run );
  virtual void EndOfRunAction(const G4Run* run);

private:
  // ofstream output;
  analysis *Analysis;
};
#endif
// 
// LeeCourse2RunAction.hh ends here
