/**
\file   blinky.c
\brief  A minimal Contiki application showing how Contiki programs look.
\author  Gene Kozin

Copyright (c) 2011, Gene Kozin.
All rights reserved.
**/
#include <contiki.h>
#include <dev/leds.h>
#include <stdio.h>

/* Declare tasks */
PROCESS(blinky_task, "Blinky task");
AUTOSTART_PROCESSES(&blinky_task);

/**
\brief  Blinky Task.
**/
PROCESS_THREAD(blinky_task, ev, data)
{
    /* only static data is allowed within the thread body */
    static struct etimer led_timer;
    static unsigned count;

    PROCESS_BEGIN();

    /* print a "hello" message */
    printf("Blinky demo.\n\r");

    for (;;) {
        printf("Blinky task running. Loop count: %u\n\r", count++);

        /* toggle LEDs */
        leds_toggle(LEDS_GREEN);

        /* sleep for 1 second */
        etimer_set(&led_timer, CLOCK_SECOND);
        PROCESS_WAIT_UNTIL(etimer_expired(&led_timer));
    }

    PROCESS_END();
}
