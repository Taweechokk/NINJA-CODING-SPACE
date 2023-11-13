int pin = A2 ;
int LED1 = 2;
int LED2 = 3;
int value ,control;
void setup() {
  // put your setup code here, to run once:
  pinMode(pin,INPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println(analogRead(pin));
  value = analogRead(pin);
  control = map(value,0,1023,0,255);
  analogWrite(LED2,control);

  if(value<300){
    digitalWrite(LED1,HIGH);
  }else{
    digitalWrite(LED1,LOW);
  }
}
