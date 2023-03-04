/* ========================================================================== */
/*                                                                            */
/*                                                                            */
/*  !!!!!!!!!!!!!! Replace DOUTH with the name of your module!!!!!!!!!!  */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*   DOUTH_.c                                                            */
/*   Autor(s): Ciucu Alexandru-Mihai, Lupu Nicolae, Popescu Andrei-Florin, Preda Stefan-Marian                                                    */
/*   Description                                                              */
/*       File Containing the implementation of the module DOUTH          */
/* ========================================================================== */

#include "DOUTH.h"
#include "DOUTH_Private.h"
/* ========================================================================== */
/*                  PUT YOUR INCLUDES HERE                                    */
/* ========================================================================== */
#include "Dio.h"
/* ========================================================================== */
/*                  PUT YOUR VARIABLE DECLARATIONS HERE                       */
/* ========================================================================== */

static boolean DOUTH_InitStatus = FALSE;

static DoutH_BufferType buffer;

static uint8 output_pins[DO_NO_PINS] = {8, 9, 10, 11}; // digital output

/* ========================================================================== */
/*                  PUT YOUR API IMPLEMENTATIONS HERE                         */
/* ========================================================================== */

void DOUTH_Init(void)
{
    uint8 i;	
    for (i = 0; i < DOUTH_NO_CHANNELS; i++)
    {
        buffer[i] = DOUTH_LOW;
    }

    DOUTH_InitStatus = TRUE;
    return;
}

void DoutH_Cyclic()
{
    uint8 i;
    if (DOUTH_InitStatus == FALSE)
    {
        Det_Report();
    }
    else
    {	
        for (i = 0; i < DOUTH_NO_CHANNELS; i++)
        {
            DIO_PinWrite(output_pins[i], buffer[i]);
        }
    }
}

Std_ReturnType DoutH_SetChannelValue(DoutH_ChannelIdType ChannelId, DoutH_ValueType Value){
    Std_ReturnType status = E_NOT_OK;

    if(ChannelId < output_pins[0] || ChannelId > output_pins[DOUTH_NO_CHANNELS - 1]){
        Det_Report();
        status = E_NOT_OK;
    }
     if(Value < DOUTH_LOW || Value > DOUTH_HIGH){
        Det_Report();
        status = E_NOT_OK;
    }
    else if(DOUTH_InitStatus == FALSE){
        Det_Report();
        status = E_NOT_OK;
    }
    else{
	switch(ChannelId){
	    case DIO_OUT_HB_LEFT:
	        buffer[0] = Value;
		break;
	    case DIO_OUT_HB_RIGHT:
	        buffer[1] = Value;
		break;
	    case DIO_OUT_FOG:
	        buffer[2] = Value;
		break;
	    case DIO_OUT_REVERSE:
	        buffer[3] = Value;
		break;   
	    default:
		break;
	}
        status = E_OK;
    }
    
    return status;
}