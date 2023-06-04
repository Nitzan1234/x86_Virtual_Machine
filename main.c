#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


#define MEMORY_MAX (1 << 16)

uint16_t memory[MEMORY_MAX];  /* 65536 locations */

typedef enum
{
    R_R0 = 0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC, /* program counter */
    R_COND,
    R_COUNT
}Registers;

uint16_t reg[R_COUNT];

typedef enum
{
    OP_BR = 0, /* branch */
    OP_ADD,    /* add  */
    OP_LD,     /* load */
    OP_ST,     /* store */
    OP_JSR,    /* jump register */
    OP_AND,    /* bitwise and */
    OP_LDR,    /* load register */
    OP_STR,    /* store register */
    OP_RTI,    /* unused */
    OP_NOT,    /* bitwise not */
    OP_LDI,    /* load indirect */
    OP_STI,    /* store indirect */
    OP_JMP,    /* jump */
    OP_RES,    /* reserved (unused) */
    OP_LEA,    /* load effective address */
    OP_TRAP    /* execute trap */
}CPU_Instructions;

typedef enum
{
    FL_POS = 1 << 0, /* P */
    FL_ZRO = 1 << 1, /* Z */
    FL_NEG = 1 << 2, /* N */
}Condition_Flags;

int main()
{
 /* since exactly one condition flag should be set at any given time, set the Z flag */
    reg[R_COND] = FL_ZRO;

    /* set the PC to starting position */
    enum { PC_START = 0x3000 };
    reg[R_PC] = PC_START;

    int running = 1;
    while (running)
    {
        /* FETCH */
        uint16_t instr = mem_read(reg[R_PC]++);
        uint16_t op = instr >> 12;

        switch (op)
        {
            case OP_ADD:
            asm [ volatile ] (op);
            break;
            case OP_AND:
                asm [ volatile ] (op);
                break;
            case OP_NOT:
                asm [ volatile ] (op);
                break;
            case OP_BR:
                asm [ volatile ] (op);
                break;
            case OP_JMP:
                asm [ volatile ] (op);
                break;
            case OP_JSR:
                asm [ volatile ] (op);
                break;
            case OP_LD:
                asm [ volatile ] (op);
                break;
            case OP_LDI:
                asm [ volatile ] (op);
                break;
            case OP_LDR:
                asm [ volatile ] (op);
                break;
            case OP_LEA:
                asm [ volatile ] (op);
                break;
            case OP_ST:
                asm [ volatile ] (op);
                break;
            case OP_STI:
                asm [ volatile ] (op);
                break;
            case OP_STR:
                asm [ volatile ] (op);
                break;
            case OP_TRAP:
                asm [ volatile ] (op);
                break;
            case OP_RES:
                asm [ volatile ] (op);
                break;
            case OP_RTI:
                asm [ volatile ] (op);
                break;
            default:
                printf("Invalid Instruction\n")
                break;
        }
    }
}
}
