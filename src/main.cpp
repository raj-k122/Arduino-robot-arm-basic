#include <Servo.h>
#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>

#define stepPinBASE 5
#define dirPinBASE 6

#define servoHIP 1
#define servoSHOULDER 2
#define servoELBOW 3
#define servoWRIST 4

int pos = 0;
char input;

/* Create an instance of the library */
Adafruit_PWMServoDriver Driver(); // Library using B010101 (A5-A0) i2c address, and default Wire @400kHz

// needs link to servo drivers (base motor)
#define SCL A1
#define SDA A2

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

    Serial.begin(115200); 
    Driver.setPWMFreq(50);
    Driver.begin();


}

void loop(){

    if (Serial.available()){
        input = Serial.read();
        //H and G is for HIP SERVO
        if(input == 'h'){
            pos++;
            pos = limiterFunction(pos);
            Serial.println(pos);
            Driver.setPWM()

        }
        if (input == 'g'){
            pos--;
            pos = limiterFunction(pos);
            Serial.println(pos);
            Driver(servoHIP, pos);

        }
        //S and A is for SHOULDER SERVO
        if(input == 's'){
            pos++;
            pos = limiterFunction(pos);
            Serial.println(pos);
            Driver(servoSHOULDER, pos);

        }
        if (input == 'a'){
            pos--;
            pos = limiterFunction(pos);
            Serial.println(pos);
            Driver(servoSHOULDER, pos);

        }
        // //E and R is for ELBOW SERVO
        if(input == 'e'){
            pos++;
            pos = limiterFunction(pos);
            Serial.println(pos);
            Driver(servoELBOW, pos);

        }
        if (input == 'r'){
            pos--;
            pos = limiterFunction(pos);
            Serial.println(pos);
            Driver(servoELBOW, pos);

        }
        // //W and Q is for WRIST SERVO
        if(input == 'w'){
            pos++;
            pos = limiterFunction(pos);
            Serial.println(pos);
            Driver(servoWRIST, pos);

        }
        if (input == 'q'){
            pos--;
            pos = limiterFunction(pos);
            Serial.println(pos);
            Driver(servoWRIST, pos);

        }

    }
}

