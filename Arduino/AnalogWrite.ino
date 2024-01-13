int analog = A0;
int value ;
int LED = 7 ;
int A ;
void setup()
{
  pinMode(analog, INPUT);
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  value = analogRead(analog);
  Serial.println(value);
  A = map(value,0,1023,0,255);
  analogWrite(LED,A);

}