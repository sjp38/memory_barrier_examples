/*
 * For assmebly code, use the command below:
 * gcc -S -o loop.s loop.c -O3 -std=gnu99
 */

#include "barrier.h"

static int the_var;

void fastest_loop(void)
{
	int i;
	for (i = 0; i < 1000; i++)
		the_var++;
}

void loop_but_nostore(void)
{
	int i;
	for (i = 0; ACCESS_ONCE(i) < 1000; i++)
		the_var++;
}

static volatile int volatile_var;
void loop_excessive_load(void)
{
	int i;
	for (i = 0; i < 1000; i++)
		volatile_var++;
}

void loop_reasonable(void)
{
	int i;
	for (i = 0; i < 1000; i++) {
		the_var++;
		barrier();
	}
}
