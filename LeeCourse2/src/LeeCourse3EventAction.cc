// LeeCourse3EvenAction.cc --- 
// 
// Filename: LeeCourse3EvenAction.cc
// Description: 
// Author: Li Hui,李会
// Maintainer: 
// Created: 二 9月 24 21:01:35 2019 (+0800)
// Version: 
// Package-Requires: ()
// Last-Updated: 二 9月 24 21:18:39 2019 (+0800)
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
#include "LeeCourse3EventAction.hh"

#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4TrajectoryContainer.hh"
#include "G4Trajectory.hh"
#include "G4ios.hh"
////////////////////////////////////////////////////
LeeCourse3EventAction::LeeCourse3EventAction():G4UserEventAction()
{

}
////////////////////////////////////////////////////
LeeCourse3EventAction::~LeeCourse3EventAction()
{

}
////////////////////////////////////////////////////
void LeeCourse3EventAction::BeginOfEventAction(const G4Event*)
{}
////////////////////////////////////////////////////
void LeeCourse3EventAction::EndOfEventAction(const G4Event*)
{}
// 
// LeeCourse3EventAction.cc ends here
