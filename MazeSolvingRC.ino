#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1); // RX | TX
int command ;
void setup() {
   Serial.begin(9600);
   mySerial.begin(9600);
   Serial.println("You're connected via Bluetooth");
   pinMode(10,OUTPUT);   //left motors forward
   pinMode(9,OUTPUT);   //left motors reverse
   pinMode(8,OUTPUT);   //right motors forward
   pinMode(7,OUTPUT);   //right motors reverse

}

void loop() {
   if (mySerial.available())
   {
    command=(mySerial.read());
    if (command=='0')
    {
      Serial.println("Left");
      digitalWrite(10,LOW);
      digitalWrite(9,HIGH);
      digitalWrite(8,LOW);
      digitalWrite(7,LOW);           
    
    }
    
        else if (command=='1')
    {
      Serial.println("Right");
      digitalWrite(10,LOW);
      digitalWrite(9,LOW);
      digitalWrite(8,LOW);
      digitalWrite(7,HIGH);
    }
    
        else if (command=='2')
    {
      Serial.println("Up");
      digitalWrite(10,HIGH);
      digitalWrite(9,LOW);
      digitalWrite(8,HIGH);
      digitalWrite(7,LOW);
    }

        else if (command=='3')
    {
      Serial.println("Down");
      digitalWrite(10,LOW);
      digitalWrite(9,HIGH);
      digitalWrite(8,LOW);
      digitalWrite(7,HIGH);
    }


   
  }
}
