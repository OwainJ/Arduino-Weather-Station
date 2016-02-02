#include <dht.h>
#include <VirtualWire.h> //Load the library

#define dht_dpin A0 //no ; here. Set equal to channel sensor is on

dht DHT;

String tempVal;
String humVal;
String rainVal;

int rainSensor;
int tempSensor;
int humidSensor;
int rainNum = 0;

String message;
char sentvalues[27];

float temp;        //Define the temp float variable
int sensor = 0;     // sensor middle pin on analog pin 0
char msg[6];


void setup() {
  Serial.begin(9600);
  vw_set_tx_pin(12);          // Sets pin D12 as the TX pin
  vw_setup(2000);          // Bits per sec

  pinMode(13, OUTPUT); //RED LED
  pinMode(8, OUTPUT); //YELLOW LED
  pinMode(7, OUTPUT); //GREEN LED

  digitalWrite(13, HIGH); //Red LED on

}

void loop() {

  digitalWrite(8, HIGH); //Yellow LED on

  //===== Get the sensor values =====

  temperature();

  tempVal = "0";
  tempVal += tempSensor;
  humVal = "0";
  humVal += humidSensor;

  rain();

  rainVal = "0";
  rainVal += rainNum;

  Serial.println("");
  Serial.println("====String values====");
  Serial.print("temp: ");
  Serial.print(tempVal);
  Serial.print("  hum: ");
  Serial.print(humVal);
  Serial.print("  rain: ");
  Serial.println(rainVal);
  Serial.println("");


  //===== Send the sensor values ====

  // construct the message
  message = "T" + tempVal + "H" + humVal + "R" + rainVal;
  message.toCharArray(sentvalues, 27);

  //reset the strings to empty
  tempVal = "";
  humVal = "";
  rainVal = "";

  Serial.println("====message==== ");
  Serial.println(message);
  Serial.println("========");
  Serial.println("");

  //send the message
  vw_send((uint8_t *)sentvalues, strlen(sentvalues));
  vw_wait_tx();

  //=================================

  delay(50);
  digitalWrite(8, LOW); //YellowLED off
  delay(200);

}
