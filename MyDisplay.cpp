#include "wiring_digital.h"
#include "global.h"

MyDisplay::MyDisplay() {}

void MyDisplay::menu(byte sequance, byte choice) {
  switch (sequance) {
    case MENU:
      switch (choice) {
        case CLASSIC:
          choice_0 = "Settings";
          choice_1 = "Normal Mode";
          choice_2 = "VS Mode";
          break;
        case VS:
          choice_0 = "Normal Mode";
          choice_1 = "VS Mode";
          choice_2 = "Skin Select";
          break;
        case SKIN:
          choice_0 = "VS Mode";
          choice_1 = "Skin Select";
          choice_2 = "Settings";
          break;
        case DIFFICULTY:
          choice_0 = "Skin Select";
          choice_1 = "Settings";
          choice_2 = "Normal Mode";
          break;
      }
      break;
    case SKIN:
      break;
    case DIFFICULTY:
      switch (choix) {
        case EASY:
          choice_0 = "Hard";
          choice_1 = "Easy";
          choice_2 = "Normal";
          break;
        case NORMAL:
          choice_0 = "Easy";
          choice_1 = "Normal";
          choice_2 = "Hard";
          break;
        case HARD:
          choice_0 = "Normal";
          choice_1 = "Hard";
          choice_2 = "Easy";
          break;
      }
      break;
  }

  // AFFICHAGE DES RECTANGLES
  display.drawLine(5, 29, 5, 37, SH110X_WHITE);
  display.drawLine(8, 26, 115, 26, SH110X_WHITE);
  display.drawLine(5, 29, 8, 26, SH110X_WHITE);
  display.drawLine(118, 29, 118, 37, SH110X_WHITE);
  display.drawLine(8, 40, 115, 40, SH110X_WHITE);
  display.drawLine(118, 37, 115, 40, SH110X_WHITE);
  display.drawLine(118, 29, 115, 26, SH110X_WHITE);
  display.drawLine(5, 37, 8, 40, SH110X_WHITE);

  // AFFICHAGE DU TEXTE
  display.setTextSize(1);
  display.setCursor(10, 13);
  display.print(choice_0);
  display.setTextSize(1.5);
  display.setCursor(10, 30);
  display.print(choice_1);
  display.setTextSize(1);
  display.setCursor(10, 47);
  display.print(choice_2);
}

void MyDisplay::stats() {
  Serial.println("JOUEUR :");
  Serial.print("vies =");
  Serial.println(vies_joueur);
  Serial.print("munitions = ");
  Serial.println(munitions);
  Serial.println("ENNEMIS :");
  Serial.print("vies = ");
  Serial.println(vies_ennemi);
  Serial.print("ennemis restants = ");
  Serial.println(nombre_ennemi);
  Serial.print("SCORE : ");
  Serial.println(score);
  Serial.println("-------------------------------------------------------------");
}

void MyDisplay::end() {
  Serial.println("GAME OVER !");
  Serial.println("-------------------------------------------------------------");
  stats();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setRotation(1);
  display.setCursor(15, 10);

  if (munitions == 0 || vies_joueur == 0)
    display.print("GAME OVER");
  if (nombre_ennemi == 0) {
    display.print("YOU WON !");
  }
  display.setCursor(15, 30);
  display.print("SCORE : ");
  display.print(score);
  logo();
  display.setRotation(1);
  display.setCursor(40, 55);
  display.print("press A");
  display.display();
  while (digitalRead(BP_A)) {}
  while (!digitalRead(BP_A)) {}
  pos_joueur = 16;
  pos_ennemi = 48;
  dep_ennemi = true;
  vies_joueur = 5;
  vies_ennemi = 2;
  nombre_ennemi = 5;
  munitions = 250;
  sequance = MENU;
}

void MyDisplay::logo() {
  display.setRotation(0);
  display.drawLine(7, 4, 7, 10, SH110X_WHITE);  //   logo
  display.drawLine(7, 4, 5, 2, SH110X_WHITE);
  display.drawLine(5, 2, 3, 2, SH110X_WHITE);
  display.drawLine(5, 2, 5, 12, SH110X_WHITE);
  display.drawLine(6, 3, 6, 4, SH110X_WHITE);
  display.drawLine(6, 6, 6, 8, SH110X_WHITE);
  display.drawLine(6, 10, 6, 11, SH110X_WHITE);
  display.drawLine(5, 12, 3, 12, SH110X_WHITE);
  display.drawLine(8, 5, 9, 4, SH110X_WHITE);
  display.drawLine(8, 9, 9, 10, SH110X_WHITE);
  display.drawLine(4, 4, 4, 10, SH110X_WHITE);
  display.drawLine(4, 4, 3, 4, SH110X_WHITE);
  display.drawLine(4, 10, 3, 10, SH110X_WHITE);
  display.drawLine(2, 5, 2, 6, SH110X_WHITE);
  display.drawLine(2, 8, 2, 9, SH110X_WHITE);
}