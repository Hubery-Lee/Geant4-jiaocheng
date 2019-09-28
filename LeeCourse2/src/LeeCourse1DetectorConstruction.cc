// LeeCurse1DetectorConstruction.cc --- 
// 
// Filename: LeeCurse1DetectorConstruction.cc
// Description: 
// Author: Li Hui,李会
// Maintainer: 
// Created: 一 9月 16 21:57:55 2019 (+0800)
// Version: 
// Package-Requires: ()
// Last-Updated: 六 9月 28 09:34:47 2019 (+0800)
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

#include "LeeCourse1DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

///////////////////////////////
LeeCourse1DetectorConstruction::LeeCourse1DetectorConstruction():G4VUserDetectorConstruction(),fVolume(0)
{}
//////////////////////////////
LeeCourse1DetectorConstruction::~LeeCourse1DetectorConstruction()
{}

//////////////////////////////
G4VPhysicalVolume* LeeCourse1DetectorConstruction::Construct()
{
  // Get nist material manager
  G4NistManager* nist = G4NistManager::Instance();
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");
  G4Material* env_mat = nist->FindOrBuildMaterial("G4_WATER");

  //     
  // World
  //
  G4double world_sizeXY = 30.0*cm;
  G4double world_sizeZ  =70.0*cm;
  //G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");
  
 // Option to switch on/off checking of volumes overlaps
  //
  G4bool checkOverlaps = true;

  G4Box* solidWorld =    
    new G4Box("World",                       //its name
       0.5*world_sizeXY, 0.5*world_sizeXY, 0.5*world_sizeZ);     //its size
      
  G4LogicalVolume* logicWorld =                         
    new G4LogicalVolume(solidWorld,          //its solid
                        world_mat,           //its material
                        "World");            //its name
                                   
  G4VPhysicalVolume* physWorld = 
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(),       //at (0,0,0)
                      logicWorld,            //its logical volume
                      "World",               //its name
                      0,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      checkOverlaps);        //overlaps checking

  //     
  // Detector
  //  
  G4double env_sizeXY = 20*cm, env_sizeZ = 30*cm;
  G4Box* solidEnv =    
    new G4Box("Envelope",                    //its name
        0.5*env_sizeXY, 0.5*env_sizeXY, 0.5*env_sizeZ); //its size
      
  G4LogicalVolume* logicEnv =                         
    new G4LogicalVolume(solidEnv,            //its solid
                        env_mat,             //its material
                        "Envelope");         //its name
               
  new G4PVPlacement(0,                       //no rotation
                    G4ThreeVector(),         //at (0,0,0)
                    logicEnv,                //its logical volume
                    "Envelope",              //its name
                    logicWorld,              //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking


  //将要传递给steppingaction的逻辑体传给指针变量fVolume,其他类通过GetVolume()函数获取这个逻辑体
  fVolume = logicEnv;

  return physWorld;

}
// 
// LeeCurse1DetectorConstruction.cc ends here
