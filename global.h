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
#define NORMAL 1
#define VS 2
#define SURVIVAL 3
#define SETTINGS 4

// DEFINITION DES SKINS
#define DEFAULT 0

// DEFINITION DES DIFFICULTES CHOISIES
#define EASY 0

extern unsigned long t;  //le temps de tir

extern byte sequance;
extern byte choix_menu;
extern byte skin;

extern Adafruit_SH1107 display;

class Affichage {
private:
  String choix_0;
  String choix_1;
  String choix_2;

  byte pos_joueur = 16;
  byte pos_ennemi = 48;

  bool dep_ennemi = true;

public:
  Affichage();
  void menu(int choix_menu);
  void joueur(int dep);
  void ennemi();
  void tir();
  void logo();
};

#endif