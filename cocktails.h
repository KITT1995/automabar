#include "Arduino.h"
#include <LiquidCrystal_I2C.h>
#define btnUp 2
#define btnDown 3
#define btnOk 4

#define pumpAperol 5
#define pumpCoke 6
#define pumpFernet 7
#define pumpGin 8
#define pumpJager 9
#define pumpLemon 10

#define pumpProsecco 11
#define pumpRedbull 12
#define pumpTonic 13
#define pumpVodka A0
// tempo in millisecondi che dovrebbe metterci in totale un bicchiere a riempirsi
#define glassUnityTime 12500
#define delay 300
#define totCocktails 9
#define totIngredients 11
#define progrSymbol B11111

extern LiquidCrystal_I2C lcd;
extern bool delivery;
extern int selectedValue;
extern unsigned long timer;
extern String cocktail[];
extern String ingredients[];
extern byte progressSimbol[];

void GinLemon ();
void GinTonic ();
void VodkaTonic ();
void VodkaLemon ();
void VodkaRedbull ();
void JagerBomb ();
void Spritz ();
void Fernesito();
void Manual();
void initializeCocktail(int* pumps, int lenght, String cocktail);
void executeSingleIngredients(String ingredient, int pump);
void executeCocktail(String cocktail, int* part, int* pumps, int lenght, int glassUnityTimePersonal);
void initialize_pins();
void shutdown_pins();
void callCocktail();
void callIngredient();
extern int arraySum(int* array, int length);