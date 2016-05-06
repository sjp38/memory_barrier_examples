
#ifndef __BARRIER_H__
#define __BARRIER_H__

#define ACCESS_ONCE(x) (*(volatile typeof(x) *)&(x))
#define barrier()	__asm__ __volatile__("": : :"memory")

#if defined(__x86_64__)

#define smp_rmb()	__asm__ __volatile__("lfence" ::: "memory")
#define smp_wmb()	__asm__ __volatile__("sfence" ::: "memory")
#define smp_mb()	__asm__ __volatile__("mfence" ::: "memory")

#else

#define smp_rmb()	__sync_synchronize()
#define smp_wmb()	__sync_synchronize()
#define smp_mb()	__sync_synchronize()

#endif

#endif
