#include "KEYPAD_interface.h"


/*	KEYPAD VALUES (MATRIX)	*/
static u8 Global_u8_Kpd_Arr[KEYPAD_ROW_NUM][KEYPAD_COL_NUM] = KEYPAD_ARR_VAL_MATRIXMODE;

/*	KEYPAD VALUES (DIRECT)	*/
static u8 Global_u8_Kpd_Arr_DirectMode[KEYPAD_ROW_NUM] = KEYPAD_ARR_VAL_DirectMode;

/*	KEYPAD COLUMNS	*/
static u8 Global_u8_Kpd_Col_Arr[KEYPAD_COL_NUM] = {KEYPAD_COL_1, KEYPAD_COL_2, KEYPAD_COL_3, KEYPAD_COL_4};

/*	KEYPAD ROWS	*/
static u8 Global_u8_Kpd_Row_Arr[KEYPAD_ROW_NUM] = {KEYPAD_ROW_1, KEYPAD_ROW_2, KEYPAD_ROW_3, KEYPAD_ROW_4};

typedef enum {DirectMode, MatrixMode} mode;
static mode CurrectMode;

void KEYPAD_VidInitMatrixMode(void){
	/* Initialize column and row bits in keypad as input pins */
	for (u8 Local_u8_Counter = 0; Local_u8_Counter < KEYPAD_COL_NUM; Local_u8_Counter++){
		// SET COL AS INPUT
		DIO_VidSetPinDirection(KEYPAD_COL_PORT, Global_u8_Kpd_Col_Arr[Local_u8_Counter], Input);
		// CONNECT COL TO PULL-UP RESISTANCE
		DIO_VidSetPinValue(KEYPAD_COL_PORT, Global_u8_Kpd_Col_Arr[Local_u8_Counter], PinHigh);

		// SET ROW AS INPUT
		DIO_VidSetPinDirection(KEYPAD_ROW_PORT, Global_u8_Kpd_Row_Arr[Local_u8_Counter], Input);
		// CONNECT ROW TO PULL-UP RESISTANCE
		DIO_VidSetPinValue(KEYPAD_ROW_PORT, Global_u8_Kpd_Row_Arr[Local_u8_Counter], PinHigh);
	}
	// Set currect mode to matrix mode
	CurrectMode = MatrixMode;
}

void KEYPAD_VidInitDirectMode(void){
	/* Initialize all columns bits in keypad as input pins */
	for (u8 Local_u8_Counter = 0; Local_u8_Counter < KEYPAD_COL_NUM; Local_u8_Counter++){
		// SET COL AS INPUT
		DIO_VidSetPinDirection(KEYPAD_COL_PORT, Global_u8_Kpd_Col_Arr[Local_u8_Counter], Input);
		// CONNECT COL TO PULL-UP RESISTANCE
		DIO_VidSetPinValue(KEYPAD_COL_PORT, Global_u8_Kpd_Col_Arr[Local_u8_Counter], PinHigh);
	}
	
	// Set currect mode to direct mode
	CurrectMode = DirectMode;
}

u8 KEYPAD_u8CheckPress(void){
	// KEY HOLDER
	u8 Local_u8_Btn = NOT_PRESSED;
	
	/*****************************************	Matrix mode	******************************************************/
	if (CurrectMode == MatrixMode){
		
		// LOOP ON ROWS
		for (u8 Local_u8_Row_Cntr = 0; Local_u8_Row_Cntr < KEYPAD_ROW_NUM; Local_u8_Row_Cntr++){
			// SET ROW AS OUTPUT
			DIO_VidSetPinDirection(KEYPAD_ROW_PORT, Global_u8_Kpd_Row_Arr[Local_u8_Row_Cntr], Output);
			// SET ROW VALUE AS LOW
			DIO_VidSetPinValue(KEYPAD_ROW_PORT, Global_u8_Kpd_Row_Arr[Local_u8_Row_Cntr], PinLow);
			
			// LOOP ON COLUMNS
			for (u8 Local_u8_Col_Cntr = 0; Local_u8_Col_Cntr < KEYPAD_COL_NUM; Local_u8_Col_Cntr++){
				// GET COLUMN VALUE
				DIO_VidGetPinValue(KEYPAD_COL_PORT, Global_u8_Kpd_Col_Arr[Local_u8_Col_Cntr], &Local_u8_Btn);
				
				// CHECK IF COLUMN IS LOW (key pressed)
				if (PinLow == Local_u8_Btn){
					// DEBOUNCING
					while (PinLow == Local_u8_Btn){
						// GET COLUMN VALUE
						DIO_VidGetPinValue(KEYPAD_COL_PORT, Global_u8_Kpd_Col_Arr[Local_u8_Col_Cntr], &Local_u8_Btn);
					}
					// SET ROW AS INPUT
					DIO_VidSetPinDirection(KEYPAD_ROW_PORT, Global_u8_Kpd_Row_Arr[Local_u8_Row_Cntr], Input);
					// RETURN KEYPAD VALUE
					Local_u8_Btn = Global_u8_Kpd_Arr[Local_u8_Row_Cntr][Local_u8_Col_Cntr];
					return Local_u8_Btn;
				}
			}
			
			// Revert ROW as INPUT and continue looping on rows if key is NOT pressed
			DIO_VidSetPinDirection(KEYPAD_ROW_PORT, Global_u8_Kpd_Row_Arr[Local_u8_Row_Cntr], Input);
		}
	}
	/*************************************************************************************************************/

	/*****************************************	Direct mode	******************************************************/
	else if (CurrectMode == DirectMode){ 
		// LOOP ON COLUMNS
		for (u8 Local_u8_Col_Cntr = 0; Local_u8_Col_Cntr < KEYPAD_COL_NUM; Local_u8_Col_Cntr++){
			// GET COLUMN VALUE
			DIO_VidGetPinValue(KEYPAD_COL_PORT, Global_u8_Kpd_Col_Arr[Local_u8_Col_Cntr], &Local_u8_Btn);
			
			// CHECK IF COLUMN IS LOW (key pressed)
			if (PinLow == Local_u8_Btn){
				// DEBOUNCING
				while (PinLow == Local_u8_Btn){
					// GET COLUMN VALUE
					DIO_VidGetPinValue(KEYPAD_COL_PORT, Global_u8_Kpd_Col_Arr[Local_u8_Col_Cntr], &Local_u8_Btn);
				}
				// RETURN KEYPAD VALUE
				Local_u8_Btn = Global_u8_Kpd_Arr_DirectMode[Local_u8_Col_Cntr];
				return Local_u8_Btn;
			}
		}
	}
	/*************************************************************************************************************/
	
	// if no key is pressed
	return NOT_PRESSED;
}

void WaitForKey(u8 *PtrKeyPressed){
    u8 Local_u8KeyPressed = NOT_PRESSED;
	
	// repeat until the user presses any key
    while (Local_u8KeyPressed == NOT_PRESSED){
		// if the user pressed any button in keypad save the value in Local_u8KeyPressed
        Local_u8KeyPressed = KEYPAD_u8CheckPress();
    }

    *PtrKeyPressed = Local_u8KeyPressed;
}