/******************************************************************************
  Example 2: Toggling a Load with a Button
  Written By: Ho Yun "Bobby" Chan
  SparkFun Electronics
  Date: October 27th, 2023
  License: MIT. See license file for more information but you can
  basically do whatever you want with this code.

  This example toggles the load (solenoid, DC motor, or 12V LED)
  based on a button press. The status LED will light up at the
  same time. This example checks to see if the momentary button
  is still being pressed and will only toggle the load when the
  button after releasing and pressing down on the button again.

  The example was tested on the SparkFun IoT RedBoard - ESP32.
  However, it can be used with any Arduino that has a digital pin.
  Users can also open the Serial Monitor at 115200 to check on
  the status of the button for debugging.

  Feel like supporting open source hardware?
  Buy a board or component from SparkFun!

      SparkFun MOSFET Power Switch and Buck Regulator (Low-Side): https://www.sparkfun.com/products/23979
      SparkFun IoT RedBoard - ESP32 Development Board:            https://www.sparkfun.com/products/19177
      Solenoid - 12V (Latch / Lock):                              https://www.sparkfun.com/products/15324
      Hobby Motor - Gear:                                         https://www.sparkfun.com/products/11696
      Blower - Squirrel Cage (12V):                               https://www.sparkfun.com/products/11270
      12V LED RGB Strip - Bare (1m):                              https://www.sparkfun.com/products/12021
      Wall Adapter 12V/600mA, (Barrel Jack):                      https://www.sparkfun.com/products/15313

  Distributed as-is; no warranty is given.
******************************************************************************/

// pushbutton 1 pin
const int button1Pin = 4;
boolean button1State = false;
boolean prevbutton1State = false;
boolean currentbutton1State = false;

//define a pin for the load, you'll need to adjust this
//depending on the microcontroller that you using
const int loadPin = 25;
boolean mode = false;  //mode to toggle load, set to off at the start

const int ledPin = 18;  // built-in LED pin for IoT RedBoard - ESP32
                        /*Note: Users can also use the macro LED_BUILTIN. Just make sure to comment the line above
                        and replace "ledPIN" with "LEDBUILTIN"*/



void setup() {

  //Initialize Serial for Debugging if there is no built-in LED
  Serial.begin(115200);
  Serial.println("Toggling a Load with a Button!");

  // Set up the pushbutton pin to be an input with a pull-up resistor:
  pinMode(button1Pin, INPUT_PULLUP);

  // Set up the load pin to be an output and turn it off:
  pinMode(loadPin, OUTPUT);
  digitalWrite(loadPin, HIGH);

  //Set up built-in LED as an OUTPUT and ensure that it is off as well:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  Serial.println("OFF");

}  //END SETUP



void loop() {

  button1State = digitalRead(button1Pin);

  //if button is pressed, it will be pulled low
  if (button1State == LOW) {
    currentbutton1State = true;  // button has been pressed once

    if (prevbutton1State != currentbutton1State) {  //check to see if button is still being pressed

      if (mode == false) {
        mode = true;
      } else {
        mode = false;
      }

      if (mode == true) {

        digitalWrite(loadPin, LOW);
        digitalWrite(ledPin, HIGH);
        Serial.println("ON");

      } else {

        digitalWrite(loadPin, HIGH);
        digitalWrite(ledPin, LOW);
        Serial.println("OFF");
      }

      delay(500);  //add small delay, you may need to have a bigger delay for button debouncing

    } else {  //do nothing because finger is still on button
    }



    prevbutton1State = currentbutton1State;  //update button1 state
  }
  //button has not been pressed, it will be high
  else {

    currentbutton1State = false;
    prevbutton1State = currentbutton1State;  //update button1 state
  }



}  //END LOOP