#include "DIO_interface.h"
#include "DIO_private.h"

#include "../../../include/bitmanip.h"

// Get the address of the desired port register
static volatile u8* DIO_u8GetDirectionRegisterAddress(et_Port reg){
	// Select the appropriate port register based on the desired port
    switch (reg){
        case Port_A: return &DDRA;
        case Port_B: return &DDRB;
        case Port_C: return &DDRC;
        case Port_D: return &DDRD;
        default: return NULL;
    }
}

// Get the address of the desired port register
static volatile u8* DIO_u8GetOutputRegisterAddress(et_Port reg){
	// Select the appropriate port register based on the desired port
    switch (reg){
        case Port_A: return &PORTA;
        case Port_B: return &PORTB;
        case Port_C: return &PORTC;
        case Port_D: return &PORTD;
        default: return NULL;
    }
}

// Get the address of the desired pin register
static volatile u8* DIO_u8GetInputRegisterAddress(et_Port reg){
	// Select the appropriate port register based on the desired port
    switch (reg){
        case Port_A: return &PINA;
        case Port_B: return &PINB;
        case Port_C: return &PINC;
        case Port_D: return &PIND;
        default: return NULL;
    }
}

// Setting pin direction
void DIO_VidSetPinDirection(et_Port port, et_Pin pin, et_Direction direction){
    // Select the appropriate port register based on the selected port
    volatile u8 *Local_u8Port = DIO_u8GetDirectionRegisterAddress(port);

	if (direction == Input){
		CLR_BIT(*Local_u8Port, pin);
	}

    else if (direction == Output){
		SET_BIT(*Local_u8Port, pin);
    }
}

// Setting pin value
void DIO_VidSetPinValue(et_Port port, et_Pin pin, et_Status value){
	// Select the appropriate port register based on the selected port
    volatile u8 *Local_u8Port = DIO_u8GetOutputRegisterAddress(port);

	if (value == PinLow){
		CLR_BIT(*Local_u8Port, pin);
	}

	else if (value == PinHigh){
		SET_BIT(*Local_u8Port, pin);
    }
}

// Toggling pin value
void DIO_VidTogglePinValue(et_Port port, et_Pin pin){
	// Select the appropriate port register based on the selected port
    volatile u8 *Local_u8Port = DIO_u8GetOutputRegisterAddress(port);

	TGL_BIT(*Local_u8Port, pin);
}

// getting pin value
void DIO_VidGetPinValue(et_Port port, et_Pin pin, u8 *Ptr_u8Data){
	// Select the appropriate pin register based on the selected port
    volatile u8 *Local_u8Pin = DIO_u8GetInputRegisterAddress(port);

	*Ptr_u8Data = GET_BIT(*Local_u8Pin, pin);
}

// Setting port direction
void DIO_VidSetPortDirection(et_Port port, et_Direction direction){
	volatile u8 *Local_u8Port = DIO_u8GetDirectionRegisterAddress(port);

	if (direction == Input){
		*Local_u8Port = 0x00;
	}

	else if (direction == Output){
		*Local_u8Port = 0xFF;
    }
}

// Setting port value
void DIO_VidSetPortValue(et_Port port, u8 value){
	// Select the appropriate port register based on the selected port
    volatile u8 *Local_u8Port = DIO_u8GetOutputRegisterAddress(port);

	*Local_u8Port = value;
}

// getting port value
void DIO_VidGetPortValue(et_Port port, u8 *Ptr_u8Data){
	// Select the appropriate port register based on the selected port
    volatile u8 *Local_u8Port = DIO_u8GetInputRegisterAddress(port);
	
	*Ptr_u8Data = *Local_u8Port;
}

// Setting low(right) nibble value
void DIO_VidSetLowNibbleValue(et_Port port, u8 data, u8 startIndex){
	// Extract the lower nibble from the data
    u8 Local_u8Nibble = data & 0x0F;

    // Calculate the mask to isolate the lower nibble at the specified index
    u8 Local_u8Mask = 0x0F << startIndex;

	// Select the appropriate port register based on the selected port
    volatile u8 *Local_u8Port = DIO_u8GetOutputRegisterAddress(port);

    // Clear the bits at the specified index
    *Local_u8Port &= ~Local_u8Mask;

    // Write the lower nibble to the port at the specified index
    *Local_u8Port |= Local_u8Nibble << startIndex;
}