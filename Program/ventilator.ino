#include <>  

// Declaring Pins
const int buzzerPin = ;
const int ledPin = ;
const int pressurePin = ;
const int buttonPin = ;

// Setting Buzzer mode to False
boolean buzzer_mode = false;

// For LED
int ledState = LOW;
long previousMillis = 0; 
long interval = 100;  // Interval at which LED blinks

void setup()
{
  //The Following are our output
  pinMode(ledPin,OUTPUT);
  pinMode(buzzerPin,OUTPUT);

  //Button is our Input
  pinMode(buttonPin, INPUT);
  
  // Wait before starting the alarm
  delay(5000);
}

void loop()
{
  // To check whether the pressure drop below is detected or not
  if (digitalRead(pressurePin)) {
    buzzer_mode = true; 
  }

  // If alarm mode is on,blink our LED
  if (buzzer_mode){
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis > interval) {
      previousMillis = currentMillis;   
      if (ledState == LOW)
        ledState = HIGH;
      else
        ledState = LOW;
    // Switch the LED
    digitalWrite(ledPin, ledState);
    }
    tone(buzzerPin,1000);
  }

  // If alarm is off
  if (buzzer_mode == false) {
  
    // No tone & LED off
    noTone(buzzerPin);  
    digitalWrite(ledPin, LOW);
  }

  // If our button is pressed Switch off ringing and Setup
  int button_state = digitalRead(buttonPin);
  if (button_state) {buzzer_mode = false;}
}