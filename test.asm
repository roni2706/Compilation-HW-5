.text

main:
sw $30, 0($sp)
addi $sp, $sp, -4
addi $fp, $sp, 4
sw $0, 0($sp)
addi $sp, $sp, -4
sw $0, 0($sp)
addi $sp, $sp, -4
sw $0, 0($sp)
addi $sp, $sp, -4
lw $8, 0($fp)
li $9, 0
bgt $8, $9, label_18
j label_22
label_18:
li $8, 8
sw $8, -4($fp)
j main_end
label_22:
li $8, 7
sw $8, -4($fp)
main_end:
addi $sp, $fp, 72
addi $sp,$sp,4
lw $30, 0($sp)
jr $ra
