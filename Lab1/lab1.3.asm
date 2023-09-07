.data
    prompt: .asciiz "Enter a floating number: "
    result: .float 0.0

.text
.globl main

main:
    # Print prompt message
    li $v0, 4       # syscall for print_str
    la $a0, prompt  # load address of prompt
    syscall

    # Read float from user
    li $v0, 6       # syscall for read_float
    syscall
    mov.s $f12, $f0 # move the float value to $f12

    # Store the float in memory for printing
    s.s $f12, result

    # Print the float
    li $v0, 2       # syscall for print_float
    l.s $f12, result
    syscall

    # Exit program
    li $v0, 10      # syscall for exit
    syscall
