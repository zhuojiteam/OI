	.section	__TEXT,__text,regular,pure_instructions
	.globl	__Z3fibi
	.align	4, 0x90
__Z3fibi:                               ## @_Z3fibi
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp2:
	.cfi_def_cfa_offset 16
Ltmp3:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp4:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	%edi, -8(%rbp)
	cmpl	$3, -8(%rbp)
	jge	LBB0_2
## BB#1:
	movl	-8(%rbp), %eax
	movl	%eax, -4(%rbp)
	jmp	LBB0_6
LBB0_2:
	movl	-8(%rbp), %eax
	movl	%eax, %ecx
	shrl	$31, %ecx
	addl	%ecx, %eax
	sarl	%eax
	movl	%eax, -12(%rbp)
	movl	%eax, %edi
	callq	__Z3fibi
	movl	%eax, -16(%rbp)
	movl	-12(%rbp), %eax
	incl	%eax
	movl	%eax, %edi
	callq	__Z3fibi
	movl	%eax, -20(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, %ecx
	shrl	$31, %ecx
	movl	%eax, %edi
	addl	%ecx, %edi
	andl	$-2, %edi
	subl	%edi, %eax
	movl	%eax, %ecx
	subl	$1, %ecx
	movl	%eax, -24(%rbp)         ## 4-byte Spill
	movl	%ecx, -28(%rbp)         ## 4-byte Spill
	je	LBB0_4
	jmp	LBB0_7
LBB0_7:
	movl	-24(%rbp), %eax         ## 4-byte Reload
	testl	%eax, %eax
	jne	LBB0_5
	jmp	LBB0_3
LBB0_3:
	movl	-16(%rbp), %eax
	movl	-20(%rbp), %ecx
	shll	$1, %ecx
	subl	-16(%rbp), %ecx
	imull	%ecx, %eax
	movl	%eax, -4(%rbp)
	jmp	LBB0_6
LBB0_4:
	movl	-16(%rbp), %eax
	imull	-16(%rbp), %eax
	movl	-20(%rbp), %ecx
	imull	-20(%rbp), %ecx
	addl	%ecx, %eax
	movl	%eax, -4(%rbp)
	jmp	LBB0_6
LBB0_5:
	jmp	LBB0_6
LBB0_6:
	movl	-4(%rbp), %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp7:
	.cfi_def_cfa_offset 16
Ltmp8:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp9:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$1, -20(%rbp)
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$10, -20(%rbp)
	jge	LBB1_4
## BB#2:                                ##   in Loop: Header=BB1_1 Depth=1
	movl	-20(%rbp), %edi
	callq	__Z3fibi
	leaq	L_.str(%rip), %rdi
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -24(%rbp)         ## 4-byte Spill
## BB#3:                                ##   in Loop: Header=BB1_1 Depth=1
	movl	-20(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -20(%rbp)
	jmp	LBB1_1
LBB1_4:
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d\n"


.subsections_via_symbols
