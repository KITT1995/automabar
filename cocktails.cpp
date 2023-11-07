#include "cocktails.h"
extern LiquidCrystal_I2C lcd(0x27, 16, 2);
// unsigned long currentMillis;

void initialize_pins(){
  pinMode(pumpGin, OUTPUT);
  pinMode(pumpVodka, OUTPUT);
  pinMode(pumpLemon, OUTPUT);
  pinMode(pumpTonic, OUTPUT);
  pinMode(pumpAperol, OUTPUT);
  pinMode(pumpProsecco, OUTPUT);
  pinMode(pumpJager, OUTPUT);
  pinMode(pumpRedbull, OUTPUT);
  pinMode(pumpFernet, OUTPUT);
  pinMode(pumpCoke, OUTPUT);

  pinMode(btnUp, INPUT);
  pinMode(btnDown, INPUT);
  pinMode(btnOk, INPUT);
}

void GinLemon() {
  // una parte di gin e due di lemon
  //currentMillis = millis();
  int pumps[] = {pumpGin,pumpLemon};
  int parts[] = {1,2};
 // inizializeCocktail(pumps);
  executeCocktail(parts, pumps, sizeof(pumps)/sizeof(pumps[0]));  
}

void GinTonic() {
  // una parte di gin e due di tonica
  int pumps[] = {pumpGin,pumpLemon};
  int parts[] = {1,2};
 // inizializeCocktail(pumps);
  executeCocktail(parts, pumps, sizeof(pumps)/sizeof(pumps[0]));  
}

void VodkaTonic() {
  // una parte di vodka e due di tonica
  int pumps[] = {pumpVodka,pumpTonic};
  int parts[] = {1,2};
  //inizializeCocktail(pumps);
  executeCocktail(parts, pumps, sizeof(pumps)/sizeof(pumps[0]));    
}

void VodkaLemon() {
  // una parte di vodka e due di lemon
  int pumps[] = {pumpVodka,pumpLemon};
  int parts[] = {1,2};
  //inizializeCocktail(pumps);
  executeCocktail(parts, pumps, sizeof(pumps)/sizeof(pumps[0]));  
}

void VodkaRedbull() {
  // una 3 di vodka e 7 di redbull
  int pumps[] = {pumpVodka,pumpRedbull};
  int parts[] = {3,7};
  //inizializeCocktail(pumps);
  executeCocktail(parts, pumps, sizeof(pumps)/sizeof(pumps[0]));  
}

void JagerBomb() {
  // una parte di jager e tre di redbull
  int pumps[] = {pumpJager,pumpRedbull};
  int parts[] = {1,3};
  //inizializeCocktail(pumps);
  executeCocktail(parts, pumps, sizeof(pumps)/sizeof(pumps[0]));   
}

void Spritz() {
  // tre parti di prosecco, due di aperol e una di tonica
  int pumps[] = {pumpTonic,pumpAperol,pumpProsecco};
  int parts[] = {1,2,3};
  executeCocktail(parts, pumps, sizeof(pumps)/sizeof(pumps[0]));   
}

void Fernesito(){
  //1 fernet e 4 coca
  int pumps[] = {pumpFernet,pumpCoke};
  int parts[] = {1,4};
  executeCocktail(parts, pumps, sizeof(pumps)/sizeof(pumps[0]));   
}

void Manual(){
  selectedValue = 0;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Selezionare");
  lcd.setCursor(0, 1);
  lcd.print(ingredients[selectedValue]);
  do{
    if (millis() - timer >= delay) {
      //delay
      if (digitalRead(btnOk) == HIGH) {
        if (selectedValue < totIngredients - 1){
          callIngredient();
        }
        else {
          selectedValue = totCocktails - 1;
          delivery = 0;
          timer = millis();
          lcd.clear();
          break;
        }
      }
      else if (digitalRead(btnUp) == HIGH) {
        if (selectedValue == 0) {
          selectedValue = totIngredients - 1;
        }
        else {
          selectedValue -= 1;
        }
        //Serial.println(ingredients[selectedValue]);
        timer = millis();
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Selezionare");
        lcd.setCursor(0, 1);
        lcd.print(ingredients[selectedValue]);
      }
      else if (digitalRead(btnDown) == HIGH) {
        if (selectedValue == totIngredients - 1) {
          selectedValue = 0;
        }
        else {
          selectedValue += 1;
        }
        //Serial.println(ingredients[selectedValue]);
        timer = millis();
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Selezionare");
        lcd.setCursor(0, 1);
        lcd.print(ingredients[selectedValue]);
      }
    } 
  }while(delivery == 1);
}

