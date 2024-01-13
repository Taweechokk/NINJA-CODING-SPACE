// beep buzzer
int buzzer = 6;
int LDR = A0;
void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer,OUTPUT);
  pinMode(LDR,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(analogRead(LDR)<200){
    tone(buzzer,1500,500);
    delay(1000);
  }

}


