/* $NetBSD: machdep.h,v 1.7 2002/02/21 02:52:21 thorpej Exp $ */
/* $FreeBSD$ */

#ifndef _MACHDEP_BOOT_MACHDEP_H_
#define _MACHDEP_BOOT_MACHDEP_H_

/* Structs that need to be initialised by initarm */
#ifdef ARM_NEW_PMAP
extern vm_offset_t irqstack;
extern vm_offset_t undstack;
extern vm_offset_t abtstack;
#else
struct pv_addr;
extern struct pv_addr irqstack;
extern struct pv_addr undstack;
extern struct pv_addr abtstack;
#endif

/* Define various stack sizes in pages */
#define IRQ_STACK_SIZE	1
#define ABT_STACK_SIZE	1
#define UND_STACK_SIZE	1

/* misc prototypes used by the many arm machdeps */
struct trapframe;
void arm_lock_cache_line(vm_offset_t);
void init_proc0(vm_offset_t kstack);
void halt(void);
void abort_handler(struct trapframe *, int );
void set_stackptrs(int cpu);
void undefinedinstruction_bounce(struct trapframe *);

/* Early boot related helper functions */
struct arm_boot_params;
vm_offset_t default_parse_boot_param(struct arm_boot_params *abp);
vm_offset_t freebsd_parse_boot_param(struct arm_boot_params *abp);
vm_offset_t linux_parse_boot_param(struct arm_boot_params *abp);
vm_offset_t fake_preload_metadata(struct arm_boot_params *abp);
vm_offset_t parse_boot_param(struct arm_boot_params *abp);
void arm_generic_initclocks(void);

/* Board-specific attributes */
void board_set_serial(uint64_t);
void board_set_revision(uint32_t);

#endif /* !_MACHINE_MACHDEP_H_ */
