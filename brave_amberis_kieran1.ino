#include <Servo.h>

Servo myservo;  
int pos = 2;    
int tempPin = A0; 
float temperature; 

void setup() {
  
 
  myservo.attach(3);  
  Serial.begin(9600); 
}

void loop() {
  
  int reading = analogRead(tempPin);
  
  temperature = (reading * 5.0) / 1024.0 * 100.0;
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");
  
  
  if (temperature > 30) {
    myservo.write(90); 
  } else {
    myservo.write(0); 
  }
  
  delay(500); 
}
