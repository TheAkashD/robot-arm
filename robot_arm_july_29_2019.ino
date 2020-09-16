#include <Servo.h>
 
Servo HeadServo;
Servo ClawServo;
Servo BaseServo;
Servo SideServo;

int pos = 0;
const int BasePot = A4;
const int HeadPot = A5;
int BaseVal, HeadVal, ClawVal;

const int ClawButton = 11;
const int RecButton = 13;
const int PlayButton = 12;

int BasePositions[] = {1, 1, 1, 1, 1};
int HeadPositions[] = {1, 1, 1, 1, 1};
int ClawPositions[] = {1, 1, 1, 1, 1};

int RecButtonPressed;

boolean Play = false;
boolean CloseClaw = false;

void setup() {
  // put your setup code here, to run once:
  HeadServo.attach(3);
  ClawServo.attach(4);
  BaseServo.attach(6);
  
  pinMode(ClawButton, INPUT_PULLUP);
  pinMode(RecButton, INPUT_PULLUP);
  pinMode(PlayButton, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("COM Port 4 Opened Successfully.");
}

void loop() {
  int BaseVal = analogRead(BasePot);
  BaseVal = map(BaseVal, 0, 1023, 0, 180);
  BaseServo.write(BaseVal);

  int HeadVal = analogRead(HeadPot);
  HeadVal = map(HeadVal, 0, 1023, 0, 160);
  HeadServo.write(HeadVal);
  
  if(digitalRead(ClawButton) == LOW){
    CloseClaw = true;
    //Serial.println("CLAW HAS BEEN CLOSED");
    ClawServo.write(120);
  } else {
    CloseClaw = false;
    ClawServo.write(0);
  }

  Serial.println(digitalRead(ClawButton)); //I DON'T TRUST IT
  
  if(digitalRead(RecButton) == LOW){
    RecButtonPressed++;
    switch(RecButtonPressed){
      case 1:
        BasePositions[0] = BaseVal;
        HeadPositions[0] = HeadVal;
        ClawPositions[0] = ClawVal;
        Serial.println("Position #1 Saved");
        delay(1000);
       break;
       case 2:
        BasePositions[1] = BaseVal;
        HeadPositions[1] = HeadVal;
        ClawPositions[1] = ClawVal;
        Serial.println("Position #2 Saved");
        delay(1000);
       break;
       case 3:
        BasePositions[2] = BaseVal;
        HeadPositions[2] = HeadVal;
        ClawPositions[2] = ClawVal;
        //digitalWrite(RedLED, HIGH);
        Serial.println("Position #3 Saved");
        delay(1000);
       break;
       case 4:
        BasePositions[3] = BaseVal;
        HeadPositions[3] = HeadVal;
        ClawPositions[3] = ClawVal;
        //digitalWrite(RedLED, HIGH);
        Serial.println("Position #4 Saved");
        delay(1000);
       break;
       case 5:
        BasePositions[4] = BaseVal;
        HeadPositions[4] = HeadVal;
        ClawPositions[4] = ClawVal;
        Serial.println("Position #5 Saved");
        delay(1000);
       break;
    }
  }

  if(digitalRead(PlayButton) == LOW){
      Play = true;
      Serial.println("MOVE TO POSITIONS");
    }
  
  if(Play){
    for(int i=0; i<5; i++){
      BaseServo.write(BasePositions[i]);
      HeadServo.write(HeadPositions[i]);
      ClawServo.write(ClawPositions[i]);
      delay(2000);
    }
  }
}
