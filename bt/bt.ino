#include <SoftwareSerial.h>
const int rxPin = 10;
const int txPin = 11;
SoftwareSerial BTSerial(rxPin, txPin);

void setup() {
  BTSerial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(2, HIGH);
}

void loop() {
  if (BTSerial.available()) {
    String command = BTSerial.readStringUntil('\n');
    if (command == "LED ON"){
      digitalWrite(LED_BUILTIN, HIGH);
      BTSerial.println("ON");
    } else if (command == "LED OFF"){
      digitalWrite(LED_BUILTIN, LOW);
      BTSerial.println("OFF");
    } else{
      BTSerial.println(command);
    }
  }
  delay(10);
}