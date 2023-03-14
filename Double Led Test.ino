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
bool airQual;
bool Humid;

void setup() {
 Serial.begin(9600);
 pinMode(sensor,INPUT);
 pinMode(button1Pin, INPUT);
 pinMode(button2Pin, INPUT);
 FastLED.addLeds<WS2812B, LED_STRIP2_PIN, GRB>(leds, NUM_LEDS);
 FastLED.addLeds<WS2812B, LED_STRIP2_PIN, GRB>(leds, NUM_LEDS);
 FastLED.setMaxPowerInVoltsAndMilliamps(10, 500);
 FastLED.clear();
 FastLED.show();
}
void loop() {

  button1State= digitalRead(button1Pin);
  button2State= digitalRead(button2Pin);




if (button1State == HIGH){




 gasLevel= 600;
 Serial.println(analogRead(0));
  leds[5] = CRGB(0,255,0);
 for (int i = 0; i < 10; i++) {
 if(gasLevel<100){
 leds[i] = CRGB(0,255,0);
  // leds2[i] = CRGB(0,255,0);
 } else if(gasLevel>100 && gasLevel<250){
 leds[i] = CRGB(255,255,0);
  // leds2[i] = CRGB(255,255,0);
 } else if(gasLevel>250 && gasLevel<500){
 leds[i] = CRGB(255, 120, 0);
  // leds2[i] = CRGB(255, 120, 0);
} else{
 leds[i] = CRGB(255,0,0);
  // leds2[i] = CRGB(255,0,0);
 }
 }
 FastLED.show();

}

if (button2State == HIGH){

   Serial.println();

  int chk = DHT11.read(DHT11PIN);
  Serial.print("Humidity (%): ");
   Serial.println((float)DHT11.humidity, 2);

  Serial.print("Temperature   (C): ");
  Serial.println((float)DHT11.temperature, 2);
  delay(2000);
}
}
