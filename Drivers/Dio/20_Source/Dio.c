/* ========================================================================== */
/*                                                                            */
/*                                                                            */
/*  !!!!!!!!!!!!!! Replace ModuleName with the name of your module!!!!!!!!!!  */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*   ModuleName_.c                                                            */
/*   Autor(s): YourName(s)                                                    */
/*   Description                                                              */
/*       File Containing the implementation of the module ModuleName          */
/* ========================================================================== */

#include "Dio.h"
#include "Dio_Private.h"
#include "Dio_Types.h"
#include "Std_Types.h"
#include "DET.h"

/* ========================================================================== */
/*                  PUT YOUR INCLUDES HERE                                    */
/* ========================================================================== */


/* ========================================================================== */
/*                  PUT YOUR VARIABLE DECLARATIONS HERE                       */
/* ========================================================================== */

static boolean DIO_InitStatus = FALSE;
//uint8 P11, P10, PORTPPR9, PPR20;

/* ========================================================================== */
/*                  PUT YOUR API IMPLEMENTATIONS HERE                         */
/* ========================================================================== */

void Dio_Init(void)
{
	/* Put here the code */

	DIO_InitStatus = TRUE;
	return;
}
uint8 test_value;
uint8 test_id;

Std_ReturnType DIO_PinWrite(DIO_PinIdType PinId, DIO_PinValueType Value)
{
	test_value = Value;
	test_id = PinId;
	if ((PinId <8 || PinId > 11) || (Value > DIO_HIGH))
	{
		Det_Report();
	}
	else
	{
		switch (PinId)
		{
		case DIO_OUT_HB_LEFT:
			if (Value == 1)
			{
				PORTP11 = PORTP11 | (1 << 0);
			}
			else
			{
				PORTP11 = PORTP11 & (~(1 << 0));
			}
		break;
		
		case DIO_OUT_HB_RIGHT:
			if (Value == 1)
			{
				PORTP10 = PORTP10 | (1 << 7);
			}
			else
			{
				PORTP11 = PORTP11 & (~(1 << 7));
			}
		break;
		
		case DIO_OUT_FOG:
			if (Value == 1)
			{
				PORTP11 = PORTP11 | (1 << 5);
			}
			else
			{
				PORTP11 = PORTP11 & (~(1 << 5));
			}
		break;
		
		case DIO_OUT_REVERSE:
			if (Value == 1)
			{
				PORTP11 = PORTP11 | (1 << 6);
			}
			else
			{
				PORTP11 = PORTP11 & (~(1 << 6));
			}
		break;
		}
	}
	return E_OK;
}

uint8 Pin_id;

Std_ReturnType DIO_PinRead(DIO_PinIdType PinId, DIO_PinValueType *Value)
{ 
	

	if (PinId > 7 || Value == NULL_PTR)
	{
		Det_Report();
	}
	
	
	switch (PinId)
	{
		case DIO_IN_CAR_UNLK:
			*Value = (PORTPPR9 & (1 << 0)) >> 0;
		break;
		
		case DIO_IN_CAR_LCK:
			*Value = (PORTPPR9 & (1 << 1)) >> 1;
		break;
		
		case DIO_IN_HAZARD_REQ:
			*Value = (PORTPPR9 & (1 << 2)) >> 2;
		break;
		
		case DIO_IN_LGT_SENSOR:
			*Value = (PORTPPR9 & (1 << 3)) >> 3;
		break;
		
		case DIO_IN_HB_REQ:
			*Value = (PORTPPR9 & (1 << 4)) >> 4;
		break;
		
		case DIO_IN_REVERSE_REQ:
			*Value = (PORTPPR9 & (1 << 5)) >> 5;
		break;
		
		case DIO_IN_FOG_REQ:
			*Value = (PORTPPR9 & (1 << 6)) >> 6;
		break;
		
		case DIO_IN_CRASH:
			*Value = (PORTPPR20 & (1 << 0)) >> 0;
		break;
	}
	return E_OK;
}
