// #include <Arduino.h>
// #include <SoftwareSerial.h>
// #include <SPI.h>
// #include <MFRC522.h>

// #define RST_PIN 9
// #define SS_PIN 10

// #define ARDUINO_ACCEPTED    (u8)'a'
// #define ARDUINO_REJECTED    (u8)'r'
// #define ARDUINO_CLEAR       (u8)'c'
// #define ARDUINO_PRINT       (u8)'p'
// #define ARDUINO_NEWLINE     (u8)'n'


// char scannedCard[8];
// String AcceptedTag = "531F41F";	// REPLACE thi`s Tag ID with your Tag ID!!!
// String tagID = "";

// // Create instances
// MFRC522 mfrc522(SS_PIN, RST_PIN);

// void sendStringWithDelay(const char* str);
// boolean getID(void);
// void serialEvent(void);

// void setup() 
// {
//   // Initiating
//   SPI.begin(); // SPI bus
//   mfrc522.PCD_Init(); // MFRC522
//   Serial.begin(9600);		// Initialize serial communications with the ATMEGA
//   delay(1000);
// }

// void loop() 
// {

//   //Wait until new tag is available
  
//   Serial.println("Looping...");
//   while (getID()) 
//   {
//     Serial.println("Verifying card...");
//     if (tagID == AcceptedTag) 
//     {
//       Serial.write(ARDUINO_CLEAR);
//       sendStringWithDelay(" Access Granted!");
//       Serial.write(ARDUINO_NEWLINE);
//       sendStringWithDelay(" ID : ");
//       sendStringWithDelay(tagID.c_str());
//       Serial.write(ARDUINO_ACCEPTED);
//     }
//     else
//     {
//       Serial.write(ARDUINO_CLEAR);
//       sendStringWithDelay(" Access Denied!");
//       Serial.write(ARDUINO_NEWLINE);
//       sendStringWithDelay(" ID : ");
//       sendStringWithDelay(tagID.c_str());
//       Serial.write(ARDUINO_REJECTED);
//     }
    
//     delay(2000);
//   }
// }


// //Read new tag if available
// boolean getID(void) 
// {
  
//   if(Serial.available()){
//     serialEvent();
//   }
//   Serial.println("Checking for card...");
//   // Getting ready for Reading PICCs
//   if ( ! mfrc522.PICC_IsNewCardPresent()) { //If a new PICC placed to RFID reader continue
//   return false;
//   }
//   if ( ! mfrc522.PICC_ReadCardSerial()) { //Since a PICC placed get Serial and continue
//   return false;
//   }
//   Serial.println("Card detected!");
//   tagID = "";
//   for ( uint8_t i = 0; i < 4; i++) { // The MIFARE PICCs that we use have 4 byte UID
//   tagID.concat(String(mfrc522.uid.uidByte[i], HEX)); // Adds the 4 bytes in a single String variable
//   scannedCard[i] = tagID[i];
//   }
//   tagID.toUpperCase();
//   mfrc522.PICC_HaltA(); // Stop reading
//   return true;
// }

// //Read new tag if available
// // boolean getID() 
// // {
// //   // Getting ready for Reading PICCs
// //   if ( ! mfrc522.PICC_IsNewCardPresent()) { //If a new PICC placed to RFID reader continue
// //     return false;
// //   }
// //   if ( ! mfrc522.PICC_ReadCardSerial()) { //Since a PICC placed get Serial and continue
// //     return false;
// //   }
// //   tagID = "";
// //   for ( uint8_t i = 0; i < 4; i++) { // The MIFARE PICCs that we use have 4 byte UID
// //     scannedCard[i] = mfrc522.uid.uidByte[i];
// //     tagID.concat(String(mfrc522.uid.uidByte[i], HEX)); // Adds the 4 bytes in a single String variable
// //   }
// //   tagID.toUpperCase();
// //   mfrc522.PICC_HaltA(); // Stop reading
// //   return true;
// // }

// // Define the ISR
// void serialEvent(void) {
//   Serial.println("gwa el event");
    
//     char receivedChar = Serial.read(); // Read the received byte from the UART data register
//     // Check if the received byte matches the target code
//     if (ARDUINO_PRINT == receivedChar) {
//         sendStringWithDelay(" Access Control ");
//         Serial.write(ARDUINO_NEWLINE);
//         sendStringWithDelay("Scan Your Card>>");
//     }
//     delay(2000);
// }

// void sendStringWithDelay(const char* str) {
//   delay(500);
//   int i = 0;
//   Serial.write(ARDUINO_PRINT);
//   while (str[i] != '\0') {
//     Serial.write(str[i]); // Print the current character
//     delay(5);             // Delay for 5ms
//     i++;                  // Move to the next character
//   }
//   Serial.write('\n');
// }