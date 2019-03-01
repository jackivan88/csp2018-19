long number1;
long number2;
char sign;
long result;
String printCalculation;

void setup() {
  Serial.begin(9600);
  Serial.println("Enter a calculation, such as 2+3 or 5-2.");
  Serial.println("I can process addition, subtraction, multiplication, or division of two numbers.");
}

void loop() {
  while (Serial.available() > 0) {
    number1 = Serial.parseInt();
    sign = Serial.read();
    number2 = Serial.parseInt();
    clearIncomingSerial();
    calculate();
    concatenateResultsAndPrint();
  }
}

void calculate() {
  Serial.println("Calculating...");
  switch (sign) {
    case '+' :
      result = number1 + number2;
      break;
    case '-' :
      result = number1 - number2;
      break;
    case '*' :
      result = number1 * number2;
      break;
    case '/' :
      result = number1 / number2;
      break;
    default:
      Serial.println("Please try again.");
      break;
  }
}

void concatenateResultsAndPrint() {
  String printCalculation = String(number1) + ' ' + String(sign) + ' ' + String(number2) + String(" = ") + String(result);
  Serial.println(printCalculation);
  Serial.println("Please enter another operation.");
}

void clearIncomingSerial() {
  while (Serial.available())
    Serial.read();
}

void operationParser() {
  while (Serial.available() > 0) {
    if (isDigit(Serial.peek()) {
      number1 = Serial.parseInt();
    }
    else (isWhitespace(Serial.peek()) {
      Serial.read();
    }
  }
}
