//define sensor 
const int frontTrigPin=7;
const int frontEchoPin=9;
const int sideTrigPin=11;
const int sideEchoPin=12;
//define motor pins
const int motor1Pin1=3;//right motor//input3
const int motor1Pin2=4;//right motor//input4
const int motor2Pin1=13;//left motor//input1
const int motor2Pin2=10;//left motor//input2
//define enable pins
const int enable1Pin=5;//right_B
const int enable2Pin=6;//left_A
//define LED pin
const int ledPin=8;
//degrees turned
int degree=0;
bool flag=false;

void setup() {
  Serial.begin(9600);
  //initialise sensors
  pinMode(frontTrigPin,OUTPUT);
  pinMode(frontEchoPin,INPUT);  
  pinMode(sideTrigPin,OUTPUT);
  pinMode(sideEchoPin,INPUT);
  //initialise motors
  pinMode(motor1Pin1,OUTPUT);
  pinMode(motor1Pin2,OUTPUT);
  pinMode(motor2Pin1,OUTPUT);
  pinMode(motor2Pin2,OUTPUT);
  //initialise LED
  pinMode(ledPin,OUTPUT);
  //inititalise enable pins
  pinMode(enable1Pin,OUTPUT);
  pinMode(enable2Pin,OUTPUT);
}

void loop() {
  digitalWrite(ledPin,LOW); 
  //measure distance
  int frontDistance=getDistance(frontTrigPin,frontEchoPin);
  int sideDistance=getDistance(sideTrigPin,sideEchoPin);
  //moveForward();
  //checking conditions
 // moveForward();
  /*while(frontDistance<30 && frontDistance){
    turnLeftwards();
  }*/
  
  if(degree>=360){
    stopMoving();
  }

  if(frontDistance>5 && frontDistance<=10){
    //concave turn
    delay(500);
    digitalWrite(ledPin,HIGH);
    moveBackwards();
    concaveLeftwards();
    delay(500);
    flag=true;
    degree-=40;
    digitalWrite(ledPin,LOW);
  }
  else if(sideDistance<frontDistance && sideDistance<=20 && sideDistance>=15){
    moveForward();
  }
  else if(sideDistance<=15){
    delay(500);
    turnLeftwards();
    degree-=20;
  }
  else if(sideDistance>20 && frontDistance>30){
    //non concave turn
    delay(500);
    moveForward();
    turnRightwards();
    degree+=20;
  }
  else if(sideDistance>50 && frontDistance>50)
  {
    delay(500);
    moveBackwards();

  }
  else{
    delay(500);
    moveBackwards();
  }
  delay(500);
}
int getDistance(int trigPin,int echoPin){
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  return pulseIn(echoPin,HIGH)/2*0.034; //returns distance in cm
} 

//movement functions
void moveForward(){
  digitalWrite(motor1Pin1,HIGH);
  digitalWrite(motor1Pin2,LOW);
  digitalWrite(motor2Pin1,HIGH);
  digitalWrite(motor2Pin2,LOW);
  analogWrite(enable1Pin,162);
  analogWrite(enable2Pin,170);
  }
void turnRightwards(){
    digitalWrite(motor1Pin1,LOW);
    digitalWrite(motor1Pin2,LOW);
    digitalWrite(motor2Pin1,HIGH);
    digitalWrite(motor2Pin2,LOW);
    analogWrite(enable2Pin,150);

  }
void turnLeftwards(){
    digitalWrite(motor1Pin1,HIGH);
    digitalWrite(motor1Pin2,LOW);
    digitalWrite(motor2Pin1,LOW);
    digitalWrite(motor2Pin2,LOW);
    analogWrite(enable1Pin,142);
  }
void concaveLeftwards(){
    digitalWrite(motor1Pin1,HIGH);
    digitalWrite(motor1Pin2,LOW);
    digitalWrite(motor2Pin1,LOW);
    digitalWrite(motor2Pin2,HIGH);
    analogWrite(enable1Pin,142);
}
void moveBackwards(){
  digitalWrite(motor1Pin1,LOW);
  digitalWrite(motor1Pin2,HIGH);
  digitalWrite(motor2Pin1,LOW);
  digitalWrite(motor2Pin2,HIGH);
  analogWrite(enable1Pin,122);
  analogWrite(enable2Pin,130);

}
void stopMoving(){
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
    if(flag==true){
      digitalWrite(ledPin,HIGH);
    delay(5000);
    digitalWrite(ledPin,LOW);
    }
    exit(0);
  }
