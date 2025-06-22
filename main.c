#include <DHT.h>
#include <Servo.h>

// Pin Definitions
#define DHTPIN 2
#define DHTTYPE DHT22
#define RAIN_SENSOR_PIN 3 // Push button as rain sensor
#define TRIG_PIN 4
#define ECHO_PIN 5
#define SERVO_PIN 6

// Thresholds
const float TEMPERATURE_THRESHOLD = 25.0; // Minimum temperature for drying (in °C)
const float HUMIDITY_THRESHOLD = 70.0;    // Maximum humidity for drying (in %)
const float OBSTACLE_DISTANCE_THRESHOLD = 20.0; // cm
const int RAIN_DETECTION_STATE = LOW;          // Button pressed indicates rain

// Objects
DHT dht(DHTPIN, DHTTYPE);
Servo dryingRack;

void setup() {
  Serial.begin(9600);
  dht.begin();
  dryingRack.attach(SERVO_PIN);

  pinMode(RAIN_SENSOR_PIN, INPUT_PULLUP); // Push button with pull-up configuration
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  dryingRack.write(0); // Start with the rack retracted
  Serial.println("System Initialized");
}

void loop() {
  // Read DHT sensor
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Read rain sensor
  bool isRaining = digitalRead(RAIN_SENSOR_PIN) == RAIN_DETECTION_STATE;

  // Read ultrasonic sensor
  long duration, distance;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration * 0.034) / 2; // Convert to cm

  // Debugging output
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.print(humidity);
  Serial.print(" %, Rain: ");
  Serial.print(isRaining ? "Yes" : "No");
  Serial.print(", Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check conditions for drying
  if (temperature >= TEMPERATURE_THRESHOLD && humidity <= HUMIDITY_THRESHOLD && !isRaining && distance > OBSTACLE_DISTANCE_THRESHOLD) {
    dryingRack.write(90); // Extend the drying rack
    Serial.println("Drying rack extended.");
  } else {
    dryingRack.write(0); // Retract the drying rack
    Serial.println("Drying rack retracted.");
  }

  delay(2000); // Delay for stability
}

// Function to measure ultrasonic sensor distance
long getUltrasonicDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  return pulseIn(ECHO_PIN, HIGH);
}