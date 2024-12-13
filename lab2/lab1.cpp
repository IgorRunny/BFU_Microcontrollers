#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <RTClib.h>
#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp;
RTC_DS1307 rtc;
LiquidCrystal_I2C LCD(0x27, 16, 2);
DHT dht(2, DHT22);
int hours = 0;
int minutes = 0;
int seconds = 0;

void setup() {
  dht.begin();
  LCD.init();
  LCD.backlight();
  bmp.begin();
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  LCD.setCursor(0, 0);
  LCD.print(humidity);
  LCD.setCursor(0, 1);
  LCD.print(temperature);
  LCD.print("C");

  displayTime();

  LCD.setCursor(8, 1);
  LCD.print(bmp.readPressure());
  LCD.print(" Pa");

  delay(5000);
  LCD.clear();
}

void displayTime() {
  DateTime now = rtc.now();
  hours = now.hour();
  minutes = now.minute();
  seconds = now.second();

  LCD.setCursor(6, 0);
  if (hours <= 9) {
    LCD.print("0");
  }
  LCD.print(hours);
  LCD.setCursor(8, 0);
  LCD.print(":");

  LCD.setCursor(9, 0);
  if (minutes <= 9) {
    LCD.print("0");
  }
  LCD.print(minutes);
  LCD.setCursor(11, 0);
  LCD.print(":");

  LCD.setCursor(12, 0);
  if (seconds <= 9) {
    LCD.print("0");
  }
  LCD.print(seconds);
}