#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <NewPing.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11);

#define TRIGGER_PIN  4
#define ECHO_PIN     3
#define BUZZER_PIN   2

NewPing sonar(TRIGGER_PIN, ECHO_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

String data;
String ketinggianAir;
char c;

int distance;

unsigned long previousMillis = 0;
const long interval = 180000; // Interval dalam milidetik (3 menit)

void setup() {
  Serial.begin(115200);
  mySerial.begin(115200);  // Initialize Software Serial
  lcd.begin(16, 2);
  lcd.backlight();
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  distance = sonar.ping_cm();
  ketinggianAir = "Jarak :" + String(distance) + "cm";

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(ketinggianAir);

  if (distance < 80) {
    // Siaga banjir: Jika ketinggian air mencapai 120 cm atau lebih
    lcd.setCursor(0, 1);
    lcd.println("Awas Banjir");
    digitalWrite(BUZZER_PIN, HIGH); // Aktifkan buzzer atau notifikasi lainnya
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      Serial.println("Awas Banjir");
      mySerial.println("Awas");
    }

  } else if (distance < 160) {
    // Awas banjir: Jika ketinggian air mencapai 60 cm atau lebih
    lcd.setCursor(0, 1);
    lcd.println("Siaga Banjir");
    digitalWrite(BUZZER_PIN, HIGH); // Aktifkan buzzer atau notifikasi lainnya
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      Serial.println("Siaga Banjir");
      mySerial.println("Siaga");
    }
  } else {
    digitalWrite(BUZZER_PIN, LOW); // Matikan buzzer jika ketinggian air kurang dari 60 cm
  }

  while (mySerial.available() > 0) {
    delay(10);
    c = mySerial.read();
    data += c;
  }
  if (data.length() > 0) {
    Serial.println(data);
    if (data == "/cek_ketinggian") {
      mySerial.print(String(distance));
      Serial.println(String(distance));
    }
    data = "";
  }
  delay(500);
}
