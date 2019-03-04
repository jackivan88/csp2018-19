# Calculate

In this lesson you will use your Arduino as primitive calculators to perform addition, subtraction, multiplication, and division. You will also implement [`while`](https://www.arduino.cc/reference/en/language/structure/control-structure/while/) and `switch` in addition to `if / else` statements.

## Checkpoint 1: Connect Your Arduino

Get your supplies and take out only the Arduino and the USB cable. Connect your Arduino to your laptop, open the Arduino IDE, and make sure the correct port is selected.

## Checkpoint 2: Set Up Setup

Open a new sketch. Use `Serial.begin()` to open a 9600-baud serial connection when the Arduino powers on. Save the new program as _serialCalculate_. Upload the sketch to your Arduino and then add, commit, and push your changes.

<p class="checkpoint">Have Mr. Olinda verify this checkpoint before moving on.</p>

## Checkpoint 3: Program Scope

You need to decide what you want a program to accomplish so that you can design it appropriately. In this case, you know that you want to perform four operations: addition, subtraction, multiplication, and division. However, you also need to decide how many numbers you want the program to work with and whether those numbers should be [integers](https://www.arduino.cc/reference/en/language/variables/data-types/int/), [longs](https://www.arduino.cc/reference/en/language/variables/data-types/long/), or [floating point numbers](https://www.arduino.cc/reference/en/language/variables/data-types/float/). Integers are whole numbers up to 16 bits in size, longs are whole numbers up to 32 bits in size, and floats are numbers with decimal values up to 32 bits in size.

Look at your reference to determine the largest possible integer and long your Arduino can handle. For now, you will work with integers.

At the very beginning of your program, you should declare global variables so that they are available for your entire program to use. You will declare four variables so that your program can perform operations involving two numbers. Add the following lines of code at the top of your program:

```
int number1;
char sign;
int number2;
int result;
```

This tells your Arduino that you want three integer variables to work with along with one character variable. Save, add, commit, and push your code. Then be prepared to explain what information will go in each variable.

<p class="checkpoint">Have Mr. Olinda verify this checkpoint before moving on.</p>

## Checkpoint 4: Set Up Loop

We need to set up your program to handle incoming serial data. Before you write the actual code, we're going to create a test to make sure your incoming data is being processed. Add the following code to your `void loop()` section:

```
  while (Serial.available() > 0) {
    char inbound = Serial.read();
    Serial.println(inbound);
  }
```

We are declaring a `char` variable within the `while` statement, which means it won't be available everywhere in your program. This is acceptable here. Now, upload your code and type something into the serial monitor. Your program should send back what you typed, broken into one character per line. Try a few different strings of text. Then, change your `Serial.println(inbound);` to `Serial.println(inbound, HEX);` and see what happens when you send text. You'll notice that you're getting back more characters than you sent. Why do you think this is? Try `BIN` and `OCT` to see what happens. These return what you sent in hexadecimal, binary, and octal respectively. But why are there more characters than when you first ran the test?

_Hint: this is why you used `.trim` in the Serial lesson._

<p class="checkpoint">Have Mr. Olinda verify this checkpoint before moving on.</p>

## Checkpoint 5: Sanitizing Data

This gives you an opportunity to build a tool that will clean out certain characters from your serial input. Let's assume you only want to use visible characters and get rid of line feeds, newlines, spaces, and other "invisible" characters. The Arduino library has a function designed to detect whether a character has visible content called `isGraph()`. Replace your `void loop()` content with:

```
  while (Serial.available() > 0) {
    char inbound = Serial.read();
    if (isGraph(inbound)) {
      Serial.println(inbound);
    }
  }
```

Now type in a complete sentence and send it to your Arduino. Your result should come back with all the spaces removed. This will help you clean up your data and make it easier to work with. Now, create a function called `void cleanData()` at the bottom of your program and cut and paste the content of your `void loop()` into this new function. Call the function in your now-empty `void loop()`, which should look like this:

```
void loop() {
  cleanData();
}
```

Upload your code and test it. It should work exactly as it did before, but now you've created your own function that can be used anywhere in your code. _However, variables declared within this function aren't available anywhere else yet._ Add, commit, and push your code.

<p class="checkpoint">Have Mr. Olinda verify this checkpoint before moving on.</p>

## Checkpoint 6: Create and Test an Array

[Arrays](https://www.arduino.cc/reference/en/language/variables/data-types/array/) allow you to store a collection of variables, such as integers or characters, and then access them again later. Since you are trying to store information about numbers and characters, for now you will store them in a `char` array. Later you will parse the information out into integers and characters.

Because you are designing this program with your own functions, you are going to create a new function called `printCleanData()` that will help you test your modifications, add some global variables, and make changes to your `cleanData()` function.

## Checkpoint 7: Declare Global Variables

At the top of your program, declare a character array for your data that has 32 slots:

```
char cleanData[32];
```

Then, declare a new type of variable: the [boolean](https://www.arduino.cc/reference/en/language/variables/data-types/bool/). This variable will be used to tell the program whether or not there is new data to work with when you change your `cleanData()` function.

```
bool newData = false;
```

Why do you use a boolean variable, and what are the possible states for a boolean variable?

## Checkpoint 8: Edit cleanData()

Modify your `cleanData()` function to pass your serial input along to the new `cleanData` array. First, declare a new integer variable called _count_ and set it to zero. You should do this before your `while` loop at the very beginning, otherwise it won't be available later when you need it. Then, change your `if` statement from:

```
if (isGraph(inbound)) {
  Serial.println(inbound);
}
```

to:

```
if (isGraph(inbound)) {
  newData = true;
  cleanData[count] = inbound;
  count++;
}
```

This will send the data to your array instead of the serial monitor. First, it flips the boolean from _false_ to _true_, which you will take advantage of later. Then it sends each character to a slot in the array based on the `count` variable. Remember that many times in programming, lists or arrays start at zero, not one. This is true in C++, which is what you are using to program your Arduino. Therefore, at the moment, the `count` variable is zero, since that's what you set it to at the beginning of your `while` statement. We're placing the `inbound` variable's value in slot 0 of the array. However, the next time the loop runs, you want it to place the next character in the next slot, so you use the `++` iterator. Iterating is simply adding to the previous value. So if `count` was zero before, `count++` makes it one. The next time it will be two, and so on. If you send "This is a test" to your Arduino, these modifications will result in the `cleanData` array containing `{ T, h, i, s, i, s, a, t, e, s, t ....}`.

How many of your 32 slots would be in use at this point?

## Checkpoint 9: Create printCleanData()

Running your program would work, but you wouldn't be able to tell, so you're going to design a temporary function to help you test it. You will take advantage of your `newData` boolean, learn how to test for equivalance, reset your array, and reset your boolean to indicate the program is ready to run again.

Create a new function at the bottom of your program called _printCleanData_ and then type in the following statement:

```
if (newData == true) {
  Serial.println(cleanData);
  char cleanData[32] = "";
  newData = false;
}
```

At this point, make sure to format your code and verify it. Upload it and test it by sending the Arduino several phrases and sentences to see if you get clean data back. If you don't, see if you can figure out what's missing from your `void loop()` function and fix it. Upload and test, and if your code works, go ahead and add, commit, and push your code.

<p class="checkpoint">Have Mr. Olinda verify this checkpoint before moving on.</p>

## Checkpoint 10: Modify printCleanData()

Go ahead and change `printCleanData()` to `parseData()` everywhere it appears in the program. Then rename your array to _integers_. Now it's time to use the variables you declared at the beginning of the program. Replace

```
Serial.println(cleanData);
char cleanData[32] = "";
```

with

```
number1 = integers[0];
number2 = integers[1];
Serial.println(number1);
Serial.println(sign);
Serial.println(number2);
```

Note that when you are assigning a value to a variable, the variable goes on the left of the equation, but when you are using it as a value for something else, it goes on the right. The `Serial.println()` functions will help you test the program. Add, commit, and push your code.

<p class="checkpoint">Have Mr. Olinda verify this checkpoint before moving on.</p>

## Checkpoint 11: Modify cleanData()

Now, you need to make significant changes to `cleanData()`. 

```
void cleanData() {
  count = 0;
  while (Serial.available() > 0) {
    newData = true;
    if (isDigit(Serial.peek()) == true) {
      integers[count] = Serial.parseInt();
      count++;
      Serial.print("The current count is ");
      Serial.println(count);
    }
    else if (isGraph(Serial.peek()) == true) {
      sign = Serial.read();
      Serial.println(sign);
    }
    else {
      Serial.read();
    }
  }
}
```

As before, the `cleanData()` function sets `count` to zero, and you still have a `while` statement. You're also still toggling your `newData` boolean to true, which your program will use later on. Your `if` statement is where things start to get a little more complicated. `(isDigit(Serial.peek()) == true)` tests to see if the incoming serial data starts with a digit by using `Serial.peek()`. Peek looks at the data without removing it from the serial buffer, which lets you do something depending on what it is. In this case, you're checking to see if it's a digit, and if it is, you're running the `parseInt()` function and storing the result in the first slot of the `integers` array. You're then iterating `count` and printing the current count to the serial monitor. 

Now, study the `else if` and `else` statements and prepare to explain what they do. _If you run the program at this point it will not work. We will address this in the next checkpoint, but feel free to try it and see what happens._ Add, commit, and push your code.

<p class="checkpoint">Have Mr. Olinda verify this checkpoint before moving on.</p>

## Checkpoint 12: Fix cleanData()

The reason your code will not work is because your microcontroller is so much faster than your serial connection. Thus, it can read a byte from the serial buffer and cycle through the whole program in less time than it takes for the next byte to arrive. So you will get unusual errors in your results because of incomplete data transfer. There are multiple ways to solve this, and [the optimal solution](http://gammon.com.au/serial) involves storing the serial buffer locally where it can be parsed as quickly as possible. However, a conceptually simpler, but slower, solution is to artificially delay the program long enough for the serial connection to keep up. To do this, add a one-millisecond delay to your _isDigit_ and _isGraph_ statements and test your program again.

<p class="checkpoint">Have Mr. Olinda verify this checkpoint before moving on.</p>

## Checkpoint 13: switch

Now it is time to actually crunch numbers. Create a new function called _calculate_ and open it with an `if` statement that tests whether `readyToCalculate` is _true_. You should also create a `Serial.println` that will let you know this function is running to help you debug errors. Then, create a [`switch`](https://www.arduino.cc/reference/en/language/structure/control-structure/switchcase/) control structure. It will look like: 

```
switch (var) {
  case label1:
    // statements
    break;
  case label2:
    // statements
    break;
  default:
    // statements
    break;
}
```

Your `switch` control structure is based on your `sign` variable and should start like this:

```
switch (sign) {
  case '+' :
    result = number1 + number2;
    readyToPrint = true;
    break;
```

Create cases for the other three operations and then end with a default:

```
default:
  Serial.println("This operation is not supported. Please try again.");
  readyToPrint = false;
  break;
```

After you close your `switch`, toggle the `readyToCalculate` boolean to _false_. Add `Serial.print()` to each case to help debug any mistakes. Add your new function to `void loop()` and save, add, commit, and push your work.

<p class="checkpoint">Have Mr. Olinda verify this checkpoint before moving on.</p>

## Checkpoint 14: Show Your Work

It's time to print. Create a function called _concatenateResultsAndPrint_ and add it to your `void loop()` function. Create an `if` statement testing whether the `readyToPrint` boolean is _true_. Inside the `if` statement you will concatenate several variables and then print your results to the serial monitor. Declare a local `String` variable called _printCalculation_ and set it to `String(number1) + ' ' + String(sign) + ' ' + String(number2) + String(" = ") + String(result);` This long line converts the `number1`, `sign`, `number2`, and `result` variables into strings and then fills in the necessary spaces and _equals_ sign.

Use the `Serial.println` function to print this new string and then prompt the user to enter another operation. Lastly, set the `readyToPrint` boolean to _false_. Test, save, add, commit, and push your work.

<p class="checkpoint">Have Mr. Olinda verify this checkpoint before moving on.</p>

## Checkpoint 15: Break It

What happens if you attempt to perform operations on very large numbers? What happens if you attempt to use floating-point numbers? What happens if you divide numbers that leave a remainder? Figure out the answers to these questions, and then solve at least one of the resulting problems. Then save, add, commit, and push your code.

<p class="checkpoint">Have Mr. Olinda verify this checkpoint before moving on.</p>

## Checkpoint 16: Improve It

At this point, remove your extra printing functions and add instructions for the user that show when the Arduino connects via serial. Clean up and organize your code and see if you can make any improvements before you commit your final code. Then save, add, commit, and push your code.

<p class="checkpoint">Have Mr. Olinda verify this checkpoint before moving on.</p>
