/* ========================================================================== */
/*                                                                            */
/*                                                                            */
/*  !!!!!!!!!!!!!! Replace DOUTH with the name of your module!!!!!!!!!!  */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*   DOUTH_.h                                                            */
/*   Autor(s): Ciucu Alexandru-Mihai, Lupu Nicolae, Popescu Andrei-Florin, Preda Stefan-Marian                                                    */
/*   Description                                                              */
/*       File Containing the Public Data for the module DOUTH            */
/* ========================================================================== */

#ifndef DOUTH_H
#define DOUTH_H
/* ========================================================================== */
/*                  PUT YOUR CODE HERE                                        */
/* ========================================================================== */
#include "Std_Types.h"
#include "DOUTH_Types.h" 

extern void DOUTH_Init(void); /* Make here the appropiate changes */

extern void DoutH_Cyclic();

extern Std_ReturnType DoutH_SetChannelValue(DoutH_ChannelIdType ChannelId, DoutH_ValueType Value);

#endif
