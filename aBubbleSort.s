.global aBubbleSort

aBubbleSort:
        stp x29, x30, [sp, #-16]! //saving x29, x30 (fp, return address)
        mov x29, sp               //set fp to sp              

        mov x2, #0                //set counter to 0

outerLoop:
        cmp x2, x1                //cmp the val in outer loop counter (x2) with x1 (length)
        bge end_outerLoop         //if gtr jump

        sub x3, x1,x2             //adjust the limit for inner loop
        sub x3, x3, #1            //sub 1 for zero based index 
        mov x4, #0                // set couter for inner loop to 0

innerLoop:
        cmp x4, x3                //cmp inner loop w x3 
        bge end_innerLoop        //if x4 is gtr then jmp

        add x5, x0, x4, lsl #2    //calc the memory add of current elem
        add x6, x5, #4            // add of next elem

        ldr w7,[x5]                //load word at x5 to w7
        ldr w8,[x6]                //load word at x6 into w8

        cmp w7, w8                //compare values
        blt no_swap                //if w7 is less then skip swap instructions

        str w8, [x5]               //swap x5
        str w7, [x6]               //swap x6 

no_swap:
        add x4, x4, #1             //inc inner loop counter 
        b innerLoop                //jmp to start of innerLoop

end_innerLoop:
        add x2, x2, #1             //inc outer loop counter
        b outerLoop                //jmp to start of outerLoop

end_outerLoop:
        ldp x29, x30, [sp], #16    //load pair
        RET                        //return 
