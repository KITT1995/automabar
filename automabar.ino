#include "cocktails.h"

int selectedValueCocktail = 0;
int selectedValueIngredient = 0;

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
  Serial.begin(9600);
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
    lcd.print(cocktail[selectedValueCocktail]);
    
    //questo delay2 evita che cliccndo il pulsante per qualche millisecondo in più salti dei cocktail
    if (millis() - timer >= delay2) {
      //delay2
      if (digitalRead(btnUp) == HIGH) {
        selectedValueCocktail = manageButtonUp(selectedValueCocktail);
        //Serial.println(cocktail[selectedValueCocktail]);
        lcd.clear();
        timer = millis();
      }
      else if (digitalRead(btnDown) == HIGH) {
        selectedValueCocktail = manageButtonDown(selectedValueCocktail);
        //Serial.println(cocktail[selectedValueCocktail]);
        lcd.clear();
        timer = millis();
      }
      else if (digitalRead(btnOk) == HIGH) {
        delivery = 1;
        timer = millis();
        while(digitalRead(btnOk) == HIGH){
          if(millis() - timer >= 2000){
            timer = millis();
            allPumps();
            //delivery = 0;
            //delay(600);
          }            
        }
        
        if (millis() - timer <= delay2){
          
          callCocktail();
        }else
        delivery = 0;
          
         
      }
    } 
  }
}

int manageButtonUp(int selectedValueCocktail){

  if (selectedValueCocktail == 0) {
    //se viene cliccato il pulsante freccia su quando il cocktail selezionato 
    //è il primo allora si giunge all'ultimo selezionato altrimenti si prosegue con la lista
    selectedValueCocktail = totCocktails - 1;
  }
  else {
    selectedValueCocktail -= 1;
  }

  return selectedValueCocktail;

}

int manageButtonDown(int selectedValueCocktail){

  if (selectedValueCocktail == totCocktails - 1) {
    //al contrario se il cocktail selezionato è l'ultimo
    selectedValueCocktail = 0;
  }
  else {
    selectedValueCocktail += 1;
  }

  return selectedValueCocktail;

}

