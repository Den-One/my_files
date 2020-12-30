s_s segment
dd 10 dup(0)
s_s ends

d_s segment

    ;Служебное сообщение №1
    input_msg db 'Please, input massif end click on ''Enter'': ', '$'

    ;Служебное сообщение №2
    output_msg db 'Your maximum is: ', '$'

    ;Массив, который мы введём
    mas db 8 dup(0)

    ;Присваиваем максимуму 0
    max db 00h

d_s ends

c_s segment
assume ss:s_s, ds:d_s, cs:c_s
begin:
mov ax, d_s
mov ds, ax
xor ax, ax

;Вывод служебного сообщения №1
    mov ah, 09h
    mov cx, offset input_msg
    int 21h

;ввод массива
    mov ah, 3Fh            ;Функция ввода
    mov bx, 0              ;Дескриптор клавиатуры
    mov cx, 9              ;Вводим максимум 8 байт
    mov dx, offset mas     ;Адрес буфера ввода
    int 21h

;Обрабатываем полученные на вход числа
    mov cx, 8      ;Цикл из 8 повторов
    lea si, mas
srch:

    lodsb          ;Загружаем в al эл. массива
    rcr ax, 1      ;Сдвиг цикл. вправо/проверк. на чёт.
    jnc maxTrue1   ;Переход, если чёт (CF=0)
    jmp next       ;если нет, проверка след. эл.

maxTrue1:
    rcl ax,1       ;Обратно сдвиг цикл. плево
    mov bl, max    ;Загружаем в bl максимум
    cmp al, bl     ;Сравниваем значения
    jg maxTrue2    ;Переход, если ax > max
    jmp next       ;если нет, проверка след. эл.

maxTrue2:
    mov bl, al
    mov max, bl    ;Сохраняем новый, чётный max

next:
    Loop srch      ;Проверяем следующий эл.


;Вывод служебного сообщения №2
    mov ah, 40h
    mov bx, 1
    mov cx, 17
    mov dx, offset output_msg
    int 21h

;Вывод найденного чётного максимума
    mov ah, 40h
    mov bx, 1             ;Дескриптор экрана
    mov cx, 1             ;Длина сообщения
    mov dx, offset max
    int 21h

;Выход в концоль, чтобы увидеть результат
    mov ah,01             ;Остановим программу
    int 21h               ;в ожидании нажатия клавиши

;mov ah, 3Fh
;mov bx, 1
;mov cx, 80
;mov dx, offset inpstr
;int 21h
;mov ah, 40h
;mov bx, 0


mov ah, 4ch
int 21h
c_s ends
end begin