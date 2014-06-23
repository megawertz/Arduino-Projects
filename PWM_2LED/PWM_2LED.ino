

int LED1 = 11;
int LED2 = 10;

int DELAY = 5;

void setup() {
 // 2 LEDs
 pinMode(LED1, OUTPUT); 
 pinMode(LED2, OUTPUT);
}

void loop() {
  // Alternating
  //pulseLED(LED1,DELAY);
  //pulseLED(LED2,DELAY);
  
  // Pulse 2
  int leds[] = {LED1, LED2};
  int sizeof_leds = (sizeof(leds)/sizeof(int));
  
//  Serial.begin(9600);
//  Serial.print(sizeof_leds);
  
  pulseLEDArray(leds, DELAY, sizeof_leds);
  delay(500);
}

void pulseLED(int led, int del) {
   for(int i = 0 ; i < 256 ; i++) {
     analogWrite(led,i);
     delay(del);
   } 
  
   for(int i = 255 ; i >= 0 ; i--) {
     analogWrite(led,i);
     delay(del);
   } 
}

void pulseLEDArray(int l[], int d, int sizeof_l) {
    for(int i = 0 ; i < 256 ; i++) {
     for(int j = 0 ; j < sizeof_l ; j++) {
       analogWrite(l[j],i);
     }
     delay(d);
   } 
  
   for(int i = 255 ; i >= 0 ; i--) {
     for(int j = 0 ; j < sizeof_l ; j++) {
       analogWrite(l[j],i);
     }
     delay(d);
   } 
}
