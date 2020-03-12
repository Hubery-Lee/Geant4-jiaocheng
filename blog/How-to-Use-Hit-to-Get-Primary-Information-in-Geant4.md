---
title: How to Use Hit to Get Primary Information in Geant4
date: 2018-09-23 13:04:15
categories: Geant4及Root应用
tags: [geant4]
description: This page introduce the struction of Geant4 and using Hit to get information of PrimaryGeneratorAction. 
password: lihuigeant4
message: Contact lihui to get the password.
---

## Code Structure of Geant4

The structure shows as the following pictrue.
![Class categories in Geant4](Geant4CodeStructure.png)

* Run and Event
These are categories related to the generation of events, interfaces to event generators, and any secondary particles produced. Their roles are principally to provide particles to be tracked to the Tracking Management.
* Tracking and Track
These are categories related to propagating a particle by analyzing the factors limiting the step and applying the relevant physics processes. The important aspect of the design was that a generalized GEANT4 physics process (or interaction) could perform actions, along a tracking step, either localized in space, or in time, or distributed in space and time (and all the possible combinations that could be built from these cases).
* Geometry and Magnetic Field
These categories manage the geometrical definition of a detector (solid modeling) and the computation of distances to solids (also in a magnetic field). The GEANT4 geometry solid modeler is based on the ISO STEP
standard and it is fully compliant with it. A key feature of the GEANT4 geometry is that the volume definitions
are independent of the solid representation. By this abstract interface for the G4 solids, the tracking component works identically for various representations. The treatment of the propagation in the presence of fields has been provided within specified accuracy. An OO design allows to exchange different numerical algorithms and/or different fields (not only B-field), without affecting any other component of the toolkit.
* Particle Definition and Matter
These two categories manage the the definition of materials and particles.
* Physics
This category manages all physics processes participating in the interactions of particles in matter. The abstract interface of physics processes allows multiple implementations of physics models per interaction or per channel. Models can be selected by energy range, particle type, material, etc. Data encapsulation and polymorphism make it possible to give transparent access to the cross sections (independently of the choice of reading from an ascii file, or of interpolating from a tabulated set, or of computing analytically from a formula). Electromagnetic and hadronic physics were handled in a uniform way in such a design, opening up the physics to the users.
* Hits and Digitization
These two categories manage the creation of hits and their use for the digitization phase. The basic design and
implementation of the Hits and Digi had been realized, and also several prototypes, test cases and scenarios
had been developed before the alpha-release. Volumes (not necessarily the ones used by the tracking) are
aggregated in sensitive detectors, while hits collections represent the logical read out of the detector. Different ways of creating and managing hits collections had been delivered and tested, notably for both single hits and calorimetry hits types. In all cases, hits collections had been successfully stored into and retrieved from an Object Data Base Management System.
* Visualization
This manages the visualization of solids, trajectories and hits, and interacts with underlying graphical libraries(the Visualization class category). The basic and most frequently used graphics functionality had been implemented already by the alpha-release. The OO design of the visualization component allowed us to develop
several drivers independently, such as for OpenGL, Qt and OpenInventor (for X11 and Windows), DAWN, Postscript (via DAWN) and VRML.
* Interfaces
This category handles the production of the graphical user interface (GUI) and the interactions with external
software (OODBMS, reconstruction etc.).

`MORE DETAIL INFORMATION ABOUT THIS，YOU CAN REFER TO GEANT4 BOOK FOR APPLICATION CHAPTER 3`

## Collect information from PrimaryGeneratorAction

Data record in step or event, and stored in hitscollection. data write in EventAction; general understanding of geant4 and its application as follows. Geant is the abbreviation of Geometry and Tracking. 
![General UnderStanding of Geant4](Geant4Application.png)
