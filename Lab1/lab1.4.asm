.data
    prompt: .asciiz "Enter a double number: "
    result: .double 0.0

.text
.globl main

main:
    # Print prompt message
    li $v0, 4       # syscall for print_str
    la $a0, prompt  # load address of prompt
    syscall

    # Read double from user
    li $v0, 7       # syscall for read_double
    syscall
    mov.d $f12, $f0 # move the double value to $f12

    # Store the double in memory for printing
    s.d $f12, result

    # Print the double
    li $v0, 3       # syscall for print_double
    l.d $f12, result
    syscall

    # Exit program
    li $v0, 10      # syscall for exit
    syscall
