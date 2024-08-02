#ifndef BITMANIP_H
#define BITMANIP_H

// Set a bit in a register
#define SET_BIT(reg, bit) (reg |= (1 << bit))

// Clear a bit in a register
#define CLR_BIT(reg, bit) (reg &= ~(1 << bit))

// Toggle a bit in a register
#define TGL_BIT(reg, bit) (reg ^= (1 << bit))

// Read a bit in a register
#define GET_BIT(reg, bit) (1 & (reg >> bit))

#endif /* BITMANIP_H */
