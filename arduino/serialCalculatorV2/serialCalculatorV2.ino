long number1;
long number2;
long result;
long cleanDigits[32];

char sign;

bool newData = false;
bool readyToCalculate = false;
bool readyToPrint = false;

int count;

void setup() {
  Serial.begin(115200);
  Serial.println("This program is able to perform addition, subtraction, multiplication, and division of two integers.");
  Serial.println("Please enter an operation");
}

void loop() {
  clean();
  parseCleanData();
  calculate();
  concatenateResultsAndPrint();
}

void clean() {
  int count = 0;
  while (Serial.available() > 0) {
    newData = true;
    if (isDigit(Serial.peek()) == true) {
      cleanDigits[count] = Serial.parseInt();
      count++;
      //      Serial.print("The current count is ");
      //      Serial.println(count);
      delay(10);
    }
    else if (isGraph(Serial.peek()) == true) {
      sign = Serial.read();
      //      Serial.println(sign);
      delay(10);
    }
    else {
      Serial.read();
    }
  }
}

void parseCleanData() {
  if (newData == true) {
    number1 = cleanDigits[0];
    number2 = cleanDigits[1];
//    Serial.println(number1);
//    Serial.println(sign);
//    Serial.println(number2);
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
    readyToCalculate = false;
    readyToPrint = true;
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
