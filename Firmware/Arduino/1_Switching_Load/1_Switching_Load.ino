/******************************************************************************
  Example 1: Switching a Load
  Modified By: Ho Yun "Bobby" Chan
  SparkFun Electronics
  Date: October 27th, 2023
  License: MIT. See license file for more information but you can
  basically do whatever you want with this code.

  This example is based on Arduino's blink example. It has been modified
  so that it can be used for the SparkFun IoT RedBoard - ESP32 but it can be
  used with any Arduino that has a digital pin. The load (solenoid, DC motor,
  or 12V LED) will toggle on and off every 5 seconds.

  Users can also open the Serial Monitor at 115200 to check on
  the status of the load for debugging.

  Feel like supporting open source hardware?
  Buy a board or component from SparkFun!

      SparkFun IoT RedBoard - ESP32 Development Board:            https://www.sparkfun.com/products/19177
      SparkFun MOSFET Power Switch and Buck Regulator (Low-Side): https://www.sparkfun.com/products/23979
      Solenoid - 12V (Latch / Lock):                              https://www.sparkfun.com/products/15324
      Hobby Motor - Gear:                                         https://www.sparkfun.com/products/11696
      Blower - Squirrel Cage (12V):                               https://www.sparkfun.com/products/11270
      12V LED RGB Strip - Bare (1m):                              https://www.sparkfun.com/products/12021
      Wall Adapter 12V/600mA, (Barrel Jack):                      https://www.sparkfun.com/products/15313

  Distributed as-is; no warranty is given.
******************************************************************************/

//define a pin for the load, you'll need to adjust this
//depending on the microcontroller that you using
const int loadPin = 25;

// the setup function runs once when you press reset or power the board
void setup() {

  //Initialize Serial for Debugging if there is no built-in LED
  Serial.begin(115200);
  Serial.println("Toggling a Load!");

  // initialize digital pin as an output.
  pinMode(loadPin, OUTPUT);
  digitalWrite(loadPin, HIGH);  // turn the LOAD off (HIGH is the voltage level)
  Serial.println("OFF");

}  //END SETUP



// the loop function runs over and over again forever
void loop() {

  digitalWrite(loadPin, LOW);  // turn the LOAD ON (LOW is the voltage level)
  Serial.println("ON");
  delay(5000);  // wait for a few seconds

  digitalWrite(loadPin, HIGH);  // turn the LOAD OFF by making the voltage HIGH
  Serial.println("OFF");
  delay(5000);  // wait for a few seconds

}  //END LOOP
