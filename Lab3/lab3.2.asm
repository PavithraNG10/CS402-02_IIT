.data
var1: .word 1 # first digit of your SSN
var2: .word 3 # second digit of your SSN
var3: .word -2023 # minus the number of this year

.text
main:
    lw $t0, var1
    lw $t1, var2
    lw $t2, var3

    slt $t0, $t1, $t2   #if ($t1 < $t2) $t0 = 1, else $t0 = 0 
	bgtz $t0, else     #jump at else if $t0 is greater than zero

    sw $t2, var1
    sw $t2, var2
    j exit

else:
    
    lw $t0, var2
    lw $t1, var1

    sw $t0, var1
    sw $t1, var2

exit:
    jr $ra
