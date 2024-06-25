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

/** @file main.c
 ** @brief Definición de la función principal del programa
 **/

/* === Headers files inclusions =============================================================== */

#include "main.h"
#include "gpio.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#

/* === Macros definitions ====================================================================== */
#define PUERTO_A         1
#define LED_ROJO_PUERTO  PUERTO_A
#define LED_VERDE_PUERTO PUERTO_A
#define LED_AZUL_PUERTO  PUERTO_A
#define LED_ROJO_BIT     7
#define LED_VERDE_BIT    6
#define LED_AZUL_BIT     5

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */

int main(void) {
    printf("Inicia el programa\n");
    // Inicializo el led Rojo
    gpio_t ledRed = gpioCreate(LED_ROJO_PUERTO, LED_ROJO_BIT);

    if (ledRed == NULL) {
        perror("no hay lugar para led ROJO\n");
        exit(1);
    }

    gpioSetOutput(ledRed, true);
    gpioSetState(ledRed, true);

    // Inicializo el led Azul
    gpio_t ledBlue = gpioCreate(LED_AZUL_PUERTO, LED_AZUL_BIT);

    if (ledBlue == NULL) {
        perror("no hay lugar para led AZUL\n");
        exit(1);
    }

    gpioSetOutput(ledBlue, true);
    gpioSetState(ledBlue, true);

    // Inicializo el Led Verde

    gpio_t ledGreen = gpioCreate(LED_VERDE_PUERTO, LED_VERDE_BIT);

    if (ledGreen == NULL) {
        perror("no hay lugar para led VERDE\n");
        exit(1);
    }

    gpioSetOutput(ledGreen, true);
    gpioSetState(ledGreen, true);

    printf("Inicia el ciclo\n");

    while (1) {
        if (gpioGetState(ledRed))
            gpioSetState(ledRed, false);
        else
            gpioSetState(ledRed, true);

        sleep(2);
        printf("Terminó Loop\n");
    }
    return 0;
}

/* === End of documentation ==================================================================== */
