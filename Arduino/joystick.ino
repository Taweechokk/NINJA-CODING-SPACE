const int VRX = A0;
const int VRY = A1;
const int SW = 8;
const int LED_RED = 2;
const int LED_GREEN = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(VRX,INPUT);
  pinMode(VRY,INPUT);
  pinMode(SW,INPUT);
  pinMode(LED_RED,OUTPUT);
  pinMode(LED_GREEN,OUTPUT);
  digitalWrite(SW, HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int X = analogRead(VRX);
  int Y = analogRead(VRY);
  int state_button = digitalRead(SW);

  Serial.print("X_value= ");
  Serial.print(X);
  Serial.print("\t");
  Serial.print("Y_value= ");
  Serial.print(Y);
  Serial.print("\t");
  Serial.print("state_button= ");
  Serial.println(state_button);
  delay(100);

  if(state_button==0){
    digitalWrite(LED_RED,HIGH);
  }else{
    digitalWrite(LED_RED,LOW);
  }

  if(X<450){
    int value = map(X,0,1023,0,255);
    analogWrite(LED_GREEN,value);
  }else if(X>600){
    int value = map(X,0,1023,0,255);
    analogWrite(LED_GREEN,value);
  }else{
    analogWrite(LED_GREEN,0);
  }
}
