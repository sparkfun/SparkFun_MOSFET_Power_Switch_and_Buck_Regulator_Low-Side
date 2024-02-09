/*
  12V RGB LED Nightlight Example

  Turns an 12V RGB strip LED on or off based on the light level read by a photoresistor.
  Change colors by turning the potentiometer. This example is based off the SparkFun
  Inventor's Kit v4.2 RGB Night-Light Example:
  
      https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v41

  Note that instead of the RedBoard with ATmega328P we are using the IoT RedBoard with ESP32.
  Since the hardware is different the following code was modified:
  
      - analog and PWM pins were redifined
      - threshold was modified due to the ADC's higher resolution 
      - logic is reversed due to the transistors
  
  WARNING: Since the IoT RedBoard with ESP32 has a system voltage of 3.3V, the logic levels
  is 3.3V instead of 5V on the RedBoard with ATmega328P. Thus, the analog reference voltage
  for the potentiometer and photoresistor is 3.3V. Make sure you are using 3.3V!

  This sketch was written by SparkFun Electronics, with lots of help from the Arduino community.
  This code is completely free for any use.

*/

int photoresistor = A4;  //variable for storing the photoresistor value
int potentiometer = A5;  //this variable will hold a value based on the position of the knob
int threshold = 3000;    //if the photoresistor reading is lower than this value the light will turn on
                         /*Note: The ESP32's ADC resolution is bigger. The max is 4095. In a bright room
                                 with your finger covering the sensor, the threshold was about 3000. In a dimly
                                 lit room, the threshold was about 1000. You will need to adjust this value when
                                 installing it in a room. Just make sure to make it a little more than the thresholed
                                 of the room. Try adding a button and some code  to save the threshold value! */

//LEDs are connected to these pins
int RedPin = 16;
int GreenPin = 17;
int BluePin = 25;

void setup() {
  Serial.begin(115200);  //start a serial connection with the computer
  Serial.println("12V RGB LED Strip Nightlight!");

  //set the LED pins to output
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);

}  //END SETUP

void loop() {

  photoresistor = analogRead(A4);  //read the value of the photoresistor
  potentiometer = analogRead(A5);  //read the value of the potentiometer

  Serial.print("Photoresistor value:");
  Serial.print(photoresistor);  //print the photoresistor value to the serial monitor
  Serial.print("  Potentiometer value:");
  Serial.println(potentiometer);  //print the potentiometer value to the serial monitor

  if (photoresistor < threshold) {  //if it's dark (the photoresistor value is below the threshold) turn the LED on
    //These nested if statements check for a variety of ranges and
    //call different functions based on the current potentiometer value.
    //Those functions are found at the bottom of the sketch.

    /*Note: We divided 4095 by 14 colors (including "off") and had a window of about 292.5. For users
            Adding more colors, try dividing 4095 by the total number and adjust
            eac condition statement*/

    if (potentiometer > 292 && potentiometer <= 585)
      red();
    if (potentiometer > 585 && potentiometer <= 877)
      orange();
    if (potentiometer > 877 && potentiometer <= 1170)
      yellow();
    if (potentiometer > 1170 && potentiometer <= 1462)
      chartruese();
    if (potentiometer > 1462 && potentiometer <= 1755)
      green();
    if (potentiometer > 1755 && potentiometer <= 2047)
      spring_green();
    if (potentiometer > 2047 && potentiometer <= 2340)
      cyan();
    if (potentiometer > 2340 && potentiometer <= 2632)
      azure();
    if (potentiometer > 2632 && potentiometer <= 2925)
      blue();
    if (potentiometer > 2925 && potentiometer <= 3217)
      violet();
    if (potentiometer > 3217 && potentiometer <= 3510)
      magenta();
    if (potentiometer > 3510 && potentiometer <= 3802)
      rose();
    if (potentiometer > 3802)
      white();
  } else {  //if it isn't dark turn the LED off

    turnOff();  //call the turn off function
  }

  delay(100);  //short delay so that the printout is easier to read

}  //END LOOP

void red() {

  //set the LED pins to values that make red
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 255);
  analogWrite(BluePin, 255);
}
void orange() {

  //set the LED pins to values that make orange
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 128);
  analogWrite(BluePin, 255);
}
void yellow() {

  //set the LED pins to values that make yellow
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 255);
}
void chartruese() {

  //set the LED pins to values that make chartruese
  analogWrite(RedPin, 128);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 255);
}
void green() {

  //set the LED pins to values that make green
  analogWrite(RedPin, 255);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 255);
}
void spring_green() {

  //set the LED pins to values that make spring green
  analogWrite(RedPin, 255);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 128);
}
void cyan() {

  //set the LED pins to values that make cyan
  analogWrite(RedPin, 255);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 0);
}
void azure() {

  //set the LED pins to values that make azure
  analogWrite(RedPin, 255);
  analogWrite(GreenPin, 128);
  analogWrite(BluePin, 0);
}
void blue() {

  //set the LED pins to values that make blue
  analogWrite(RedPin, 255);
  analogWrite(GreenPin, 255);
  analogWrite(BluePin, 0);
}
void violet() {

  //set the LED pins to values that make violet
  analogWrite(RedPin, 128);
  analogWrite(GreenPin, 255);
  analogWrite(BluePin, 0);
}
void magenta() {

  //set the LED pins to values that make magenta
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 255);
  analogWrite(BluePin, 0);
}
void rose() {

  //set the LED pins to values that make rose
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 255);
  analogWrite(BluePin, 128);
}
void white() {

  //set the LED pins to values that make white
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 0);
}
void turnOff() {

  //set all three LED pins to 0 or OFF
  analogWrite(RedPin, 255);
  analogWrite(GreenPin, 255);
  analogWrite(BluePin, 255);
}
