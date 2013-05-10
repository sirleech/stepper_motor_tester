//////////////////////////////////////////////////////////////////
//©2011 bildr
//Released under the MIT License - Please reuse change and share
//Using the easy stepper with your arduino
//use rotate and/or rotateDeg to controll stepper motor
//speed is any number from .01 -> 1 with 1 being fastest - 
//Slower Speed == Stronger movement
/////////////////////////////////////////////////////////////////

#define DIR_PIN 2
#define STEP_PIN 3
#define RIGHT_BUTTON 4
#define LEFT_BUTTON 6
#define SHIFT_BUTTON 5

int rightButtonState = 0;
int leftButtonState = 0;
int shiftButtonState = 0;
float minSpeed = .1;
float maxSpeed = 3.0;

float speed = 1.00;

void setup() {
  pinMode(DIR_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(RIGHT_BUTTON, INPUT);
  pinMode(LEFT_BUTTON, INPUT);
  pinMode(SHIFT_BUTTON, INPUT);
  pinMode(13, OUTPUT);
} 

void loop(){ 
  digitalWrite(13, LOW);
  rightButtonState = digitalRead(RIGHT_BUTTON);
  leftButtonState = digitalRead(LEFT_BUTTON);
  shiftButtonState = digitalRead(SHIFT_BUTTON);
  
  // increase speed with shift button and left/right
  if (shiftButtonState == HIGH)
    digitalWrite(13, HIGH);
  
  if (rightButtonState == HIGH && shiftButtonState == HIGH && speed <= maxSpeed){
    speed = speed + .05;
    delay(50);
  }   
  	
  if (leftButtonState == HIGH && shiftButtonState == HIGH && speed >= minSpeed){
    speed = speed - .05;
    delay(50);
  }
  
  if (rightButtonState == HIGH && shiftButtonState == LOW){
    digitalWrite(DIR_PIN,HIGH);
    float usDelay = (1/speed) * 70;

    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(usDelay); 
  
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(usDelay);
  }
  
  if (leftButtonState == HIGH && shiftButtonState == LOW){
    digitalWrite(DIR_PIN,LOW);
    float usDelay = (1/speed) * 70;

    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(usDelay); 
  
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(usDelay);
  }
}

