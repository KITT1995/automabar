#include "cocktails.h"
#define btnUp 2
#define btnDown 3
#define btnOk 4
#define totCocktails 7

int selectedCocktail = 0;
bool delivery = 0;

String cocktail[totCocktails] = {"Gin Lemon", "Gin Tonic", "Vodka Tonik", "Vodka Lemon", "Jager Bomb", "Spritz", "Vodka Redbull"};

void setup() {

  pinMode(btnUp, INPUT);
  pinMode(btnDown, INPUT);
  pinMode(btnOk, INPUT);

  inizialize_pomp();
  
  Serial.begin(9600);
}

void loop() {
  
  if (delivery == 0) {
    Serial.print(cocktail[selectedCocktail]);
    if (digitalRead(btnUp) == HIGH) {
      if (selectedCocktail == 0) {
        //se viene cliccato il pulsante su quando il cocktail selezionato 
        //è il primo allora si giunge all'ultimo selezionato altrimenti si prosegue con la lista
        selectedCocktail = totCocktails - 1;
      }
      else {
        selectedCocktail -= 1;
      }
    }
    else if (digitalRead(btnDown) == HIGH) {
      if (selectedCocktail == totCocktails - 1) {
        //al contrario se il cocktail selezionato è l'ultimo
        selectedCocktail = 0;
      }
      else {
        selectedCocktail += 1;
      }
    }
  }
}
