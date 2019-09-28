// LeeCourse1ActionInitialization.cc --- 
// 
// Filename: LeeCourse1ActionInitialization.cc
// Description: 
// Author: Li Hui,李会
// Maintainer: 
// Created: 一 9月 16 22:23:37 2019 (+0800)
// Version: 
// Package-Requires: ()
// Last-Updated: 六 9月 28 17:17:02 2019 (+0800)
//           By: Li Hui,李会
//     Update #: 10
// URL: https://github.com/Hubery-Lee
// Doc URL: 
// Keywords: 
// Compatibility: 
// 

// Change Log:
// 

// Code:
#include "LeeCourse1ActionInitialization.hh"
#include "B1PrimaryGeneratorAction.hh"   //**
#include "LeeCourse2RunAction.hh"  //**
#include "LeeCourse3EventAction.hh"
#include "LeeCourse4SteppingAction.hh"
#include "analysis.hh"
/////////////////////////////////////////////
LeeCourse1ActionInitialization::LeeCourse1ActionInitialization()
 : G4VUserActionInitialization()
{}
/////////////////////////////////////////////

LeeCourse1ActionInitialization::~LeeCourse1ActionInitialization()
{}

////////////////////////////////////////////
void LeeCourse1ActionInitialization::BuildForMaster() const
{

  analysis *A_analy = new analysis();

  LeeCourse2RunAction* runAction = new LeeCourse2RunAction(A_analy);
  SetUserAction(runAction);
}
////////////////////////////////////////////
void LeeCourse1ActionInitialization::Build() const
{
  SetUserAction(new B1PrimaryGeneratorAction);

  analysis *A_analy = new analysis();

  LeeCourse2RunAction* runAction = new LeeCourse2RunAction(A_analy);
  SetUserAction(runAction);

  LeeCourse3EventAction* eventAction = new LeeCourse3EventAction;
  SetUserAction(eventAction);

  SetUserAction(new LeeCourse4SteppingAction(eventAction,A_analy));
  
}  

// 
// LeeCourse1ActionInitialization.cc ends here
