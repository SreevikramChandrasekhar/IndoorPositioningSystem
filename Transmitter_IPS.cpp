#include <SoftwareSerial.h>
SoftwareSerial serial1(3,5);
SoftwareSerial serial2(6,9);

void setup() {
// setup code, to run once:
Serial.begin(1200);
serial1.begin(1200);
serial2.begin(1200);
}

void loop() {
//main code, to run repeatedly:
Serial.println("A");
serial1.println("B");
serial2.println("C");
//delay(2000);
}