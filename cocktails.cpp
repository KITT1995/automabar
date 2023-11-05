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
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(cocktail[selectedCocktail]);
  delivery = 1;
  digitalWrite(pumpGin, HIGH);
  digitalWrite(pumpLemon, HIGH);

  do{
    if (millis() - timer >= (glassUnityTime / 3)){
      digitalWrite(pumpGin, LOW);
    }
    if (millis() - timer >= (glassUnityTime * 2 / 3)){
      delivery = 0;
      digitalWrite(pumpLemon, LOW);
    }
    else {
      lcd.setCursor((millis() - timer) * 16 / (glassUnityTime * 2 / 3) ,1);
      //lcd.print((millis() - timer) * 16 / (glassUnityTime * 2 / 3));
      lcd.write(0);
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
  // una parte di gin e due di tonica
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(cocktail[selectedCocktail]);
  delivery = 1;
  digitalWrite(pumpGin, HIGH);
  digitalWrite(pumpTonic, HIGH);
  do{
    if (millis() - timer >= (glassUnityTime / 3)){
      digitalWrite(pumpGin, LOW);
    }
    if (millis() - timer >= (glassUnityTime * 2 / 3)){
      delivery = 0;
      digitalWrite(pumpTonic, LOW);
    }
    else {
      lcd.setCursor((millis() - timer) * 16 / (glassUnityTime * 2 / 3) ,1);
      lcd.write(0);
    }
  }while(delivery == 1);
  lcd.clear();
}

void VodkaTonic() {
  // una parte di vodka e due di tonica
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(cocktail[selectedCocktail]);
  delivery = 1;
  digitalWrite(pumpVodka, HIGH);
  digitalWrite(pumpTonic, HIGH);
  do{
    if (millis() - timer >= (glassUnityTime / 3)){
      digitalWrite(pumpVodka, LOW);
    }
    if (millis() - timer >= (glassUnityTime * 2 / 3)){
      delivery = 0;
      digitalWrite(pumpTonic, LOW);
    }
    else {
      lcd.setCursor((millis() - timer) * 16 / (glassUnityTime * 2 / 3) ,1);
      lcd.write(0);
    }
  }while(delivery == 1);
  lcd.clear();
}

void VodkaLemon() {
  // una parte di vodka e due di lemon
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(cocktail[selectedCocktail]);
  delivery = 1;
  digitalWrite(pumpVodka, HIGH);
  digitalWrite(pumpLemon, HIGH);
  do{
    if (millis() - timer >= (glassUnityTime / 3)){
      digitalWrite(pumpVodka, LOW);
    }
    if (millis() - timer >= (glassUnityTime * 2 / 3)){
      delivery = 0;
      digitalWrite(pumpLemon, LOW);
    }
    else {
      lcd.setCursor((millis() - timer) * 16 / (glassUnityTime * 2 / 3) ,1);
      lcd.write(0);
    }
  }while(delivery == 1);
  lcd.clear();
}

void VodkaRedbull() {
  // una parte di vodka e due di redbull
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(cocktail[selectedCocktail]);
  delivery = 1;
  digitalWrite(pumpVodka, HIGH);
  digitalWrite(pumpRedbull, HIGH);
  do{
    if (millis() - timer >= (glassUnityTime / 3)){
      digitalWrite(pumpVodka, LOW);
    }
    if (millis() - timer >= (glassUnityTime * 2 / 3)){
      delivery = 0;
      digitalWrite(pumpRedbull, LOW);
    }
    else {
      lcd.setCursor((millis() - timer) * 16 / (glassUnityTime * 2 / 3) ,1);
      lcd.write(0);
    }
  }while(delivery == 1);
  lcd.clear();
}

void JagerBomb() {
  // una parte di jager e tre di redbull
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(cocktail[selectedCocktail]);
  delivery = 1;
  digitalWrite(pumpJager, HIGH);
  digitalWrite(pumpRedbull, HIGH);
  do{
    if (millis() - timer >= (glassUnityTime / 4)){
      digitalWrite(pumpJager, LOW);
    }
    if (millis() - timer >= (glassUnityTime * 3 / 4)){
      delivery = 0;
      digitalWrite(pumpRedbull, LOW);
    }
    else {
      lcd.setCursor((millis() - timer) * 16 / (glassUnityTime * 3 / 4) ,1);
      lcd.write(0);
    }
  }while(delivery == 1);
  lcd.clear();
}

void Spritz() {
  // tre parti di prosecco, due di aperol e una di tonica
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(cocktail[selectedCocktail]);
  delivery = 1;
  digitalWrite(pumpProsecco, HIGH);
  digitalWrite(pumpAperol, HIGH);
  digitalWrite(pumpTonic, HIGH);
  do{
    if (millis() - timer >= (glassUnityTime * 3 / 6)){
      delivery = 0;
      digitalWrite(pumpProsecco, LOW);
    }
    else {
      lcd.setCursor((millis() - timer) * 16 / (glassUnityTime * 3 / 6) ,1);
      //lcd.print((millis() - timer) * 16 / (glassUnityTime * 2 / 3));
      lcd.write(0);
    }
    if (millis() - timer >= (glassUnityTime * 2 / 6)){
      digitalWrite(pumpAperol, LOW);
    }
    if (millis() - timer >= (glassUnityTime / 6)){
      digitalWrite(pumpTonic, LOW);
    }
  }while(delivery == 1);
  lcd.clear();
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