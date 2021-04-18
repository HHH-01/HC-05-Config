
//Circuit SetupL Need a voltage devider into RXD | Need Enable Pin connected to VCC
//Need to set up the Baud Rate for Command Mode as 38400 regardless the Baud Rate on the chip
//To change the Baudrate using command AT+UART=9600,1,0 or AT+UART=9600,0,0  (9600 baud rate, 1 stop bit, 0 parity)

/*
 * Master Mode Commands: 
AT+RMAAD Clear any paired devices
AT+ROLE=1 Set mode to Master
AT+RESET After changing role, reset is required
AT+CMODE=0 Allow connection to any address (I have been told this is wrong and CMODE=1 sets “any address”
AT+INQM=0,5,5 Inquire mode – Standard, stop after 5 devices found or after 5 seconds
AT+PSWD=1234 Set PIN. Should be same as slave device
AT+INIT Start Serial Port Profile (SPP) ( If Error(17) returned – ignore as profile already loaded)
AT+INQ Start searching for devices
 */

 /*
  * Reference
  * 1.https://gadgetperfect.wordpress.com/701-2/ for Commands
  * 2. http://www.martyncurrey.com/arduino-with-hc-05-bluetooth-module-at-mode/ for HC-05 / HC-06 connection
  */

#include <SoftwareSerial.h>
//SoftwareSerial EEBlue(10, 11); // RX | TX
 SoftwareSerial EEBlue(2, 3); // RX | TX
void setup()
{
  Serial.begin(9600);
  EEBlue.begin(38400);  //Baud Rate for command Mode. 
  Serial.println("Enter AT commands!");
}
 
void loop()
{
 
  // Feed any data from bluetooth to Terminal.
  if (EEBlue.available())
    Serial.write(EEBlue.read());
 
  // Feed all data from termial to bluetooth
  if (Serial.available())
    EEBlue.write(Serial.read());
}
