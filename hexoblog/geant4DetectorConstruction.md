---
title: geant4DetectorConstruction
date: 2018-09-11 11:39:07
tags: [geant4]
categories: Geant4及Root应用
---

## geant detector construction

1. 几何旋转符合`左手法则`及RotationMatrix的使用
经过验证geant4中的rotate符合`左手法则`

``` bash
  G4RotationMatrix *rot=new G4RotationMatrix;
  rot->rotateX(90*degree);
  rot->rotateY(90*degree);
  rot->rotateZ(90*degree);
```

注意，再次对rot重复赋值无效，如对上述代码再作如下操作`rot->rotateX(180*degree)`,该操作将无效，不会改变之前的rot；
那么，要对rot再次赋值该怎么办呢？如下：只需在再次赋值前加`rot =new G4RotationMatrix`即可；
```bash
  G4RotationMatrix* rotationMatrix_X = new G4RotationMatrix;

  for(G4int x_col_num = 0; x_col_num <=NBD_colNb; x_col_num++){
    if(x_col_num==0){  // the center colume
      NBDx = NBDx0;
      for(G4int y_row_num = 0; y_row_num <=NBD_rowNb; y_row_num++ ){
	// NBDx = NBDx0;
	NBDy = NBDy0+R*sin(y_row_num*theta);
	NBDz = NBDz0+R*(1-cos(y_row_num*theta));

	if(y_row_num==0){
	  // center position
	  rotationMatrix_X = new G4RotationMatrix;
	  rotationMatrix_X->rotateX(y_row_num*theta);

	  new G4PVPlacement(rotationMatrix_X,                      //no rotation
			    G4ThreeVector(NBDx,NBDy,NBDz),       //at (0,0,0)
			    logicAssembleNBD,                    //its logical volume
			    "AssembleNBD",         //its name
			    expHall_logV,          //its mother  volume
			    false,                 //no boolean operation
			    0,                     //copy number
			    true);                    //overlaps checking    
	}
	else{
	  //+y++
	  rotationMatrix_X = new G4RotationMatrix;
	  rotationMatrix_X->rotateX(-y_row_num*theta);

	  new G4PVPlacement(rotationMatrix_X,                      //no rotation
			    G4ThreeVector(NBDx,NBDy,NBDz),       //at (0,0,0)
			    logicAssembleNBD,                    //its logical volume
			    "AssembleNBD",         //its name
			    expHall_logV,          //its mother  volume
			    false,                 //no boolean operation
			    0,                     //copy number
			    true);               // overlaps checking 
	  //-y++
	  rotationMatrix_X = new G4RotationMatrix;
	  rotationMatrix_X->rotateX(y_row_num*theta);
	  new G4PVPlacement(rotationMatrix_X,                      //no rotation
			    G4ThreeVector(NBDx,-NBDy,NBDz),       //at (0,0,0)
			    logicAssembleNBD,                    //its logical volume
			    "AssembleNBD",         //its name
			    expHall_logV,          //its mother  volume
			    false,                 //no boolean operation
			    0,                     //copy number
			    true);               // overlaps checking    
	}
      }
...

```

2. G4VParameterisation()的使用

* `ComputeTransformation` defines where one of the copies is placed
* `ComputeDimensions` defines the size of one copy, and a constructor that initializes any member variables that are required.

G4VParameterisation的具体应用可参看Basics/B2/B2b
