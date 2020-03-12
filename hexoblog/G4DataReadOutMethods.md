---
title: Gean4 Data Read Out Methods
date: 2018-09-17 22:21:46
categories: [Geant4及Root应用]
tags: [geant4]
description: This page introduce different methods to read out data from geant4 simulation; This page focus on StepAction and Hit with SD method.
---

## Introduction of Data Aquisition Methods in Geant4 Simulation

* G4ScoringManager
* SteppingAction
* TrackingAction
* SensitiveDetctor + HitCollection

![Geant4 Data Read Out Method](Geant4数据输出方式.png)

More detail information about these methods to get data can you refer to [this site](https://wenku.baidu.com/view/f13f4725be23482fb5da4c63.html)

```
A: To get the information at tracking time in a given volume A, one can adopt either one or a combination of the following strategies:

1.  If the geometry is simple enough, and wish to score some commonly used physics quantities (e.g. energy deposition, dose, flux, etc.), just activate G4ScoringManager in your main program, and use the scorer-based UI commands to transform volume A into a scorer.

    See Option 6 below, and the example examples/extended/runAndEvent/RE03.

2.  Through the SteppingAction, check that the particle is inside volume A and do whatever needed. Hints can be found in the previous chapter of this FAQ document.

    Usually, the hits containers and histograms are attributes of a Track, Event or Run and can be managed through either a TrackingAction, EventAction and/or RunAction and eventually messaging their pointer to the SteppingAction.

    A similar approach is illustrated in examples/basic/B2, B4, extended/electromagnetic, optical, and many others…

3.  In DetectorConstruction, by declaring volume A as a SensitiveDetector. At stepping time, the Geant4 kernel will automatically check that a particle is inside volume A and will handle the control to a specific function G4VSensitiveDetector::ProcessHits(). It is just necessary to instanciate a class inherited from G4VSensitiveDetector, say VolumeA_SD, and do whatever needed by implementing the function VolumeA_SD::ProcessHits(), as described in Option 2 above.

4.  In addition to Option 3 above, should create a HitsCollection to store the information. A HitsCollection can be created in VolumeA_SD::Initialize(). A Hit can be created or filled in VolumeA_SD::ProcessHits(). Additional operations on HitsCollection can be performed in VolumeA_SD::EndOfEvent().

    This approach is illustrated in examples/basic/B2, B4 and extended/analysis, extended/runAndEvent/RE01, etc…

5.  In DetectorConstruction, volume A can be declared as SensitiveDetector, and one or several pre-defined scorers can be attached to volume A. In this case, neither a SteppingAction nor a spcific VolumeA_SD sensitive detector is needed any longer. It is just necessary to create a dedicated scorer, e.g. MyRunScorer, inherited from G4Run, and handle the HitsCollections within MyRunScorer::RecordEvent(). MyRunScorer itself can be instanciated from RunAction::GenerateRun().

    This approach is illustrated in examples/novice/N07, extended/runAndEvent/RE02.

6.  A set of build-in scorer-based UI commands allows to perform most possible operations described through the previous Option 5 directly from run-time macros.

    See example extended/runAndEvent/RE03.

```

## Detector Response


对于Geant4模拟数据输出与存储可以参看`examples/basic/B4`,对于不同的数据输出方式，看该文件夹下的`README`.

```
 6- DETECTOR RESPONSE
 
   The energy deposit and track lengths of the charged particles are recorded on
   an event by event basis in the Absober and Gap layers.
   
   In order to demonstrate several possible ways of data scoring,
   the example is provided in four variants:
   
   Variant a: User Actions
   
     These 4 quantities are data members of the B4aEventAction class.  
     They are collected step by step in 
     B4aSteppingAction::UserSteppingAction(), and passed to the event action
     via two methods: B4aEventAction::AddAbs() and B4aEventAction::AddGap().
   
     In B4aEventAction::EndOfEventAction(), these quantities are printed and 
     filled in H1D histograms and ntuple to accumulate statistic and compute 
     dispersion.
     
   Variant b: User data object 
   
     In order to avoid dependencies between action classes, a user object
     B4bRunData, derived from G4Run, is defined with data members needed 
     for the accounted information. 
     In order to reduce the number of data members a 2-dimensions array
     is introduced for each quantity.
     Then the quantities are collected step by step in user action classes:
     B4bSteppingAction::UserSteppingAction() and 
     B4bEventAction::EndOfEventAction() in a similar way as in variant a. 
     
   Variant c: Hits and Sensitive detectors
   
     In this option, the physics quantities are accounted using the hits
     and sensitive detectors framework defined in the Geant4 kernel.  
     The physics quantities are stored in B4cCalorHit via two B4cCalorimeterSD
     objects, one associated with the Absorber volume and another one with Gap
     in B4cDetectorConstruction::ConstructSDandField().
     
     In contrary to the B2 example (Tracker) where a new hit is created
     with each track passing the sensitive volume (in the calorimeter), only one
     hit is created for each calorimeter layer and one more hit to account for
     the total quantities in all layers. In addition to the variants a and b,
     the quantities per each layer are also available in addition to the total 
     quantities.
     
   Variant d: Scorer
    
     In this option, the Geant4 scorers which are defined on the top of hits
     and sensitive detectors Geant4 framework are used.  
     In practice this means that the user does not need to define hits and sensitive
     detector classes but rather uses the classes already defined
     in Geant4. In this example, the G4MultiFunctionalDetector with
     G4PSEnergyDeposit and G4PSTrackLength primitive scores are used (see
     B4dDetectorConstruction::ConstructSDandField()).
    
     Also with this approach, the quantities per each layer are available 
     in addition to the total quantities.
       
  7- HISTOGRAMS
 
   The analysis tools are used to accumulate statistics and compute the dispersion
   of the energy deposit and track lengths of the charged particles.
   H1D histograms are created in B4[b]RunAction::B4[b]RunAction() for the 
   following quantities:
   - Energy deposit in absorber
   - Energy deposit in gap
   - Track length in absorber
   - Track length in gap
   The same values are also saved in an ntuple.

   The histograms and the ntuple are saved in the output file in a format
   according to a technology selected in B4Analysis.hh, the default in this example
   is ROOT.

   The accumulated statistic and computed dispersion is printed at the end of 
   run, in B4RunAction::EndOfRunAction().
   When running in multi-threading mode, the histograms and the ntuple accumulated 
   on threads are merged in a single output file. While merging of histograms is
   performed by default, merging of ntuples is explicitly activated in the B4RunAction 
   constructor.

   The ROOT histograms and ntuple can be plotted with ROOT using the plotHisto.C
   and plotNtuple.C macros.
```


## Geant4 Simulation Data ReadOut by SensitiveDetctor + HitCollection Methods

### RunAction

* RunAction()
* ~RunAction()
* BegingOfRunAction(const G4Run *)
* EndOfRunAction(const G4Run *)

该方式的数据输出与存储参看`examples/basic/B4/B4c`

#### RunAction() 构造函数

打开和关闭数据存储文件，在RunAction中；

```
  // set printing event number per each event
  G4RunManager::GetRunManager()->SetPrintProgress(1);
  
  // Create analysis manager
  // The choice of analysis technology is done via selectin of a namespace
  // in B4Analysis.hh
  auto analysisManager = G4AnalysisManager::Instance();
  G4cout << "Using " << analysisManager->GetType() << G4endl;

  analysisManager->SetVerboseLevel(1);
  analysisManager->SetNtupleMerging(true);  
  // Note: merging ntuples is available only with Root output

  // Book ntuples	   

  //Declare ntuples
  // Creating 1st ntuple
  //
  analysisManager->CreateNtuple("Det", "xyz in Det");
  analysisManager->CreateNtupleSColumn("SDName");
  analysisManager->CreateNtupleIColumn("EventID");
  analysisManager->CreateNtupleIColumn("ParentID");
  analysisManager->CreateNtupleIColumn("TrackID");
  analysisManager->CreateNtupleIColumn("StepID");
  analysisManager->CreateNtupleDColumn("Edep");
  analysisManager->CreateNtupleDColumn("PosX");
  analysisManager->CreateNtupleDColumn("PosY");
  analysisManager->CreateNtupleDColumn("PosZ");
  analysisManager->CreateNtupleDColumn("GlobalT");
  analysisManager->CreateNtupleDColumn("LocalT");
  analysisManager->CreateNtupleDColumn("ProperT");
  analysisManager->CreateNtupleDColumn("Ekin");
  analysisManager->CreateNtupleDColumn("Velocity");
  analysisManager->CreateNtupleDColumn("MomentX");
  analysisManager->CreateNtupleDColumn("MomentY");
  analysisManager->CreateNtupleDColumn("MomentZ");
  analysisManager->CreateNtupleSColumn("ProC");

  analysisManager->FinishNtuple();
```
主要设置模拟运行参数，运行显示、多线程文件合并等；

* `注意`
`B4c`中将内容目录也在构造函数中创建，文件的创建在BeginOfRunAction()中。

#### ~RunAction() 析构函数

```
  delete G4AnalysisManager::Instance(); 
```

#### BeginOfRunAction(const G4Run*)

```
  // Get analysis manager
  auto analysisManager = G4AnalysisManager::Instance();

  // Open an output file
  //
  G4String fileName = "APNIS";
  analysisManager->OpenFile(fileName);

```
新建储存文件并打开文件

#### EndOfRunAction(const G4Run*)

```
  auto analysisManager = G4AnalysisManager::Instance();

  // save histograms & ntuple
  //
  analysisManager->Write();
  analysisManager->CloseFile();
```

一个Run结束后的写文件

### EventAction

采用SD+HitCollection方式存储数据，记录的是一个Event的所有Hit点的数据，那么Geant4中数据的存储就在EventAction中进行；

当然，如果你采用StepAction方式存储数据，你只需在StepAction中去存储数据就行了；

* EventAction()
* ~EventAction()
* BeginOfEventAction(const G4Event*)
* EndOfEventAction(const G4Event*)
```
• beginOfEventAction() This method is invoked before converting the primary particles to G4Track
objects. A typical use of this method would be to initialize and/or book histograms for a particular event.
• endOfEventAction() This method is invoked at the very end of event processing. It is typically used for
a simple analysis of the processed event. If the user wants to keep the currently processing event until
the end of the current run, the user can invoke fpEventManager->KeepTheCurrentEvent(); so
that it is kept in G4Run object. This should be quite useful if you simulate quite many events and want to
visualize only the most interest ones after the long execution. Given the memory size of an event and its
contents may be large, it is the user’s responsibility not to keep unnecessary events.
```

#### EndOfEventAction(const G4Event*)

在每个Event结束时，将Hit数据存储写到存储文件中。首先获取这个Event有多少个HitCollection,（HitCollection编号HCID在Event开始前获得，在BegingOfEventAction()中定义），然后根据HCID查找对应的HitCollection，根据不同HitCollection的大小提取数据并写入到文件；

```
  G4HCofThisEvent * HCE = event->GetHCofThisEvent();//获得Event结束时，所有的HitCollection

  //根据HitCollecitonID名称，获取不同的CollectionID
  if(HCE){
  PrimaryHC = (PLANETOCOSPrimaryHitsCollection*)(HCE->GetHC(primaryCollID));
  FluxHC = (PLANETOCOSFluxHitsCollection*)(HCE->GetHC(fluxdetectorCollID));
  //FluxHC = (PLANETOCOSFluxHitsCollection*)(HCE->GetHC(1));
  //G4cout<<"ANALYSE1"<<std::endl;
  EdepHC = (PLANETOCOSEdepHitsCollection*)(HCE->GetHC(edepCollID));
  SoilEdepHC = (PLANETOCOSEdepHitsCollection*)(HCE->GetHC(edepSoilCollID));
  
  //EdepHC = (PLANETOCOSEdepHitsCollection*)(HCE->GetHC(2));
  PostTrackHC = (PLANETOCOSPostTrackHitsCollection*)(HCE->GetHC(post_trackCollID));
  //PostTrackHC = (PLANETOCOSPostTrackHitsCollection*)(HCE->GetHC(3));
  
  }

```

#### BeginOfEventAction(const G4Event*)

在Event开始前的行为，可以写在这个函数中；如下，获得不同HitCollection的编码HCID；注意，不同的HitCollection 对应不同的SD；
```
  G4SDManager * SDman = G4SDManager::GetSDMpointer();
  if(edepCollID<0||primaryCollID<0||fluxdetectorCollID<0 ||post_trackCollID <0 || edepSoilCollID<0){
  	edepCollID = SDman->GetCollectionID("edepCol");
	edepSoilCollID = SDman->GetCollectionID("edepSoilCol");
	primaryCollID = SDman->GetCollectionID("primaryCol");
   	fluxdetectorCollID = SDman->GetCollectionID("detCol");
	post_trackCollID = SDman->GetCollectionID("post_trackCol");
  } 
```

当不考虑不同的SD，对所以SD的detector的响应都一样时采用如下方法读取数据；
```
/////////////////////////////////////////////
void APNISEventAction::EndOfEventAction(const G4Event* event)
{

  G4HCofThisEvent * hce = event->GetHCofThisEvent();
  if (!hce) {
      G4ExceptionDescription msg;
      msg << "No hits collection of this event found." << G4endl; 
      G4Exception("APNISEventAction::EndOfEventAction()",
                  "APNISCode001", JustWarning, msg);
      return;
  }

  //get hit collection
  if(hce)
    {
      size_t nHCE=hce->GetCapacity();
      for(size_t i=0;i<nHCE;i++){//多个SD时用
  	APNISTrackHitsCollection *HC =0;
      HC = (APNISTrackHitsCollection *)(hce->GetHC(i));
      if(HC) OneHitOrder(HC);//写数据	
      }
    }
 }

////////////////////////////////////////////////////////////////
void APNISEventAction::OneHitOrder(APNISTrackHitsCollection*HC)
{
  //////////////////////////////////////////
  //
  // Fill histograms & ntuple
  //
  //////////////////////////////////////////

  // get analysis manager
  auto analysisManager = G4AnalysisManager::Instance();

  //analyse
  G4int n_hit = HC->entries();
  for(G4int i=0;i<n_hit;i++)
    {
      G4String SDName =(*HC)[i]->GetSDName();
      G4int    EventID=(*HC)[i]->GetEventID();//
      G4int    ParentID=(*HC)[i]->GetParentID();//
      G4int    TrackID=(*HC)[i]->GetTrackID();//
      G4int    StepID=(*HC)[i]->GetStepID();//       // Total steps number up to now
      G4double fEdep=(*HC)[i]->GetEdep();
      G4ThreeVector fPos=(*HC)[i]->GetPos();
      G4double GlobalTime=(*HC)[i]->GetGlobalTime();//                   //Time since event is created
      G4double LocalTime=(*HC)[i]->GetLocalTime();//                  // Time since track is created
      G4double ProperTime=(*HC)[i]->GetProperTime();//            // Time since track is created (in rest frame of particle)
      G4double Ekin=(*HC)[i]->GetEkin();//                    
      G4double Velocity=(*HC)[i]->GetVelocity();//
      G4ThreeVector MomentumDirection = (*HC)[i]->GetMomentumDirection();      // Direction of momentum 
      G4String CreatorProcess=(*HC)[i]->GetCreatorProcess();//

      //塞选思路

      
      
      //存储数据
      // fill ntuple
      G4int Count=0;
      analysisManager->FillNtupleSColumn(Count,SDName);Count++;
      analysisManager->FillNtupleIColumn(Count,EventID);Count++;
      analysisManager->FillNtupleIColumn(Count,ParentID);Count++;
      analysisManager->FillNtupleIColumn(Count,TrackID);Count++;
      analysisManager->FillNtupleIColumn(Count,StepID);Count++;
      analysisManager->FillNtupleDColumn(Count,fEdep/MeV);Count++;
      analysisManager->FillNtupleDColumn(Count,fPos.x()/m);Count++;
      analysisManager->FillNtupleDColumn(Count,fPos.y()/m);Count++;
      analysisManager->FillNtupleDColumn(Count,fPos.z()/m);Count++;
      analysisManager->FillNtupleDColumn(Count,GlobalTime/s);Count++;
      analysisManager->FillNtupleDColumn(Count,LocalTime/s);Count++;
      analysisManager->FillNtupleDColumn(Count,ProperTime/s);Count++;
      analysisManager->FillNtupleDColumn(Count,Ekin/MeV);Count++;
      analysisManager->FillNtupleDColumn(Count,Velocity/(m/s));Count++;
      analysisManager->FillNtupleDColumn(Count,MomentumDirection.x());Count++;
      analysisManager->FillNtupleDColumn(Count,MomentumDirection.y());Count++;
      analysisManager->FillNtupleDColumn(Count,MomentumDirection.z());Count++;
      analysisManager->FillNtupleSColumn(Count,CreatorProcess);Count++;

      // analysisManager->FillNtupleIColumn(Count,);Count++;
      // analysisManager->FillNtupleDColumn(Count,);Count++;
      // analysisManager->FillNtupleSColumn(Count,);Count++;

      analysisManager->AddNtupleRow();
    }

}
```

### Hit

参考Book for applicaiton中的4.4 [Hits](http://geant4-userdoc.web.cern.ch/geant4-userdoc/UsersGuides/ForApplicationDeveloper/html/Detector/hit.html)

A hit is a snapshot of the physical interaction of a track in the sensitive region of a detector. In it you can store
information associated with a G4Step object. This information can be
* the position and time of the step,
* the momentum and energy of the track,
* the energy deposition of the step,
* geometrical information,
* or any combination of the above.

`简而言之`
* G4中的Hit <==> C++中的vector  ，G4Allocator会给Hit分配内存空间；
* G4中的Map <==> C++中的map

#### Hit.hh头文件结构

```
  APNISTrackHit();
  APNISTrackHit(const APNISTrackHit &right);
  virtual ~APNISTrackHit();
  //operator
  const APNISTrackHit& operator=(const APNISTrackHit &right);
  G4int operator ==(const APNISTrackHit &right)const;

  inline void *operator new(size_t);
  inline void operator delete(void *aHit);

  //获取数据
  inline void SetSDName(G4String name){SDName=name;}
  inline const G4String& GetSDName() const{return SDName;}

  inline void SetEventID(G4int id){EventID=id;}//ok
  inline G4int GetEventID() const{return EventID;}//

  inline void SetParentID(G4int id){ParentID=id;}//ok
  inline G4int GetParentID() const{return ParentID;}//

  inline void SetTrackID(G4int id){TrackID=id;}//ok
  inline G4int GetTrackID() const{return TrackID;}//

  inline void SetStepID(G4int id){CurrentStepNumber=id;}//ok
  inline G4int GetStepID() const{return CurrentStepNumber;}//

  inline void SetEdep(G4double de){ fEdep = de; }
  inline G4double GetEdep(){ return fEdep; }
  ...
```

分配HitCollection存储空间，新建内存空间用完后并释放内存空间；

```
///////////////////////////////////////////////////////////////
typedef G4THitsCollection<APNISTrackHit> APNISTrackHitsCollection;

extern G4ThreadLocal G4Allocator<APNISTrackHit>* APNISTrackHitAllocator;
//////////////////////////////////////////////////////////////
inline void* APNISTrackHit::operator new(size_t)
{
  if(!APNISTrackHitAllocator) APNISTrackHitAllocator = new G4Allocator<APNISTrackHit>;
  return (void *)APNISTrackHitAllocator->MallocSingle();
}

inline void APNISTrackHit::operator delete(void* aHit)
{
  APNISTrackHitAllocator->FreeSingle((APNISTrackHit*)aHit);
}
```

#### Hit.cc

```
////////////////////////////////////////////////////////
APNISTrackHit::APNISTrackHit(const APNISTrackHit &right):G4VHit()
{
  SDName =right.SDName;
  EventID=right.EventID;
  ParentID =right.ParentID;
  TrackID =right.TrackID;
  CurrentStepNumber =right.CurrentStepNumber;
  fEdep = right.fEdep;
  ...
}
////////////////////////////////////////////////////////
//
// operator
const APNISTrackHit& APNISTrackHit::operator=(const APNISTrackHit &right)
{
  SDName =right.SDName;
  EventID=right.EventID;
  ParentID =right.ParentID;
  TrackID =right.TrackID;
  CurrentStepNumber =right.CurrentStepNumber;
  fEdep = right.fEdep;
  ...

  return *this;
}
////////
G4int APNISTrackHit::operator==(const APNISTrackHit &right) const
{
  return (this==&right) ? 1 : 0;
}
```

### SensitiveDetector

SD的作用时根据Step和Track信息，构建Hit信息；SD有以下一些函数：
* ProcessHits()
* Initialize()
* EndOfEvent()



#### ProcessHits(G4Step* aStep, G4TouchableHistory*)

在ProcessHits()中将数据存入Hit()申明的存储空间中;

```
ProcessHits() This method is invoked by G4SteppingManager when a step is composed in the
G4LogicalVolume which has the pointer to this sensitive detector. The first argument of this method is
a G4Step object of the current step. The second argument is a G4TouchableHistory object for the
Readout geometry described in the next section. The second argument is NULL if Readout geometry
is not assigned to this sensitive detector. In this method, one or more G4VHit objects should be constructed if
the current step is meaningful for your detector.
Initialize() This method is invoked at the beginning of each event. The argument of this method is an object
of the G4HCofThisEvent class. Hit collections, where hits produced in this particular event are stored,
can be associated with the G4HCofThisEvent object in this method. The hit collections associated with
the G4HCofThisEvent object during this method can be used for during the event processing
digitization.
```
example
```
  G4StepPoint* preStepPoint=aStep->GetPreStepPoint();
  G4StepPoint* postStepPoint=aStep->GetPostStepPoint();
  G4Track* aTrack=aStep->GetTrack();

  // G4double edep = aStep->GetTotalEnergyDeposit();
  // if(edep==0.) return false;
  G4ParticleDefinition* theparticle=aStep->GetTrack()->GetDefinition();
  G4String PName=theparticle->GetParticleName();

  G4TouchableHandle touch1 = preStepPoint->GetTouchableHandle();
  G4VPhysicalVolume* volume = touch1->GetVolume();

	if(preStepPoint->GetStepStatus()==fGeomBoundary)
	  {
	    // if(volume->GetName()=="AirDet")
	    //   {
	    APNISTrackHit* newHit1 = new APNISTrackHit();
	    // G4cout<<"####----In AirDet----"<<SensitiveDetectorName<<G4endl;
	    newHit1->SetSDName(volume->GetName());
	    newHit1->SetEventID(G4EventManager::GetEventManager()->GetConstCurrentEvent()->GetEventID());//ok
	    newHit1->SetParentID(aTrack->GetParentID());//ok
	    newHit1->SetTrackID(aTrack->GetTrackID());//ok
	    newHit1->SetStepID(aTrack->GetCurrentStepNumber());//ok

	    newHit1->SetEdep( aStep->GetTotalEnergyDeposit() );
	    newHit1->SetPos( aStep->GetPreStepPoint()->GetPosition());
	    newHit1->SetGlobalTime(preStepPoint->GetGlobalTime());//ok
	    newHit1->SetLocalTime(preStepPoint->GetLocalTime());//ok
	    newHit1->SetProperTime(preStepPoint->GetProperTime());//ok
	    newHit1->SetEkin(preStepPoint->GetKineticEnergy());//ok
	    newHit1->SetVelocity(preStepPoint->GetVelocity());//ok
	    newHit1->SetMomentumDirection(preStepPoint->GetMomentumDirection());//ok
	    const G4VProcess* pcr=aTrack->GetCreatorProcess();
	    if(pcr)newHit1->SetCreatorProcess(pcr->GetProcessName());
	    else newHit1->SetCreatorProcess("##");//ok
	    //数据存储到HitCollection中
	    fTrackHitCollection->insert( newHit1 );
	    }
```

#### Initialize(G4HCofThisEvent* HCE)


初始化HitsCollection，将数据存入HitsCollection前都需将空间初始化
```
Initialize() This method is invoked at the beginning of each event. The argument of this method is an object
of the G4HCofThisEvent class. Hit collections, where hits produced in this particular event are stored,
can be associated with the G4HCofThisEvent object in this method. The hit collections associated with
the G4HCofThisEvent object during this method can be used for during the event processing
digitization.
```
example
```
void PLANETOCOSSoilSD::Initialize(G4HCofThisEvent*HCE)
{ static int HCID = -1;
  
  SoilEdepHitCollection = new PLANETOCOSEdepHitsCollection
                                  (SensitiveDetectorName,collectionName[0]);
  
  HCID = GetCollectionID(0);
  HCE->AddHitsCollection(HCID,SoilEdepHitCollection);
}
```
```
void B4cCalorimeterSD::Initialize(G4HCofThisEvent* hce)
{
  // Create hits collection
  fHitsCollection 
    = new B4cCalorHitsCollection(SensitiveDetectorName, collectionName[0]); 

  // Add this collection in hce
  auto hcID 
    = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
  hce->AddHitsCollection( hcID, fHitsCollection ); 

  // Create hits
  // fNofCells for cells + one more for total sums 
  for (G4int i=0; i<fNofCells+1; i++ ) {
    fHitsCollection->insert(new B4cCalorHit());
  }
}

```
```
void APNISTrackSD::Initialize(G4HCofThisEvent* HCE)
{
  // static int HCID = -1;
  fTrackHitCollection = new APNISTrackHitsCollection
                      (SensitiveDetectorName,collectionName[0]); 
  // if(HCID<0)
  // { HCID = GetCollectionID(0); }

  // get the collection name according to the object(name).
  if(HCID<0){
    HCID = G4SDManager::GetSDMpointer()
      ->GetCollectionID(fTrackHitCollection);
  }
  HCE->AddHitsCollection(HCID,fTrackHitCollection);
}
```

### 结语

到这里，数据文件打开，写入；数据的传递与存储就介绍完了；RunAction中实现对数据文件的打开与关闭；EventAction中实现将数据写入到文件，当然，如果你采用SteppingAction方式也可以将数据写入文件（此文不再介绍）；Hit中实现给需要传递的数据分配内存空间；SensitiveDetector中实现将数据传递给Hit分配的内存空间；如果将这个问题表述为送快递的过程，那么RunAction就是告诉快递员有堆快递需要在什么时候开始送，什么时候完全送达；EventAction就是需要送的快递，Hit就是送一份快递，给快递员分配的货箱大小；SensitiveDetector就是告诉快递员将货物放到货箱里；

![SensitiveDetector+HitsCollection方式存储数据方法示意图](Geant4SD_Hit.png)