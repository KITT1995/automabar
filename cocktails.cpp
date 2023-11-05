#include "cocktails.h"
unsigned long currentMillis;

void GinLemon() {
  
  // una parte di gin e due di lemon
  currentMillis = millis();
  delivery = 1;

  digitalWrite(pumpGin, HIGH);
  digitalWrite(pumpLemon, HIGH);

  do{
    if(millis() - currentMillis >= (glassUnityTime / 3)){
      delivery = 0;
      digitalWrite(pumpGin, LOW);
    }
  }while(delivery == 1);

  currentMillis = millis();
  delivery = 1;

  do{
    if(millis() - currentMillis >= (glassUnityTime / 3)){
      delivery = 0;
      digitalWrite(pumpLemon, LOW);
    }
  }while(delivery == 1);

  
}

void inizialize_pomp(){
  pinMode(pumpGin, OUTPUT);
  pinMode(pumpVodka, OUTPUT);
  pinMode(pumpLemon, OUTPUT);
  pinMode(pumpTonic, OUTPUT);
  pinMode(pumpAperol, OUTPUT);
  pinMode(pumpProsecco, OUTPUT);
  pinMode(pumpJager, OUTPUT);
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