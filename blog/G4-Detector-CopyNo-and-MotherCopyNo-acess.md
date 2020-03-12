---
title: G4 Detector CopyNo and MotherCopyNo acess
date: 2018-10-11 11:41:25
categories: Geant4及Root应用
tags: [geant4]
description: This page introduce the mehtods to construct detector arrays and how to discriminate the different components with copyNo and motherCopyNo.
---

## How to construct assembly or replices

You can refer to Geant4 Book for Application Developers [User Guide](http://geant4-userdoc.web.cern.ch/geant4-userdoc/UsersGuides/ForApplicationDeveloper/html/Detector/Geometry/geomAssembly.html)

There are discriptions in the chapter4 Geometry/Assembly、Navigator、TouchableHandles.

## How to distinguish different detector array components


Using the ‘step’ to retrieve geometrical information

During the tracking run, geometrical information can be retrieved through the touchable handle associated to the current step. For example, to identify the exact copy-number of a specific physical volume in the mass geometry, one should do the following:

``` bash
// Given the pointer to the step object ...
//
G4Step* aStep = ..;

// ... retrieve the 'pre-step' point
//
G4StepPoint* preStepPoint = aStep->GetPreStepPoint();

// ... retrieve a touchable handle and access to the information
//
G4TouchableHandle theTouchable = preStepPoint->GetTouchableHandle();
G4int copyNo = theTouchable->GetCopyNumber();
G4int motherCopyNo = theTouchable->GetCopyNumber(1);

To determine the exact position in global coordinates in the mass geometry and convert to local coordinates (local to the current volume):

G4ThreeVector worldPosition = preStepPoint->GetPosition();
G4ThreeVector localPosition = theTouchable->GetHistory()->
              GetTopTransform().TransformPoint(worldPosition);

```

## Attention

the motherCopyNo start from 2 to motherNoCopy+1,  copyNo start from 0 to NoCopy-1;