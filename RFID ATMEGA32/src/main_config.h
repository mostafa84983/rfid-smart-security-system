#ifndef MAIN_CONFIG_H_
#define MAIN_CONFIG_H_

/************** DEFAULT VALUES ***********/
#define CARD_TRIES_ALLOWED  (u8)1
#define PIN_TRIES_ALLOWED   (u8)3
#define MOTOR_DELAY         (u8)5000
#define BLOCK_DELAY         5000
#define DEFAULT_DELAY       (u8)1000
#define PIN_SIZE            (u8)4
#define TRUE                (u8)1
#define FALSE               (u8)0
#define CHAR_PREVIEW_TIME   (u8)500
#define PASSWORD_SYMBOL     (u8)'*'

/************** ARDUINO VALUES ***********/
#define ARDUINO_ACCEPTED    (u8)'a'
#define ARDUINO_REJECTED    (u8)'r'
#define ARDUINO_CLEAR       (u8)'c'
#define ARDUINO_PRINT       (u8)'p'
#define ARDUINO_NEWLINE     (u8)'n'


/************** ADDRESSES ***********/
#define DOOR_ADDRESS        (u16)0x0000
#define LOCKMODE_ADDRESS    (u16)0x0001
#define BLOCK_ADDRESS       (u16)0x0002
#define PIN_ADDRESS         (u16)0x0003 // 3 --> 6
#define TRIES_LEFT_ADDRESS  (u16)0x00010


/************** STATUS CODES ***********/
#define DOOR_OPEN   (u8)1
#define DOOR_CLOSED (u8)0
#define CARD_MODE   (u8)1
#define PIN_MODE    (u8)0
#define BLOCKED     (u8)1
#define NOT_BLOCKED (u8)0
#define NOT_SET     (u8)0xFF

/************** HARDWARE ***********/
#define BUZZER_PORT     Port_C
#define RED_LED_PORT    Port_C
#define GREEN_LED_PORT  Port_C
#define MOTOR_PORT      Port_B
#define BUZZER_PIN      Pin5
#define RED_LED_PIN     Pin0
#define GREEN_LED_PIN   Pin1
#define MOTOR_PIN0      Pin0
#define MOTOR_PIN1      Pin1


#endif