// Last modified: 06/10/2019
// Global definitions for CA and associated .h files

#define VINE_PIN   1
#define ROOT1_PIN  2
#define ROOT2_PIN  5
#define ROOT3_PIN  6
#define NUM_LEDS    90 // number of LEDs in longest strip
#define VINE_LEDS   NUM_LEDS
#define ROOT_LEDS   60
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB

// LED array
CRGB vine[VINE_LEDS];
CRGB root1[ROOT_LEDS];
CRGB root2[ROOT_LEDS];
CRGB root3[ROOT_LEDS];
int n_roots = 3;

// color and brightness information
int oldBrights[VINE_LEDS];
int newBrights[VINE_LEDS]; 
CRGB oldColors[VINE_LEDS];
CRGB newColors[VINE_LEDS];

// Color palette and blending
CRGBPalette16 currentPalette;
TBlendType    currentBlending;
int paletteIndex = 0;
int paletteStep  = 3;

// Cellular Automaton Rules
int currentBrightnessRule=124;
int currentColorRule=1;

// Boundary Conditions-- What happens at the end of the strip?
// *Bound = -1            : treat strip as a circle (1st, last LEDs are neighbors) 
// Otherwise, hold strip constant at user-defined value
long brightBound = -1;
long colorBound  = -1; // color code from FastLED (hexadecimal)

// Rule Scheduling
int stepTime=400;      // delay between LED update
int  tMaxPat1 = 60000; // some patterns look good indefinitely 
int  tMaxPat2 = 60000; // some look good for awhile
int  tMaxPat3 = 4000;  // some get boring
int  tMaxPat4 = 4000;  // some only look good for a couple seconds
long ruleIntervals[12]; // 2 sub-cycles, x 4 parts each = 8
long startCycle  = 0;
long timeInCycle = 0; // how long has the program spent in the current cycle?
int  reSeedLEDs = 1;  // re-seed from a known LED
