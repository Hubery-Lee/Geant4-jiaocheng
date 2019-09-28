// LeeCourse1ActionInitialization.cc --- 
// 
// Filename: LeeCourse1ActionInitialization.cc
// Description: 
// Author: Li Hui,李会
// Maintainer: 
// Created: 一 9月 16 22:23:37 2019 (+0800)
// Version: 
// Package-Requires: ()
// Last-Updated: 一 9月 16 22:46:36 2019 (+0800)
//           By: Li Hui,李会
//     Update #: 4
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
// #include "LeeCourse1RunAction.hh"  //**

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
  // LeeCourse1RunAction* runAction = new LeeCourse1RunAction;
  // SetUserAction(runAction);
}
////////////////////////////////////////////
void LeeCourse1ActionInitialization::Build() const
{
  SetUserAction(new B1PrimaryGeneratorAction);

  // LeeCourse1RunAction* runAction = new LeeCourse1RunAction;
  // SetUserAction(runAction);
  
}  

// 
// LeeCourse1ActionInitialization.cc ends here
