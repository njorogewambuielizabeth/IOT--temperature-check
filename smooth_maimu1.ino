// Define the pins for the distance sensor
#define TRIG_PIN 12
#define ECHO_PIN 13
long duration;
int distance;

void setup() {
  // Start serial communication
  Serial.begin(9600);
  
  // Configure the pins for the distance sensor
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // Send a 10 microsecond pulse to the TRIG pin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the duration of the ECHO pulse
  unsigned long duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate the distance in centimeters
  float distance = duration / 58.2;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Wait for 500 milliseconds before taking another reading
  delay(500);
}

