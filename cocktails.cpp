#include "cocktails.h"
extern LiquidCrystal_I2C lcd(0x27, 16, 2);
// unsigned long currentMillis;

void inizialize_pump(){
  pinMode(pumpGin, OUTPUT);
  pinMode(pumpVodka, OUTPUT);
  pinMode(pumpLemon, OUTPUT);
  pinMode(pumpTonic, OUTPUT);
  pinMode(pumpAperol, OUTPUT);
  pinMode(pumpProsecco, OUTPUT);
  pinMode(pumpJager, OUTPUT);
  pinMode(pumpRedbull, OUTPUT);
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

void callCocktail() {
  if (selectedCocktail == 0) {
    GinLemon();
  }
  else if (selectedCocktail == 1){
    GinTonic();
  }
  else if (selectedCocktail == 2){
    VodkaTonic();
  }
  else if (selectedCocktail == 3){
    VodkaLemon();
  }
  else if (selectedCocktail == 4){
    VodkaRedbull();
  }
  else if (selectedCocktail == 5){
    JagerBomb();
  }
  else if (selectedCocktail == 6){
    Spritz();
  }
}

void inizializeCocktail(int* pumpsVet, int lenght){

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(cocktail[selectedCocktail]);
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
  
  inizializeCocktail(pumps, lenght);
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

      if (millis() - timer < (glassUnityTime / sumParts) * part[totParts]){
      
      lcd.setCursor((millis() - timer) * 16 / (glassUnityTime / sumParts)* part[0]  ,1);
      //lcd.print((millis() - timer) * 16 / (glassUnityTime * 2 / 3));
      lcd.write(0);
      }
    }
  }while(delivery == 1);
  
  lcd.clear();
}

