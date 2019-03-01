# Calculate

In this lesson we will use our Arduinos as primitive calculators to perform addition, subtraction, multiplication, and division. We will also implement [`while`](https://www.arduino.cc/reference/en/language/structure/control-structure/while/) and `switch` in addition to `if / else` statements.

## Checkpoint 1: Connect Your Arduino

Get your supplies and take out only the Arduino and the USB cable. Connect your Arduino to your laptop, open the Arduino IDE, and make sure the correct port is selected.

## Checkpoint 2: Set Up Setup

Open a new sketch. Use `Serial.begin()` to open a 9600-baud serial connection when the Arduino powers on. Save the new program as _serialCalculate_. Upload the sketch to your Arduino and then add, commit, and push your changes.

<p class="checkpoint">Have Mr. Olinda verify this checkpoint before moving on.</p>

## Checkpoint 3: Program Scope

We need to decide what we want the program to accomplish so that we can design it appropriately. In this case, we know that we want to perform four operations: addition, subtraction, multiplication, and division. However, we also need to decide how many numbers we want the program to work with and whether those numbers should be [integers](https://www.arduino.cc/reference/en/language/variables/data-types/int/), [longs](https://www.arduino.cc/reference/en/language/variables/data-types/long/), or [floating point numbers](https://www.arduino.cc/reference/en/language/variables/data-types/float/). Integers are whole numbers up to 16 bits in size, longs are whole numbers up to 32 bits in size, and floats are numbers with decimal values up to 32 bits in size.

Look at your reference to determine the largest possible integer and long your Arduino can handle. For now, we will work with integers.

At the very beginning of your program, you should declare global variables so that they are available for your entire program to use. We will declare four variables so that our program can perform operations involving two numbers. Add the following lines of code at the top of your program:

```
int number1;
char sign;
int number2;
int result;
```

This tells your Arduino that you want three integer variables to work with along with one character variable. Save, add, commit, and push your code. Then be prepared to explain what information will go in each variable.

<p class="checkpoint">Have Mr. Olinda verify this checkpoint before moving on.</p>

## Checkpoint 4: Set Up Loop

We need to set up our program to handle incoming serial data. Before we write the actual code, we're going to create a test to make sure our incoming data is being processed. Add the following code to your `void loop()` section:

```
  while (Serial.available() > 0) {
    char inbound = Serial.read();
    Serial.println(inbound);
  }
```

We are declaring a `char` variable within the `while` statement, which means it won't be available everywhere in our program. This is acceptable here. Now, upload your code and type something into the serial monitor. Your program should send back what you typed, broken into one character per line. Try a few different strings of text. Then, change your `Serial.println(inbound);` to `Serial.println(inbound, HEX);` and see what happens when you send text. You'll notice that you're getting back more characters than you sent. Why do you think this is? Try `BIN` and `OCT` to see what happens. These return what you sent in hexadecimal, binary, and octal respectively. But why are there more characters than when you first ran the test?

_Hint: this is why we used `.trim` in the Serial lesson._

<p class="checkpoint">Have Mr. Olinda verify this checkpoint before moving on.</p>

