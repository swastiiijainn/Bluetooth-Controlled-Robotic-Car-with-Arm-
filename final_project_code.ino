#include <Servo.h>
#define ena1 3
#define in1 4
#define in2 5
#define ena2 6
#define in3 7
#define in4 8
Servo elbow1;
Servo elbow2; 
Servo wrist1;
Servo wrist2;
Servo palm; // Create a servo object

int angle1 =90; int angle2=90; int angle3=90; int angle4=90; int angle5=90;
int increment = 5;  // Angle increment for each button press

void setup() {
  for (int i = 3; i <= 8; i++) {
    pinMode(i, OUTPUT);
  }

  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  analogWrite(ena1, 255);
  analogWrite(ena2, 255);

  Serial.begin(9600);  // Initialize serial communication at 9600 baud
  elbow1.attach(9);
  elbow2.attach(10);
  wrist1.attach(11);
  wrist2.attach(12);
  palm.attach(13);
}
void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void backward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void right() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void left() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    switch (command) {
      case 'F':
        forward();
        break;
      case 'B':
        backward();
        break;
      case 'R':
        right();
        break;
      case 'L':
        left();
        break;
      case 'S':
        stop();
        break;
      default:
        stop();
        break;
    }
  }
  delay(100); // Small delay to avoid rapid changes
  if (Serial.available() > 0) {
    char com = Serial.read();  // Read the incoming Bluetooth command
    if (com == 'X') {
      angle1 += increment;  // Increase the servo angle
      if (angle1 > 180) {
        angle1 = 180;  // Ensure the angle doesn't exceed 180 degrees
      }
      elbow1.write(angle1);  // Move the servo to the new angle
    } 
    else if (com == 'Y') {
      angle1 -= increment;  // Decrease the servo angle
      if (angle1 < 0) {
        angle1 = 0;  // Ensure the angle doesn't go below 0 degrees
      }
      elbow1.write(angle1);  // Move the servo to the new angle
    }

    if (com == 'M') {
      angle2 += increment;  // Increase the servo angle
      if (angle2 > 180) {
        angle2 = 180;  // Ensure the angle doesn't exceed 180 degrees
      }
      elbow2.write(angle2);  // Move the servo to the new angle
    } 
    else if (com == 'N') {
      angle2 -= increment;  // Decrease the servo angle
      if (angle2 < 0) {
        angle2 = 0;  // Ensure the angle doesn't go below 0 degrees
      }
      elbow2.write(angle2);  // Move the servo to the new angle
    }

    if (com == 'O') {
      angle3 += increment;  // Increase the servo angle
      if (angle3 > 180) {
        angle3 = 180;  // Ensure the angle doesn't exceed 180 degrees
      }
      wrist1.write(angle3);  // Move the servo to the new angle
    } 
    else if (com == 'P') {
      angle3 -= increment;  // Decrease the servo angle
      if (angle3 < 0) {
        angle3 = 0;  // Ensure the angle doesn't go below 0 degrees
      }
      wrist1.write(angle3);  // Move the servo to the new angle
    }

    if (com == 'C') {
      angle4 += increment;  // Increase the servo angle
      if (angle4 > 180) {
        angle4 = 180;  // Ensure the angle doesn't exceed 180 degrees
      }
      wrist2.write(angle4);  // Move the servo to the new angle
    } 
    else if (com == 'D') {
      angle4 -= increment;  // Decrease the servo angle
      if (angle4 < 0) {
        angle4 = 0;  // Ensure the angle doesn't go below 0 degrees
      }
      wrist2.write(angle4);  // Move the servo to the new angle
    }

    if (com == 'U') {
      angle5 += increment;  // Increase the servo angle
      if (angle5 > 180) {
        angle5 = 180;  // Ensure the angle doesn't exceed 180 degrees
      }
      palm.write(angle5);  // Move the servo to the new angle
    } 
    else if (com == 'V') {
      angle5 -= increment;  // Decrease the servo angle
      if (angle5 < 0) {
        angle5 = 0;  // Ensure the angle doesn't go below 0 degrees
      }
      palm.write(angle5);  // Move the servo to the new angle
    }
  }

  delay(100);  // Small delay to avoid rapid command processing
}