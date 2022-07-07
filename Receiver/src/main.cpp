#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>

#define SERVOMIN 115
#define SERVOMAX 500

#define servoHIP 0
#define servoSHOULDER 1
#define servoELBOW 2
#define servoWRIST 3

#define I2CAdd 0x40

char input;
int pos;

/* Create an instance of the library */
Adafruit_PWMServoDriver Driver = Adafruit_PWMServoDriver(0x40); 

int limiterFunction(int position){
    if(position > 500){
        position = 500;
    }
    if(position < 115)
    {
        position = 115;
    }
    return position;
    
}

void setup(){
    Driver.wakeup();
    Driver.begin();
    Driver.setPWMFreq(50);
    Serial.begin(9600);
}

void loop(){

    if (Serial.available()){
        input = Serial.read();
        //H and G is for HIP SERVO
        if(input == 'h'){
            pos = pos + 5;
            pos = limiterFunction(pos);
            Serial.println(pos);
            Driver.setPWM(servoHIP, 0, pos);

        }
        if (input == 'g'){
            pos = pos - 5;
            pos = limiterFunction(pos);
            Serial.println(pos);
            Driver.setPWM(servoHIP, 0, pos);

        }
        //S and A is for SHOULDER SERVO
        if(input == 's'){
            pos = pos + 5;
            pos = limiterFunction(pos);
            Serial.println(pos);
            Driver.setPWM(servoSHOULDER, 0, pos);

        }
        if (input == 'a'){
            pos = pos - 5;
            pos = limiterFunction(pos);
            Serial.println(pos);
            Driver.setPWM(servoSHOULDER, 0, pos);

        }
        // // //E and R is for ELBOW SERVO
        if(input == 'e'){
            pos = pos + 5;
            pos = limiterFunction(pos);
            Serial.println(pos);
            Driver.setPWM(servoELBOW, 0, pos);

        }
        if (input == 'r'){
            pos = pos - 5;
            pos = limiterFunction(pos);
            Serial.println(pos);
            Driver.setPWM(servoELBOW, 0, pos);

        }
        // // //W and Q is for WRIST SERVO
        if(input == 'w'){
            pos = pos + 5;
            pos = limiterFunction(pos);
            Serial.println(pos);
            Driver.setPWM(servoWRIST, 0, pos);

        }
        if (input == 'q'){
            pos = pos - 5;
            pos = limiterFunction(pos);
            Serial.println(pos);
            Driver.setPWM(servoWRIST, 0, pos);

        }

    }
}

