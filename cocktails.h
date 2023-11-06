#include "Arduino.h"
#include <LiquidCrystal_I2C.h>
#define btnUp 2
#define btnDown 3
#define btnOk 4
#define pumpGin 5
#define pumpVodka 6
#define pumpLemon 7
#define pumpTonic 8
#define pumpAperol 9
#define pumpProsecco 10
#define pumpJager 11
#define pumpRedbull 12
#define pumpCoke 13
#define pumpFernet A1
// tempo in millisecondi che dovrebbe metterci in totale un bicchiere a riempirsi
#define glassUnityTime 10000
#define delay 200

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
void Fernesito();
void initializeCocktail(int *pumps, int lenght);
void executeCocktail3ingredients(int minorPart, int mediumPart, int majorPart, int minorPartPump,int mediumPartPump, int majorPartPump);
void executeCocktail2ingredients(int minorPart,int majorPart, int minorPartPump,int majorPartPump);
void executeCocktail(int* part, int* pumps, int lenght);
void initialize_pump();
void callCocktail();

