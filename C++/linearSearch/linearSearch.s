	.file	"linearSearch.cpp"
	.text
#APP
	.globl _ZSt21ios_base_library_initv
	.section	.rodata
.LC1:
	.string	", "
	.align 8
.LC2:
	.string	"Inserire il numero che si vuole ricercare: "
.LC4:
	.string	"Seq: Il numero "
	.align 8
.LC5:
	.string	" \303\250 stato trovato nella posizione "
.LC6:
	.string	" non \303\250 stato trovato"
.LC7:
	.string	". Tempo impiegato: "
.LC8:
	.string	"us"
.LC9:
	.string	"Ott: Il numero "
	.align 8
.LC10:
	.string	" non \303\250 stato trovato prima del numero "
.LC11:
	.string	"Bin: Il numero "
.LC12:
	.string	"---- Grafico Brutto :) ---"
.LC13:
	.string	"Seq: *"
.LC14:
	.string	"*"
.LC15:
	.string	" "
.LC16:
	.string	"Ott: *"
.LC17:
	.string	"Bin: *"
#NO_APP
	.text
	.globl	main
	.type	main, @function
main:
.LFB1982:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$4000104, %rsp
	.cfi_offset 3, -24
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movl	$1000000, -4000072(%rbp)
	movl	$0, -4000084(%rbp)
	movss	.LC0(%rip), %xmm0
	movss	%xmm0, -4000068(%rbp)
	movl	$0, %edi
	call	time@PLT
	movl	%eax, %edi
	call	srand@PLT
	call	rand@PLT
	movl	%eax, %ecx
	movslq	%ecx, %rax
	imulq	$1717986919, %rax, %rax
	shrq	$32, %rax
	movl	%eax, %edx
	sarl	$2, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	leal	1(%rdx), %eax
	movl	%eax, -4000032(%rbp)
	movl	$1, -4000080(%rbp)
	jmp	.L2
.L3:
	movl	-4000080(%rbp), %eax
	subl	$1, %eax
	cltq
	movl	-4000032(%rbp,%rax,4), %ebx
	call	rand@PLT
	movl	%eax, %ecx
	movslq	%ecx, %rax
	imulq	$1717986919, %rax, %rax
	shrq	$32, %rax
	movl	%eax, %edx
	sarl	$2, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	leal	(%rbx,%rdx), %eax
	leal	1(%rax), %edx
	movl	-4000080(%rbp), %eax
	cltq
	movl	%edx, -4000032(%rbp,%rax,4)
	addl	$1, -4000080(%rbp)
.L2:
	cmpl	$999999, -4000080(%rbp)
	jle	.L3
	movl	$0, -4000076(%rbp)
	jmp	.L4
.L5:
	movl	-4000076(%rbp), %eax
	cltq
	movl	-4000032(%rbp,%rax,4), %eax
	movl	%eax, %esi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	addl	$1, -4000076(%rbp)
