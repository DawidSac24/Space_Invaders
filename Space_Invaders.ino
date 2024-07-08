#include "global.h"

byte sequance = MENU;
byte menu = CLASSIC;
byte difficulty = EASY;
byte player_skin;
byte ennemi_skin;
int score;
unsigned long shoot_timing;  //le temps de tir

Adafruit_SH1107 display = Adafruit_SH1107(64, 128, &Wire);

MyDispaly mydisplay;
Player player;
Ennemy ennemy;

void setup() {
  Serial.begin(9600);  //   Initialise the Serial port at 2400 baud.
  while (!Serial) {}
  display.begin(0x3C, true);
  display.clearDisplay();

  pinMode(BP_A, INPUT_PULLUP);
  // attachInterrupt(digitalPinToInterrupt(BP_A), bp_a, FALLING);
  pinMode(BP_B, INPUT_PULLUP);
  // attachInterrupt(digitalPinToInterrupt(BP_B), bp_b, FALLING);
  pinMode(BP_C, INPUT_PULLUP);
  // attachInterrupt(digitalPinToInterrupt(BP_C), bp_c, FALLING);
  pinMode(LED, OUTPUT);

  display.setTextSize(1.5);  // le chargement
  display.setTextColor(SH110X_WHITE);
  display.setRotation(1);
  display.setCursor(15, 15);
  display.print("Space");
  display.setCursor(15, 30);
  display.print("Invaders");
  display.setRotation(0);

  mydisplay.logo();

  display.display();

  // delay(2000);
  display.clearDisplay();
}

void loop() {
  switch (sequance) {
    case MENU:
      display.setRotation(1);
      display.setTextSize(1.5);
      display.setTextColor(SH110X_WHITE);

      mydisplay.menu(sequance, menu);

      if (!digitalRead(BP_A)) {
        while (!digitalRead(BP_A)) {}
        if (menu > 1)
          menu--;
        else
          menu = 4;
      }
      if (!digitalRead(BP_B)) {
        while (!digitalRead(BP_B)) {}
        sequance = menu;
      }
      if (!digitalRead(BP_C)) {
        while (!digitalRead(BP_C)) {}
        if (menu < 4)
          menu++;
        else
          menu = 1;
      }

      display.display();
      display.clearDisplay();
      break;
    case CLASSIC:
      display.setRotation(0);
      player.move(0);
      ennemy.move();

      if (!digitalRead(BP_A))
        player.move(1);

      if (!digitalRead(BP_B)) {
        if (millis() > shoot_timing + 150) {
          player.shoot();
          shoot_timing = millis();
        }
      }

      if (!digitalRead(BP_C))
        player.move(-1);

      display.display();
      display.clearDisplay();
      break;
    case DIFFICULTY:
      mydisplay.menu(sequance, choix_diff);

      if (!digitalRead(BP_A)) {
        while (!digitalRead(BP_A)) {}
        if (choix_diff > 1)
          choix_diff--;
        else
          choix_diff = 3;
      }
      if (!digitalRead(BP_B)) {
        while (!digitalRead(BP_B)) {}
        sequance = choix_diff;
      }
      if (!digitalRead(BP_C)) {
        while (!digitalRead(BP_C)) {}
        if (choix_diff < 3)
          choix_diff++;
        else
          choix_diff = 1;
      }
      display.display();
      display.clearDisplay();

      break;
  }
}