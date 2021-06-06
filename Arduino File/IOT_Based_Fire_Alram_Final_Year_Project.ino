int gasPin = 13;
#define buzzer1 10
#define greenLed 2
int gasVal=156;
String readString1="You are Safe";
String readString2="Fire Detected";
void setup() {
 Serial.begin(9600);
 pinMode(8, OUTPUT);
 pinMode(buzzer1, OUTPUT);
 pinMode(greenLed, OUTPUT);
 pinMode(13,INPUT);// put your setup code here, to run once:
 }

void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()>0)
   {
 bool data = digitalRead(13);   
//  bool data = bool(Serial.read()); // reading the data received from the bluetooth module
  switch (data) {
  case LOW:   
    Serial.println(readString1);
    digitalWrite(greenLed,LOW);
    digitalWrite(buzzer1,LOW);
    delay(1000);// statements
    break;
  case HIGH:
    Serial.println(readString2); 
    digitalWrite(greenLed,HIGH);
    delay(500);
    digitalWrite(greenLed,LOW);
    digitalWrite(buzzer1,HIGH);
    delay(500);
    digitalWrite(buzzer1,LOW);
    digitalWrite(greenLed,HIGH);
    delay(500);
    break;// statements
  default:
    Serial.println("Invalid INPUT");
    delay(150);// statements
    break;
}
}
}
