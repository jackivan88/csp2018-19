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

## Checkpoint 5: Sanitizing Data

This gives us an opportunity to build a tool that will clean out certain characters from our serial input. Let's assume we only want to use visible characters and get rid of line feeds, newlines, spaces, and other "invisible" characters. The Arduino library has a function designed to detect whether a character has visible content called `isGraph()`. Replace your `void loop()` content with:

```
  while (Serial.available() > 0) {
    char inbound = Serial.read();
    if (isGraph(inbound)) {
      Serial.println(inbound);
    }
  }
```

Now type in a complete sentence and send it to your Arduino. Your result should come back with all the spaces removed. This will help us clean up our data and make it easier to work with. Now, create a function called `void clean()` at the bottom of your program and cut and paste the content of your `void loop()` into this new function. Call the function in your now-empty `void loop()`, which should look like this:

```
void loop() {
  clean();
}
```

Upload your code and test it. It should work exactly as it did before, but now you've created your own function that can be used anywhere in your code. _However, variables declared within this function aren't available anywhere else yet._ Add, commit, and push your code.

<p class="checkpoint">Have Mr. Olinda verify this checkpoint before moving on.</p>

## Checkpoint 6: Create and Test an Array

[Arrays](https://www.arduino.cc/reference/en/language/variables/data-types/array/) allow us to store a collection of variables, such as integers or characters, and then access them again later. Since we are trying to store information about numbers and characters, for now we will store them in a `char` array. Later we will parse the information out into integers and characters.

Because we are designing this program with our own functions, we are going to create a new function called `printCleanData()` that will help us test our modifications, add some global variables, and make changes to our `clean()` function.

## Checkpoint 7: Declare Global Variables

At the top of your program, declare a character array for your data that has 32 slots:

```
char cleanData[32];
```

Then, declare a new type of variable: the [boolean](https://www.arduino.cc/reference/en/language/variables/data-types/bool/). This variable will be used to tell the program whether or not there is new data to work with when we change our `clean()` function.

```
bool newData = false;
```

Why do we use a boolean variable, and what are the possible states for a boolean variable?

## Checkpoint 8: Edit clean()

Modify your `clean()` function to pass your serial input along to the new `cleanData` array. First, declare a new integer variable called _count_ and set it to zero. You should do this inside your `while` loop at the very beginning, otherwise it won't be available later when you need it. Then, change your `if` statement from:

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

This will send the data to your array instead of the serial monitor. First, it flips the boolean from _false_ to _true_, which we will take advantage of later. Then it sends each character to a slot in the array based on the `count` variable. Remember that many times in programming, lists or arrays start at zero, not one. This is true in C++, which is what we are using to program our Arduinos. Therefore, at the moment, the `count` variable is zero, since that's what we set it to at the beginning of our `while` statement. We're placing the `inbound` variable's value in slot 0 of the array. However, the next time the loop runs, we want it to place the next character in the next slot, so we use the `++` iterator. Iterating is simply adding to the previous value. So if `count` was zero before, `count++` makes it one. The next time it will be two, and so on. If we send "This is a test" to our Arduino, these modifications will result in the `cleanData` array containing `{ T, h, i, s, i, s, a, t, e, s, t ....}`.

How many of our 32 slots would be in use at this point?

## Checkpoint 9: Create printCleanData()

Running our program would work, but we wouldn't be able to tell, so we're going to design a temporary function to help us test it. We will take advantage of our `newData` boolean, learn how to test for equivalance, reset our array, and reset our boolean to indicate the program is ready to run again.

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

