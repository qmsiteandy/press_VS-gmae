#include <Servo.h>

static const int servoPin = A15;
int player1_Pin = 35;
int player2_Pin = 34;
int led_Pin = 14;

int degree;
int eachPoint = 5;

bool player1_Pressing = false;
bool player2_Pressing = false;

Servo servo1;

void setup() {
    Serial.begin(115200);
    servo1.attach(servoPin);

    pinMode(player1_Pin,INPUT);
    pinMode(player2_Pin,INPUT);
    pinMode(led_Pin,OUTPUT);

    degree = 90;

    digitalWrite(led_Pin,LOW);
}

void loop() {

    servo1.write(degree);
    Serial.println(degree);
    
    if(digitalRead(player1_Pin) && !player1_Pressing){
      degree-=eachPoint;
      player1_Pressing = true;
    }else if(!digitalRead(player1_Pin)){
      player1_Pressing = false;
    }

    if(digitalRead(player2_Pin) && !player2_Pressing){
      degree+=eachPoint;
      player2_Pressing = true;
    }else if(!digitalRead(player2_Pin)){
      player2_Pressing = false;
    }
    
    if(degree<0 || degree>180){
      servo1.write(degree);
      End();
    }
}

void End(){
    digitalWrite(led_Pin,HIGH);

    delay(3000);

    digitalWrite(led_Pin,LOW);
    degree = 90;
}


