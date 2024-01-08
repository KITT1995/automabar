#include "cocktails.h"
extern LiquidCrystal_I2C lcd(0x27, 16, 2);
// unsigned long currentMillis;

void initialize_pins(){
  pinMode(pumpAperol, OUTPUT);
  pinMode(pumpCoke, OUTPUT);
  pinMode(pumpFernet, OUTPUT);
  pinMode(pumpGin, OUTPUT);
  pinMode(pumpJager, OUTPUT);
  pinMode(pumpLemon, OUTPUT);
  pinMode(pumpProsecco, OUTPUT);
  pinMode(pumpRedbull, OUTPUT);
  pinMode(pumpTonic, OUTPUT);
  pinMode(pumpVodka, OUTPUT);

  pinMode(btnUp, INPUT);
  pinMode(btnDown, INPUT);
  pinMode(btnOk, INPUT);
}

void shutdown_pins(){
  digitalWrite(pumpAperol, HIGH);
  digitalWrite(pumpCoke, HIGH);
  digitalWrite(pumpFernet, HIGH);
  digitalWrite(pumpGin, HIGH);
  digitalWrite(pumpJager, HIGH);
  digitalWrite(pumpLemon, HIGH);
  digitalWrite(pumpRedbull, HIGH);
  digitalWrite(pumpProsecco, HIGH);
  digitalWrite(pumpTonic, HIGH);
  digitalWrite(pumpVodka, HIGH);

}

void turnOnAll(){
  digitalWrite(pumpAperol, LOW);
  digitalWrite(pumpCoke, LOW);
  digitalWrite(pumpFernet, LOW);
  digitalWrite(pumpGin, LOW);
  digitalWrite(pumpJager, LOW);
  digitalWrite(pumpLemon, LOW);
  digitalWrite(pumpRedbull, LOW);
  digitalWrite(pumpProsecco, LOW);
  digitalWrite(pumpTonic, LOW);
  digitalWrite(pumpVodka, LOW);
}


void allPumps(){
  int pumps[] = {pumpAperol, pumpCoke, pumpFernet, pumpGin, pumpJager};
  int pumps2[] = {pumpLemon, pumpRedbull, pumpProsecco, pumpTonic, pumpVodka};
  int parts[] = {1,1,1,1,1};
 // inizializeCocktail(pumps);
  executeCocktail("Cleaning p1", parts, pumps, sizeof(pumps)/sizeof(pumps[0]),5000);
  delivery = executeCocktail("Cleaning p2", parts, pumps2, sizeof(pumps2)/sizeof(pumps2[0]),5000);  
}

void GinLemon() {
  // una parte di gin e due di lemon
  //currentMillis = millis();
  int pumps[] = {pumpGin,pumpLemon};
  int parts[] = {1,2};
 // inizializeCocktail(pumps);
  delivery = executeCocktail(cocktail[selectedValueCocktail], parts, pumps, sizeof(pumps)/sizeof(pumps[0]),glassUnityTime);  
}

void GinTonic() {
  // una parte di gin e due di tonica
  int pumps[] = {pumpGin,pumpTonic};
  int parts[] = {1,2};
 // inizializeCocktail(pumps);
  delivery = executeCocktail(cocktail[selectedValueCocktail], parts, pumps, sizeof(pumps)/sizeof(pumps[0]),glassUnityTime);  
}

void VodkaTonic() {
  // una parte di vodka e due di tonica
  int pumps[] = {pumpVodka,pumpTonic};
  int parts[] = {1,2};
  //inizializeCocktail(pumps);
  delivery = executeCocktail(cocktail[selectedValueCocktail], parts, pumps, sizeof(pumps)/sizeof(pumps[0]),glassUnityTime);    
}

void VodkaLemon() {
  // una parte di vodka e due di lemon
  int pumps[] = {pumpVodka,pumpLemon};
  int parts[] = {1,2};
  //inizializeCocktail(pumps);
  delivery = executeCocktail(cocktail[selectedValueCocktail], parts, pumps, sizeof(pumps)/sizeof(pumps[0]),glassUnityTime);  
}


