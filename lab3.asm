d_s segment
num1 db 1Eh;	; 1-е число в 16-й системе (30)
num2 db 12h;	; 2-е число в 16-й системе (18)
NOD db 0	; Ячейка, где храни
d_s ends
c_s segment
assume ds:d_s, cs:c_s
begin:
mov ax, d_s
mov ds, ax
xor ax, ax
mov bh, num1	; помещаем числа в регистры.
mov bl, num2
again:		; метка начачала  алгоритма Евклида
    cmp bh, 0		
    jnz bhnz
    jmp exit	; выход если bh = 0
bhnz:		; while bh != 0 and bl != 0
    cmp bl, 0
    jnz blnz	; переход к условию сравнения
    jmp exit	; выход если bl = 0
blnz:
    cmp bh, bl	; if bh > bl
    jg bhmore	; переход при условии bh > bl
    mov ax, 0	
    mov al, bl	; if bh < bl
    div bh		; ax / bh = ax
    mov bl, ah	; ah (целое) ah (остаток)
    jmp again
bhmore:	; начало метки - if bh > bl
    mov ax, 0	; ax / bl = ax
    mov al, bh	; ah (целое) ah (остаток)
    div bl
    mov bh, ah
jmp again	; повтор цикла Евклида
 
exit:
mov NOD, bl	;сохраняем НОД в ячейку памяти NOD
add NOD, bh
mov cl, 8	; (int i = 0; i < 8; i++)
mov ax, 0	
mov al, NOD	; передаём в al число, биты которого будем сдв.
mov dx, 0
mov bx, 0
cycle:		; начало цикла loop
rcr al, 1		; сдвигаем бит нашего NOD
rcl bl, 1	; из FC сохраняем рез. сдвига в регистр bl
add dl, bl	; сохраняем число единиц
mov bx, 0
loop cycle	; конец цикла loop (cl - 1)
mov ah, 4ch
int 21h		; завершение программы, прерывание 21h
c_s ends
ыend begin
