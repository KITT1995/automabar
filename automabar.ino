#include "cocktails.h"
#define btnUp 2
#define btnDown 3
#define btnOk 4
#define totCocktails 7

int selectedCocktail = 0;
bool delivery = 0;

String cocktail[totCocktails] = {"Gin Lemon", "Gin Tonic", "Vodka Tonik", "Vodka Lemon", "Jager Bomb", "Spritz", "Vodka Redbull"};

void setup() {
  // put your setup code here, to run once:
  pinMode(btnUp, INPUT);
  pinMode(btnDown, INPUT);
  pinMode(btnOk, INPUT);
  pinMode(pumpGin, OUTPUT);
  pinMode(pumpVodka, OUTPUT);
  pinMode(pumpLemon, OUTPUT);
  pinMode(pumpTonic, OUTPUT);
  pinMode(pumpAperol, OUTPUT);
  pinMode(pumpProsecco, OUTPUT);
  pinMode(pumpJager, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (delivery = 0) {
    Serial.print(cocktail[selectedCocktail]);
    if (digitalRead(btnUp) == HIGH) {
      if (selectedCocktail == 0) {
        selectedCocktail = totCocktails - 1;
      }
      else {
        selectedCocktail -= 1;
      }
    }
    else if (digitalRead(btnDown) == HIGH) {
      if (selectedCocktail == totCocktails - 1) {
        selectedCocktail = 0;
      }
      else {
        selectedCocktail += 1;
      }
    }
  }
}
