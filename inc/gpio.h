/************************************************************************************************
Copyright 2024, Ingenieria de Software
Facultad de Ingenieria
Universidad Nacional de Buenos Aires

Copyright (c) 2023, Martin Paura Bersan <mpb39212@gmail.comr>

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

#ifndef GPIO_H
#define GPIO_H

/** @file gpio.h
 ** @brief Definición de la funciónes para manejo de pin mediante objeto
 **/

/* === Headers files inclusions ================================================================ */
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

/* === Public data type declarations =========================================================== */
typedef struct gpio_s * gpio_t;

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */
/// @brief Funcion que crea el objeto para controlar el pin de interes
/// @param puerto data register donde se encuentra el pin a controlar
/// @param bit  numero de bit que se desea controlar
/// @return el handle para manipular el pin a controlar
gpio_t gpioCreate(uint8_t puerto, uint8_t bit);

/// @brief Funcion que se encarga de configurar la direccion de trabajo del pin
/// @param gpio objeto que contiene la inforamción del pin que se desea manipular
/// @param output Direccion de la informacion que manejará el pin (true para output, false para
/// input)
void gpioSetOutput(gpio_t gpio, bool output);

/// @brief Funcion utilizada para manipular el estado del pin
/// @param gpio Objeto que maneja el pin
/// @param state Valor al cual se requiere que se ponga el pin (true = High, false = Low)
void gpioSetState(gpio_t gpio, bool state);

/// @brief Funcion para preguntar el estado del pin
/// @param gpio Objeto que contiene la información del pin de interes
/// @return devuelve el estado del pin (true= high, false = low)
bool gpioGetState(gpio_t gpio);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* GPIO_H */
