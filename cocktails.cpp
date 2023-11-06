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
  int pumpsVet[] = {pumpGin,pumpLemon};
  inizializeCocktail(pumpsVet);
  executeCocktail2ingredients(1,2,pumpsVet[0],pumpsVet[1]);  
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
    }
    
    if (millis() - timer >= (glassUnityTime * majorPart) / (minorPart + majorPart)){
      digitalWrite(majorPartPump, LOW);
    }
    else {
      delivery = 0;
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
  int pumpsVet[] = {pumpGin,pumpTonic};
  inizializeCocktail(pumpsVet);
  executeCocktail2ingredients(1,2,pumpsVet[0],pumpsVet[1]);  

}

void VodkaTonic() {
  // una parte di vodka e due di tonica
  int pumpsVet[] = {pumpVodka,pumpTonic};
  inizializeCocktail(pumpsVet);
  executeCocktail2ingredients(1,2,pumpsVet[0],pumpsVet[1]);  

}

void VodkaLemon() {
  // una parte di vodka e due di lemon
  int pumpsVet[] = {pumpVodka,pumpLemon};
  inizializeCocktail(pumpsVet);
  executeCocktail2ingredients(1,2,pumpsVet[0],pumpsVet[1]);  
  
}

void VodkaRedbull() {
  // una 3 di vodka e 7 di redbull
  int pumpsVet[] = {pumpVodka,pumpRedbull};
  inizializeCocktail(pumpsVet);
  executeCocktail2ingredients(3,7,pumpsVet[0],pumpsVet[1]);  

}

void JagerBomb() {
  // una parte di jager e tre di redbull
  int pumpsVet[] = {pumpJager,pumpRedbull};
  inizializeCocktail(pumpsVet);
  executeCocktail2ingredients(1,3,pumpsVet[0],pumpsVet[1]);  

}

void Spritz() {
  // tre parti di prosecco, due di aperol e una di tonica
  int pumpsVet[] = {pumpTonic,pumpAperol,pumpProsecco};
  inizializeCocktail(pumpsVet);
  executeCocktail3ingredients(1,2,3,pumpsVet[0],pumpsVet[1],pumpsVet[2]);  

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
