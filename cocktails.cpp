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
  inizializeCocktail(pumps);
  executeCocktail(parts, pumps);  
}

void executeCocktail(int* part, int* pumps){

  int sumParts = 0;
  int totParts = sizeof(part);

  for(int i = 0; i<totParts; i++){
    sumParts += part[i];
  }

  do{
    for(int i = 0; i < totParts; i++){
      if (millis() - timer >= (glassUnityTime * part[i]) / (sumParts)){
        digitalWrite(pumps[i], LOW);
        if(i == (totParts-1))
          delivery = 0;
      } 


      if (millis() - timer < (glassUnityTime * part[totParts]) / (sumParts)){
      
      lcd.setCursor((millis() - timer) * 16 / (glassUnityTime * part[0]) / (sumParts) ,1);
      //lcd.print((millis() - timer) * 16 / (glassUnityTime * 2 / 3));
      lcd.write(0);
      }
    }
  }while(delivery == 1);
  
  lcd.clear();
}

/*
  @minorPart e @majorPart vanno inserite le parti di ingredienti che vanno in ordine crescente
  @minorPartPump e @majorPartPump vanno inserite le pompe relativmentealle parti in ordine crescente
*/
void executeCocktail2ingredients(int minorPart,int majorPart, int minorPartPump,int majorPartPump){

  do{
    //potrebbe comportarsi male se il primo valore è 1. 
    //in quel caso bisogna controllare che faccia la
    //divisione con virgola e non tra interi
    if (millis() - timer >= (glassUnityTime * minorPart) / (minorPart + majorPart)){
      digitalWrite(minorPartPump, LOW);
      //delivery = 0;
    }    
    if (millis() - timer >= (glassUnityTime * majorPart) / (minorPart + majorPart)){
      digitalWrite(majorPartPump, LOW);
      delivery = 0;
    }
    if (millis() - timer < (glassUnityTime * majorPart) / (minorPart + majorPart)){
      
      lcd.setCursor((millis() - timer) * 16 / (glassUnityTime * minorPart) / (minorPart + majorPart) ,1);
      //lcd.print((millis() - timer) * 16 / (glassUnityTime * 2 / 3));
      lcd.write(0);
    }
  }while(delivery == 1);

lcd.clear();
}

/*
  @minorPart e @majorPart vanno inserite le parti di ingredienti che vanno in ordine crescente
  @minorPartPump e @majorPartPump vanno inserite le pompe relativmentealle parti in ordine crescente
*/
void executeCocktail3ingredients(int minorPart, int mediumPart, int majorPart, int minorPartPump,int mediumPartPump, int majorPartPump){

  do{
    if (millis() - timer >= (glassUnityTime * majorPart) / (minorPart + mediumPart + majorPart)){
      delivery = 0;
      digitalWrite(majorPartPump, LOW);
    }
    else {
      lcd.setCursor((millis() - timer) * 16 / (glassUnityTime * majorPart) / (minorPart + mediumPart + majorPart) ,1);
      //lcd.print((millis() - timer) * 16 / (glassUnityTime * 2 / 3));
      lcd.write(0);
    }
    if (millis() - timer >= (glassUnityTime * mediumPart) / (minorPart + mediumPart + majorPart)){
      digitalWrite(mediumPartPump, LOW);
    }
    if (millis() - timer >= (glassUnityTime * minorPart) / (minorPart + mediumPart + majorPart)){
      digitalWrite(minorPartPump, LOW);
    }
  }while(delivery == 1);

  lcd.clear();
}


void GinTonic() {
  // una parte di gin e due di tonica
  int pumps[] = {pumpGin,pumpLemon};
  int parts[] = {1,2};
  inizializeCocktail(pumps);
  executeCocktail(parts, pumps);  

}

void VodkaTonic() {
  // una parte di vodka e due di tonica
  int pumps[] = {pumpVodka,pumpTonic};
  int parts[] = {1,2};
  inizializeCocktail(pumps);
  executeCocktail(parts, pumps);    

}

void VodkaLemon() {
  // una parte di vodka e due di lemon
  int pumps[] = {pumpVodka,pumpLemon};
  int parts[] = {1,2};
  inizializeCocktail(pumps);
  executeCocktail(parts, pumps);  
  
}

void VodkaRedbull() {
  // una 3 di vodka e 7 di redbull
  int pumps[] = {pumpVodka,pumpRedbull};
  int parts[] = {3,7};
  inizializeCocktail(pumps);
  executeCocktail(parts, pumps);  

}

void JagerBomb() {
  // una parte di jager e tre di redbull
  int pumps[] = {pumpJager,pumpRedbull};
  int parts[] = {1,3};
  inizializeCocktail(pumps);
  executeCocktail(parts, pumps);   

}

void Spritz() {
  // tre parti di prosecco, due di aperol e una di tonica
  int pumps[] = {pumpTonic,pumpAperol,pumpProsecco};
  int parts[] = {1,2};
  inizializeCocktail(pumps);
  executeCocktail(parts, pumps);   

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

int inizializeCocktail(int* pumps){

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(cocktail[selectedCocktail]);
  //inizializza l'lcd impostando il nome del cocktail che sta per eseguire
  delivery = 1;
  for(int i = 0; i < sizeof(pumps); i++){
    //accende tutte le pompe che devono essere utilizzate
    digitalWrite(pumps[i], HIGH);
  }

}
