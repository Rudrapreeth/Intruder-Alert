#include <SoftwareSerial.h>

SoftwareSerial SIM900(2, 3);

String textForSMS;

 

int pirsensor = 8;

int red = 7;

int green = 8;

 

void setup() {

  randomSeed(analogRead(0));

  Serial.begin(9600);

  SIM900.begin(9600); // original 19200. while enter 9600 for sim900A

  Serial.println(" logging time completed!");

  pinMode(pirsensor, INPUT);

  pinMode(red, OUTPUT);

  pinMode(green, OUTPUT);

  digitalWrite(red, LOW);

  digitalWrite(green, LOW);

 

  delay(100);

 

}

 

void loop() {

 

  if ( digitalRead(pirsensor) == HIGH) //

  {

    textForSMS =  "\Security alert!! Please Check ";

 

    digitalWrite(red, HIGH);

    digitalWrite(green, LOW);

    sendSMS(textForSMS);

    Serial.println(textForSMS);

    Serial.println("message sent.");

    delay(8000);

  }

  if ( digitalRead(pirsensor) == LOW) //

  {

    digitalWrite(red, LOW);

    digitalWrite(green, HIGH);

    delay(1000);

  }

 

}

 

void sendSMS(String message)

{

  SIM900.print("AT+CMGF=1\r");                     // AT command to send SMS message

  delay(1000);

  SIM900.println("AT + CMGS = \"+919392273736\"");  // recipient's mobile number, in international format

 

  delay(1000);

  SIM900.println(message);                         // message to send

 

  SIM900.println((char)26);                        // End AT command with a ^Z, ASCII code 26

  delay(1000);

  SIM900.println();

  // give module time to send SMS

 

}