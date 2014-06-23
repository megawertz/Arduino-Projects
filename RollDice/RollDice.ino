/**************** 
 *
 * Arduino 7-segment LED dispaly d6 roller 
 * With button and piezo speaker
 *
 ****************/

#define A 8
#define B 9
#define C 2
#define D 3
#define E 4
#define FF 7 // Why can't I name this F?
#define DP 5 // Decimal point
#define G 6
#define POWER 13
#define BUTTON 12
#define SPEAKER 11
#define SEGMENTS 10

#define FIRSTPIN 2

int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
//            mid C  C#   D    D#   E    F    F#   G    G#   A

void drawNumber(int num) {
  if(num < 0 || num > 6) {
    return;
  }
    
  // Initialize numbers
  int myNums[7][SEGMENTS] = { 
                        {0,0,1,1,1,0,0,1,1,1}, // 0
                        {0,0,1,0,0,0,0,0,0,1}, // 1
                        {0,0,0,1,1,0,1,0,1,1}, // 2
                        {0,0,1,1,0,0,1,0,1,1}, // 3
                        {0,0,1,0,0,0,1,1,0,1}, // 4
                        {0,0,1,1,0,0,1,1,1,0}, // 5                                                
                        {0,0,1,1,1,0,1,1,1,0}, // 6 
                      };

  
  for (int i = FIRSTPIN; i < SEGMENTS; i++) {
    if(myNums[num][i] == 0) {
      digitalWrite(i, HIGH); 
    }
    if(myNums[num][i] == 1) {
     digitalWrite(i, LOW); 
    }
  }
}

void spin() {
  int timesToSpin = 3;
  int spinDelay = 90;
  turnAllOff();
 
  int nums[SEGMENTS] = {0,0,1,1,1,0,0,1,1,1};
 
  for(int j = 0; j < timesToSpin ; j++) {
    for (int i = FIRSTPIN; i < SEGMENTS; i++) { 
      tone(SPEAKER, tones[i]);
      digitalWrite(i-1,HIGH); // Turn off the one behind us
      if(nums[i] == 1) {
       digitalWrite(i, LOW); 
       delay(spinDelay);
      }
    }
    digitalWrite(SEGMENTS-1,HIGH);
    noTone(SPEAKER);
  }
}

void turnAllOff() {
    for (int i = FIRSTPIN; i < SEGMENTS; i++) { 
      digitalWrite(i,HIGH);
    }
}

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(FF, OUTPUT);
  pinMode(DP, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(POWER, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  
  digitalWrite(POWER, HIGH);
  randomSeed(analogRead(0));
  turnAllOff();
}

void loop() {
  if(digitalRead(BUTTON) == LOW) {
    spin();
    drawNumber(random(1, 7));
  }
}
