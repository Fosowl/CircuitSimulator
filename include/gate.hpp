/*
** EPITECH PROJECT, 2020
** project file
** File description:
** logic gate macro
*/

#ifndef GATE_H
#define GATE_H

#define AND_GATE(I1, I2) I1 == TRUE && I2 == TRUE
#define OR_GATE(I1, I2) I1 == TRUE || I2 == TRUE
#define NOT_GATE(I1) I1 == TRUE ? FALSE : TRUE
#define NAND_GATE(I1, I2) !(I1 == TRUE && I2 == TRUE)
#define NOR_GATE(I1, I2) I1 == FALSE && I2 == FALSE
#define XOR_GATE(I1, I2) (I1 == FALSE && I2 == FALSE) || (I1 == TRUE && I2 == TRUE)
#define TRIPLE_NAND_GATE(I1, I2, I3) !(I1 == TRUE && I2 == TRUE && I3 == TRUE)

#endif /* GATE_H */
