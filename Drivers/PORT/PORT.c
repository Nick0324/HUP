/* ========================================================================== */
/*                                                                            */
/*                                                                            */
/*  !!!!!!!!!!!!!! Replace ModuleName with the name of your module!!!!!!!!!!  */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*   PORT_.c                                                            */
/*   Autor(s): Ciucu Alexandru-Mihai, Lupu Nicolae, Popescu Andrei-Florin, Preda Stefan-Marian  */
/*   Description                                                              */
/*       File Containing the implementation of the module PORT          */
/* ========================================================================== */

#include "PORT.h"
#include "PORT_Private.h"
/* ========================================================================== */
/*                  PUT YOUR INCLUDES HERE                                    */
/* ========================================================================== */

#include "dr7f701587.dvf.h"

/* ========================================================================== */
/*                  PUT YOUR VARIABLE DECLARATIONS HERE                       */
/* ========================================================================== */

static boolean PORT_InitStatus = FALSE;
static struct pin pins[PORT_NO_PINS];

/* ========================================================================== */
/*                  PUT YOUR API IMPLEMENTATIONS HERE                         */
/* ========================================================================== */

void PORT_Init(void)
{
/* Put here the code */
uint8 i;
for(i = 0; i < PORT_NO_PINS; i++){

    pins[i].id = i;

    // setting the digital outputs
    if(i == 7 || i == 153 || i == 165 || i == 166){
        pins[i].direction = PORT_PIN_OUTPUT;
        pins[i].type = DIGITAL;
    }

    // setting the analog inputs
    else if(i == 106 || i == 105 || i == 104 || i == 103){
        pins[i].direction = PORT_PIN_INPUT;
        pins[i].type = ANALOG;
    }

    // setting the pwm outputs
    else if(i == 15 || i == 154 || i == 161 || i == 167 || i == 16 || i == 155 || i == 162 || i == 8 || i == 17 || i == 156 || i == 163 || i == 9){
        pins[i].direction = PORT_PIN_OUTPUT;
        pins[i].type = PWN;
    }  
    // setting all other pins as digital inputs
    else{
        pins[i].direction = PORT_PIN_INPUT;
        pins[i].type = DIGITAL;
    }   
}

//Initialize all pins as digital inputs
    PORTPM0   = 0xFFFF;
    PORTPMC0  = 0x0000;
    PORTPM1   = 0xFFFF;
    PORTPMC1  = 0x0000;
    PORTPM2   = 0xFFFF;
    PORTPMC2  = 0x0000;
    PORTPM8   = 0xFFFF;
    PORTPMC8  = 0x0000;
    PORTPM9   = 0xFFFF;
    PORTPMC9  = 0x0000;
    PORTPM10  = 0xFFFF;
    PORTPMC10 = 0x0000;
    PORTPM11  = 0xFFFF;
    PORTPMC11 = 0x0000;
    PORTPM12  = 0xFFFF;
    PORTPMC12 = 0x0000;
    PORTPM18  = 0xFFFF;
    PORTPMC18 = 0x0000;
    PORTPM20  = 0xFFFF;         
    PORTPMC20 = 0x0000;


    //Configuram Port 11 pin 0 ca Digital Outputs
    PORTPM11 &=~(1<<0); // face 0 pentru ca e output mode
    PORTPMC11 &=~ (1<<0); // face 0 pt ca e digital

    //Configuram Port 10 pin 7 ca Digital Outputs
    PORTPM10 &=~(1<<7); // face 0 pentru ca e output mode
    PORTPMC10 &=~ (1<<7); // face 0 pt ca e digital

    //Configuram Port 11 pin 5 ca Digital Outputs
    PORTPM11 &=~(1<<5); // face 0 pentru ca e output mode
    PORTPMC11 &=~ (1<<5); // face 0 pt ca e digital

    //Configuram Port 11 pin 6 ca Digital Outputs
    PORTPM11 &=~(1<<6); // face 0 pentru ca e output mode
    PORTPMC11 &=~ (1<<6); // face 0 pt ca e digital



    //Configuram Port 0 pin 0 ca Analog Inputs
    PORTAPM0 |= (1<<0); // face 1 pentru input mode
    PORTPMC0 &=~ (1<<0);
    //Configuram Port 0 pin 1 ca Analog Inputs
    PORTAPM0 |= (1<<1); // face 1 pentru input mode
    PORTPMC0 &=~ (1<<1);
    //Configuram Port 0 pin 2 ca Analog Inputs
    PORTAPM0 |= (1<<2); // face 1 pentru input mode
    PORTPMC0 &=~ (1<<2);
    //Configuram Port 0 pin 3 ca Analog Inputs
    PORTAPM0 |= (1<<3); // face 1 pentru input mode
    PORTPMC0 &=~ (1<<3);

    //Configuram Port 12 pin 3 ca PWM Output
    PORTPM12 &=~(1<<3); // face 0
    PORTPFCAE12 &=~(1<<3); // face 0
    PORTPFCE12 &=~(1<<3); // face 0
    PORTPFC12 |= (1<<3); // face 1


    //Configuram Port 10 pin 8 ca PWM Output
    PORTPIPC10  &=~(1<<8);
    PORTPM10 &=~(1<<8);
    PORTPFCAE10 &=~(1<<8);
    PORTPFCE10 |= 1<<8;
    PORTPFC10 &=~(1<<8);


    //Configuram Port 11 pin 1 ca PWM Output
    PORTPIPC11  &=~(1<<1);
    PORTPM11 &=~(1<<1);
    PORTPFCAE11 &=~(1<<1);
    PORTPFCE11 |= 1<<1;
    PORTPFC11 &=~(1<<1);


    //Configuram Port 11 pin 7 ca PWM Output
    PORTPIPC11 &=~(1<<7);
    PORTPM11 &=~(1<<7);
    PORTPFCAE11 &=~(1<<7);
    PORTPFCE11 &=~(1<<7);
    PORTPFC11 |= (1<<7);


    //Configuram Port 12 pin 4 ca PWM Output
    PORTPM12 &=~(1<<4);
    PORTPFCAE12 &=~(1<<4);
    PORTPFCE12 &=~(1<<4);
    PORTPFC12 |= (1<<4);


    //Configuram Port 10 pin 9 ca PWM Output
    PORTPIPC10  &=~(1<<9);
    PORTPM10 &=~(1<<9);
    PORTPFCAE10 &=~(1<<9);
    PORTPFCE10 |= 1<<9;
    PORTPFC10 &=~(1<<9);


    //Configuram Port 11 pin 2 ca PWM Output
    PORTPIPC11  &=~(1<<2);
    PORTPM11 &=~(1<<2);
    PORTPFCAE11 &=~(1<<2);
    PORTPFCE11 |= 1<<2;
    PORTPFC11 &=~(1<<2);


    //Configuram Port 11 pin 8 ca PWM Output *
    PORTPIPC11  &=~(1<<8);
    PORTPM11 &=~(1<<8);
    PORTPFCAE11 &=~(1<<8);
    PORTPFCE11 &= 1<<8;
    PORTPFC11 |=~(1<<8);


    //Configuram Port 12 pin 5 ca PWM Output
    PORTPM12 &=~(1<<5);
    PORTPFCAE12 &=~(1<<5);
    PORTPFCE12 &=~(1<<5);
    PORTPFC12 &=~(1<<5);


    //Configuram Port 10 pin 10 ca PWM Output
    PORTPIPC10  &=~(1<<10);
    PORTPM10 &=~(1<<10);
    PORTPFCAE10 &=~(1<<10);
    PORTPFCE10 |= 1<<10;
    PORTPFC10 &=~(1<<10);


    //Configuram Port 11 pin 3 ca PWM Output *
    PORTPIPC11  &=~(1<<3);
    PORTPM11 &=~(1<<3);
    PORTPFCAE11 &=~(1<<3);
    PORTPFCE11 &=~(1<<3);
    PORTPFC11 |= (1<<3);


    //Configuram Port 11 pin 9 ca PWM Output
    PORTPIPC11  &=~(1<<9);
    PORTPM11 &=~(1<<9);
    PORTPFCAE11 &=~(1<<9);
    PORTPFCE11 &=~(1<<9);
    PORTPFC11 |= (1<<9);



PORT_InitStatus = TRUE;
return;
}

Std_ReturnType PORT_GetPinMode(PORT_PinType PinId, PORT_PinModeType *mode, PORT_PinDirectionType *direction)
{
    Std_ReturnType status = E_OK;

    if(PinId < 0 || PinId > PORT_NO_PINS - 1){
        Det_Report();
        status = E_NOT_OK;
    }

    if(mode == NULL_PTR || direction == NULL_PTR){
        Det_Report();
        status = E_NOT_OK;
    }

    if(PORT_InitStatus == FALSE){
        Det_Report();
        status = E_NOT_OK;
    }
    

    *mode = pins[PinId].type;
    *direction = pins[PinId].direction;


    return status;
}
