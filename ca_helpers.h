// Last modified: 06/08/2019
// helper functions for the Cellular Automaton main loop

#include "brightness_rules.h"
#include "color_rules.h"

void window1DBright();
void window1DColor();
int applyBrightness(CRGB leftNeighbor, CRGB self, CRGB rightNeighbor);
CRGB applyColor(CRGB leftNeighbor, CRGB self, CRGB rightNeighbor);


// Run a 3-LED moving window down the brightess array, to (a) determine each cell's neighborhood and (b)
// apply the current brightness CA rule
void window1DBright(){
  //Serial.println("New call to window1D BRIGHTNESS");
  //Serial.print("Boundary condition is ");
  //Serial.println(brightBound);

  // variables to store values in the neighborhood
  int leftNeighbor  = -1;
  int self          = -1;
  int rightNeighbor = -1;

  for(int i = 0; i < NUM_LEDS; i++) {
      // Get neighborhood for LED i
      self = oldBrights[i];

      if (i==0) { // first LED in strip
        if(brightBound < 0) {leftNeighbor  = oldBrights[NUM_LEDS-1];}
        else {leftNeighbor = brightBound;}
        rightNeighbor = oldBrights[i+1];
      }
      else if (i==NUM_LEDS-1) { // last LED in strip
        if(brightBound < 0) {rightNeighbor = oldBrights[0];}
        else {rightNeighbor=brightBound;}
        leftNeighbor  = oldBrights[i-1];
      }
      else{// LED in middle of strip
        leftNeighbor  = oldBrights[i-1];
        rightNeighbor = oldBrights[i+1];
      }

      //Serial.print(leftNeighbor);
      //Serial.print(" ");
      //Serial.print(self);
      //Serial.print(" ");
      //Serial.println(rightNeighbor);

      // apply brightness CA rule
      newBrights[i] = applyBrightness(leftNeighbor, self, rightNeighbor);
      
    } // end for
  
} // end window1DBright


// Run a 3-LED moving window down the color array, to (a) determine each cell's neighborhood and (b)
// apply the current color CA rule
void window1DColor(){
  //Serial.println("New call to window1D COLOR");
  //Serial.print("Boundary condition is ");
  //Serial.println(colorBound);

  // variables to store values in the neighborhood
  CRGB leftNeighbor  = CRGB::Black;
  CRGB self          = CRGB::Black;
  CRGB rightNeighbor = CRGB::Black;

  for(int i = 0; i < NUM_LEDS; i++) {
      self = oldColors[i];

      if (i==0) { // first LED in strip
        if(colorBound < 0) {leftNeighbor  = oldColors[NUM_LEDS-1];}
        else {leftNeighbor = colorBound;}
        rightNeighbor = oldColors[i+1];
      }
      else if (i==NUM_LEDS-1) { // last LED in strip
        if(colorBound < 0) {rightNeighbor = oldColors[0];} 
        else {rightNeighbor=colorBound;}
        leftNeighbor  = oldColors[i-1];
      }
      else{ // LED in middle of strip
        leftNeighbor  = oldColors[i-1];
        rightNeighbor = oldColors[i+1];
      }

      // apply color CA rule
      newColors[i] = applyColor(leftNeighbor, self, rightNeighbor);      
      
    } // end for

} // end window1DColor


// Apply the current brightness rule to the strip
int applyBrightness(CRGB leftNeighbor, CRGB self, CRGB rightNeighbor) {

  int new_brightness = -1;
  switch(currentBrightnessRule) {
    case 73:
      new_brightness = rule73(leftNeighbor, self, rightNeighbor);
      break;
    case 84:
      new_brightness = rule84(leftNeighbor, self, rightNeighbor);
      break;
    case 90:
      new_brightness = rule90(leftNeighbor, self, rightNeighbor);
      break;
    case 110:
      new_brightness = rule110(leftNeighbor, self, rightNeighbor);
      break;
    case 124:
      new_brightness = rule124(leftNeighbor, self, rightNeighbor);
      break;
    case 150:
      new_brightness = rule150(leftNeighbor, self, rightNeighbor);
      break;
    case 157:
      new_brightness = rule157(leftNeighbor, self, rightNeighbor);
      break;
    case 160:
      new_brightness = rule160(leftNeighbor, self, rightNeighbor);
      break;
    case 168:
      new_brightness = rule168(leftNeighbor, self, rightNeighbor);
      break;
    case 169:
      new_brightness = rule169(leftNeighbor, self, rightNeighbor);
      break;
    case 181:
      new_brightness = rule181(leftNeighbor, self, rightNeighbor);
      break;
    case 188:
      new_brightness = rule188(leftNeighbor, self, rightNeighbor);
      break;
    case 194:
      new_brightness = rule194(leftNeighbor, self, rightNeighbor);
      break;
    case 216:
      new_brightness = rule216(leftNeighbor, self, rightNeighbor);
      break;
    case 232:
      new_brightness = rule232(leftNeighbor, self, rightNeighbor);
      break;
    case 235:
      new_brightness = rule235(leftNeighbor, self, rightNeighbor);
      break;
    default:
      break;
  } // end switch

  return(new_brightness);
} // end applyBrightness


// Apply the current color rule to the strip
CRGB applyColor(CRGB leftNeighbor, CRGB self, CRGB rightNeighbor) {
  
  CRGB new_color = -1;
  
  switch(currentColorRule) {
    case 1:
      new_color = noChange(self);
      break;
    default:
      break;
  } // end switch

  return(new_color);
} // end applyColor
