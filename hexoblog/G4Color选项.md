---
title: G4Color选项
date: 2018-09-09 18:53:53
tags: [Geant4]
categories: Geant4及Root应用
discription: 本文介绍geant4的颜色配置选项
---

## 颜色的配置

Geant4中的颜色配置由红、绿、蓝、是否透明四个构成；red、green、blue、alpha(opacity/opaque)
``` bash
G4Colour::G4Colour ( G4double  r = 1.0,
		     G4double  g = 1.0,
		     G4double  b = 1.0,
                     G4double  a = 1.0);
                 //0<=red, green, blue <= 1.0

```

## 颜色的实例化应用

1.颜色配置实例化
``` bash
G4Colour  white  ();  //white
G4Colour  white  (1.0,1.0,1.0);  //white
G4Colour  gray   (0.5,0.5,0.5);  //gray
G4Colour  black  (0.0,0.0,0.0);	 //black
G4Colour  red    (1.0,0.0,0.0);  //red
G4Colour  green  (0.0,1.0,0.0);  //green
G4Colour  blue   (0.0,0.0,1.0);  //blue
G4Colour  cyan   (0.0,1.0,1.0);	 //cyan
G4Colour  magenta(1.0,0.0,1.0);  //magenta
G4Colour  yellow (1.0,1.0,0.0);  //yellow
```
example 
``` bash
  G4VisAttributes* Assemble_VisAtt= new G4VisAttributes(G4Colour(0.0,0.0,1.0));//blue
```

2.静态公用数据函数实例化
``` bash
static const G4Colour& White   ();
static const G4Colour& Gray    ();
static const G4Colour& Grey    ();
static const G4Colour& Black   ();
static const G4Colour& Red     ();
static const G4Colour& Green   ();
static const G4Colour& Blue    ();
static const G4Colour& Cyan    ();
static const G4Colour& Magenta ();
static const G4Colour& Yellow  ();
```
example
``` bash
G4Colour myRed(G4Colour::Red());
```
实例化Colour对象后，可以采用如下方式获得函数
``` bash
G4double G4Colour::GetRed   () const;
G4double G4Colour::GetGreen () const;
G4double G4Colour::GetBlue  () const;
```

## Colour Map的应用

```
G4String		G4Colour
---------------------------------------
white			G4Colour::White	()
gray			G4Colour::Gray	()
grey			G4Colour::Grey	()
black			G4Colour::Black	()
red			G4Colour::Red	()
green			G4Colour::Green	()
blue			G4Colour::Blue	()
cyan			G4Colour::Cyan	()
magenta			G4Colour::Magenta ()
yellow			G4Colour::Yellow ()
```

Colours的检索可以采用如下方式
``` bash
bool G4Colour::GetColour(const G4String& key, G4Colour& result)
```
example
``` bash
G4Colour myColour(G4Colour::Black());
if (G4Colour::GetColour("red", myColour)) {
// Successfully retrieved colour "red". myColour is now red
}
else {
// Colour did not exist in map. myColour is still black
}
```
