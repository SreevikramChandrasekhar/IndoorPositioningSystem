#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>
SoftwareSerial serial1(3,5);
//String word1 = "";
bool flag;
//SoftwareSerial serial2(6,9);

void setup() {
flag= true;
//setup code here, to run once:
//word1[0] = '\0';
Serial.begin(1200);
serial1.begin(9600);
mp3_set_serial (serial1); //set Serial for DFPlayer-mini mp3 module
mp3_set_volume (25);
//serial2.begin(1200);
}

void loop() {
// main code here, to run repeatedly:
if(Serial.available() > 0)
{
char word1= char(Serial.read());
Serial.print(word1);
Serial.end(); // Ends the serial communication once all data is received
Serial.begin(1200); // Re-establishes serial communication , this causes deletion of anything previously stored in the buffer or cache.
//word1 = word1[0];                  
Serial.println("size of word");
//Serial.print(word1.length());
//Serial.end();
flag=false;
// Serial.print("busy");
// Serial.println(digitalRead(7));
if(word1 == 'A')
{
word1 = '\0';
Serial.println("*1");
Serial.print("word+new=");
Serial.println(word1);
mp3_play (1); //play 0001.mp3
delay(3000);
// Serial.end();
flag=true;
// Serial.flush();
}

else if (word1 == 'B')
{
word1 = '\0';
Serial.println("*2");
Serial.print("word+new=");
Serial.print(word1);
mp3_play (2); //play 0001.mp3
// Serial.print("new busy");
// Serial.println(digitalRead(7));
delay(3000);
// Serial.end();
flag=true;
}

}

else if(word1 == "C")
{
word1[0] = '\0';
Serial.println("3");
//mp3_play (3); //play 0001.mp3
delay(1000);
Serial.begin(1200);
}
}