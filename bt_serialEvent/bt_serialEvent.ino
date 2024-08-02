void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(2, HIGH);
}

void loop() {
  delay(10);
}

void serialEvent(){
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    if (command == "LED ON"){
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("ON");
    } else if (command == "LED OFF"){
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("OFF");
    } else{
      Serial.println(command);
    }
  }
  delay(10);
}