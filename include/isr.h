#ifndef ISR_H
#define ISR_H

#ifdef fix_asm_fns
#define ISR_HANDLER _isr_handler
#define IRQ_HANDLER _irq_handler
#else
#define ISR_HANDLER isr_handler
#define IRQ_HANDLER irq_handler
#endif

#include "common.h"

/* ISRs reserved for CPU exceptions */
APIDEC void isr0();
APIDEC void isr1();
APIDEC void isr2();
APIDEC void isr3();
APIDEC void isr4();
APIDEC void isr5();
APIDEC void isr6();
APIDEC void isr7();
APIDEC void isr8();
APIDEC void isr9();
APIDEC void isr10();
APIDEC void isr11();
APIDEC void isr12();
APIDEC void isr13();
APIDEC void isr14();
APIDEC void isr15();
APIDEC void isr16();
APIDEC void isr17();
APIDEC void isr18();
APIDEC void isr19();
APIDEC void isr20();
APIDEC void isr21();
APIDEC void isr22();
APIDEC void isr23();
APIDEC void isr24();
APIDEC void isr25();
APIDEC void isr26();
APIDEC void isr27();
APIDEC void isr28();
APIDEC void isr29();
APIDEC void isr30();
APIDEC void isr31();
/* IRQ definitions */
APIDEC void irq0();
APIDEC void irq1();
APIDEC void irq2();
APIDEC void irq3();
APIDEC void irq4();
APIDEC void irq5();
APIDEC void irq6();
APIDEC void irq7();
APIDEC void irq8();
APIDEC void irq9();
APIDEC void irq10();
APIDEC void irq11();
APIDEC void irq12();
APIDEC void irq13();
APIDEC void irq14();
APIDEC void irq15();

#define IRQ0 32
#define IRQ1 33
#define IRQ2 34
#define IRQ3 35
#define IRQ4 36
#define IRQ5 37
#define IRQ6 38
#define IRQ7 39
#define IRQ8 40
#define IRQ9 41
#define IRQ10 42
#define IRQ11 43
#define IRQ12 44
#define IRQ13 45
#define IRQ14 46
#define IRQ15 47

/* Struct which aggregates many registers.
 * It matches exactly the pushes on interrupt.asm. From the bottom:
 * - Pushed by the processor automatically
 * - `push byte`s on the isr-specific code: error code, then int number
 * - All the registers by pusha
 * - `push eax` whose lower 16-bits contain DS
 */
typedef struct {
   uint32_t ds; /* Data segment selector */
   uint32_t edi, esi, ebp, useless, ebx, edx, ecx, eax; /* Pushed by pusha. */
   uint32_t int_no, err_code; /* Interrupt number and error code (if applicable) */
   uint32_t eip, cs, eflags, esp, ss; /* Pushed by the processor automatically */
} registers_t;

void isr_install();
void irq_install();

typedef void (*isr_t)(registers_t*);
void register_interrupt_handler(uint8_t n, isr_t handler);

#endif
