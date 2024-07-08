#include "wiring_digital.h"
#include "global.h"

Player::Player() {
  shoot_timing = millis();  // implementation du temps de tir
}

void Player::move(int movement) {
  if (movement == 1 && position < 58)
    position = position + movement;
  else if (movement == -1 && pos_joueur > 6)
    position = position + movement;

  switch (skin) {
    case DEFAULT:
      display.drawTriangle(pos_joueur - 5, 0, pos_joueur + 5, 0, pos_joueur, 10, SH110X_WHITE);
      break;
  }
}

void Player::shoot() {
  display.drawLine(pos_joueur, 10, pos_joueur, 127, SH110X_WHITE);
  munitions--;
  if (pos_joueur > pos_ennemi - 5 && pos_joueur < pos_ennemi + 5) {
    display.fillCircle(pos_ennemi, 122, 5, SH110X_WHITE);
    vies_ennemi--;
    if (vies_ennemi == 0) {
      score++;
      nombre_ennemi--;
      vies_ennemi = 2;
      if (nombre_ennemi == 0)
        fin();
    }
  }
  MyDisplay.stats();
  if (munitions == 0)
    MyDisplay.end();
}