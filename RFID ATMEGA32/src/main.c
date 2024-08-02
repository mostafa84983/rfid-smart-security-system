#include "main.h"  
#include "main_config.h"  
// Function Prototypes
void Door_VidInit(); // done
void Door_VidOpen(); // done
void Door_VidClose(); // done
void Door_VidCheck(); // done
void EEP_Vidinit(); // done
void BuzzerLed_VidInit(); // done

void Block_VidCheck(); // done
void LockMode_VidCheck(); // done
void BuzzerLed_VidEnable(); // done
void BuzzerLed_VidDisable(); // done
void Buzzer_VidEnable(); // done

void ArdTest();

u8 Global_u8Mode = NOT_SET; // Global mode variable
u8 receivedData;

int main(void) {
    // Initialize the LCD
    UART_VidInit(9600);
    _delay_ms(10);
    LCD_VidInit("Initializing...");
    Global_u8Mode = EEPROM_U8Read(LOCKMODE_ADDRESS);
    EEP_Vidinit();
    Door_VidInit(); // Check Door
    Block_VidCheck(); // Check Block
    KEYPAD_VidInitMatrixMode();
    BuzzerLed_VidInit();
    LCD_VidCmd(LCD_CLEAR);
    UART_VidSendByte(ARDUINO_PRINT);
    _delay_ms(10);

    while(1){
        LockMode_VidCheck(); // Uses global variable directly
    }
}
void Door_VidInit()
{
    DIO_VidSetPinDirection(GREEN_LED_PORT, GREEN_LED_PIN, Output);
    DIO_VidSetPinDirection(MOTOR_PORT, MOTOR_PIN0, Output);
    DIO_VidSetPinDirection(MOTOR_PORT, MOTOR_PIN1, Output);
    DIO_VidSetPinValue(MOTOR_PORT, MOTOR_PIN0, PinLow);
    DIO_VidSetPinValue(MOTOR_PORT, MOTOR_PIN1, PinLow);
    DIO_VidSetPinValue(GREEN_LED_PORT, GREEN_LED_PIN, PinLow);
    Door_VidCheck();
}
void Door_VidOpen()
{
    // TURN-ON MOTOR
    DIO_VidSetPinValue(MOTOR_PORT, MOTOR_PIN0, PinHigh);
    DIO_VidSetPinValue(MOTOR_PORT, MOTOR_PIN1, PinLow);
    _delay_ms(MOTOR_DELAY);
    // TURN-OFF MOTOR
    DIO_VidSetPinValue(MOTOR_PORT, MOTOR_PIN0, PinLow);
    DIO_VidSetPinValue(MOTOR_PORT, MOTOR_PIN1, PinLow);

    EEPROM_VidWrite(DOOR_ADDRESS, DOOR_OPEN);
    DIO_VidSetPinValue(GREEN_LED_PORT, GREEN_LED_PIN, PinHigh);
    _delay_ms(DEFAULT_DELAY * 5);
}
void Door_VidClose()
{
    // TURN-ON MOTOR
    DIO_VidSetPinValue(MOTOR_PORT, MOTOR_PIN0, PinLow);
    DIO_VidSetPinValue(MOTOR_PORT, MOTOR_PIN1, PinHigh);
    _delay_ms(MOTOR_DELAY);
    // TURN-OFF MOTOR
    DIO_VidSetPinValue(MOTOR_PORT, MOTOR_PIN0, PinLow);
    DIO_VidSetPinValue(MOTOR_PORT, MOTOR_PIN1, PinLow);

    EEPROM_VidWrite(DOOR_ADDRESS, DOOR_CLOSED);
    DIO_VidSetPinValue(GREEN_LED_PORT, GREEN_LED_PIN, PinLow);
}
void BuzzerLed_VidInit()
{
    DIO_VidSetPinDirection(BUZZER_PORT, BUZZER_PIN, Output);
    DIO_VidSetPinValue(BUZZER_PORT, BUZZER_PIN, PinLow);
    DIO_VidSetPinDirection(RED_LED_PORT, RED_LED_PIN, Output);
    DIO_VidSetPinValue(RED_LED_PORT, RED_LED_PIN, PinLow);
}
void BuzzerLed_VidEnable()
{
    DIO_VidSetPinValue(BUZZER_PORT, BUZZER_PIN, PinHigh);
    DIO_VidSetPinValue(RED_LED_PORT, RED_LED_PIN, PinHigh);
}
void BuzzerLed_VidDisable()
{
    DIO_VidSetPinValue(BUZZER_PORT, BUZZER_PIN, PinLow);
    DIO_VidSetPinValue(RED_LED_PORT, RED_LED_PIN, PinLow);
}
void Door_VidCheck(){
    u8 Local_u8Door = EEPROM_U8Read(DOOR_ADDRESS);
    if (DOOR_OPEN == Local_u8Door){
        Door_VidClose();
    }
}
void Block_VidCheck(){
    u8 Local_u8Block = EEPROM_U8Read(BLOCK_ADDRESS);
    if (BLOCKED == Local_u8Block){
        LCD_VidCmd(LCD_CLEAR);
        LCD_VidPrintString("Login Blocked");
        LCD_VidCmd(LCD_2ND_LINE);
        LCD_VidPrintString("Wait 5 Seconds");
        BuzzerLed_VidEnable();
        _delay_ms(BLOCK_DELAY);
        BuzzerLed_VidDisable();
        EEPROM_VidWrite(BLOCK_ADDRESS, NOT_BLOCKED);
        EEPROM_VidWrite(TRIES_LEFT_ADDRESS, PIN_TRIES_ALLOWED);
        EEPROM_VidWrite(LOCKMODE_ADDRESS, CARD_MODE);
        Global_u8Mode = CARD_MODE;
        LCD_VidCmd(LCD_CLEAR);
        UART_VidSendByte(ARDUINO_PRINT);
    }
}
void LockMode_VidCheck(){
    if (CARD_MODE == Global_u8Mode){
        u8 Local_u8Recieved_Data = UART_u8ReceiveData();
        switch (Local_u8Recieved_Data)
        {
            case ARDUINO_ACCEPTED:
                Buzzer_VidEnable();
                Door_VidOpen();
                _delay_ms(DEFAULT_DELAY * 5);
                Door_VidClose();
                _delay_ms(DEFAULT_DELAY * 5);
                LCD_VidCmd(LCD_CLEAR);
                UART_VidSendByte(ARDUINO_PRINT);
                break;
        
            case ARDUINO_REJECTED:
                Buzzer_VidEnable();
                Door_VidCheck();
                EEPROM_VidWrite(LOCKMODE_ADDRESS, PIN_MODE);
                Global_u8Mode = PIN_MODE;
                _delay_ms(DEFAULT_DELAY * 5);
                break;
        
            case ARDUINO_CLEAR:
                LCD_VidCmd(LCD_CLEAR);               
                break;
        
            case ARDUINO_PRINT:
                while('\n' != Local_u8Recieved_Data){
                    Local_u8Recieved_Data = UART_u8ReceiveData();
                    LCD_VidPrintChar(Local_u8Recieved_Data);
                }
                break;
            case ARDUINO_NEWLINE:
                LCD_VidCmd(LCD_2ND_LINE);
                break;
        
            default:
                LCD_VidPrintString("Err: ");
                LCD_VidPrintChar(Local_u8Recieved_Data);
                break;
        }
    
    }
    else if (PIN_MODE == Global_u8Mode){
        // Get Pass
        u8 Local_u8PinCounter = 0;
        u8 Local_u8KeyPressed = NOT_PRESSED;
        u8 Entered_Pin[PIN_SIZE];
        for (u8 Local_u8Counter = 0; Local_u8Counter < PIN_SIZE; Local_u8Counter++){
            Entered_Pin[Local_u8Counter] = NOT_SET;
        }
    
        u8 Local_u8TriesLeft = EEPROM_U8Read(TRIES_LEFT_ADDRESS);
        LCD_VidCmd(LCD_CLEAR);
        LCD_VidPrintString("Tries = ");
        LCD_VidPrintNumber(Local_u8TriesLeft);
        _delay_ms(DEFAULT_DELAY * 5);
        while(Local_u8TriesLeft > 0){
            LCD_VidCmd(LCD_CLEAR);
            LCD_VidPrintString("Enter Your Pin:");
            LCD_VidCmd(LCD_2ND_LINE);
        
            Local_u8PinCounter = 0;
            while (Local_u8PinCounter < PIN_SIZE)
            {
                WaitForKey(&Local_u8KeyPressed);
                if (Local_u8KeyPressed >= '0' && Local_u8KeyPressed <= '9')
                {
                    Entered_Pin[Local_u8PinCounter] = Local_u8KeyPressed;
                    LCD_VidPrintChar_XY(Local_u8KeyPressed, 2, Local_u8PinCounter + 1);
                    _delay_ms(CHAR_PREVIEW_TIME);
                    LCD_VidPrintChar_XY(PASSWORD_SYMBOL, 2, Local_u8PinCounter + 1);
                    Local_u8PinCounter++;
                }
            }
            LCD_VidCmd(LCD_CLEAR);
            // check Pass
            u8 Local_u8PinMatch = TRUE;
            u8 Local_u8StoredPin = NOT_SET;
            for (Local_u8PinCounter = 0; Local_u8PinCounter < PIN_SIZE; Local_u8PinCounter++)
            {
                Local_u8StoredPin = EEPROM_U8Read(PIN_ADDRESS + Local_u8PinCounter); // Stored Pin
                if (Entered_Pin[Local_u8PinCounter] != Local_u8StoredPin)
                {
                    Local_u8PinMatch = FALSE;
                    break;
                }
                else
                    continue;
            }
            if (TRUE == Local_u8PinMatch)
            {
                LCD_VidPrintString_XY("Pin Accepted", 1, 4);
                Door_VidOpen();
                _delay_ms(DEFAULT_DELAY * 5);
                Door_VidClose();
                EEPROM_VidWrite(LOCKMODE_ADDRESS, CARD_MODE);
                Global_u8Mode = CARD_MODE;
                LCD_VidCmd(LCD_CLEAR);
                UART_VidSendByte(ARDUINO_PRINT);                
                break;
            }
            else
            {
                Local_u8TriesLeft--;
                EEPROM_VidWrite(TRIES_LEFT_ADDRESS, Local_u8TriesLeft);
                LCD_VidPrintString_XY("Wrong Pin!!", 1, 3);
                LCD_VidPrintString_XY("Tries Left: ", 2, 1);
                LCD_VidPrintNumber(Local_u8TriesLeft);
                _delay_ms(DEFAULT_DELAY * 5);
                LCD_VidCmd(LCD_CLEAR);
            }
        }
    
        if (Local_u8TriesLeft == 0){
            EEPROM_VidWrite(BLOCK_ADDRESS, BLOCKED);
            Block_VidCheck();
        }
    }
}
void Buzzer_VidEnable(){
    DIO_VidSetPinValue(BUZZER_PORT, BUZZER_PIN, PinHigh);
    _delay_ms(DEFAULT_DELAY);
    DIO_VidSetPinValue(BUZZER_PORT, BUZZER_PIN, PinLow);
}
void EEP_Vidinit(){
    // Set Pin
    u8 Pin[PIN_SIZE] = "1234";
    EEPROM_WriteBlock(PIN_ADDRESS, Pin, PIN_SIZE);
    // Default Card Mode
    if (NOT_SET == Global_u8Mode){
        EEPROM_VidWrite(LOCKMODE_ADDRESS, CARD_MODE);
        Global_u8Mode = CARD_MODE;
    }
    // Default Door Status
    if (NOT_SET == EEPROM_U8Read(DOOR_ADDRESS)){
        EEPROM_VidWrite(DOOR_ADDRESS, DOOR_CLOSED);
    }
    // Default Block Status
    if (NOT_SET == EEPROM_U8Read(BLOCK_ADDRESS)){
        EEPROM_VidWrite(BLOCK_ADDRESS, NOT_BLOCKED);
    }
    // Default Tries Left
    if (NOT_SET == EEPROM_U8Read(TRIES_LEFT_ADDRESS)){
        EEPROM_VidWrite(TRIES_LEFT_ADDRESS, PIN_TRIES_ALLOWED);
    }
}
void ArdTest(){
    receivedData = UART_u8ReceiveData();
    LCD_VidPrintChar(receivedData);
    UART_VidSendByte(receivedData);
    _delay_ms(100);
}