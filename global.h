#ifndef global_h
#define global_h

#include "Arduino.h"
#include <Adafruit_SH110X.h>  // Librairie de l'écran
#include <Adafruit_NeoPixel.h>

// DEFINITION DES PATTES
#define NEOPIXEL_PIN 8
#define BP_A 9
#define BP_B 6
#define BP_C 5
#define LED 13

// DEFINITION DES SEQUANCES
#define MENU 0
#define CLASSIC 1
#define VS 2
#define SKIN 3
#define DIFFICULTY 4

// DEFINITION DES SKINS
#define DEFAULT 0

// DEFINITION DES DIFFICULTES CHOISIES
#define EASY 1
#define NORMAL 2
#define HARD 3

extern byte sequance;
extern byte choix_menu;
extern byte choix_diff;
extern byte skin_joueur;
extern byte skin_ennemi;
extern int score;

extern Adafruit_SH1107 display;

class MyDispaly {
private:
  String choice_0;
  String choice_1;
  String choice_2;
public:
  MyDispaly();
  void menu(byte sequance, byte choice);
  void stats();
  void end();
  void logo();
};

class Player {
private:
public:
  Player();
  void move(int movement);
  void shoot();
};

class Ennemy {
private:
public:
  Ennemy();
  void move();
  void shoot();
};

#endif