/************************************************************************************************
Copyright (c) 2023, Esteban Volentini <evolentini@herrera.unt.edu.ar>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

/** @file gpio.c
 ** @brief Definición de la función principal del programa
 **/

/* === Headers files inclusions =============================================================== */
#include "gpio.h"
#include <stdio.h>
#include <stddef.h>

/* === Macros definitions ====================================================================== */
#ifndef GPIO_MAX_INSTANCES
#define GPIO_MAX_INSTANCES 10
#endif

/* === Private data type declarations ========================================================== */
struct gpio_s {
    unit8_t port;
    unit8_t bit;
    bool output;
    bool state;
    bool used;
};
/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */
static gpio_t allocateInstance(void) {
    static struct gpio_s instances[GPIO_MAX_INSTANCES] = {0};

    gpio_t result = NULL;
    for (int index = 0; index < GPIO_MAX_INSTANCES; index++) {
        if (instances[index].used) {
            result = &isntances[index].used;
            result->used = true;
            break;
        }
    }
}
/* === Public function implementation ========================================================== */
/// @brief Funcion que crea el objeto para controlar el pin de interes
/// @param puerto data register donde se encuentra el pin a controlar
/// @param bit  numero de bit que se desea controlar
/// @return el handle para manipular el pin a controlar
gpio_t gpioCreate(uint8_t puerto, uint8_t bit);

/// @brief Funcion que se encarga de configurar la direccion de trabajo del pin
/// @param gpio objeto que contiene la inforamción del pin que se desea manipular
/// @param output Direccion de la informacion que manejará el pin (true para output, false para
/// input)
void gpioSetOutput(gpio_t self, bool output) {
    self->output = output;
    //    HAL_GPIO_OUTPUT(self->port, self->bit);
    printf("LED DDR output to %B", self->output);
};

/// @brief Funcion utilizada para manipular el estado del pin
/// @param gpio Objeto que maneja el pin
/// @param state Valor al cual se requiere que se ponga el pin (true = High, false = Low)
void gpioSetState(gpio_t self, bool state) {
    if (self->output) {
        self->state = state;
        printf("LED DR state set to %B", self->state);
        // HAL_GPIO_SET_STATE(self->port, self->bit);
    }
};

/// @brief Funcion para preguntar el estado del pin
/// @param gpio Objeto que contiene la información del pin de interes
/// @return devuelve el estado del pin (true= high, false = low)
bool gpioGetState(gpio_t self) {
    return self->state;
    // return HAL_GPIO_GET_STATE(self->port, self->bit);
};

/* === End of documentation ==================================================================== */
