#include <DHT.h>
#include <SimpleTimer.h>
#include <SPI.h>
#include <RF24.h>
#include <RF24Network.h>

#include "config.h"

/* radio */
#define RADIO_CE_PIN 9
#define RADIO_CS_PIN 53


RF24 radio = RF24(RADIO_CE_PIN, RADIO_CS_PIN);


/* sensor */
int DELAY=  /*60 */ 1000;    

int ledPin= 13;
int photocellPin= 0;       
int temperatureCellPin= A2;

// DHT11 sensor pins
#define DHTPIN 7
#define DHTTYPE DHT11
 
// DHT instance
DHT dht(DHTPIN, DHTTYPE);


typedef struct t_payload{
        uint16_t cmd;
	uint16_t timeStamp;
	uint16_t valLight;
	uint16_t valTemperature;
	uint16_t valHumidity;
} payload;


SimpleTimer timerSend;

payload data;
payload receiv;


int saveHumi;
int saveTemp;

int tmpHumi;
int tmpTemp;


unsigned long timeStamp=0;


void setup(void){
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(7, INPUT);
  
  pinMode(13, OUTPUT);

  dht.begin();
  
  radio.begin();
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_1MBPS);
  radio.openWritingPipe(   0x0000000001LL);
  radio.openReadingPipe(1, 0x0000000002LL);
  
   radio.startListening();
  
  /// pour recuperer le time de l'ordinateur
   data.cmd= INIT;
   data.timeStamp= 1;
   data.valTemperature= 2;       
   data.valLight= 3;
   data.valHumidity= 4;

  
   radio.stopListening();
   radio.write(&data, sizeof(payload));
   radio.startListening();
   Serial.println("Ecriture attente reponse");
   
   while(!radio.available()){
   }
   
   radio.read(&data, sizeof(payload));
   Serial.println("reponse recu, demarage ");
   
   timerSend.setInterval(DELAY, sendData);
   
   
   /* init capteur */
    data.valLight= analogRead(photocellPin);
    saveHumi= dht.readHumidity();
    saveTemp= dht.readTemperature();
}


void loop(void){
  timerSend.run();
  if(radio.available()){
    radio.read(&receiv, sizeof(payload));

    if(receiv.cmd == LEDON){
      digitalWrite(ledPin, HIGH);
    }
    if(receiv.cmd == LEDOFF){
      digitalWrite(ledPin, LOW);
    }
  }
}


void sendData(void){
  //recuperation valeurs capteurs
  data.cmd= DATA;
  
  tmpTemp= dht.readTemperature(); //analogRead(temperatureCellPin);
  
  if( !( tmpTemp < (saveTemp * 0.8) || tmpTemp > (saveTemp * 1.2) ) ){
    data.valTemperature= tmpTemp;
    saveTemp= tmpTemp;
  }
  else{
    data.valTemperature= saveTemp;
  }
  
  data.valLight= analogRead(photocellPin);
  
  int tmpHumi= dht.readHumidity();
  if(!(tmpHumi < 20 || tmpHumi> 80)){
    data.valHumidity= tmpHumi;
    saveHumi= tmpHumi;
  }
  else{
    data.valHumidity= saveHumi;
  }
  
   // commencer a emettre
    radio.stopListening();
   //send payload
   radio.write(&data, sizeof(payload));
   //arreter d'emettre
    radio.startListening();  
    data.timeStamp++;
}
