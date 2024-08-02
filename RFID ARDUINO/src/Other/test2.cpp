// #include <Arduino.h>
// #include <SoftwareSerial.h>

// #define ARDUINO_PRINT       (u8)1

// // Define RX and TX pins for SoftwareSerial
// const int rxPin = 2;
// const int txPin = 3;

// // Create a SoftwareSerial object
// SoftwareSerial mySerial(rxPin, txPin);

// void sendStringWithDelay(const char* str);

// void setup() {
//   // Initialize the hardware serial for debugging
//   Serial.begin(9600);

//   // Initialize SoftwareSerial
//   mySerial.begin(9600);
//   delay(2000);
//   sendStringWithDelay("Arduino Ckeck");
//   mySerial.flush();
// }

// void loop() {
//   // Check if there are any incoming bytes available in the SoftwareSerial buffer
//   if (mySerial.available() > 0) {
//   mySerial.println("for loop");
//     // Read the incoming byte
//     char incomingByte = mySerial.read();

//     // Process the incoming byte
//     sendStringWithDelay("Received: ");
//     Serial.write(incomingByte);
//   }

// }

// void sendStringWithDelay(const char* str) {
//   int i = 0;
//   Serial.write(ARDUINO_PRINT);
//   while (str[i] != '\0') {
//     Serial.write(str[i]); // Print the current character
//     delay(5);             // Delay for 5ms
//     i++;                  // Move to the next character
//   }
//   Serial.write('\n');
// }