.data
    var1:   .word   0

.text
 main:
        # Load the first digit of your SSN into var1
        li $t0, 2
        sw $t0, var1
        
        # Initialize i to var1
        lw $t0, var1
        move $t1, $t0
        
 loop:
        # Check if i < 100
        li $t2, 100
        slt $t3, $t1, $t2
        
        beq $t3, $zero, end_loop
        
        # Increment var1 by 1
        lw $t0, var1
        addi $t0, $t0, 1
        sw $t0, var1
        
        # Increment i by 1
        addi $t1, $t1, 1
        
        j loop
        nop
 
       
 
end_loop:
        # End of loop
        
        # Exit the program
		# Print the updated value of var1
        li $v0, 1
        lw $a0, var1
        syscall
 
        li $v0, 10
        syscall
