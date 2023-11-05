#include "cocktails.h"
extern LiquidCrystal_I2C lcd(0x27, 16, 2);
unsigned long currentMillis;

void inizialize_pump(){
  pinMode(pumpGin, OUTPUT);
  pinMode(pumpVodka, OUTPUT);
  pinMode(pumpLemon, OUTPUT);
  pinMode(pumpTonic, OUTPUT);
  pinMode(pumpAperol, OUTPUT);
  pinMode(pumpProsecco, OUTPUT);
  pinMode(pumpJager, OUTPUT);
}

void GinLemon() {
  // una parte di gin e due di lemon
  //currentMillis = millis();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(cocktail[selectedCocktail]);
  delivery = 1;
  digitalWrite(pumpGin, HIGH);
  digitalWrite(pumpLemon, HIGH);

  do{
    if (millis() - timer >= (glassUnityTime * 2 / 3)){
      delivery = 0;
      digitalWrite(pumpGin, LOW);
    }
    else {
      lcd.setCursor((millis() - timer) * 16 / (glassUnityTime * 2 / 3) ,1);
      //lcd.print((millis() - timer) * 16 / (glassUnityTime * 2 / 3));
      lcd.write(0);
    }
    if (millis() - timer >= (glassUnityTime / 3)){
      digitalWrite(pumpGin, LOW);
    }
  }while(delivery == 1);
  
  /*do{
    if(millis() - currentMillis >= (glassUnityTime / 3)){
      delivery = 0;
      digitalWrite(pumpGin, LOW);
    }
  }while(delivery == 1); */ 
  lcd.clear();
}

void GinTonic() {
  
}

void VodkaTonic() {
  
}

void VodkaLemon() {
  
}

void JagerBomb() {
  
}

void Spritz() {
  
}

void VodkaRedbull() {

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
    JagerBomb();
  }
  else if (selectedCocktail == 5){
    Spritz();
  }
  else if (selectedCocktail == 6){
    VodkaRedbull();
  }
}