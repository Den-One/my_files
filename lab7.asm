s_s segment 
dw 20 dup('$')
s_s ends

d_s segment
string db '()','$';
result db 0
d_s ends

c_s segment
assume ss:s_s,ds:d_s,cs:c_s
begin: ; начало программы
mov ax,d_s
mov ds,ax
xor ax,ax

lea si, string

;Ищем в строке скобку
search:
    lodsb

    ;Проверка, это конец строки?
    cmp al, '$'
    je endString

    ;Это открывающая или закрывающая скобка?
        ;Это открывающие скобки?
        cmp al, '('
        je inStack
        cmp al, '{'
        je inStack
        cmp al, '['
        je inStack

        ;Это закрывающие скобки?
        cmp al, ')'
        je outStack
        cmp al, '}'
        je outStack
        cmp al, ']'
        je outStack
        jmp search

        ;Помещаем скобку в Stack, увеличиваем счётчик
        inStack:
            inc cx
            push ax
            jmp search

        ;Выниманием из Stack скобку, проверяем пару
        outStack:
            ;Была передана лишняя закрыв. скобка?
            cmp cx, 0
            je error3

            dec cx
            pop bx
            
            ;Вскрытая скобка закрыта верно?
            cmp bl, '('
            jne close1
            cmp al, ')'
            jne error1
            jmp search

            close1:
            cmp bl, '['
            jne close2
            cmp al, ']'
            jne error1
            jmp search

            close2:
            cmp bl, '{'
            cmp al, '}'
            jne error1
            jmp search

    ;Остались ли незакрытые скобки?
    endString:
    cmp cx, 0
    jne error2
    jmp exit

    ;Скобки остались, это ошибка №2
    error2:
    mov result, 2
    jmp exit

    ;Лишняя скобка передана, ошибка №3
    error3:
    mov result, 3
    jmp exit

    ;Закрывающая скобка несоответствует открывающей, ош №1
    error1:
    mov result, 1
    jmp exit


    ;Пред-завершение. Каков результат программы?
    exit:
    cmp result, 1
    jne enough
    
    ;Ищем нужную скобку для исправления ошибки №1
    cmp bl, '('
    jne next1
    mov bl, ')'
    jmp enough

    next1:
    cmp bl, '{'
    jne next2
    mov bl, '}'
    jmp enough

    next2:
    cmp bl, '['
    mov bl, ']'
    jmp enough


enough:
mov dl, result
xor dx, dx
mov dl, bl 

mov ah,4ch
int 21h
c_s ends
end begin
