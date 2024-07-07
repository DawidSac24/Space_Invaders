#include "wiring_digital.h"
#include "global.h"

Affichage::Affichage() {
}

void Affichage::menu(int choix_menu) {
  switch (choix_menu) {
    case 1:
      choix_0 = "Settings";
      choix_1 = "Normal Mode";
      choix_2 = "VS Mode";
      break;
    case 2:
      choix_0 = "Normal Mode";
      choix_1 = "VS Mode";
      choix_2 = "Survival Mode";
      break;
    case 3:
      choix_0 = "VS Mode";
      choix_1 = "Survival Mode";
      choix_2 = "Settings";
      break;
    case 4:
      choix_0 = "Survival Mode";
      choix_1 = "Settings";
      choix_2 = "Normal Mode";
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
  display.print(choix_0);
  display.setTextSize(1.5);
  display.setCursor(10, 30);
  display.print(choix_1);
  display.setTextSize(1);
  display.setCursor(10, 47);
  display.print(choix_2);
}

void Affichage::joueur(int dep) {
  if (dep == 1 && pos_joueur < 58)
    pos_joueur = pos_joueur + dep;
  else if (dep == -1 && pos_joueur > 6)
    pos_joueur = pos_joueur + dep;

  switch (skin) {
    case DEFAULT:
      display.drawTriangle(pos_joueur - 5, 0, pos_joueur + 5, 0, pos_joueur, 10, SH110X_WHITE);
      break;
  }
}

void Affichage::ennemi() {
  switch (sequance) {
    case NORMAL:

      if (dep_ennemi == true)
        pos_ennemi++;
      if (dep_ennemi == false)
        pos_ennemi--;

      if (pos_ennemi == 58)
        dep_ennemi = false;
      if (pos_ennemi == 6)
        dep_ennemi = true;

      switch (skin) {
        case DEFAULT:
          display.drawCircle(pos_ennemi, 122, 5, SH110X_WHITE);
          break;
      }
      break;
  }
}

void Affichage::tir() {
  display.drawLine(pos_joueur, 10, pos_joueur, 127, SH110X_WHITE);
  munitions--;
  if (pos_joueur > pos_ennemi - 5 && pos_joueur < pos_ennemi + 5) {
    display.fillCircle(pos_ennemi, 122, 5, SH110X_WHITE);
    vies_ennemi--;
    if (vies_ennemi == 0) {
      nombre_ennemi--;
      vies_ennemi = 2;
      if (nombre_ennemi == 0)
        fin();
    }
    score++;
  }
  stats();
  if (munitions == 0)
    fin();
}

void Affichage::stats() {
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

void Affichage::fin() {
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
  pos_joueur = 16;
  pos_ennemi = 48;
  dep_ennemi = true;
  vies_joueur = 5;
  vies_ennemi = 2;
  nombre_ennemi = 5;
  munitions = 250;
  sequance = MENU;
  logo();
  display.setRotation(1);
  display.setCursor(40, 55);
  display.print("press A");
  display.display();
  while (digitalRead(BP_A)) {}
}

void Affichage::logo() {
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