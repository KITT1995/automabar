#include "Arduino.h"
#include <LiquidCrystal_I2C.h>
#define pumpGin 5
#define pumpVodka 6
#define pumpLemon 7
#define pumpTonic 8
#define pumpAperol 9
#define pumpProsecco 10
#define pumpJager 11
#define pumpRedbull 12
// tempo in millisecondi che dovrebbe metterci in totale un bicchiere a riempirsi
#define glassUnityTime 10000

extern LiquidCrystal_I2C lcd;
extern bool delivery;
extern int selectedCocktail;
extern unsigned long timer;
extern String cocktail[];
extern byte progressSimbol[];

void GinLemon ();
void GinTonic ();
void VodkaTonic ();
void VodkaLemon ();
void VodkaRedbull ();
void JagerBomb ();
void Spritz ();
void inizialize_pump();
void callCocktail();

