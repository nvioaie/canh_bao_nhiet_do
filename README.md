# canh_bao_nhiet_do1. Linh kiện

ESP32

Cảm biến DHT11 hoặc DHT22

LCD 16x2 I2C (địa chỉ thường 0x27 hoặc 0x3F)

Buzzer (cảnh báo)

Điện trở 10kΩ (kéo DATA DHT)

Dây nối

2. Sơ đồ kết nối
🔹 DHT11 / DHT22
DHT	ESP32
VCC	3.3V
DATA	GPIO 4
GND	GND

(DATA nối điện trở 10k lên VCC)

🔹 LCD I2C
LCD	ESP32
VCC	5V
GND	GND
SDA	GPIO 21
SCL	GPIO 22
🔹 Buzzer
Buzzer	ESP32
+	GPIO 15
-	GND
