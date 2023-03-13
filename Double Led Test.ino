#include <FastLED.h>
// #define LED_STRIP1_PIN 1
#define LED_STRIP2_PIN 2 //turns on long led strip
#define NUM_LEDS 51
#define sensor A0
int gasLevel = 0;
CRGB leds[NUM_LEDS];

void setup() {
 Serial.begin(9600);
 pinMode(sensor,INPUT);
 FastLED.addLeds<WS2812B, LED_STRIP2_PIN, GRB>(leds, NUM_LEDS);
 FastLED.addLeds<WS2812B, LED_STRIP2_PIN, GRB>(leds, NUM_LEDS);
 FastLED.setMaxPowerInVoltsAndMilliamps(10, 500);
 FastLED.clear();
 FastLED.show();
}
void loop() {
 gasLevel= analogRead(sensor);
 Serial.println(analogRead(0));
//  leds[5] = CRGB(0,255,0);
 for (int i = 0; i < 10; i++) {
 if(gasLevel<90){
 leds[i] = CRGB(0,255,0);
  // leds2[i] = CRGB(0,255,0);
 } else if(gasLevel>90 && gasLevel<115){
 leds[i] = CRGB(255,255,0);
  // leds2[i] = CRGB(255,255,0);
 } else if(gasLevel>115 && gasLevel<130){
 leds[i] = CRGB(255, 120, 0);
  // leds2[i] = CRGB(255, 120, 0);
} else{
 leds[i] = CRGB(255,0,0);
  // leds2[i] = CRGB(255,0,0);
 }
 }
 FastLED.show();
}