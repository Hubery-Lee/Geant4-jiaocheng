// LeeCourse2RunAction.cc --- 
// 
// Filename: LeeCourse2RunAction.cc
// Description: 
// Author: Li Hui,李会
// Maintainer: 
// Created: 二 9月 24 20:29:12 2019 (+0800)
// Version: 
// Package-Requires: ()
// Last-Updated: 六 9月 28 17:20:02 2019 (+0800)
//           By: Li Hui,李会
//     Update #: 37
// URL: https://github.com/Hubery-Lee
// Doc URL: 
// Keywords: 
// Compatibility: 
// 

// Change Log:
// 

// Code:
#include "LeeCourse2RunAction.hh"
#include "analysis.hh"
#include "G4Run.hh"
#include "G4RunManager.hh"
/////////////////////////////////
LeeCourse2RunAction::LeeCourse2RunAction(analysis* A_analy):G4UserRunAction(),Analysis(A_analy)
{

}
////////////////////////////////
LeeCourse2RunAction::~LeeCourse2RunAction()
{}
///////////////////////////////
void LeeCourse2RunAction::BeginOfRunAction(const G4Run*)
{
 // output.open("test.txt",ios::app); 
 // output<<"this is a test for run action.";
  Analysis->Book();
}
//////////////////////////////
void LeeCourse2RunAction::EndOfRunAction(const G4Run*)
{
  // output.close();
  Analysis->Save();
}

// 
// LeeCourse2RunAction.cc ends here