void VodkaRedbull() {
  // una 3 di vodka e 7 di redbull
  int pumps[] = {pumpVodka,pumpRedbull};
  int parts[] = {3,7};
  //inizializeCocktail(pumps);
  delivery = executeCocktail(cocktail[selectedValueCocktail], parts, pumps, sizeof(pumps)/sizeof(pumps[0]),glassUnityTime);  
}

void JagerBomb() {
  // una parte di jager e tre di redbull
  int pumps[] = {pumpJager,pumpRedbull};
  int parts[] = {1,3};
  //inizializeCocktail(pumps);
  delivery = executeCocktail(cocktail[selectedValueCocktail], parts, pumps, sizeof(pumps)/sizeof(pumps[0]),glassUnityTime);   
}

void Spritz() {
  // 3 prosecco, 2 aperol e 1 tonica
  int pumps[] = {pumpTonic,pumpAperol,pumpProsecco};
  int parts[] = {3,2,8};
  delivery = executeCocktail(cocktail[selectedValueCocktail], parts, pumps, sizeof(pumps)/sizeof(pumps[0]),glassUnityTime + (glassUnityTime/arraySum(parts, sizeof(parts)/sizeof(parts[0]))*6));
  //executeCocktail(cocktail[selectedValueCocktail], parts, pumps, sizeof(pumps)/sizeof(pumps[0]),glassUnityTime + ((glassUnityTime/9)*3));   
}

void Fernesito(){
  //1 fernet e 4 coca
  int pumps[] = {pumpFernet,pumpCoke};
  int parts[] = {2,7};
  //9 sarebbe 2+7 mentre 4 sarebbe la differenza tra il totale delle parti originali e il totale delle parti attuali
  delivery = executeCocktail(cocktail[selectedValueCocktail], parts, pumps, sizeof(pumps)/sizeof(pumps[0]),glassUnityTime + (glassUnityTime/arraySum(parts, sizeof(parts)/sizeof(parts[0]))*4));
  //executeCocktail(cocktail[selectedValueCocktail], parts, pumps, sizeof(pumps)/sizeof(pumps[0]), glassUnityTime + ((glassUnityTime/9)*4));   
}

void Manual(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Selezionare");
  lcd.setCursor(0, 1);
  lcd.print(ingredients[selectedValueIngredient]);
  do{
    if (millis() - timer >= delay) {
      //delay
      if (digitalRead(btnOk) == HIGH) {
        if (selectedValueIngredient < totIngredients - 1){          
          timer = millis();
          callIngredient();
        }
        else {
          selectedValueIngredient = totCocktails - 1;
          delivery = 0;
          timer = millis();
          lcd.clear();
          return;
        }
      }
      else if (digitalRead(btnUp) == HIGH) {
        if (selectedValueIngredient == 0) {
          selectedValueIngredient = totIngredients - 1;
        }
        else {
          selectedValueIngredient -= 1;
        }
        //Serial.println(ingredients[selectedValueCocktail]);
        timer = millis();
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Selezionare");
        lcd.setCursor(0, 1);
        lcd.print(ingredients[selectedValueIngredient]);
      }
      else if (digitalRead(btnDown) == HIGH) {
        if (selectedValueIngredient == totIngredients - 1) {
          selectedValueIngredient = 0;
        }
        else {
          selectedValueIngredient += 1;
        }
        //Serial.println(ingredients[selectedValueCocktail]);
        timer = millis();
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Selezionare");
        lcd.setCursor(0, 1);
        lcd.print(ingredients[selectedValueIngredient]);
      }
    } 
  }while(delivery == 1);
}


void executeSingleIngredients(String ingredient, int pump){
  int pumps[] = {pump};
  int parts[] = {1};
  executeCocktail(ingredient, parts, pumps, 1,glassUnityTime); 
}


