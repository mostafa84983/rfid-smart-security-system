// #include <Arduino.h>
// #include <SoftwareSerial.h>

// #define ARDUINO_ACCEPTED     (u8)'6'
// #define ARDUINO_REJECTED    (u8)'2'
// #define ARDUINO_CLEAR       (u8)'0'
// #define ARDUINO_SCAN        (u8)'8'
// #define ARDUINO_PRINT       (u8)0x01

// // Constants
// const int rxPin = 2; // RX pin for SoftwareSerial
// const int txPin = 3; // TX pin for SoftwareSerial

// // Variables
// volatile bool operationFlag = false; // Flag to control main loop execution

// // Create a SoftwareSerial object
// SoftwareSerial terminal(rxPin, txPin);

// void serialEvent();
// void sendStringWithDelay(const char* str);

// void setup() {
//   // Initialize the hardware serial (Serial Monitor)
//   Serial.begin(9600);
  
//   // Initialize SoftwareSerial
//   terminal.begin(9600);
// }

// void loop() {
//   // Check for new data from the Serial Monitor
//   if (Serial.available()) {
//     serialEvent();
//   }

//   if (operationFlag) {
//     // Send "Main" to the other board
//     terminal.write(ARDUINO_PRINT);
//     delay(100); // Add a short delay
//     sendStringWithDelay("Accepted");
//     delay(100); // Add a short delay
//     // Optionally, reset the flag if this action should only happen once
//     operationFlag = false;
//   }
// }

// void serialEvent() {
//   // Read data from the Serial Monitor
//   char incomingByte = Serial.read();
  
//   // Check if the received byte matches the target code
//   if (incomingByte == ARDUINO_SCAN) {
//     // Send "Hello" to the other board
//     terminal.write(ARDUINO_PRINT);
//     delay(100); // Add a short delay
//     sendStringWithDelay("ABCDEFGH");
//     delay(100); // Add a short delay
//     // Set the operation flag to true
//     operationFlag = true;
//   }
  
// }

// void sendStringWithDelay(const char* str) {
//   int i = 0;
//   while (str[i] != '\0') {
//     terminal.write(str[i]); // Print the current character
//     delay(5); // Delay for 1ms
//     i++; // Move to the next character
//   }
//   terminal.write('\n');
// }
