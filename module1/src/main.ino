#include "Arduino.h"
#include <DHT.h>

int buttonPin=10;

long buttonPressedAt;
long buttonPressTimeout = 300;
long sleepTimeout = 30000;
byte currentScreen = 0;
byte screensCount = 5;

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println();

  buttonPressedAt = millis();
  pinMode(buttonPin, INPUT);
}

void loop() {
  boolean buttonPressed = true;
  buttonPressed = digitalRead(buttonPin);
  if (buttonPressed && millis() - buttonPressedAt > buttonPressTimeout) {
    buttonPressedAt = millis();
    currentScreen = currentScreen + 1;
    if (currentScreen > screensCount)
      currentScreen = 0;
      Serial.println("Button pressed - show screen "+String(currentScreen));
  }
  if (millis() - buttonPressedAt > sleepTimeout) {
    Serial.println("Time is out - display OFF");
  }
}
