#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Sensor pins
const int moisturePin = A0;
const int lightPin = A1;

// Face animations (4 frames)
const char* happyFrames[] = {
  "(^_^)",    // base
  "(^.^)",    // softer
  "(^o^)",    // open mouth
  "(^-^)"     // closed, but happy
};

const char* sadFrames[] = {
  "(._.)", "(;_;)", "(T_T)", "(._.)"
};

const char* deadFrames[] = {
  "(x_x)", "(X_X)", "(x_x)", "(-_-)"
};

// Sleeping Zz animations (4 frames)
const char* sleepFrames[] = {
  "(-_-).   ", "(-_-). z ", "(-_-). Zz", "(-_-). zZ"
};

int frame = 0;
unsigned long lastFrameTime = 0;
const int frameDelay = 600;

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(moisturePin, INPUT);
  pinMode(lightPin, INPUT);
}

void loop() {
  int moisture = analogRead(moisturePin);
  int light = analogRead(lightPin);

  int moisturePct = map(moisture, 1023, 0, 0, 100);
  int lightPct = map(light, 0, 1023, 0, 100);

  String topLine = "";

  // 🌙 Sleep mode if it's dark
  if (lightPct < 10) {
    topLine = sleepFrames[frame];
  }
  else if (moisturePct < 20 || lightPct < 15) {
    topLine = String(deadFrames[frame]) + " Dying";
  } 
  else if (moisturePct < 40 || lightPct < 30) {
    topLine = String(sadFrames[frame]) + " Sad";
  } 
  else if (moisturePct > 90 && lightPct > 90) {
    topLine = String(sadFrames[frame]) + " Too much";
  } 
  else {
    topLine = String(happyFrames[frame]) + " Happy";
  }

  // Top line: face + status (max 16 characters)
  lcd.setCursor(0, 0);
  lcd.print(topLine);
  for (int i = topLine.length(); i < 16; i++) lcd.print(" "); // clear the rest

  // Bottom line: light and water percentages
  String bottomLine = "Light:" + String(lightPct) + "% " + "Water:" + String(moisturePct) + "%";
  lcd.setCursor(0, 1);
  lcd.print(bottomLine);
  for (int i = bottomLine.length(); i < 16; i++) lcd.print(" "); // clear here too

  // Animate frames every frameDelay ms
  if (millis() - lastFrameTime > frameDelay) {
    frame = (frame + 1) % 4;
    lastFrameTime = millis();
  }

  delay(100);
}
