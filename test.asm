.text
print:
sw $30, 0($sp)
addi $sp, $sp, -4
addi $fp, $sp, 4
li $2, 4
lw $4, 4($fp)
syscall
addi $sp,$sp,4
lw $30, 0($sp)
jr $ra

printi:
sw $30, 0($sp)
addi $sp, $sp, -4
addi $fp, $sp, 4
li $2, 1
lw $4, 4($fp)
syscall
addi $sp,$sp,4
lw $30, 0($sp)
jr $ra


#function: main
main:
sw $30, 0($sp)
addi $sp, $sp, -4
addi $fp, $sp, 4
sw $0, 0($sp)
addi $sp, $sp, -4
li $8, 0
sw $8, -4($fp)
sw $31, 0($sp)
addi $sp, $sp, -4
addi $sp, $sp, -4
li $8, 8
lw $9, -4($fp)
bne $9, $0, label_42
la $9, _str_div_error
jal print #jump to print err
li $v0 10 #exit
syscall
label_42:
div $8, $8, $9
addi $sp, $sp, 4
sw $8, 0($sp)
addi $sp, $sp, -4
jal printi
addi $sp, $sp, 4
addi $sp,$sp,4
lw $31, 0($sp)
main_end:
addi $sp, $fp, -4
addi $sp,$sp,4
lw $30, 0($sp)
jr $ra
.data
_str_div_error: .asciiz "Error division by zero
"
