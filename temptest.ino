// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>

int led = D7;  // The on-board LED
//int temp = A0;
#define DHTPIN 2     // what pin we're connected to

#define DHTTYPE DHT11		// DHT 11 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(led, OUTPUT);
  //pinMode(temp, INPUT);
  dht.begin();
}

void loop() {
  digitalWrite(led, HIGH);   // Turn ON the LED
  float t = dht.getTempCelcius();
  //int tempsense = analogRead(temp);
  Particle.publish("temp", String(t), PRIVATE);
  delay(10000);               // Wait for 30 seconds

  digitalWrite(led, LOW);    // Turn OFF the LED
  delay(10000);               // Wait for 30 seconds
}
