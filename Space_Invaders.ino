#include "global.h"

byte sequance = 1;
byte choix_menu = 1;
byte skin;
int score;
unsigned long temps_tir;  //le temps de tir

Adafruit_SH1107 display = Adafruit_SH1107(64, 128, &Wire);

Affichage affichage;

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

  temps_tir = millis();  // implementation du temps de tir

  display.setTextSize(1.5);  // le chargement
  display.setTextColor(SH110X_WHITE);
  display.setRotation(1);
  display.setCursor(15, 15);
  display.print("Space");
  display.setCursor(15, 30);
  display.print("Invaders");
  display.setRotation(0);

  affichage.logo();
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

      affichage.menu(choix_menu);

      if (!digitalRead(BP_A)) {
        while (!digitalRead(BP_A)) {}
        if (choix_menu > 1)
          choix_menu--;
        else
          choix_menu = 4;
      }
      if (!digitalRead(BP_B)) {
        while (!digitalRead(BP_B)) {}
        sequance = choix_menu;
      }
      if (!digitalRead(BP_C)) {
        while (!digitalRead(BP_C)) {}
        if (choix_menu < 4)
          choix_menu++;
        else
          choix_menu = 1;
      }

      display.display();
      display.clearDisplay();
      break;
    case NORMAL:
      display.setRotation(0);
      affichage.joueur(0);
      affichage.ennemi();

      if (!digitalRead(BP_A))
        affichage.joueur(1);

      if (!digitalRead(BP_B)) {
        if (millis() > temps_tir + 150) {
          affichage.tir();
          temps_tir = millis();
        }
      }

      if (!digitalRead(BP_C))
        affichage.joueur(-1);

      display.display();
      display.clearDisplay();
      break;
  }
}