#include <Servo.h>

int servoPin=3;
Servo myServo;
int posA=0;
int posB=180;

int sensorPin=A1;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(servoPin);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorData=  analogRead(sensorPin);//0-23
  //Serial.println(sensorData);
  if(sensorData<350){
    moveSerovo(500);
  } else if (sensorData<450) {
    moveSerovo(1000);
  }else if (sensorData<650) {
    moveSerovo(2000);
  }else{
    stopServo();
  }
}


void moveSerovo(int delayTime){
  myServo.write(posB);
  delay(500);
  myServo.write(posA);
  delay(500);

  delay(delayTime);
}

void stopServo(){
  myServo.write(posA);
  delay(1000);
}
