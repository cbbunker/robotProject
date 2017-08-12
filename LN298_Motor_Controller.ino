#define SERIAL_OUTPUT(message) Serial.println(message); Serial.println("   ");

const char MOTOR_FAST = 255;
const char MOTOR_MEDIUM = 192;
const char MOTOR_SLOW = 128;
const char MOTOR_STOP = 0;

// Motor 1
int dir1PinA = 2;
int dir2PinA = 3;
int speedPinA = 9; // Needs to be a PWM pin to be able to control motor speed

// Motor 2
int dir1PinB = 4;
int dir2PinB = 5;
int speedPinB = 10; // Needs to be a PWM pin to be able to control motor speed

int motorSpeed = MOTOR_FAST;

void setup() {
  // initialize serial communication @ 9600 baud:
  Serial.begin(9600);

  //Define L298N Dual H-Bridge Motor Controller Pins
  pinMode(dir1PinA, OUTPUT);
  pinMode(dir2PinA, OUTPUT);
  pinMode(speedPinA, OUTPUT);
  pinMode(dir1PinB, OUTPUT);
  pinMode(dir2PinB, OUTPUT);
  pinMode(speedPinB, OUTPUT);

}
void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0) {
    int inByte = Serial.read();
    int speed; // Local variable

    switch (inByte) {

      //    case 'f':
      //      break;
      //
      //    case 'r':
      //      break;
      //
      //    case 'l':
      //      break;
      //
      //    case 's':
      //      break;
      //
      //    case 'b':
      //      break;
      //
      //______________Motor 1_____________
      case '1': // Motor 1 Forward
        analogWrite(speedPinA, motorSpeed);//Sets speed variable via PWM
        digitalWrite(dir1PinA, LOW);
        digitalWrite(dir2PinA, HIGH);
        SERIAL_OUTPUT("Motor 1 Forward")
        //      Serial.println("Motor 1 Forward"); // Prints out “Motor 1 Forward” on the serial monitor
        //      Serial.println("   "); // Creates a blank line printed on the serial monitor
        break;

      case '2': // Motor 1 Stop (Freespin)
        analogWrite(speedPinA, MOTOR_STOP);
        digitalWrite(dir1PinA, LOW);
        digitalWrite(dir2PinA, HIGH);
        SERIAL_OUTPUT("Motor 1 Stop")
        break;

      case '3': // Motor 1 Reverse
        analogWrite(speedPinA, motorSpeed);
        digitalWrite(dir1PinA, HIGH);
        digitalWrite(dir2PinA, LOW);
        SERIAL_OUTPUT("Motor 1 Reverse")
        break;

      //______________Motor 2______________

      case '4': // Motor 2 Forward
        analogWrite(speedPinB, motorSpeed);
        digitalWrite(dir1PinB, LOW);
        digitalWrite(dir2PinB, HIGH);
        SERIAL_OUTPUT("Motor 2 Forward")
        break;

      case '5': // Motor 2 Stop (Freespin)
        analogWrite(speedPinB, MOTOR_STOP);
        digitalWrite(dir1PinB, LOW);
        digitalWrite(dir2PinB, HIGH);
        SERIAL_OUTPUT("Motor 2 Stop")
        break;

      case '6': // Motor 2 Reverse
        analogWrite(speedPinB, motorSpeed);
        digitalWrite(dir1PinB, HIGH);
        digitalWrite(dir2PinB, LOW);
        SERIAL_OUTPUT("Motor 2 Reverse")
        break;

      case '7' : //Motor speed fast
        motorSpeed = MOTOR_FAST;
        SERIAL_OUTPUT("Motor Speed: FAST")
        break;

      case '8' : //Motor speed fast
        motorSpeed = MOTOR_MEDIUM;
        SERIAL_OUTPUT("Motor Speed: MEDIUM")
        break;

      case '9' : //Motor speed fast
        motorSpeed = MOTOR_SLOW;
        Serial.println("Motor Speed: SLOW");
        Serial.println("   ");
        break;

      default:
        // turn all the connections off if an unmapped key is pressed:
        for (int thisPin = 2; thisPin < 11; thisPin++) {
          digitalWrite(thisPin, LOW);
        }
    }
  }
}
