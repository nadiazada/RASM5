global aBubbleSort

aBubbleSort:
        stp x29, x30, [sp, #-16]!
        mov 29, sp

        mov x2, #0

outerLoop:
        cmp x2, x1
        bge end_outerLoop

        sub x3, x1,x2
        sub x3, x4, #1
        mov x2, #0

innerLoop:
        cmp x4, x3
        bge end_innerLoop

        add x5, x0, x4, lsl #2
        add x6, x5, #4

        ldr w7,[x5]
        ldr w8,[x6]

        cmp w7, w8
        blt no_swap

        str w8, [x5]
        str w7, [x6]

no_swap:
        add x4, x4, #1
        b innerLoop

end_innerLoop:
        add x2, x2, #1
        b outerLoop

end_outerLoop:
        ldp x29, x30, [sp], #16
        RET
