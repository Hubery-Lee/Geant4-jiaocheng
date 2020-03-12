---
title: Show RunTime and Solve Problem that Data ReadOut Are Disordered in Geant4 Multi-thread Mode
date: 2018-10-16 20:29:30
discription: 
categories: Geant4及Root应用
tags: [Geant]
password: lihuigeant4
messages: Contact lihui to get the password
---

# How to show runtime

## Using G4Timer in RunAction
time count start at the begin of run and stop at the end of run. 
## Detail Consturciton
declare a pionter to G4Timer in construct function.

``` bash
fTimer = new G4Timer;
```

free memory of G4Timer in distruct function

``` bash
delete fTimer;
```

time count start in BeginOfRunAction()

``` bash
fTimer ->Start()
```

time count stop in EndOfRunAction()

``` bash
fTimer ->Stop();
```

## Result Shows
Time used will be showed in the end of run.

```
number of event = ... User=...s Real=...s Sys=...s
```

# Solve Problem that Data ReadOut Are Disordered in Geant4 Multi-thread Mode

## problem discription
 I encountered a problem in Geant4 multi-thread run mode. The data readout from two different sensitive detector with hits  are corrected in single thread mode but disordered  in multi-thread run mode. I don't know how this problem should happen. I think there must be something wrong in the Merge() function. Memory storage may be disordered in the multi-thread mode.
 
## problem solving

Do not use Geant4 Data Merge() in root mode

``` bash
//analysisManager->SetNtupleMerging(true);
//or
analysisManager->SetNtupleMerging(false);
```
