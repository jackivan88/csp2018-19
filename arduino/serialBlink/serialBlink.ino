void setup() {
  Serial.begin(115200);
  Serial.setTimeout(10);
  pinMode(13, OUTPUT);
  Serial.println("Hello!");
  Serial.println("Type 'On' to turn on the LED.");
  Serial.println("Type 'Off' to turn off the LED.");
  Serial.flush();
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readString();
    command.trim();
    Serial.flush();
    if (command == "On") {
      Serial.println("OK, turning the light on...");
      digitalWrite(13, HIGH);
    }
    else if (command == "Off") {
      Serial.println("OK, turning the light off...");
      digitalWrite(13, LOW);
    }
    else {
      Serial.print("I'm sorry, I didn't understand that. Please type 'On' or 'Off' before sending. I received: ");
      Serial.println(command);
    }
  }
}
