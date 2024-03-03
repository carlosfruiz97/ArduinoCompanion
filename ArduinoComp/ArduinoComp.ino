/**
 * @file arcade_taquilla
 * @details Juego arcade con dos b
 */

/* -- Libraries --------------------------------------------------------------*/
#include <Bounce2.h>
#include "types.h"


/* -- Setup Btns -------------------------------------------------------------*/
Bounce * buttons = new Bounce[NB_PINS];
char str_buffer[100];

/* -- Setup ------------------------------------------------------------------*/
/**
   @brief Setup Game
*/
void setup()
{
    Serial.begin(BAUD_RATE);

    for (uint8_t i=0; i<NB_PINS; i++)
    {
        init_button(i);
    }
}

/* -- Loop -------------------------------------------------------------------*/
/**
   @brief loop
*/
void loop()
{
    for (uint8_t i=0; i<NB_PINS; i++)
    {
        buttons[i].update();
        if (buttons[i].changed())
        {
            sprintf(str_buffer, CMD_STR, ENABLED_PINS[i], buttons[i].read());
            Serial.print(str_buffer);
        }
    }
}

/* -- Button inerfaces -------------------------------------------------------*/
void init_button(uint16_t index)
{
    if (index >= NB_PINS)
        return;
    uint8_t pin = ENABLED_PINS[index];
    buttons[index].attach(pin, INPUT_PULLUP);
    buttons[index].interval(BUTTON_INTERVAL);    
}