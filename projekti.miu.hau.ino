#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
const int sensor=A1;
float tempc;
float vout;

const int trigPin = 7; 
const int echoPin = 8;
float duration, distance;

void setup()
{
pinMode(sensor,INPUT);
Serial.begin(9600);
lcd.begin(16,2);  
  delay(500);

   pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
}


void loop() 
{

 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH); 
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  delay(100);
 
vout=analogRead(sensor);
vout=(vout*500)/1023;
tempc=vout;
lcd.setCursor(0,0);
lcd.print("Temp C = ");
lcd.print(tempc);

lcd.setCursor(0,1);
lcd.print("Dist CM = ");
lcd.print(distance);
-
Serial.print("Temperature C: ");
Serial.println(tempc);
Serial.print("Distance: ");
Serial.println(distance);

delay(1000);
}
