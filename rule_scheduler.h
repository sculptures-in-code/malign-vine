// Last modified: 06/10/2019
// Specifies which CA rules are applied and when.
//
// I don't have enough time to randomize the order of the patterns right now, so I'm specifying a
// repeating cycle made up of several sub-cycles.
// The structure of each sub-cycle is as follows:
// 1. Expand a pattern across the LED strips (duration: tMaxLong)
// 2. Run another full-strip pattern         (duration: tMaxLong)
// 3. Reduce to a static pattern             (duration: tMaxShort)
// 4. Fade in or out                         (duration: tMaxShort)


// Define intervals within the cycle
void setRuleIntervals() {
  int nRuleChanges = 12; // make this global
  long cumulativeTime = 0;
  //Serial.println("cumulative time:");
  //Serial.print(cumulativeTime);
  
  for(int i=0; i< nRuleChanges; i+=4){
    cumulativeTime = cumulativeTime + tMaxPat1;
    ruleIntervals[i] = cumulativeTime;
    
    cumulativeTime = cumulativeTime + tMaxPat2;
    ruleIntervals[i+1] = cumulativeTime;
    
    cumulativeTime = cumulativeTime + tMaxPat3;
    ruleIntervals[i+2] = cumulativeTime;
    
    cumulativeTime = cumulativeTime + tMaxPat4;
    ruleIntervals[i+3] = cumulativeTime;
  }
}

// Based on interval, assign CA rule
void setCurrentRule() {
  timeInCycle = millis()- startCycle;
  //Serial.print("millis: ");
  //Serial.println(millis());
  //Serial.print("Time in Cycle: ");
  //Serial.println(timeInCycle);
  
  //Serial.print("Rule Intervals: ");
  //for(int i = 0; i < 4; i++){Serial.print(ruleIntervals[i]); Serial.print(" ");}
  //Serial.println("");

  // SUB-CYCLE 1
  if(0 <= timeInCycle && timeInCycle < ruleIntervals[0]){ currentBrightnessRule=124;
    if(reSeedLEDs==1){
      for( int i = 0; i < NUM_LEDS; i++) {newBrights[i]=0;} 
      newBrights[0] = 255;
      reSeedLEDs=0; 
    }
  }  // fractal
  if(ruleIntervals[0] <= timeInCycle && timeInCycle < ruleIntervals[1]) { currentBrightnessRule=169; } // travelling chaotic
  if(ruleIntervals[1] <= timeInCycle && timeInCycle < ruleIntervals[2]) { currentBrightnessRule=188; } // static simple 
  if(ruleIntervals[2] <= timeInCycle && timeInCycle < ruleIntervals[3]) { currentBrightnessRule=160; 
    reSeedLEDs = 1;
  } // fade out

  // SUB-CYCLE 2
  if(ruleIntervals[3] <= timeInCycle && timeInCycle < ruleIntervals[4]) { currentBrightnessRule=150;   // fractal
    if(reSeedLEDs==1){
      for( int i = 0; i < NUM_LEDS; i++) {newBrights[i]=0;} 
      newBrights[40] = 255;
      reSeedLEDs=0;
    }
  }                                                                                                    
  if(ruleIntervals[4] <= timeInCycle && timeInCycle < ruleIntervals[5]) { currentBrightnessRule=90;  } // chaotic
  if(ruleIntervals[5] <= timeInCycle && timeInCycle < ruleIntervals[6]) { currentBrightnessRule=84;  } // weird travelling striptes
  if(ruleIntervals[6] <= timeInCycle && timeInCycle < ruleIntervals[7]) { currentBrightnessRule=235; 
    reSeedLEDs = 1;                                                                                  } // fade in

  // SUB-CYCLE 3
  if(ruleIntervals[7] <= timeInCycle && timeInCycle < ruleIntervals[8]) { currentBrightnessRule=110;   // constant stripe fill
    if(reSeedLEDs==1){
      for( int i = 0; i < NUM_LEDS; i++) {newBrights[i]=0;} 
      newBrights[NUM_LEDS-1] = 255;
      reSeedLEDs=0;
    }
  }
  if(ruleIntervals[8] <= timeInCycle && timeInCycle < ruleIntervals[9])   { currentBrightnessRule=150; }  // chaotic
  if(ruleIntervals[9] <= timeInCycle && timeInCycle < ruleIntervals[10])  { currentBrightnessRule=73;  }  //chaotic
  if(ruleIntervals[10] <= timeInCycle && timeInCycle < ruleIntervals[11]) { currentBrightnessRule=160; }  // fade out
  
  if(timeInCycle >= ruleIntervals[11]) { startCycle = millis(); 
    //Serial.println("NEW CYCLE!"); 
  } // start new cycle
   
} // end setCurrentRule
