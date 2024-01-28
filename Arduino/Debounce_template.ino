int buttonState = LOW;             
int lastButtonState = LOW; 
long lastDebounceTime = 0;  
long debounceDelay = 50;

void setup()
{

}

void loop()
{
  

}

boolean Debounce(int button){
  
  int reading = digitalRead(button);
    if (reading != lastButtonState) {
      lastDebounceTime = millis();
    }
    
    if ((millis() - lastDebounceTime) > debounceDelay) {
      if (reading != buttonState) {
        buttonState = reading;
        if (buttonState == HIGH) {
          lastButtonState = reading; 
          return(HIGH);
        }
      }
    }
    
    lastButtonState = reading;
    return(LOW);
}