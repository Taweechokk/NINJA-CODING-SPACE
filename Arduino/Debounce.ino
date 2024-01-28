// C++ code
//
const int buttonPin = 2;
int buttonState = LOW;             
int lastButtonState = LOW; 
long lastDebounceTime = 0;  
long debounceDelay = 50;
const int LED1=3; 
const int LED2=4; 

int state = 0;

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  
  if(Debounce(buttonPin) == HIGH)             //button1
    {         
      state++;   
       
    }
  Serial.println(state);
  if(state==0){
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
  }
  if(state==1){
    digitalWrite(LED1,HIGH);
    digitalWrite(LED2,LOW);
  }
  if(state==2){
    digitalWrite(LED2,HIGH);
    digitalWrite(LED1,LOW);
  }
  if(state==3){
    digitalWrite(LED2,HIGH);
    digitalWrite(LED1,HIGH);
  }
  if(state==4){
    state=0;
  }
  
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