
## Version
* Info: HC-05 AT Config | Date: 4/2021
* Developer: HHH
## Introduction
Main task: communicate with HC-05 in AT mode to configure baud rate, name, password, etc. 

Notice:
1. To Enter AT Mode in HC-05, the small black button on the board needs to be hold at in initial turn on. The LED blinking patters is much slower in AT mode comparing to its normal turn-on mode.
2. Some special AT commands such as AT+INQM, AT+INIT, AT+INQ, AT+PAIR, AT+BIND, AT+LINK, etc might require to hold down the same black button. In my hardware, it won't response without the action. 


## Connection
 HC05-> Arduino Uno
1. VCC ->5V
2. GND ->GND
3. TXD ->Pin#2
4. RXD -> Voltage Divider (1k in series with 2k resistors) to Pin#3
		
## Component
1. HC-05 FC-114
2. Arduino Uno
3. 3x 1k resistor


