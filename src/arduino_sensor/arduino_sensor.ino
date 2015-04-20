#include <SimpleTimer.h>
#include <SPI.h>
#include <RF24.h>
#include <RF24Network.h>

#include "config.h"

/* radio */
#define RADIO_CE_PIN 9
#define RADIO_CS_PIN 53


RF24 radio = RF24(RADIO_CE_PIN, RADIO_CS_PIN);
//const uint64_t pipes[2] = { 0x0000000001LL, 0xF0F0F0F0D2LL };       


/* sensor */
int DELAY= 1000;    

int photocellPin= 0;       
int temperatureCellPin= 1;



SimpleTimer timerSend;

payload data;
unsigned long timeStamp=0;   // ulong: 2^32= 13,8 ans si DELAY= 100 ms 138 ans si DELAY= 1s



void setup(void){
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  
  radio.begin();
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_1MBPS);
  
  radio.openWritingPipe(0x0000000001LL);
  radio.openReadingPipe(1, 0xF0F0F0F0D2LL);

  
  radio.startListening();
  /// pour recuperer le time de l'ordinateur
  /*
  while(!radio.available()){}   // on attend que ca soit possible 
  
  radio.read(&data, sizeof(Payload));
  
  radio.stopListening();
  */
  
  timerSend.setInterval(DELAY, sendData);
  data.timeStamp=0;
}


void loop(void){
  timerSend.run();
}


void sendData(void){
  //recuperation valeurs capteurs
  data.valTemperature= analogRead(temperatureCellPin);       
  data.valLight= analogRead(photocellPin);
  data.valHumidity= 0;
  
  Serial.println(data.timeStamp);
  Serial.println(data.valTemperature);    //debbug
  Serial.println(data.valLight);
  
   // commencer a emettre
    radio.stopListening();
   //send payload
   radio.write(&data, sizeof(payload));
   //arreter d'emettre
    radio.startListening();  
    data.timeStamp++;
}
