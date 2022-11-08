// Last modified: 06/10/2019
// Cellular automaton rules for brightness display
// SOURCE: wolframalpha.com

/* 1 DDIMENSIONAL BINARY CA TEMPLATE

// Scale LED brightness to 0 or 255 according to Binary CA Rule ???
// Good for: 
int rule???(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return();   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return();   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return();   }
}// end rule ???

*/

// Scale LED brightness to 0 or 255 according to Binary CA Rule 73
// Good for: full strip. CAUTION: FLASHING IF INITIALIZED WITH 1 CELL
int rule73(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(0);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(255); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(0);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(255);   }
}// end rule 73

// Scale LED brightness to 0 or 255 according to Binary CA Rule 84
// Good for: full strip
int rule84(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(0);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(255); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(255);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(255); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
}// end rule 84

// Scale LED brightness to 0 or 255 according to Binary CA Rule 90
// Good for: sweep from middle with 'on' seed, full strip
int rule90(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(0);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(255); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(255);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
}// end rule 90


// Scale LED brightness to 0 or 255 according to Binary CA Rule 106
// Good for: full strip
int rule106(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(0);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(255); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(0);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
}// end rule 106


// Scale LED brightness to 0 or 255 according to Binary CA Rule 110
// Good for: sweep from far end with 'on' seed, full strip
int rule110(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(0);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(255); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(0);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(255); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
}// end rule 110


// Scale LED brightness to 0 or 255 according to Binary CA Rule 124
// Good for: sweep from near end with 'on' seed, full strip
int rule124(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(0);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(255); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(255);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(255); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
}// end rule 124


// Scale LED brightness to 0 or 255 according to Binary CA Rule 135
// Good for: sweep from middle with 'off' seed, full strip
int rule135(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(255);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(0);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(255); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(255);   }
}// end rule 135


// Scale LED brightness to 0 or 255 according to Binary CA Rule 150
// Good for: sweep from middle with 'on' seed, full strip
int rule150(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(255);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(255);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(255); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
}// end rule 150


// Scale LED brightness to 0 or 255 according to Binary CA Rule 157
// Good for: constant fill from far end
int rule157(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(255);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(255);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(255); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(255);   }
}// end rule 157


// Scale LED brightness to 0 or 255 according to Binary CA Rule 160
// Good for: Fade out
int rule160(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(255);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(0);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
}// end rule 160


// Scale LED brightness to 0 or 255 according to Binary CA Rule 168
// Good for: Fade out 
int rule168(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(255);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(0);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
}// end rule 168

// Scale LED brightness to 0 or 255 according to Binary CA Rule 169
// Good for: single traveling stripe, full strip
int rule169(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(255);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(0);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(255);   }
}// end rule 169


// Scale LED brightness to 0 or 255 according to Binary CA Rule 181
// Good for: Sweep from 'on' seed, 'off' seed; full strip
int rule181(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(255);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(255);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(255); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(255);   }
}// end rule 181


// Scale LED brightness to 0 or 255 according to Binary CA Rule 182
// Good for: sweep from middle with 'on' seed, full CA
int rule182(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(255);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(255);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(255); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
}// end rule 182


// Scale LED brightness to 0 or 255 according to Binary CA Rule 188
// Good for: Sweep from near end with 'on' seed, travelling stripe
int rule188(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(255);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(255);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(255); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
}// end rule 188


// Scale LED brightness to 0 or 255 according to Binary CA Rule 194
// Good for: Static with blinking
int rule194(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(255);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(255); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(0);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
}// end rule 194


// Scale LED brightness to 0 or 255 according to Binary CA Rule 216
// Good for: static, mostly on
int rule216(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(255);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(255); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(255);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
}// end rule 216

// Scale LED brightness to 0 or 255 according to Binary CA Rule 224
// Good for: Fade out 
int rule224(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(255);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(255); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(0);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
}// end rule 224


// Scale LED brightness to 0 or 255 according to Binary CA Rule 232
// Good for: Static
int rule232(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(255);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(255); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(0);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
}// end rule 232


// Scale LED brightness to 0 or 255 according to Binary CA Rule 235
// Good for: 
int rule235(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(255);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(255); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(0);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(255);   }
}// end rule 235


// Scale LED brightness to 0 or 255 according to Binary CA Rule 248
// Good for: Fade in
int rule248(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(255);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(255); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(255);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(0);   }
}// end rule 248


// Scale LED brightness to 0 or 255 according to Binary CA Rule 249
// Good for: Fade in
int rule249(int leftNeighbor, int self, int rightNeighbor) {

  if(leftNeighbor!=0 && self!=0 && rightNeighbor!=0){ return(255);   }
  if(leftNeighbor!=0 && self!=0 && rightNeighbor==0){ return(255); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor!=0 && self==0 && rightNeighbor==0){ return(255);   }
  if(leftNeighbor==0 && self!=0 && rightNeighbor!=0){ return(255); }
  if(leftNeighbor==0 && self!=0 && rightNeighbor==0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor!=0){ return(0); }
  if(leftNeighbor==0 && self==0 && rightNeighbor==0){ return(255);   }
}// end rule 249
