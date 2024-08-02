#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9
#define SS_PIN 10

#define ARDUINO_ACCEPTED    (u8)'a'
#define ARDUINO_REJECTED    (u8)'r'
#define ARDUINO_CLEAR       (u8)'c'
#define ARDUINO_PRINT       (u8)'p'
#define ARDUINO_NEWLINE     (u8)'n'


String AcceptedTag = "531F41F";
String tagID = "";

// Create instances
MFRC522 mfrc522(SS_PIN, RST_PIN);

void sendStringWithDelay(const char* str);
boolean getID(void);
void serialEvent(void);
void cardGranted(bool granted);

void setup() 
{
  // Initiating
  SPI.begin(); // SPI bus
  mfrc522.PCD_Init(); // MFRC522
  Serial.begin(9600);		// Initialize serial communications with the ATMEGA
  delay(10);
}

void loop() 
{

// Wait until new tag is available
  if (getID()) 
  {
    cardGranted(tagID == AcceptedTag);
    delay(100);
  }
}

//Read new tag if available
boolean getID(void) 
{
  
  if(Serial.available()){
    serialEvent();
  }
  // Getting ready for Reading PICCs
  if ( ! mfrc522.PICC_IsNewCardPresent()) { //If a new PICC placed to RFID reader continue
  return false;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) { //Since a PICC placed get Serial and continue
  return false;
  }
  tagID = "";
  for ( uint8_t i = 0; i < 4; i++) { // The MIFARE PICCs that we use have 4 byte UID
  tagID.concat(String(mfrc522.uid.uidByte[i], HEX)); // Adds the 4 bytes in a single String variable
  }
  tagID.toUpperCase();
  mfrc522.PICC_HaltA(); // Stop reading
  return true;
}

// Define the ISR
void serialEvent(void) {
    char receivedChar = Serial.read(); // Read the received byte from the UART data register
    // Check if the received byte matches the target code
    if (ARDUINO_PRINT == receivedChar) {
        sendStringWithDelay(" Access Control ");
        Serial.write(ARDUINO_NEWLINE);
        sendStringWithDelay("Scan Your Card>>");
    }
    delay(10);
}

void sendStringWithDelay(const char* str) {
  delay(10);
  int i = 0;
  Serial.write(ARDUINO_PRINT);
  while (str[i] != '\0') {
    Serial.write(str[i]); // Print the current character
    delay(5);             // Delay for 5ms
    i++;                  // Move to the next character
  }
  Serial.write('\n');
  delay(10);
}

void cardGranted(bool granted){
  Serial.write(ARDUINO_CLEAR);
  
  if (granted)
    sendStringWithDelay(" ACCESS GRANTED!");
  else
    sendStringWithDelay(" ACCESS DENIED!");

  Serial.write(ARDUINO_NEWLINE);
  sendStringWithDelay(" ID : ");
  sendStringWithDelay(tagID.c_str());
  if (granted)
    Serial.write(ARDUINO_ACCEPTED);
  else
    Serial.write(ARDUINO_REJECTED);
}