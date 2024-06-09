#include <SoftwareSerial.h>
SoftwareSerial HC05(10, 11); //HC05-TX Pin 10, HC05-RX to Arduino Pin 11

// Motor A connections
int enA = 6;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;

void setup() {
  HC05.begin(9600); //Baudrate 9600 , Choose your own baudrate 

  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop() {
    uint8_t i;
    char receive = HC05.read(); //Read from Serial Communication

    analogWrite(enA, 255);
    analogWrite(enB, 255);
  
    if(receive == '5'){          //FORWARD ---- 
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
    }
 
    if(receive == '0'){          //STOP --- 
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);

    }
 
    if(receive == '2'){          //LEFT --- 
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);

    }
 
    if(receive == '1'){          //RIGHT --- 
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);

    }
  }
