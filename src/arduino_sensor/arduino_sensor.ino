#include <SimpleTimer.h>

int DELAY= 1000;            //une seconde

SimpleTimer timerSend;

int photocellPin= 0;        // d'apres les schemas de Fritzing
int temperaturePin= 1;

int valTemp;
int valLight;

unsigned long timeStamp=0;   // ulong: 2^32= 13,8 ans si DELAY= 100 ms 138 ans si DELAY= 1s


void setup(void){
  Serial.begin(9600);
  timerSend.setInterval(DELAY, sendData);    
}


void loop(void){
  timerSend.run();
}


void sendData(void){
  Serial.println(millis());
  
  
  //recuperation valeurs capteurs
  valTemp=  analogRead(temperaturePin);       
  valLight= analogRead(photocellPin);
  
  Serial.println(valTemp);    //debbug
  Serial.println(valLight);
  
   // commencer a emettre
   //send timeStamp
   // envoyer par ondes temperature et lumiere 
   //arreter d'emettre
      
  timeStamp+=1;
}
