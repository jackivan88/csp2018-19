long number1;
long number2;
long result;
long integers[2];

char sign;

bool newData = false;
bool readyToCalculate = false;
bool readyToPrint = false;

int count;

String inbound;

void setup() {
  Serial.begin(115200);
  Serial.println("This program is able to perform addition, subtraction, multiplication, and division of two integers.");
  Serial.println("Please enter an operation.");
}

void loop() {
  cleanData();
  parseData();
  calculate();
  concatenateResultsAndPrint();
}

void cleanData() {
  count = 0;
  while (Serial.available() > 0) {
    newData = true;
    if (isDigit(Serial.peek()) == true) {
      integers[count] = Serial.parseInt();
      count++;
      delay(1);
    }
    else if (isGraph(Serial.peek()) == true) {
      sign = Serial.read();
      delay(1);
    }
    else {
      Serial.read();
    }
  }
}

void parseData() {
  if (newData == true) {
    number1 = integers[0];
    number2 = integers[1];
    newData = false;
    readyToCalculate = true;
  }
}

void calculate() {
  if (readyToCalculate == true) {
    Serial.println("Calculating...");
    switch (sign) {
      case '+' :
        result = number1 + number2;
        readyToPrint = true;
        break;
      case '-' :
        result = number1 - number2;
        readyToPrint = true;
        break;
      case '*' :
        result = number1 * number2;
        readyToPrint = true;
        break;
      case '/' :
        result = number1 / number2;
        readyToPrint = true;
        break;
      default:
        Serial.println("This operation is not supported. Please try again.");
        readyToPrint = false;
        break;
    }
    readyToCalculate = false;
  }
}

void concatenateResultsAndPrint() {
  if (readyToPrint == true) {
    String printCalculation = String(number1) + ' ' + String(sign) + ' ' + String(number2) + String(" = ") + String(result);
    Serial.println(printCalculation);
    Serial.println("Please enter another operation.");
    readyToPrint = false;
  }
}
