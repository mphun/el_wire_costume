const int relay1 = 3;
const int relay2 = 4;
const int buttonPin = 2;

int buttonState = 0;
int buttoncounter = 0;

void setup() {
  Serial.begin(9600);  
  pinMode(relay1, OUTPUT);  
  pinMode(relay2, OUTPUT);
  pinMode(buttonPin, INPUT);  
}

void loop(){
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == LOW) {
    Serial.println("here");
    buttoncounter++;
    delay(100);
    while (buttonState == LOW){
      buttonState = digitalRead(buttonPin);
      Serial.println("loop");
      delay(100); 
    }
  }
  Serial.println(buttoncounter);
  switch (buttoncounter % 6){
   case 0:
     digitalWrite(relay1, LOW);
     digitalWrite(relay2, LOW);
     delay(1000);
     digitalWrite(relay1, HIGH);
     digitalWrite(relay2, HIGH);
     delay(1000);
     break;
   case 1:
     digitalWrite(relay1, HIGH);
     digitalWrite(relay2, LOW);
     break;
   case 2:
     digitalWrite(relay1, LOW);
     digitalWrite(relay2, HIGH);
     break;
   case 3:
     digitalWrite(relay1, HIGH);
     digitalWrite(relay2, HIGH);
     break;
   case 4:
     digitalWrite(relay1, LOW);
     digitalWrite(relay2, LOW);
     delay(3000);
     digitalWrite(relay1, HIGH);
     digitalWrite(relay2, HIGH);
     delay(3000);
     break;
   case 5:
     digitalWrite(relay1, LOW);
     digitalWrite(relay2, LOW);
     break;
  }
}
