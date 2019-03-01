int number1;
int number2;
char sign;
int result;
char cleanData[10] = { 0 };

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  clean();
  int count = 0;
  Serial.println(cleanData[count]);
}

void clean() {
  while (Serial.available() > 0) {
    int count = 0;
    char graph;
    char inbound = Serial.read();
    if (isGraph(inbound)) {
      char graph = inbound;
    }
    else {
    }
    for (count = 0; count++;) {
      char cleanData[count] = { graph };
    }
  }
}

void parseCleanData() {

}
