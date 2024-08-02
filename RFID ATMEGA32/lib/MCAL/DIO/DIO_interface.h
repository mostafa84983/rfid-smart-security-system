#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "../../../include/std_types.h"

typedef enum{
	Port_A,
	Port_B,
	Port_C,
	Port_D
} et_Port;

typedef enum{
	Pin0,
	Pin1,
	Pin2,
	Pin3,
	Pin4,
	Pin5,
	Pin6,
	Pin7
} et_Pin;

typedef enum{
	Input,
	Output
} et_Direction;

typedef enum{
	PinLow,
	PinHigh
} et_Status;


// ******************************	Pins	*****************************************

// Setting pin direction
void DIO_VidSetPinDirection(et_Port port, et_Pin pin, et_Direction direction);

// Setting pin value
void DIO_VidSetPinValue(et_Port port, et_Pin pin, et_Status value);

// Toggling pin value
void DIO_VidTogglePinValue(et_Port port, et_Pin pin);

// getting pin value
void DIO_VidGetPinValue(et_Port port, et_Pin pin, u8 *Ptr_u8Data);

// ******************************	Ports	*****************************************

// Setting port direction
void DIO_VidSetPortDirection(et_Port port, et_Direction direction);

// Setting port value
void DIO_VidSetPortValue(et_Port port, u8 value);

// getting port value
void DIO_VidGetPortValue(et_Port port, u8 *Ptr_u8Data);

// ******************************	Nibbles	*****************************************

// Setting low(right) nibble value
void DIO_VidSetLowNibbleValue(et_Port port, u8 data, u8 startIndex);

#endif
