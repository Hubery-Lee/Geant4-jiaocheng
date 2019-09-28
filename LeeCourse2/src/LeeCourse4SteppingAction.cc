// LeeCourse4SteppingAction.cc --- 
// 
// Filename: LeeCourse4SteppingAction.cc
// Description: 
// Author: Li Hui,李会
// Maintainer: 
// Created: 二 9月 24 21:22:53 2019 (+0800)
// Version: 
// Package-Requires: ()
// Last-Updated: 六 9月 28 17:31:07 2019 (+0800)
//           By: Li Hui,李会
//     Update #: 54
// URL: https://github.com/Hubery-Lee
// Doc URL: 
// Keywords: 
// Compatibility: 
// 

// Change Log:
// 

// Code:
#include "LeeCourse4SteppingAction.hh"
#include "LeeCourse3EventAction.hh"
#include "LeeCourse2RunAction.hh"
#include "LeeCourse1DetectorConstruction.hh"
#include "analysis.hh"

#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"

#include "analysis.hh"

/////////////////////////////////////
LeeCourse4SteppingAction::LeeCourse4SteppingAction(LeeCourse3EventAction* ,analysis* A_analy):G4UserSteppingAction()
											     ,fEventAction(0),fScoringVolume(0),Analysis(A_analy)
{

}
/////////////////////////////////////
LeeCourse4SteppingAction::~LeeCourse4SteppingAction()
{}
/////////////////////////////////////
void LeeCourse4SteppingAction::UserSteppingAction(const G4Step *aStep)
{
  if (!fScoringVolume) { 
    const LeeCourse1DetectorConstruction* detectorConstruction
      = static_cast<const LeeCourse1DetectorConstruction*>
        (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
    fScoringVolume = detectorConstruction->GetVolume();   
  }

  //获取步
  const G4StepPoint* preStepPoint = aStep->GetPreStepPoint();
  // const G4StepPoint* postStepPoint = aStep->GetPostStepPoint();

  // get volume of the current step
  // G4LogicalVolume* volume 
  //   = aStep->GetPreStepPoint()->GetTouchableHandle()
  //     ->GetVolume()->GetLogicalVolume();

  G4LogicalVolume* volume 
    = preStepPoint->GetTouchableHandle()
    ->GetVolume()->GetLogicalVolume();

  // if(preStepPoint->GetStepStatus()==fGeomBoundary) return;

  if (volume != fScoringVolume) return;
  //如果在scoring volume 里面，接下来开始提取数据。

  //利用步去获取其他信息
  const G4Track* track = aStep->GetTrack();
  const G4ThreeVector& momentum = track->GetMomentum();
  const G4double kinEnergy = track->GetKineticEnergy();
  const G4double eDeposit = aStep->GetTotalEnergyDeposit();
  const G4double sLength = aStep->GetStepLength();

  Analysis->RecordValue(kinEnergy,"Ekin = ");
  // G4cout<< "momentum = "<<momentum<<G4endl;
  // G4cout<< "Ekin = "<<kinEnergy/MeV<<G4endl;
  // G4cout<< "eDeposit = "<<eDeposit<<G4endl;
  // G4cout<< "sLength = "<<sLength<<G4endl;
  // cout <<"Ekin = @@@@@@@@@@@@"<<endl;

}

// 
// LeeCourse4SteppingAction.cc ends here
