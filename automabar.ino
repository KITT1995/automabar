#include "cocktails.h"

int selectedValue = 0;
unsigned long timer = 0;
bool delivery = 0;
byte progressSymbol[] = {progrSymbol, progrSymbol, progrSymbol, progrSymbol, progrSymbol, progrSymbol, progrSymbol, progrSymbol};

String cocktail[totCocktails] = {"Fernesito", "Gin Lemon", "Gin Tonic", "Jager Bomb", "Spritz", "Vodka Lemon", "Vodka Redbull", "Vodka Tonic", "Manuale"};
String ingredients[totIngredients] = {"Aperol", "Coca Cola", "Fernet", "Gin", "Jager", "Lemon", "Prosecco", "Redbull", "Tonica", "Vodka", "Indietro"};

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, progressSymbol);
  
  initialize_pins();
  shutdown_pins();
  //Serial.begin(9600);
}

void loop() {
  //delivery = 0 se non c'è nulla in esecuzione
  //delivery = 1 se il cocktail è in esecuzione
  if (delivery == 0) {
    //setta il cursone sulla prima colonna e prima riga per poter scrivere
    lcd.setCursor(0, 0);
    lcd.print("Selezionare");
    //setta il cursore sulla prima colonna e seconda riga per poter scrivere
    lcd.setCursor(0, 1);
    lcd.print(cocktail[selectedValue]);
    
    //questo delay evita che cliccndo il pulsante per qualche millisecondo in più salti dei cocktail
    if (millis() - timer >= delay) {
      //delay
      if (digitalRead(btnUp) == HIGH) {
        selectedValue = manageButtonUp(selectedValue);
        //Serial.println(cocktail[selectedValue]);
        lcd.clear();
        timer = millis();
      }
      else if (digitalRead(btnDown) == HIGH) {
        selectedValue = manageButtonDown(selectedValue);
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

int manageButtonUp(int selectedValue){

  if (selectedValue == 0) {
    //se viene cliccato il pulsante freccia su quando il cocktail selezionato 
    //è il primo allora si giunge all'ultimo selezionato altrimenti si prosegue con la lista
    selectedValue = totCocktails - 1;
  }
  else {
    selectedValue -= 1;
  }

  return selectedValue;

}

int manageButtonDown(int selectedValue){

  if (selectedValue == totCocktails - 1) {
    //al contrario se il cocktail selezionato è l'ultimo
    selectedValue = 0;
  }
  else {
    selectedValue += 1;
  }

  return selectedValue;

}

