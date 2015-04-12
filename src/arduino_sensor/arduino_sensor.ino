#include <SimpleTimer.h>

int DELAY= 100;
const int size_buff= 10;

SimpleTimer timerSend;

int photocellPin= 0;        // d'apres les schemas de Fritzing
int temperaturePin= 1;

int valTemp[size_buff];
int valLight[size_buff];
int comptLight= 0;
int comptTemp= 0;

unsigned long /*long*/ timeStamp=0;   // ulong: 2^32= 13,8 ans si DELAY= 100 ms
                                      // ulong long: 2^64= 60 milliard d'an si DELAY= 100ms


void setup(void){
  Serial.begin(9600);
  timerSend.setInterval(DELAY * size_buff, sendData);      // pour envoyer moins souvant pourquoi ne pas le bufferiser?
}


void loop(void){
  timerSend.run();
  
  int tempTmp= analogRead(temperaturePin);       
  /*float volatage= (tempsTmp * 5.0) / 1024.0;        // a faire dans le serveur si on veut faire donner le choix de degre F/C
  valTemp[compt]= (int) (voltage - 0.5) * 100;*/
  
  valTemp[comptTemp]= tempTmp;
  comptTemp++;
  comptTemp%=size_buff;
  
  valLight[comptLight]= analogRead(photocellPin);
  comptLight++;
  comptLight%=size_buff;
  
  delay(DELAY);
}




void sendData(void){
// commencer a emettre
  //send timeStamp
  //du nombre de valeur envoyé pour photocell
  for(int i=0; i<comptLight; i++){
     // envoyer par ondes radio pour photocell
  }
  //du nombre de valeur envoyé pour temperature
  for(int i=0; i<comptTemp; i++){
     // envoyer par ondes radio pour temperature
  }
  //arreter d'emettre
  timeStamp+=1;
}
