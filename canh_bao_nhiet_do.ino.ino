#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

// ===== CẤU HÌNH =====
#define DHTPIN 4
#define DHTTYPE DHT11       // đổi thành DHT22 nếu dùng DHT22
#define BUZZER_PIN 15
#define TEMP_LIMIT 35       // nhiệt độ cảnh báo (°C)

// ===== KHAI BÁO =====
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); // nếu không hiện thử 0x3F

void setup() {
  Serial.begin(115200);
  
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  dht.begin();

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Nhiet do ESP32");
  delay(2000);
  lcd.clear();
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // °C

  if (isnan(temperature) || isnan(humidity)) {
    lcd.setCursor(0, 0);
    lcd.print("Loi cam bien");
    return;
  }

  // Hiển thị LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print((char)223);
  lcd.print("C   ");

  lcd.setCursor(0, 1);
  lcd.print("Humi: ");
  lcd.print(humidity);
  lcd.print("%   ");

  // Cảnh báo nhiệt độ
  if (temperature >= TEMP_LIMIT) {
    digitalWrite(BUZZER_PIN, HIGH);
    lcd.setCursor(12, 0);
    lcd.print("!!!");
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(2000);
}
