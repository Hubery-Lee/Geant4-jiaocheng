// LeeCourse1ActionInitialization.hh --- 
// 
// Filename: LeeCourse1ActionInitialization.hh
// Description: 
// Author: Li Hui,李会
// Maintainer: 
// Created: 一 9月 16 22:23:26 2019 (+0800)
// Version: 
// Package-Requires: ()
// Last-Updated: 一 9月 16 22:26:27 2019 (+0800)
//           By: Li Hui,李会
//     Update #: 1
// URL: https://github.com/Hubery-Lee
// Doc URL: 
// Keywords: 
// Compatibility: 
// 

// Change Log:
// 

// Code:

#ifndef LeeCourse1ActionInitialization_h
#define LeeCourse1ActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

/// Action initialization class.

class LeeCourse1ActionInitialization : public G4VUserActionInitialization
{
  public:
    LeeCourse1ActionInitialization();
    virtual ~LeeCourse1ActionInitialization();

    virtual void BuildForMaster() const;
    virtual void Build() const;
};

#endif
// 
// LeeCourse1ActionInitialization.hh ends here
