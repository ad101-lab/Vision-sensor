/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\adick                                            */
/*    Created:      Thu Mar 12 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Vision1              vision        1               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  while(1 == 1){
    task::sleep(90);
    Vision1.takeSnapshot(Vision1__BLUE_BOX); 
    if(Vision1.objects[0].exists){
      Brain.Screen.clearScreen();
      Brain.Screen.setCursor(1, 1);
      Brain.Screen.print("X: %d, Y: %d,Width: %d, Height: %d",Vision1.largestObject.centerX,Vision1.largestObject.centerY,Vision1.largestObject.width, Vision1.largestObject.height);
      if(Vision1.largestObject.centerX>=170){
        Brain.Screen.newLine();
        Brain.Screen.print("Go Right");
      } else if(Vision1.largestObject.centerX<=130){
        Brain.Screen.newLine();
        Brain.Screen.print("Go Left");
      } else{
        Brain.Screen.newLine();
        Brain.Screen.print("In the middle");
      }
      if(Vision1.largestObject.width>=180){
        Brain.Screen.newLine();
        Brain.Screen.print("Too CLose");
      } else if(Vision1.largestObject.centerX<=160){
        Brain.Screen.newLine();
        Brain.Screen.print("Too Far");
      } else{
        Brain.Screen.newLine();
        Brain.Screen.print("Just Right");
      }
    }else{
      Brain.Screen.clearScreen();
      Brain.Screen.setCursor(1, 1);
      Brain.Screen.print("No Object Detected");
    }
  }
}