.L4:
	cmpl	$999998, -4000076(%rbp)
	jle	.L5
	movl	-36(%rbp), %eax
	movl	%eax, %esi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	.LC2(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	-4000100(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt3cin(%rip), %rax
	movq	%rax, %rdi
	call	_ZNSirsERi@PLT
	call	clock@PLT
	movq	%rax, -4000048(%rbp)
	jmp	.L6
.L8:
	addl	$1, -4000084(%rbp)
.L6:
	movl	-4000084(%rbp), %eax
	cltq
	movl	-4000032(%rbp,%rax,4), %edx
	movl	-4000100(%rbp), %eax
	cmpl	%eax, %edx
	je	.L7
	cmpl	$999999, -4000084(%rbp)
	jle	.L8
.L7:
	call	clock@PLT
	movq	%rax, -4000040(%rbp)
	movq	-4000040(%rbp), %rax
	subq	-4000048(%rbp), %rax
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rax, %xmm1
	movsd	.LC3(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	.LC3(%rip), %xmm1
	divsd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm0
	movss	%xmm0, -4000064(%rbp)
	leaq	.LC4(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movl	-4000100(%rbp), %eax
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	_ZNSolsEi@PLT
	cmpl	$999999, -4000084(%rbp)
	jg	.L9
	leaq	.LC5(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movl	-4000084(%rbp), %eax
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	_ZNSolsEi@PLT
	jmp	.L10
.L9:
	leaq	.LC6(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
.L10:
	leaq	.LC7(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movl	-4000064(%rbp), %eax
	movd	%eax, %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEf@PLT
	movq	%rax, %rdx
	leaq	.LC8(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	call	clock@PLT
	movq	%rax, -4000048(%rbp)
	movl	$0, -4000084(%rbp)
	jmp	.L11
.L13:
	addl	$1, -4000084(%rbp)
.L11:
	movl	-4000084(%rbp), %eax
	cltq
	movl	-4000032(%rbp,%rax,4), %edx
	movl	-4000100(%rbp), %eax
	cmpl	%eax, %edx
	jge	.L12
	cmpl	$999999, -4000084(%rbp)
	jle	.L13
.L12:
	call	clock@PLT
	movq	%rax, -4000040(%rbp)
	movq	-4000040(%rbp), %rax
	subq	-4000048(%rbp), %rax
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rax, %xmm1
	movsd	.LC3(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	.LC3(%rip), %xmm1
	divsd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm0
	movss	%xmm0, -4000060(%rbp)
	leaq	.LC9(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movl	-4000100(%rbp), %eax
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	_ZNSolsEi@PLT
	movl	-4000084(%rbp), %eax
	cltq
	movl	-4000032(%rbp,%rax,4), %edx
	movl	-4000100(%rbp), %eax
	cmpl	%eax, %edx
	jne	.L14
	leaq	.LC5(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movl	-4000084(%rbp), %eax
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	_ZNSolsEi@PLT
	jmp	.L15
.L14:
	cmpl	$1000000, -4000084(%rbp)
	jne	.L16
	movl	$999999, -4000084(%rbp)
.L16:
	leaq	.LC10(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movl	-4000084(%rbp), %eax
	cltq
	movl	-4000032(%rbp,%rax,4), %eax
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	_ZNSolsEi@PLT
.L15:
	leaq	.LC7(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movl	-4000060(%rbp), %eax
	movd	%eax, %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEf@PLT
	movq	%rax, %rdx
	leaq	.LC8(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movl	$0, -4000092(%rbp)
	movl	$999999, -4000088(%rbp)
	movl	$-1, -4000096(%rbp)
	call	clock@PLT
	movq	%rax, -4000048(%rbp)
.L21:
	movl	-4000092(%rbp), %edx
	movl	-4000088(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -4000056(%rbp)
	movl	-4000056(%rbp), %eax
	cltq
	movl	-4000032(%rbp,%rax,4), %edx
	movl	-4000100(%rbp), %eax
	cmpl	%eax, %edx
	jne	.L17
	movl	-4000056(%rbp), %eax
	movl	%eax, -4000096(%rbp)
	jmp	.L18
.L17:
	movl	-4000056(%rbp), %eax
	cltq
	movl	-4000032(%rbp,%rax,4), %edx
	movl	-4000100(%rbp), %eax
	cmpl	%eax, %edx
	jge	.L19
	movl	-4000056(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4000092(%rbp)
	jmp	.L18
.L19:
	movl	-4000056(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -4000088(%rbp)
.L18:
	movl	-4000092(%rbp), %eax
	cmpl	-4000088(%rbp), %eax
	jg	.L20
	cmpl	$-1, -4000096(%rbp)
	je	.L21
.L20:
	call	clock@PLT
	movq	%rax, -4000040(%rbp)
	movq	-4000040(%rbp), %rax
	subq	-4000048(%rbp), %rax
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rax, %xmm1
	movsd	.LC3(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	.LC3(%rip), %xmm1
	divsd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm0
	movss	%xmm0, -4000052(%rbp)
	leaq	.LC11(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movl	-4000100(%rbp), %eax
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	_ZNSolsEi@PLT
	cmpl	$-1, -4000096(%rbp)
	je	.L22
	leaq	.LC5(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movl	-4000096(%rbp), %eax
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	_ZNSolsEi@PLT
	jmp	.L23
.L22:
	leaq	.LC6(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
.L23:
	leaq	.LC7(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movl	-4000052(%rbp), %eax
	movd	%eax, %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEf@PLT
	movq	%rax, %rdx
	leaq	.LC8(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rdx
	leaq	.LC12(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rdx
	leaq	.LC13(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movss	-4000064(%rbp), %xmm0
	cvttss2sil	%xmm0, %eax
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%eax, %xmm0
	mulss	-4000068(%rbp), %xmm0
	cvttss2sil	%xmm0, %eax
	movl	%eax, -4000096(%rbp)
	movl	$0, -4000084(%rbp)
	jmp	.L24
.L25:
	leaq	.LC14(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	addl	$1, -4000084(%rbp)
.L24:
	movl	-4000084(%rbp), %eax
	cmpl	-4000096(%rbp), %eax
	jl	.L25
	leaq	.LC15(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movl	-4000064(%rbp), %eax
	movd	%eax, %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEf@PLT
	movq	%rax, %rdx
	leaq	.LC8(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	.LC16(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movss	-4000060(%rbp), %xmm0
	cvttss2sil	%xmm0, %eax
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%eax, %xmm0
	mulss	-4000068(%rbp), %xmm0
	cvttss2sil	%xmm0, %eax
	movl	%eax, -4000096(%rbp)
	movl	$0, -4000084(%rbp)
	jmp	.L26
.L27:
	leaq	.LC14(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	addl	$1, -4000084(%rbp)
.L26:
	movl	-4000084(%rbp), %eax
	cmpl	-4000096(%rbp), %eax
	jl	.L27
	leaq	.LC15(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movl	-4000060(%rbp), %eax
	movd	%eax, %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEf@PLT
	movq	%rax, %rdx
	leaq	.LC8(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	.LC17(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movss	-4000052(%rbp), %xmm0
	cvttss2sil	%xmm0, %eax
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%eax, %xmm0
	mulss	-4000068(%rbp), %xmm0
	cvttss2sil	%xmm0, %eax
	movl	%eax, -4000096(%rbp)
	movl	$0, -4000084(%rbp)
	jmp	.L28
.L29:
	leaq	.LC14(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	addl	$1, -4000084(%rbp)
.L28:
	movl	-4000084(%rbp), %eax
	cmpl	-4000096(%rbp), %eax
	jl	.L29
	leaq	.LC15(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movl	-4000052(%rbp), %eax
	movd	%eax, %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEf@PLT
	movq	%rax, %rdx
	leaq	.LC8(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movl	$0, %eax
	movq	-24(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L31
	call	__stack_chk_fail@PLT
.L31:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1982:
	.size	main, .-main
	.section	.rodata
	.type	_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE, @object
	.size	_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE, 1
_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE:
	.byte	1
	.type	_ZNSt8__detail30__integer_to_chars_is_unsignedImEE, @object
	.size	_ZNSt8__detail30__integer_to_chars_is_unsignedImEE, 1
_ZNSt8__detail30__integer_to_chars_is_unsignedImEE:
	.byte	1
	.type	_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE, @object
	.size	_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE, 1
_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE:
	.byte	1
	.align 4
.LC0:
	.long	1008981770
	.align 8
.LC3:
	.long	0
	.long	1093567616
	.ident	"GCC: (GNU) 13.2.1 20230801"
	.section	.note.GNU-stack,"",@progbits
