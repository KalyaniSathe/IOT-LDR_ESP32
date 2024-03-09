#include<BluetoothSerial.h>
BluetoothSerial b;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  b.begin("Aman");
  pinMode(2,OUTPUT);
  pinMode(35,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(b.available()>0)
  {
    int val = analogRead(35);
    Serial.println(val);
    b.println(val);
    char ip = b.read();
    if(ip=='1')
    {
      digitalWrite(2,HIGH);
    }
    if(ip=='0')
    {
      digitalWrite(2,LOW);
    }
  }
}
