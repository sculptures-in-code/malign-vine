// Last modifies: 06/10/2019
// Main function for Cellular Automata (CA) LED display
//
// Runs 1 strand representing a vine and 3 strands representing roots on the same brightness CA
// All calculations are done on the vine, then copied backwards onto the first root
// (because the vine and the roots extend in opposite directions from the controller).
// The second and third roots follow 1 and 2 time steps behind the first root
//
// Color and brightness are handled separately. In this version, CAs are applied to brightness only.
//

#include <FastLED.h>
#include "global_defs.h"
#include "ca_helpers.h"
#include "rule_scheduler.h"


void setup() {
  delay( 3000 ); // power-up safety delay

  FastLED.addLeds<WS2812B, VINE_PIN, GRB>(vine, VINE_LEDS);
  FastLED.addLeds<WS2812B, ROOT1_PIN, GRB>(root1, ROOT_LEDS);
  FastLED.addLeds<WS2812B, ROOT2_PIN, GRB>(root2, ROOT_LEDS);
  FastLED.addLeds<WS2812B, ROOT3_PIN, GRB>(root3, ROOT_LEDS);
  
  // set up text output
  //Serial.begin(57600);

  // initialize color from palette
  currentPalette = PartyColors_p;
  currentBlending = LINEARBLEND; 
  for( int i = 0; i < NUM_LEDS; i++) {
        newColors[i] = ColorFromPalette( currentPalette, paletteIndex, 255, currentBlending);
        paletteIndex += paletteStep;
  }

  // initialize brightness
  newBrights[0] = 255;
  for(int i = 1; i < NUM_LEDS; i++) { newBrights[i]=0; }
  //for( int i = 0; i < NUM_LEDS; i++) {Serial.print(newBrights[i]);}
  //Serial.println("");

  // apply color, brightness to the vine
  for(int i = 0; i < VINE_LEDS; i++) { 
    vine[i]=newColors[i];
    vine[i].nscale8(newBrights[i]);
  }
  FastLED.show();

  // set up the rule scheduler
  setRuleIntervals();
  //Serial.print("Current rule: ");
  //Serial.println(currentBrightnessRule);
  startCycle = millis();

}

void loop() {
  // Shift the pattern to next strip
  for(int i = 0; i < ROOT_LEDS; i++) {
    root3[i]=root2[i];            // root 3 gets root 2
    root2[i]=root1[i];            // root 2 gets root 1
    root1[i]=vine[ROOT_LEDS-1-i]; // root 1 gets vine
  }

  // change last step's 'new' color and brightness into 'old' color and brightness
  for(int i = 0; i < NUM_LEDS; i++) { 
    oldBrights[i] = newBrights[i];
    oldColors[i]  = newColors[i];
  }

  // Periodically change the steepness of the color ramp
  adjustPalettePeriodically();

  // Set current brightness rule accoring to schedule
  setCurrentRule();
  //Serial.print("Current rule: ");
  //Serial.println(currentBrightnessRule);
  //Serial.println(timeInCycle);
  
  // apply current CA rule to brightness
  window1DBright();
  //Serial.print("NEW BRIGHTS: ");
  //for( int i = 0; i < NUM_LEDS; i++) {Serial.print(newBrights[i]);}
  //Serial.println("");

  // apply current CA rule to color (not implemented right now)
  // window1DColor();

  // If all LEDs are off, randomly seed a new one
  int sumBrights = 0;
  for(int i=0; i< NUM_LEDS; i++) {sumBrights += newBrights[i];}        
  if(sumBrights==0){ //Serial.println("SEED IT"); 
    newBrights[random(0, NUM_LEDS-1)]= 255; 
  }
  
  // apply new color, brightness vine & kick all to display
  for(int i = 0; i < VINE_LEDS; i++) { 
    vine[i] = newColors[i];
    vine[i].nscale8(newBrights[i]);
    //Serial.print(newBrights[i]);
  }
  //Serial.println("");
  FastLED.show();
  delay(stepTime);

}


void adjustPalettePeriodically()
{  // Modified from ColorPalette example
  
    uint8_t secondHand = (millis() / 1000) % 60;
    static uint8_t lastSecond = 99;
    int changed = 0;
    
    if( lastSecond != secondHand) {
        lastSecond = secondHand;
        if( secondHand ==  0)  { paletteIndex = 0;   paletteStep = 1;   changed = 1; }
        if( secondHand == 10)  { paletteIndex = 8;   paletteStep = 1;   changed = 1; }
        if( secondHand == 15)  { paletteIndex = 15;  paletteStep = 1;   changed = 1; }
        if( secondHand == 20)  { paletteIndex = 0;   paletteStep = 3;   changed = 1; }
        if( secondHand == 25)  { paletteIndex = 8;   paletteStep = 3;   changed = 1; }
        if( secondHand == 30)  { paletteIndex = 15;  paletteStep = 3;   changed = 1; }
        if( secondHand == 35)  { paletteIndex = 0;   paletteStep = 10;  changed = 1; }
        if( secondHand == 40)  { paletteIndex = 8;   paletteStep = 10;  changed = 1; }
        if( secondHand == 45)  { paletteIndex = 15;  paletteStep = 10;  changed = 1; }
        if( secondHand == 50)  { paletteIndex = 0;   paletteStep = 30;  changed = 1; }
        if( secondHand == 55)  { paletteIndex = 15;  paletteStep = 30;  changed = 1; }

        // write to newColors array
        if( changed == 1) {
          for( int i = 0; i < NUM_LEDS; i++) {
            newColors[i] = ColorFromPalette( currentPalette, paletteIndex, 255, currentBlending);
            paletteIndex += paletteStep;  
           }
           //Serial.println("Colors Updated");
        }
        

    }
}
