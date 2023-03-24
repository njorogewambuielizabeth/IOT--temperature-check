
int distance = 0;
long readDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  
  return pulseIn(echoPin, HIGH);
}
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  distance = 0.01723 * readDistance(13, 12);
  Serial.println(distance);
  delay(500); 
}

