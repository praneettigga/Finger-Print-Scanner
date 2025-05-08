#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

// Fingerprint Sensor on D2 (TX) and D3 (RX)
SoftwareSerial fingerSerial(2, 3); 
Adafruit_Fingerprint finger(&fingerSerial);

// LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(8, 9, 10, 11, 6, 7);

const int relayPin = 12;

void setup() {
  Serial.begin(9600);

  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); // Keep solenoid OFF initially

  lcd.begin(16, 2);
  lcd.print("Fingerprint Lock");
  delay(2000);
  lcd.clear();

  finger.begin(57600);
  if (finger.verifyPassword()) {
    lcd.print("Sensor Ready");
    Serial.println("Fingerprint sensor ready.");
  } else {
    lcd.print("Sensor Error");
    Serial.println("Fingerprint sensor not detected.");
    while (1); 
  }

  delay(2000);
  lcd.clear();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Place Finger...");

  int id = getFingerprintID();

  if (id >= 0) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Access Granted");
    lcd.setCursor(0, 1);
    lcd.print("ID: "); lcd.print(id);
    Serial.print("Access Granted. ID: ");
    Serial.println(id);

    digitalWrite(relayPin, LOW); // Unlock
    delay(3000);                  // Stay unlocked
    digitalWrite(relayPin, HIGH);  // Lock again

    lcd.clear();
  } else {
    lcd.setCursor(0, 1);
    lcd.print("Try Again      ");
    Serial.println("Access Denied");
    delay(1500);
    lcd.clear();
  }

  delay(500);
}

int getFingerprintID() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK) return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK) return -1;

  p = finger.fingerSearch();
  if (p != FINGERPRINT_OK) return -1;

  return finger.fingerID;
}
