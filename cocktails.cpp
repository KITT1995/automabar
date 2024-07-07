#include "cocktails.h"
extern LiquidCrystal_I2C lcd(0x27, 16, 2);

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


void allPumps(){
  
  int pumps[] = {pumpAperol, pumpCoke, pumpFernet, pumpGin, pumpJager};
  int pumps2[] = {pumpProsecco, pumpTonic, pumpVodka,pumpLemon, pumpRedbull};
  int parts[] = {1,1,1,1,1};
  executeCocktail("Cleaning p1", parts, pumps, sizeof(pumps)/sizeof(pumps[0]),11000);
  timer = millis();
  //delay(100);
  delivery = executeCocktail("Cleaning p2", parts, pumps2, sizeof(pumps2)/sizeof(pumps2[0]),11000);  
}

void GinLemon() {
  // una parte di gin e due di lemon
  int pumps[] = {pumpGin,pumpLemon};
  int parts[] = {1,2};
  delivery = executeCocktail(cocktail[selectedValueCocktail], parts, pumps, sizeof(pumps)/sizeof(pumps[0]),glassUnityTime);  
}

void GinTonic() {
  // una parte di gin e due di tonica
  int pumps[] = {pumpGin,pumpTonic};
  int parts[] = {1,2};
  delivery = executeCocktail(cocktail[selectedValueCocktail], parts, pumps, sizeof(pumps)/sizeof(pumps[0]),glassUnityTime);  
}

void VodkaTonic() {
  // una parte di vodka e due di tonica
  int pumps[] = {pumpVodka,pumpTonic};
  int parts[] = {1,2};
  delivery = executeCocktail(cocktail[selectedValueCocktail], parts, pumps, sizeof(pumps)/sizeof(pumps[0]),glassUnityTime);    
}

void VodkaLemon() {
  // una parte di vodka e due di lemon
  int pumps[] = {pumpVodka,pumpLemon};
  int parts[] = {1,2};
  delivery = executeCocktail(cocktail[selectedValueCocktail], parts, pumps, sizeof(pumps)/sizeof(pumps[0]),glassUnityTime);  
}


void VodkaRedbull() {
  // una 3 di vodka e 7 di redbull
  int pumps[] = {pumpVodka,pumpRedbull};
  int parts[] = {3,7};
  delivery = executeCocktail(cocktail[selectedValueCocktail], parts, pumps, sizeof(pumps)/sizeof(pumps[0]),glassUnityTime);  
}

void JagerBomb() {
  // una parte di jager e tre di redbull
  int pumps[] = {pumpJager,pumpRedbull};
  int parts[] = {1,3};
  delivery = executeCocktail(cocktail[selectedValueCocktail], parts, pumps, sizeof(pumps)/sizeof(pumps[0]),glassUnityTime);   
}

void Spritz() {
  // 3 prosecco, 2 aperol e 1 tonica
  int pumps[] = {pumpTonic,pumpAperol,pumpProsecco};
  int parts[] = {3,2,8};
  delivery = executeCocktail(cocktail[selectedValueCocktail], parts, pumps, sizeof(pumps)/sizeof(pumps[0]),glassUnityTime + (glassUnityTime/arraySum(parts, sizeof(parts)/sizeof(parts[0]))*6));
}

void Fernesito(){
  //1 fernet e 4 coca
  int pumps[] = {pumpFernet,pumpCoke};
  int parts[] = {2,7};
  //9 sarebbe 2+7 mentre 4 sarebbe la differenza tra il totale delle parti originali e il totale delle parti attuali
  delivery = executeCocktail(cocktail[selectedValueCocktail], parts, pumps, sizeof(pumps)/sizeof(pumps[0]),glassUnityTime + (glassUnityTime/arraySum(parts, sizeof(parts)/sizeof(parts[0]))*4));
}

void Manual(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Selezionare");
  lcd.setCursor(0, 1);
  lcd.print(ingredients[selectedValueIngredient]);
  do{
    if (millis() - timer >= delay2) {
      if (digitalRead(btnOk) == HIGH) {
        //if (selectedValueIngredient < totIngredients - 1){          
          timer = millis();
          callIngredient();
       /* }
        else {
          selectedValueIngredient = totIngredients - 1;
          delivery = 0;
          timer = millis();
          lcd.clear();
          return;
        }*/
      }
      else if (digitalRead(btnUp) == HIGH) {
        selectedValueIngredient = manageButtonUp(selectedValueIngredient, totIngredients);        
        //Serial.println(ingredients[selectedValueCocktail]);
        timer = millis();
        lcd.clear();        
      }
      else if (digitalRead(btnDown) == HIGH) {
        selectedValueIngredient = manageButtonDown(selectedValueIngredient, totIngredients);
        //Serial.println(ingredients[selectedValueCocktail]);
        timer = millis();
        lcd.clear();        
      }
      lcd.setCursor(0, 0);
      lcd.print("Selezionare");
      lcd.setCursor(0, 1);
      lcd.print(ingredients[selectedValueIngredient]);
    } 
  }while(delivery == 1);
}


void executeSingleIngredients(String ingredient, int pump){
  int pumps[] = {pump};
  int parts[] = {1};
  executeCocktail(ingredient, parts, pumps, 1,glassUnityTime); 
}


void callIngredient() {
  
      switch(selectedValueIngredient){
      case 0:
        executeSingleIngredients(ingredients[selectedValueIngredient], pumpAperol);
        break;
      case 1:
        executeSingleIngredients(ingredients[selectedValueIngredient], pumpCoke);        
        break;
      case 2:
        executeSingleIngredients(ingredients[selectedValueIngredient], pumpFernet);    
        break;
      case 3:
        executeSingleIngredients(ingredients[selectedValueIngredient], pumpGin);   
        break;
      case 4:
        executeSingleIngredients(ingredients[selectedValueIngredient], pumpJager);  
        break;
      case 5:
        executeSingleIngredients(ingredients[selectedValueIngredient], pumpLemon);  
        break;
      case 6:
        executeSingleIngredients(ingredients[selectedValueIngredient], pumpProsecco);  
        break;
      case 7:
        executeSingleIngredients(ingredients[selectedValueIngredient], pumpRedbull);  
        break;
      case 8:
        executeSingleIngredients(ingredients[selectedValueIngredient], pumpTonic);     
        break;
      case 9:
        executeSingleIngredients(ingredients[selectedValueIngredient], pumpVodka);   
        break;
      default: 
        break;
    }

  shutdown_pins();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Selezionare");
  lcd.setCursor(0, 1);
  lcd.print(ingredients[selectedValueIngredient]);
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
  int sumParts = arraySum(part, length);
  int internalDelivery = 1;

  do{
    for(int i = 0; i < totParts; i++){
      if (millis() - timer >= (glassUnityTimePersonal / sumParts) * part[i]){
        //Serial.println("shutdown ");        
        //Serial.println(pumps[i]);
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
      if (millis() - timer >= delay2){
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
}

int manageButtonUp(int selectedValue, int totSelectable){

  if (selectedValue == 0) {
    //se viene cliccato il pulsante freccia su quando il cocktail selezionato 
    //è il primo allora si giunge all'ultimo selezionato altrimenti si prosegue con la lista
    selectedValue = totSelectable - 1;
  }
  else {
    selectedValue -= 1;
  }
  return selectedValue;
}

int manageButtonDown(int selectedValue, int totSelectable){

  if (selectedValue == totSelectable - 1) {
    //al contrario se il cocktail selezionato è l'ultimo
    selectedValue = 0;
  }
  else {
    selectedValue += 1;
  }
  return selectedValue;
}
