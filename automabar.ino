#include "cocktails.h"
#define progrSymbol B11111

int selectedValue = 0;
unsigned long timer = 0;
bool delivery = 0;
byte progressSymbol[] = {progrSymbol, progrSymbol, progrSymbol, progrSymbol, progrSymbol, progrSymbol, progrSymbol, progrSymbol};

String cocktail[totCocktails] = { "Fernesito", "Gin Lemon", "Gin Tonic", "Jager Bomb", "Spritz", "Vodka Lemon", "Vodka Redbull", "Vodka Tonic", "Manuale"};
String ingredients[totIngredients] = {"Aperol", "Coca Cola", "Fernet", "Gin", "Jager", "Lemon", "Prosecco", "Redbull", "Tonica", "Vodka", "Indietro"};

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, progressSymbol);
  pinMode(btnUp, INPUT);
  pinMode(btnDown, INPUT);
  pinMode(btnOk, INPUT);
  initialize_pump();
  //Serial.begin(9600);
}

void loop() {
  if (delivery == 0) {
    lcd.setCursor(0, 0);
    lcd.print("Selezionare");
    lcd.setCursor(0, 1);
    lcd.print(cocktail[selectedValue]);
    
    if (millis() - timer >= delay) {
      //delay
      if (digitalRead(btnUp) == HIGH) {
        if (selectedValue == 0) {
          //se viene cliccato il pulsante freccia su quando il cocktail selezionato 
          //è il primo allora si giunge all'ultimo selezionato altrimenti si prosegue con la lista
          selectedValue = totCocktails - 1;
        }
        else {
          selectedValue -= 1;
        }
        //Serial.println(cocktail[selectedValue]);
        lcd.clear();
        timer = millis();
      }
      else if (digitalRead(btnDown) == HIGH) {
        if (selectedValue == totCocktails - 1) {
          //al contrario se il cocktail selezionato è l'ultimo
          selectedValue = 0;
        }
        else {
          selectedValue += 1;
        }
        //Serial.println(cocktail[selectedValue]);
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
