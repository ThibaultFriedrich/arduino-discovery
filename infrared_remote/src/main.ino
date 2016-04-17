


/*
# Infra red barrier

* 1 LED
* 1 Resistance 220 ohm



* https://arduino-info.wikispaces.com/IR-RemoteControl
* https://learn.adafruit.com/ir-sensor/using-an-ir-sensor
* https://learn.sparkfun.com/tutorials/ir-communication
* http://www.instructables.com/id/Arduino-Infrared-Remote-tutorial/
* https://learn.adafruit.com/using-an-infrared-library/hardware-needed

Libs :
* https://github.com/cyborg5/IRLib/


Remote Philips: IR protocol RC5

*/

#define KEY_1 4097
#define KEY_1_alt 6145



#include <IRLib.h>

//Create a receiver object to listen on pin 11
IRrecv My_Receiver(11);

//Create a decoder object
IRdecode My_Decoder;

int led = 8;

void setup()
{
  Serial.begin(9600);
  My_Receiver.enableIRIn(); // Start the receiver
  pinMode(led, OUTPUT);

  digitalWrite(led, LOW);
}

void loop()
{
  //Continuously look for results. When you have them pass them to the decoder
  if (My_Receiver.GetResults(&My_Decoder)) {
    My_Decoder.decode();		//Decode the data

    Serial.println(My_Decoder.value);
    //My_Decoder.DumpResults();	//Show the results on serial monitor

    if(My_Decoder.decode_type == RC5){
      if(My_Decoder.value == KEY_1 || My_Decoder.value == KEY_1_alt){
        digitalWrite(led, HIGH);
        delay(300);
        digitalWrite(led, LOW);
        delay(300);
        digitalWrite(led, HIGH);
        delay(300);
        digitalWrite(led, LOW);
      } else {
        digitalWrite(led, HIGH);
        delay(1000);
        digitalWrite(led, LOW);
      }
    }


    My_Receiver.resume(); 		//Restart the receiver
  }
}
