#include <Arduino.h>
#include <NanitLib.h>

#define BRGH P4_1

void setup() {
  Nanit_Base_Start();
  pinMode(BRGH, INPUT);
  pinMode(TFT_BL, OUTPUT);
  tft.setTextSize(1);
  tft.setTextColor(ST7735_BLUE);
  tft.fillScreen(ST7735_WHITE);
  Serial.begin(9600);
}

void loop() {
  int brightness = analogRead(BRGH);
  int percent = map(brightness, 1023, 0, 0, 100);
  analogWrite(TFT_BL, map(brightness, 1023, 0, 0, 255));
  tft.setCursor(0, 0);
  tft.setTextSize(1);
  tft.println("Brightness: " + String(percent) + "%");
  tft.setTextSize(2);
  tft.println(percent > 50 ? "Bright" : "Dark");
  tft.drawRect(0, 50, tft.width(), 50, ST7735_BLACK);
  tft.fillRect(0, 50, (tft.width() * percent) / 100, 50, ST7735_RED);
  delay(1000);
  tft.fillScreen(ST7735_WHITE);
}