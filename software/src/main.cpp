#include <Arduino.h>

// Processes some raw input and updates the value
bool handleRawSerialInput(String &inputValue) {

  bool terminated = false;
  // Process input - waiting for the terminator (enter key)
  while (!terminated && Serial.available() > 0) {
    int input=0;
    input = Serial.read();
    
    // Correct for terminals that pad out 7-bit ASCII to 8 bits with an extra high bit 
    // (like Putty - pretty sure it's because it's translating but I don't care at this point!) 
    if (input > 127) {
      input = input - 128;
    }

    if (input == '\r') {
      terminated = true;
    } else if (input == '\b') {
      inputValue.remove(inputValue.length()-1, 1);
    } else {
      inputValue.concat((char) input);
    }
  }
  return terminated;
}

// Get user input while letting the menu take care of display updates etc.
String getUserInput() {
  String inputValue="";

  while (Serial.available()==0) {
  }

  // Process the new buffer content and update the inputValue with it
  handleRawSerialInput(inputValue);
    
  return inputValue;
}

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8E1);
}

void loop() {
  String input = getUserInput();
  Serial2.print(input);
}
