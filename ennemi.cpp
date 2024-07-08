#include "wiring_digital.h"
#include "global.h"

Ennemy::Ennemy() {}
Ennemy::move() {
  switch (sequance) {
    case CLASSIC:
      if (dep_ennemi == true)
        pos_ennemi++;
      if (dep_ennemi == false)
        pos_ennemi--;

      if (pos_ennemi == 58)
        dep_ennemi = false;
      if (pos_ennemi == 6)
        dep_ennemi = true;

      switch (skin_ennemi) {
        case DEFAULT:
          display.drawCircle(pos_ennemi, 122, 5, SH110X_WHITE);
          break;
      }
      break;
  }
}
Ennemy::shoot() {
}
