#include <SD.h>
#include <SPI.h>
#include <LiquidCrystal.h>

// Pin tanımlamaları
const int buzzerPin = 9; // Buzzer pin
const int micPin = A0;
const int threshold = 600; // Gürültü eşiği
int ledPin1 = 10;   // İlk LED'in bağlı olduğu dijital pin
int ledPin2 = 8;   // İkinci LED'in bağlı olduğu dijital pin
int ledPin3 = 11;   // İlk LED'in bağlı olduğu dijital pin
int ledPin4 = 12;   // İkinci LED'in bağlı olduğu dijital pin
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  // Seri haberleşmeyi başlat
  Serial.begin(9600);

  pinMode(buzzerPin, OUTPUT); // Buzzer pinini çıkış olarak ayarla
  pinMode(ledPin1, OUTPUT);   // İlk LED pinini çıkış olarak ayarla
  pinMode(ledPin2, OUTPUT);   // İkinci LED pinini çıkış olarak ayarla
  pinMode(ledPin3, OUTPUT);   // İlk LED pinini çıkış olarak ayarla
  pinMode(ledPin4, OUTPUT);   // İkinci LED pinini çıkış olarak ayarla

  // LCD ekranı başlat
  lcd.begin(16, 2);

  // Buzzer pinini çıkış olarak ayarla
  pinMode(buzzerPin, OUTPUT);

  // LCD'ye hoş geldiniz mesajı yazdır
  lcd.print("Gurultu Ikaz");
  lcd.setCursor(0, 1);
  lcd.print("Cihazi Hazir");
  delay(2000);
  lcd.clear();
}

void loop() {
  int micValue = analogRead(micPin);
  Serial.println(micValue);

  if (micValue > threshold) {
    for (int i = 0; i < 10; i++) { // 10 kez yanıp sönecek
      lcd.clear();
      lcd.print("Lutfen Sessiz");
      lcd.setCursor(0, 1);
      lcd.print("Olun");
      
      digitalWrite(ledPin1, HIGH); // İlk LED'i yak
      digitalWrite(ledPin2, HIGH); // İkinci LED'i yak
      digitalWrite(ledPin3, HIGH); // İlk LED'i yak
      digitalWrite(ledPin4, HIGH); // İkinci LED'i yak
      tone(buzzerPin, 1000); // 1000 Hz frekansta ses üret
      
      delay(250); // 250 milisaniye bekle
      
      lcd.clear(); // LCD'yi temizle
      digitalWrite(ledPin1, LOW);  // İlk LED'i söndür
      digitalWrite(ledPin2, LOW);  // İkinci LED'i söndür
      digitalWrite(ledPin3, LOW);  // İlk LED'i söndür
      digitalWrite(ledPin4, LOW);  // İkinci LED'i söndür
      noTone(buzzerPin); // Buzzer'ı durdur
      
      delay(1000); // 250 milisaniye bekle
    }
  }
  
  delay(100);
}

