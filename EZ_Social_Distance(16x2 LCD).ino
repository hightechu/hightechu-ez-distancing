//Library
#include <LiquidCrystal.h>


//Setting up the pins for the LCD, buzzer, and LED
//Set up LCD layout
const int rs = 2, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int sensor1 = 11;
int sensor2 = 12;
//Giving the sensors a default state / pin
int val;
int val2;
int trig1 = A4;
int echo1 = A5;
int trig2 = A1;
int echo2 = A0;

//Give an init variable for the ultrasonic sensors. Using long for less rounding errors in the distances
long duration1;
long duration2;
long distance1;
long distance2;


//Set up the buzzer and LED pins
int ledPin = 10;
int buzzerPin = 9;

//Initialize all of the pins. Setting up INPUT/OUTPUTS. 
void setup() {//Start void setup

//Setting the pins to output or input  
 pinMode(buzzerPin, OUTPUT);
 pinMode(ledPin, OUTPUT);
 pinMode(sensor1, INPUT); 
  
  
//Init LCD  
 lcd.begin(16, 2);
//Power on test/reminders
  lcd.setCursor(0,0);
  lcd.print("Remember to");
  lcd.setCursor(0,1);
  lcd.print("Wear a mask!");
  digitalWrite(ledPin, HIGH);
  digitalWrite(buzzerPin, HIGH);
  delay(5000);
  lcd.clear();
//Turn on serial monitor  
  Serial.begin(9600);
 
  
}//End of void setup

void loop() {//Start void loop
 
//Set an init value/variable to the PIR sensors  
  val = digitalRead(sensor1);
  val2 = digitalRead(sensor2);
  
//Create a variable to tell the distance sensors how long to trigger
  duration1 = readUltrasonicDistance(trig1,echo1);
  duration2 = readUltrasonicDistance(trig2,echo2);
  
//Divide by 58 to convert distance to cm  
  distance1 = duration1/58;
  distance2 = duration2/58;
  
//Print the distances to the Serial, and seperate the for readability  
  Serial.println(distance1);
  Serial.println("----------");
  Serial.println(distance2);
  Serial.println(" ");
  delay(200);
  
  //If any of the PIR sensors go off AND either of the distance sensors detect a distance of >2 meters
  if ((val == HIGH || val2 == HIGH) && (distance1 < 200 || distance2 < 200)) {
    delay(200);
//Printing to the LCD/serial
    lcd.clear();
    lcd.setCursor(0,0);
//The LCD on tinkercad is too small. Actual message will read "You are not social distancing! please move away."    
    lcd.print("Motion");
    lcd.setCursor(0,1);
    lcd.print("Detected");
//Turn on the LED and buzzer
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(200);
    
  }//End of high if
  
  
//If the above conditions are not met, do not alert the user
  else{
    delay(200);
//Printing to the LCD/serial
    lcd.clear();
//Actual message will read "You are >2m away. Thank you!"    
    lcd.print("Nothing");
//Turn off LED and buzzer and add delay
    delay(200);
    
  }//End of else  
  
  
//Turn off the LED/Buzzer  
digitalWrite(ledPin, LOW);
digitalWrite(buzzerPin, LOW);
   
  
    }//End of void loop

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


}//End of void loop