void callIngredient() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Erogazione");
  lcd.setCursor(0, 1);
  lcd.print(ingredients[selectedValue]);
  
  do{
    switch(selectedValue){
      case 0:
        digitalWrite(pumpAperol, HIGH);
        break;
      case 1:
        digitalWrite(pumpCoke, HIGH);
        break;
      case 2:
        digitalWrite(pumpFernet, HIGH);
        break;
      case 3:
        digitalWrite(pumpGin, HIGH);
        break;
      case 4:
        digitalWrite(pumpJager, HIGH);
        break;
      case 5:
        digitalWrite(pumpLemon, HIGH);
        break;
      case 6:
        digitalWrite(pumpProsecco, HIGH);
        break;
      case 7:
        digitalWrite(pumpRedbull, HIGH);
        break;
      case 8:
        digitalWrite(pumpTonic, HIGH);
        break;
      case 9:
        digitalWrite(pumpVodka, HIGH);
        break;
    }
  }while (digitalRead(btnOk) == HIGH);

  switch(selectedValue){
      case 0:
        digitalWrite(pumpAperol, LOW);
        break;
      case 1:
        digitalWrite(pumpCoke, LOW);
        break;
      case 2:
        digitalWrite(pumpFernet, LOW);
        break;
      case 3:
        digitalWrite(pumpGin, LOW);
        break;
      case 4:
        digitalWrite(pumpJager, LOW);
        break;
      case 5:
        digitalWrite(pumpLemon, LOW);
        break;
      case 6:
        digitalWrite(pumpProsecco, LOW);
        break;
      case 7:
        digitalWrite(pumpRedbull, LOW);
        break;
      case 8:
        digitalWrite(pumpTonic, LOW);
        break;
      case 9:
        digitalWrite(pumpVodka, LOW);
        break;
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Selezionare");
  lcd.setCursor(0, 1);
  lcd.print(ingredients[selectedValue]);
}

void callCocktail() {
  switch(selectedValue){
    case 0:
      Fernesito();
      break;
    case 1: 
      GinLemon();
      break;
    case 2:
      GinTonic();
      break;
    case 3:
      JagerBomb();
      break;
    case 4:
      Spritz();
      break; 
    case 5:
      VodkaLemon();
      break;
    case 6:
      VodkaRedbull();
      break;   
    case 7:
      VodkaTonic();
      break;    
    case 8:
      Manual();
      break;
  } 
}

void initializeCocktail(int* pumpsVet, int lenght){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(cocktail[selectedValue]);
  //inizializza l'lcd impostando il nome del cocktail che sta per eseguire
  delivery = 1;
  
  //Serial.println(lenght);
  for(int i = 0; i < lenght; i++){
    //accende tutte le pompe che devono essere utilizzate
    //Serial.println(pumpsVet[i]);
    digitalWrite(pumpsVet[i], HIGH);
  }
}

/*
  @*part è il vettore delle parti di ogni ingrediente. il vettore deve essere in ordine crescente
  @*pumps è il vettore degli ingredienti rispettivamente alle parti
  @lenght è la lunghezz del vettore
  si può migliorare il codice facendo un piccolo metodo che ordina il vettore delle parti e il rispettivo
  vettore degli ingredienti
*/
void executeCocktail(int* part, int* pumps, int lenght){
  
  initializeCocktail(pumps, lenght);
  int sumParts = 0;
  int totParts = lenght;

  for(int i = 0; i<totParts; i++){
    sumParts += part[i];
  }

  do{
    for(int i = 0; i < totParts; i++){
      if (millis() - timer >= (glassUnityTime / sumParts) * part[i]){
        digitalWrite(pumps[i], LOW);
        if(i == (totParts-1)){
          delivery = 0;
        }          
      } 
      if (millis() - timer < (glassUnityTime / sumParts) * part[totParts - 1]){
        //lcd.setCursor(0,1);
        lcd.setCursor((millis() - timer) * 16 / ((glassUnityTime / sumParts)* part[totParts - 1]),1);
        lcd.write(0);
      }
    }
    if (digitalRead(btnOk) == HIGH) {
      if (millis() - timer >= delay){
        for(int i = 0; i < totParts; i++){
          digitalWrite(pumps[i], LOW);
        }
        delivery = 0;
        timer = millis();
      } 
    }  
  }while(delivery == 1);

  lcd.clear();
}