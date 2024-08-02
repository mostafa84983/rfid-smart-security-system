#include "SEV_SEG_interface.h"

#include <util/delay.h>

static u8 Global_SEV_SEG_ARR[10] = {
    SEG_NUM_ZERO,
    SEG_NUM_ONE,
    SEG_NUM_TWO,
    SEG_NUM_THREE,
    SEG_NUM_FOUR,
    SEG_NUM_FIVE,
    SEG_NUM_SIX,
    SEG_NUM_SEVEN,
    SEG_NUM_EIGHT,
    SEG_NUM_NINE
};

void SEV_SEG_VidInit(){
    DIO_VidSetPortDirection(SEGMENT_PORT, Output);
    DIO_VidSetPinDirection(COMM_DDR, COMM_ONES, Output);
    DIO_VidSetPinDirection(COMM_DDR, COMM_TENS, Output);
}

void SEV_SEG_VidDisplayNumber(u8 Local_u8Number, et_Status SEG_Activator){
    u8 Local_u8Ones = Local_u8Number % 10;
    u8 Local_u8Tens = Local_u8Number / 10;

    // DISABLE TENS & ACTIVATE ONES
    DIO_VidSetPinValue(COMM_PORT, COMM_TENS, !SEG_Activator);
    DIO_VidSetPinValue(COMM_PORT, COMM_ONES, SEG_Activator);
    // DISPLAY ONES
    DIO_VidSetPortValue(SEGMENT_PORT, Global_SEV_SEG_ARR[Local_u8Ones]);
    SEG_DELAY;

    // DISABLE ONES & ACTIVATE TENS
    DIO_VidSetPinValue(COMM_PORT, COMM_ONES, !SEG_Activator);
    DIO_VidSetPinValue(COMM_PORT, COMM_TENS, SEG_Activator);
    // DISPLAY TENS
    DIO_VidSetPortValue(SEGMENT_PORT, Global_SEV_SEG_ARR[Local_u8Tens]);
    SEG_DELAY;
}

void SEV_SEG_VidDisplayOnes(u8 Local_u8Ones){
    // DISABLE TENS & ACTIVATE ONES
    DIO_VidSetPinValue(COMM_PORT, COMM_TENS, PinHigh);
    DIO_VidSetPinValue(COMM_PORT, COMM_ONES, PinLow);
    // DISPLAY ONES
    DIO_VidSetPortValue(SEGMENT_PORT, Global_SEV_SEG_ARR[Local_u8Ones]);
}

void SEV_SEG_VidDisplayTens(u8 Local_u8Tens){
    // DISABLE ONES & ACTIVATE TENS
    DIO_VidSetPinValue(COMM_PORT, COMM_ONES, PinHigh);
    DIO_VidSetPinValue(COMM_PORT, COMM_TENS, PinLow);
    // DISPLAY TENS
    DIO_VidSetPortValue(SEGMENT_PORT, Global_SEV_SEG_ARR[Local_u8Tens]);
}

void SEV_SEG_VidSpinner(){
    u8 Local_u8Spinner = 0b00000010;
    while (Local_u8Spinner < 0b10000000){
        DIO_VidSetPortValue(SEGMENT_PORT, Local_u8Spinner);
        SEG_DELAY;
        SEG_DELAY;
        Local_u8Spinner *= 2;
    }
}