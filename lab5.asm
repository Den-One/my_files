s_s segment
    dw 5 dup(0)
s_s ends
d_s segment
   mus1 db 3, 5, 1, 8, 9, 4, 2, 7, '$'
   mus2 db 8 dup(0)
d_s ends
 c_s segment
assume ds:d_s, cs:c_s, ss:s_s
; Процедура ссортирует массив
sort proc near
    ;Очищаем все регистры
    xor ax, ax
    xor bx, bx
    xor cx, cx
    xor dx, dx
    ;Передаём число эл-в в массиве (N-1)
    mov cl, 8
    sub cl, 1    

    ;Производим перемещение всех пар элементов
    i:
        mov si, 0
        mov al, cl
        ;Сравниваем текущую пару, перемещаем 1 эл.
        j:
            xor dx, dx
            xor bx, bx

            ; Ищем большее число среди bl и dl
            mov bl, mus2[si]
            mov dl, mus2[si+1]
            cmp bl,dl
        ja yes
        jmp no
        ;Элемент больше, меняем местами
	yes:
            ;Меняем местами через доп. регистр bh
            mov bh, bl
            mov bl, dl
            mov dl, bh
            mov bh, 0
            ;Помещаем отсортированные эл-ты в mas2
            mov mus2[si],bl
            mov mus2[si+1],dl
        jmp jExit
        ;Элемент меньше, оставляем на местах
        no:
            ;Но всё равно помещаем в mas2
            mov mus2[si],bl
            mov mus2[si+1],dl
        jmp jExit
        ;Рассматриваем следующую пару
        jExit: 
            add si, 1
        Loop j        
        xor cx, cx
        mov cl, al
        ;sub cl, 1
        xor ax, ax
    Loop i
ret	
sort endp
check proc near

    ;Очищаем все регистры
    xor ax, ax
    xor bx, bx
    xor cx, cx
    xor dx, dx
    ;Создаём цикл для просмотра 4 пар эл-в
    mov cl, 4
    mov si, 0
    m1:
        ;Передаём в 2 регистры пару элементов mas
        mov al,mus2[si]
        mov bl,mus2[si+1]
        ;Нулируем для просмотра следующей пары
        xor ax, ax
        xor bx, bx
        add si, 2
    Loop m1 
Ret
check endp


copy proc near
    ;Очищаем все регистры
    xor ax, ax
    xor bx, bx
    xor cx, cx
    xor dx, dx
    mov si, 0
    mov cx, 8
    ;В цикле, копируем массив
    cop:
        ;Копируем черех регистр dx
        mov dl, mus1[si]
        mov mus2[si], dl
        add si, 1
    Loop cop
Ret
copy endp

;Вызов функции в начале программы
begin:
mov ax, d_s; 
mov ds, ax
xor ax, ax
    ;Копируем старый массив на место нового
    call copy
    ;Сортируем числа, занося во 2-й массив
    call sort
    ;Прогоняем по регистрам отсортированный массив.
    call check

mov ah, 4ch
int 21h
c_s ends
end begin
