#include <SimpleTimer.h>
#include <SPI.h>
#include <RF24.h>
#include <RF24Network.h>

/* radio */
#define RADIO_CE_PIN 8
#define RADIO_CS_PIN 7

#define RADIO_RETRY_DELAY 0
#define RADIO_RETRY_COUNT 0

RF24 radio = RF24(RADIO_CE_PIN, RADIO_CS_PIN);
const uint64_t pipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };        // pourquoi ces valeurs ?? je ne sais pas


typedef struct payload{
  unsigned long ts;
  int16_t pc;
  int16_t tc;
} Payload;

/* sensor */
int DELAY= 1000;            //une seconde

int photocellPin= 0;        // d'apres les schemas de Fritzing
int temperatureCellPin= 1;



SimpleTimer timerSend;
Payload data;
unsigned long timeStamp=0;   // ulong: 2^32= 13,8 ans si DELAY= 100 ms 138 ans si DELAY= 1s



void setup(void){
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  
  radio.begin();
  radio.setRetries(RADIO_RETRY_DELAY, RADIO_RETRY_COUNT);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MAX);
  radio.setPayloadSize(sizeof(Payload));
  radio.openWritingPipe(pipes[0]);
  radio.openReadingPipe(1, pipes[1]);
  
  
  /// pour recuperer le time de l'ordinateur
  /*radio.powerUp();
  radio.startListening();
  
  while(!radio.available()){}   // on attend que ca soit possible 
  
  radio.read(&data, sizeof(Payload));
  
  radio.stopListening();
  radio.powerDown();
  */
  
  timerSend.setInterval(DELAY, sendData);
}


void loop(void){
  timerSend.run();
}


void sendData(void){
  //recuperation valeurs capteurs
  data.tc= analogRead(temperatureCellPin);       
  data.pc= analogRead(photocellPin);
  
  Serial.println(data.tc);    //debbug
  Serial.println(data.pc);
  
   // commencer a emettre
   radio.powerUp();
   //send payload
   if(radio.write(&data, sizeof(Payload)) == false){
     Serial.println("Error send data");
   }
   //arreter d'emettre
   radio.powerDown();
  
  data.ts++;
}
