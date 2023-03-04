/* ========================================================================== */
/*                                                                            */
/*                                                                            */
/*  !!!!!!!!!!!!!! Replace ModuleName with the name of your module!!!!!!!!!!  */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*   ModuleName_.h                                                            */
/*   Autor(s): YourName(s)                                                    */
/*   Description                                                              */
/*       File Containing the Public Data for the module ModuleName            */
/* ========================================================================== */

#ifndef DIO_H
#define DIO_H
/* ========================================================================== */
/*                  PUT YOUR CODE HERE                                        */
/* ========================================================================== */
#include "Std_Types.h"
#include "Dio_Types.h" 
#include "dr7f701587.dvf.h"
#include "DOUTH.h"



#define	DIO_IN_CAR_UNLK 0
#define	DIO_IN_CAR_LCK 1
#define	DIO_IN_HAZARD_REQ 2
#define	DIO_IN_LGT_SENSOR 3
#define	DIO_IN_HB_REQ 4
#define	DIO_IN_REVERSE_REQ 5
#define	DIO_IN_FOG_REQ 6
#define	DIO_IN_CRASH 7
#define	DIO_OUT_HB_LEFT 8
#define	DIO_OUT_HB_RIGHT 9
#define	DIO_OUT_FOG 10
#define	DIO_OUT_REVERSE 11

#define	DIO_LOW 0
#define	DIO_HIGH 1


extern void DIO_Init(void); /* Make here the appropiate changes */

extern Std_ReturnType DIO_PinRead (DIO_PinIdType PinId, DIO_PinValueType *Value);

extern Std_ReturnType DIO_PinWrite(DIO_PinIdType PinId, DoutH_ValueType Value);

#endif
