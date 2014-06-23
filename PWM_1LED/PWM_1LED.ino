

int LED1 = 11;
int LED2 = 10;

int DELAY = 5;

void setup() {
 // Only 1 LED for now
 pinMode(LED, OUTPUT); 
}

void loop() {

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
