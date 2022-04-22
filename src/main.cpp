#include <Servo.h>
#include <Arduino.h>
Servo servoHIP;
Servo servoSHOULDER;
Servo servoELBOW;
Servo servoWRIST;
int pos = 0;
char input;

int limiterFunction(int position){
    if(position > 180){
        position = 180;
    }
    if(position < 0)
    {
        position = 0;
    }
    return position;
    
}


void setup(){
    servoHIP.attach(3);
    servoSHOULDER.attach(4);
    servoELBOW.attach(5);
    servoWRIST.attach(6);
    Serial.begin(9600);
}

void loop(){
    if (Serial.available()){
        input = Serial.read();
        //H and G is for HIP SERVO
        if(input == 'h'){
            pos++;
            pos = limiterFunction(pos);
            Serial.println(pos);
            servoHIP.write(pos);

        }
        if (input == 'g'){
            pos--;
            pos = limiterFunction(pos);
            Serial.println(pos);
            servoHIP.write(pos);

        }
        //S and A is for SHOULDER SERVO
        if(input == 's'){
            pos++;
            pos = limiterFunction(pos);
            Serial.println(pos);
            servoSHOULDER.write(pos);

        }
        if (input == 'a'){
            pos--;
            pos = limiterFunction(pos);
            Serial.println(pos);
            servoSHOULDER.write(pos);

        }
        // //E and R is for ELBOW SERVO
        if(input == 'e'){
            pos++;
            pos = limiterFunction(pos);
            Serial.println(pos);
            servoELBOW.write(pos);

        }
        if (input == 'r'){
            pos--;
            pos = limiterFunction(pos);
            Serial.println(pos);
            servoELBOW.write(pos);

        }
        // //W and Q is for WRIST SERVO
        if(input == 'w'){
            pos++;
            pos = limiterFunction(pos);
            Serial.println(pos);
            servoWRIST.write(pos);

        }
        if (input == 'q'){
            pos--;
            pos = limiterFunction(pos);
            Serial.println(pos);
            servoWRIST.write(pos);

        }

    }
}

