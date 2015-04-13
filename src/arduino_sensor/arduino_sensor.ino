#include <SimpleTimer.h>

int DELAY= 1000;            //une seconde
const int size_buff= 16;

SimpleTimer timerSend;

int photocellPin= 0;        // d'apres les schemas de Fritzing
int temperaturePin= 1;

int valTemp[size_buff];
int valLight[size_buff];
int compt= 0;

unsigned long /*long*/ timeStamp=0;   // ulong: 2^32= 13,8 ans si DELAY= 100 ms
                                      // ulong long: 2^64= 60 milliard d'an si DELAY= 100ms


void setup(void){
  Serial.begin(9600);
  timerSend.setInterval(DELAY * 60, sendData);      // buff pour eviter d'envoyer tous le temps
}


void loop(void){
  timerSend.run();
  
  delay(DELAY);
}




void sendData(void){
  
  //recuperation valeurs capteurs
   int tempTmp= analogRead(temperaturePin);       
  /*float volatage= (tempsTmp * 5.0) / 1024.0;        // a faire dans le serveur si on veut faire donner le choix de degre F/C
  valTemp[compt]= (int) (voltage - 0.5) * 100;*/
  
  valTemp[compt]= tempTmp;
  valLight[compt]= analogRead(photocellPin);
  
  compt++;
  
  if(compt >= size_buff){
     // commencer a emettre
    //send timeStamp
    //du nombre de valeur 
    for(int i=0; i<compt; i++){
       // envoyer par ondes radio pour temperature
    }
    //arreter d'emettre
      
    compt=0;
  }



  timeStamp+=1;
}
