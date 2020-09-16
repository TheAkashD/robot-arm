#include <Servo.h>

Servo ser0;
Servo ser1;
Servo ser2;
Servo ser3;

#define Pot0 A0
#define Pot1 A1
#define Pot2 A2
#define Pot3 A3

#define PlayButton 7
#define RecButton 6

int ser0Pos[] = {1, 1, 1, 1, 1};
int ser1Pos[] = {1, 1, 1, 1, 1};
int ser2Pos[] = {1, 1, 1, 1, 1};
int ser3Pos[] = {1, 1, 1, 1, 1};

int RecButtonPressed;
bool Play = false;

void setup() {
  // put your setup code here, to run once:
  ser0.attach(8); //base
  ser1.attach(9); //right
  ser2.attach(10); //claw
  ser3.attach(11); //left

  pinMode(RecButton, INPUT_PULLUP);
  pinMode(PlayButton, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val0 = analogRead(Pot0);
  val0 = map(val0,0,1023,0,180);
  ser0.write(val0);

  int val1 = analogRead(Pot1);
  val1 = map(val1,0,1023,0,180);
  ser1.write(val1);

  int val2 = analogRead(Pot2);
  val2 = map(val2,0,1023,0,180);
  ser2.write(val2);

  int val3 = analogRead(Pot3);
  val3 = map(val3,0,1023,0,180);
  ser3.write(val3);

  delay(15);
}

//  if(digitalRead(RecButton) == LOW){
//    RecButtonPressed++;
//    switch(RecButtonPressed){
//      case 1:
//        ser0Pos[0] = val0;
//        ser0Pos[0] = val1;
//        ser0Pos[0] = val2;
//        ser0Pos[0] = val3;
//        Serial.println("Position #1 Saved");
//        delay(1000);
//       break;
//       case 2:
//        ser0Pos[1] = val0;
//        ser0Pos[1] = val1;
//        ser0Pos[1] = val2;
//        ser0Pos[1] = val3;
//        Serial.println("Position #2 Saved");
//        delay(1000);
//       break;
//       case 3:
//        ser0Pos[2] = val0;
//        ser0Pos[2] = val1;
//        ser0Pos[2] = val2;
//        ser0Pos[2] = val3;
//        Serial.println("Position #3 Saved");
//        delay(1000);
//       break;
//       case 4:
//        ser0Pos[3] = val0;
//        ser0Pos[3] = val1;
//        ser0Pos[3] = val2;
//        ser0Pos[3] = val3;
//        Serial.println("Position #4 Saved");
//        delay(1000);
//       break;
//       case 5:
//        ser0Pos[4] = val0;
//        ser0Pos[4] = val1;
//        ser0Pos[4] = val2;
//        ser0Pos[4] = val3;
//        Serial.println("Position #5 Saved");
//        delay(1000);
//       break;
//    }
//  }


//  if(digitalRead(PlayButton) == HIGH){
//      Play = true;
//      Serial.println("MOVE TO POSITIONS");
//    }
//  
//  if(Play){
//    for(int i=0; i<5; i++){
//      ser0.write(ser0Pos[i]);
//      ser1.write(ser1Pos[i]);
//      ser2.write(ser2Pos[i]);
//      ser3.write(ser3Pos[i]);
//      delay(2000);
//    }
//  }
