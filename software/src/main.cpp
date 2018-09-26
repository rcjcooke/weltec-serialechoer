#include <Arduino.h>

// Get user input while letting the menu take care of display updates etc.
bool getInput(int &inputValue, HardwareSerial serialInterface) {
  bool gotSome = false;
  // Process input - waiting for the terminator (enter key)
  if (serialInterface.available() > 0) {
    while (serialInterface.available() > 0) {
      inputValue = serialInterface.read();
    }
    gotSome = true;
  } else {
    gotSome = false;
  }

  return gotSome;
}

// Get user input while letting the menu take care of display updates etc.
bool getUserInput(int &inputValue) {
  bool gotSome = false;
  // Process input - waiting for the terminator (enter key)
  if (Serial.available() > 0) {
    while (Serial.available() > 0) {
      inputValue = Serial.read();
    }
    gotSome = true;
  } else {
    gotSome = false;
  }

  return gotSome;
}

void setup() {
  Serial.begin(9600);
  Serial2.begin(9600);
  Serial3.begin(9600);
}

void loop() {
  int userInputValue = 0;
  int serial2InputValue = 0;
  int serial3InputValue = 0;

  bool userInput = getUserInput(userInputValue);
  bool serial2Input = getInput(serial2InputValue, Serial2);
  bool serial3Input = getInput(serial3InputValue, Serial3);

  if (userInput) {
    Serial2.print(userInputValue);
    Serial3.print(userInputValue);
  }
  if (serial2Input) {
    Serial.print(serial2InputValue);
    Serial3.print(serial2InputValue);
  }
  if (serial3Input) {
    Serial.print(serial3InputValue);
    Serial2.print(serial3InputValue);
  }
}
