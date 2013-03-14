/*
 RGB led driver 
 
 This example code is in the public domain.
*/


const byte ledR = 9;    // LED connected to digital pin 9
const byte ledV = 10;
const byte ledB = 11;
byte Rouge;
byte Vert;
byte Bleu;


void setup()  { 
  // IO setup
  pinMode(ledR, OUTPUT); 
  pinMode(ledV, OUTPUT); 
  pinMode(ledB, OUTPUT); 
  // serial setup
  Serial.begin(9600);
  // random init : analog input 0 should be unconnect
  randomSeed(analogRead(0));
  // set slow RED at startup
  for(int i = 0 ; i < 255; i++) { 
    Rouge++;
    analogWrite(ledR, Rouge);           
    delay(30);
  }
} 

void loop()  { 
  // init cyle
  Rouge = 255;
  Vert  = 0;
  Bleu  = 0;
  // cycle
  for(int colorIndex = 0 ; colorIndex <= 255 * 6; colorIndex++) { 
    if (colorIndex < 255) {
      Vert++; 
    } else if (colorIndex < 255 * 2) {
      Rouge--;
    } else if (colorIndex < 255 * 3) {
      Bleu++;
    } else if (colorIndex < 255 * 4) {
      Vert--;
    } else if (colorIndex < 255 * 5) {
      Rouge++;
    } else if (colorIndex < 255 * 6) {
      Bleu--;
    } 
  analogWrite(ledR, Rouge);         
  analogWrite(ledV, Vert);         
  analogWrite(ledB, Bleu);        
  delay(30); 
  }
}
