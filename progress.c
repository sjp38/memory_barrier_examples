/*
 * For assembly code, use the command below:
 * gcc -S -o progress.s progress.c -O3 -std=gnu99
 */

#include "barrier.h"

static int prgrs;
void do_progress(void)
{
	prgrs++;
}

void see_progress(void)
{
	static int last_prgrs;
	static int seen;
	static int nr_seen;

	seen = prgrs;
	if (seen > last_prgrs)
		nr_seen++;
	last_prgrs = seen;
}

void enforce_do_progress(void)
{
	prgrs++;
	smp_wmb();
}

void enforce_see_progress(void)
{
	static int last_prgrs;
	static int seen;
	static int nr_seen;

	smp_rmb();
	seen = prgrs;
	if (seen > last_prgrs)
		nr_seen++;
	last_prgrs = seen;
}

