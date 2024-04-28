const int sensorPin = A0 ;
const int LED_RED = 3 ;
const int LED_GREEN = 2 ;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensorPin,INPUT);
  pinMode(LED_RED,OUTPUT);
  pinMode(LED_GREEN,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorvalue = analogRead(sensorPin);
  float voltage = (sensorvalue/1024.0)*5000.0 ;
  float temperature = (voltage-400.0)/19.5 ;
  Serial.println(temperature);
  delay(80);

  if(temperature < 15) {
    digitalWrite(LED_GREEN,1);
  }
  else if (temperature > 35) {
    digitalWrite(LED_RED,1);
  }
  else{
    digitalWrite(LED_RED,0);
  digitalWrite(LED_GREEN,0);
  }
}
