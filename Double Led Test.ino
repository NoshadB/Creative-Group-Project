#include <FastLED.h>
#include <dht11.h>
#define DHT11PIN 4
dht11 DHT11;

// #define LED_STRIP1_PIN 1
#define LED_STRIP2_PIN 2 //turns on long led strip
#define NUM_LEDS 51
#define sensor A0


int gasLevel = 0;
CRGB leds[NUM_LEDS];
const int button1Pin = 7;
const int button2Pin = 8;
int button1State = 0;
int button2State = 0;
bool airQuality;
bool humidity;


void setup() {
 Serial.begin(9600);
 pinMode(sensor,INPUT);
 pinMode(button1Pin, INPUT);
 pinMode(button2Pin, INPUT);
 FastLED.addLeds<WS2812B, LED_STRIP2_PIN, GRB>(leds, NUM_LEDS);
 FastLED.addLeds<WS2812B, LED_STRIP2_PIN, GRB>(leds, NUM_LEDS);
 FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
 FastLED.clear();
 FastLED.show();
}
void loop() {

  button1State= digitalRead(button1Pin);
  button2State= digitalRead(button2Pin);


if (humidity) {
  showHumdity();
} 
if (airQuality) {
  showCarbonDioxide();
}


if (button1State == HIGH){
//yellow button
  Serial.println("Carbon Doxide");
  humidity = false; 
  airQuality = true; 
}

if (button2State == HIGH){
  //green button
  Serial.println("Humidity");
  humidity = true; 
  airQuality = false; 
  }

}

void showHumdity() {
  int chk = DHT11.read(DHT11PIN);
  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);
  float humidityLevel = (float)DHT11.humidity;
  
  Serial.print("Temperature   (C): ");
  Serial.println((float)DHT11.temperature, 2);

  Serial.println(analogRead(0));

  for (int i = 0; i < 10; i++) {
  if(humidityLevel<25){
  leds[i] = CRGB(125,138,244);
  } else if(humidityLevel>25 && humidityLevel<70){
  leds[i] = CRGB(64,83,240);
  } else if(humidityLevel>=70 && humidityLevel<90){
  leds[i] = CRGB(0, 0, 255);
  } 
  // leds[i] = CRGB(44, 178, 210);
  // // leds[i] = CHSV(colorBlue, 87, 127);
}
 FastLED.show();

}

void showCarbonDioxide(){
 gasLevel= 600;
  Serial.println(analogRead(0)+60);
  for (int i = 0; i < 10; i++) {
  if(gasLevel<100){
  leds[i] = CRGB(243,162,173);

  } else if(gasLevel>100 && gasLevel<250){
  leds[i] = CRGB(252,88,109);

  } else if(gasLevel>250 && gasLevel<500){
  leds[i] = CRGB(255, 0, 0);
  } else { 
  leds[i] = CRGB(255,0,0);

  }
// int colorPink= CRGB(155,50,50);
// leds[i] = CHSV(colorPink, 87, 127);
 }
 FastLED.show();
}