void callIngredient() {
  /*lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Erogazione");
  lcd.setCursor(0, 1);
  lcd.print(ingredients[selectedValueCocktail]);
  */
  
    switch(selectedValueCocktail){
      case 0:
        executeSingleIngredients(ingredients[selectedValueCocktail], pumpAperol);
        //digitalWrite(pumpAperol, LOW);
        break;
      case 1:
        executeSingleIngredients(ingredients[selectedValueCocktail], pumpCoke);        
        //digitalWrite(pumpCoke, LOW);
        break;
      case 2:
        executeSingleIngredients(ingredients[selectedValueCocktail], pumpFernet);        
        
        //digitalWrite(pumpFernet, LOW);
        break;
      case 3:
        executeSingleIngredients(ingredients[selectedValueCocktail], pumpGin);        
              
        //digitalWrite(pumpGin, LOW);
        break;
      case 4:
        executeSingleIngredients(ingredients[selectedValueCocktail], pumpJager);        
        
        //digitalWrite(pumpJager, LOW);
        break;
      case 5:
        executeSingleIngredients(ingredients[selectedValueCocktail], pumpLemon);        
        
        //digitalWrite(pumpLemon, LOW);
        break;
      case 6:
        executeSingleIngredients(ingredients[selectedValueCocktail], pumpProsecco);        
        
        //digitalWrite(pumpProsecco, LOW);
        break;
      case 7:
        executeSingleIngredients(ingredients[selectedValueCocktail], pumpRedbull);        
        
        //digitalWrite(pumpRedbull, LOW);
        break;
      case 8:
        executeSingleIngredients(ingredients[selectedValueCocktail], pumpTonic);        
        
        //digitalWrite(pumpTonic, LOW);
        break;
      case 9:
        executeSingleIngredients(ingredients[selectedValueCocktail], pumpVodka);        
        
        //digitalWrite(pumpVodka, LOW);
        break;
      default: 
        break;
    }

  shutdown_pins();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Selezionare");
  lcd.setCursor(0, 1);
  lcd.print(ingredients[selectedValueCocktail]);
}

void callCocktail() {
  switch(selectedValueCocktail){
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

void initializeCocktail(int* pumpsVet, int length, String cocktail){
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(cocktail);
  //inizializza l'lcd impostando il nome del cocktail che sta per eseguire
  delivery = 1;
  
  //Serial.println(length);
  for(int i = 0; i < length; i++){
    //accende tutte le pompe che devono essere utilizzate
    Serial.println(pumpsVet[i]);
    digitalWrite(pumpsVet[i], LOW);
  }
}

/*
  @*part è il vettore delle parti di ogni ingrediente. il vettore deve essere in ordine crescente
  @*pumps è il vettore degli ingredienti rispettivamente alle parti
  @length è la lunghezz del vettore
  si può migliorare il codice facendo un piccolo metodo che ordina il vettore delle parti e il rispettivo
  vettore degli ingredienti
*/
int executeCocktail(String cocktail, int* part, int* pumps, int length, int glassUnityTimePersonal){
  
  initializeCocktail(pumps, length, cocktail);
  int totParts = length;
  /*int sumParts = 0;
  for(int i = 0; i<totParts; i++){
    sumParts += part[i];
  }*/
  int sumParts = arraySum(part, length);
  int internalDelivery = delivery;

  do{
    for(int i = 0; i < totParts; i++){
      if (millis() - timer >= (glassUnityTimePersonal / sumParts) * part[i]){
        Serial.println("shutdown ");
        
        Serial.println(pumps[i]);

        digitalWrite(pumps[i], HIGH);
        if(i == (totParts-1)){
          internalDelivery = 0;
        }          
      } 
      if (millis() - timer < (glassUnityTimePersonal / sumParts) * part[totParts - 1]){
        //lcd.setCursor(0,1);
        lcd.setCursor((millis() - timer) * 16 / ((glassUnityTimePersonal / sumParts)* part[totParts - 1]),1);
        lcd.write(0);
      }
    }
    if (digitalRead(btnOk) == HIGH) {
      if (millis() - timer >= delay){
        shutdown_pins();
        internalDelivery = 0;
        timer = millis();
      } 
    }  
  }while(internalDelivery == 1);

  shutdown_pins();

  lcd.clear();
  return internalDelivery;
}

int arraySum(int* array, int length) {
  int sum = 0;
  for(int i = 0; i<length; i++){
    sum += array[i];
  }
  return sum;
};
