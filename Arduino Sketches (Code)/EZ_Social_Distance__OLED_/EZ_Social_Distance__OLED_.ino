//Library
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//Set up the OLED Screen
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET 4
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//Set up the PIR pins and set variables
int sensor1 = 11;
int sensor2 = 12;
int val;
int val2;

//Set up distance sensor pins
int trig2 = A2;
int echo2 = A3;
int trig1 = A1;
int echo1 = A0;

//Set up variables for the LED and vibration motor
int led = 10;
int vibration = 9;

//Give an Init variable for the Ultrasonic sensors. Using Long for less rounding errors
long duration1;
long duration2;
long distance1;
long distance2;

void setup() {
//Init OLED Screen
if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
}//OLED

//Turn on the Serial monitor
Serial.begin(9600);  

//Setting up the PIR input pins as input
pinMode(sensor1, INPUT);
pinMode(sensor2, INPUT);

//Set up LED and vibration motor pins as output
pinMode(led, OUTPUT);
pinMode(vibration, OUTPUT);

//Power On test and reminder
display.clearDisplay();
display.setTextSize(1);
display.setTextColor(SSD1306_WHITE);
display.setCursor(0,0);
display.print("Please Remember");
display.setCursor(0,10);
display.print("To Wear A Mask!");
display.display();
digitalWrite(led, HIGH);
digitalWrite(vibration, HIGH);
delay(4000);
display.clearDisplay();
digitalWrite(led, LOW);
digitalWrite(vibration, LOW);


}//Void Setup


void loop() {

//Set an init value/variable to the PIR sensors
val = digitalRead(sensor1);
val2 = digitalRead(sensor2);

//Create a variable to tell the distance sensors how long to trigger
duration1 = readUltrasonicDistance(trig1,echo1);
duration2 = readUltrasonicDistance(trig2,echo2);

//Divide by 58 to convert distance to cm
distance1 = duration1/58;
distance2 = duration2/58;

//Print the distances to the Serial monitor, and seperate values
Serial.println(distance1);
Serial.println("----------");
Serial.println(distance2);
Serial.println(" ");
delay(100);  

//Print the ultrasonic values to the OLED
//display.clearDisplay();
display.setTextSize(1);
display.setTextColor(SSD1306_WHITE);

  
  
//If any of the PIR sensors go off AND either of the distance sensors detect a distance of >2 meters
if ((val == HIGH || val2 == HIGH) && (distance1 < 200 || distance2 < 200)) {
  delay(200);
  //Print to the OLED and alert the user
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("Motion");
  display.setCursor(0,10);
  display.print("Detected");
  display.display();
  digitalWrite(led, HIGH);
  digitalWrite(vibration, HIGH);
  display.setCursor(90,0);
  display.print("1: ");
  display.setCursor(100,0);
  display.print(distance1);
  display.setCursor(90,20);
  display.print("2: ");
  display.setCursor(100,20);
  display.print(distance2);
  display.display();  
  delay(200);
  }//If

//If the above conditions are not met, do not alert the user
  else{
    delay(200);
    display.clearDisplay();
    display.setCursor(0,0);
    display.print("Nothing");
    display.setCursor(90,0);
    display.print("1: ");
    display.setCursor(100,0);
    display.print(distance1);
    display.setCursor(90,20);
    display.print("2: ");
    display.setCursor(100,20);
    display.print(distance2);
    display.display();
    delay(200);
    }//Else

//Turn off the vibration motor and LED
digitalWrite(led, LOW);
digitalWrite(vibration, LOW);
 
}//Void Loop
 
 
//FUNCTION
long readUltrasonicDistance(int triggerPin, int echoPin)//Get Values
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2); //Delay by 2 microseconds to get distance
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10); //Delay by 10 microseconds
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT); //Read the input
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH); //Get the data from sensors
//End of function
 
 
}//Function
