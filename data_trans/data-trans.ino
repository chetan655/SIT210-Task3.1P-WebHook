// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>

// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#define DHTPIN 4     // what pin we're connected to

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11		// DHT 11 
#define DHTTYPE DHT22		// DHT 22 (AM2302)
//#define DHTTYPE DHT21		// DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

String Temp;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
	dht.begin();
}

void loop() {
// Wait a few seconds between measurements.
	delay(30000);

// Reading temperature or humidity takes about 250 milliseconds!
// Sensor readings may also be up to 2 seconds 'old' (its a 
// very slow sensor)

// Read temperature as Celsius
	float temperature = dht.getTempCelcius();
	
	Temp = String::format ("%.1f C", temperature);
	
	Particle.publish("Temperature", Temp);
}
