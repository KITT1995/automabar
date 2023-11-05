#include "cocktails.h"
#define btnUp 2
#define btnDown 3
#define btnOk 4
#define totCocktails 7

int selectedCocktail = 0;
unsigned long timer = 0;
bool delivery = 0;
byte progressSymbol[] = {B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111};

String cocktail[totCocktails] = {"Gin Lemon", "Gin Tonic", "Vodka Tonik", "Vodka Lemon", "Vodka Redbull", "Jager Bomb", "Spritz"};

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, progressSymbol);
  pinMode(btnUp, INPUT);
  pinMode(btnDown, INPUT);
  pinMode(btnOk, INPUT);
  inizialize_pump();
}

void loop() {
  
  if (delivery == 0) {
    lcd.setCursor(0, 0);
    lcd.print("Selezionare");
    lcd.setCursor(0, 1);
    lcd.print(cocktail[selectedCocktail]);
    if (millis() - timer >= 200) {
      //delay
      if (digitalRead(btnUp) == HIGH) {
        if (selectedCocktail == 0) {
          //se viene cliccato il pulsante su quando il cocktail selezionato 
          //è il primo allora si giunge all'ultimo selezionato altrimenti si prosegue con la lista
          selectedCocktail = totCocktails - 1;
        }
        else {
          selectedCocktail -= 1;
        }
        lcd.clear();
        timer = millis();
      }
      else if (digitalRead(btnDown) == HIGH) {
        if (selectedCocktail == totCocktails - 1) {
          //al contrario se il cocktail selezionato è l'ultimo
          selectedCocktail = 0;
        }
        else {
          selectedCocktail += 1;
        }
        lcd.clear();
        timer = millis();
      }
      else if (digitalRead(btnOk) == HIGH) {
        delivery = 1;
        timer = millis();
        callCocktail();
      }
    } 
  }
}
