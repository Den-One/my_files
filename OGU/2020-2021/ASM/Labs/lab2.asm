s_s segment
b db 20 DUP(?)		; Выделение в сегменте Стека 20 байт
s_s ends

d_s1 segment

num1 db 00000100b	; Создание числа в яч. памяти (4)

d_s1 ends

d_s2 segment
a dd pt1			; Создание ячейки с адресом переноса
d_s2 ends

d_s3 segment

num2 db 00011000b	; Создание числа в яч. памяти (24)

d_s3 ends

c_s1 segment
assume cs:c_s1
pt1 label far 		; Определение типа точки pt1

mov ax, d_s1
mov ds, ax
assume ds:d_s1
mov ax,0
mov bx,0
mov al, num1		; Передача в регистр ‘al’ числа из яч. памяти num1
ror al, 3			; Циклический сдвиг вправо		(bx 0001)
rcl bl,1			; Циклический сдвиг влево с переносом числа из флага ‘cf’

jmp far ptr pt2		; Переход в точку pt2 в другой сегмент кода

c_s1 ends

c_s2 segment
assume cs:c_s2
pt2 label far		; Определение типа точки pt2
mov ax, d_s3
mov ds, ax
assume ds:d_s3
mov ax, 0
mov bx, 0
mov al, num2		; Передача в регистр ‘al’ числа из яч. памяти num2
ror al, 5			; Циклический сдвиг вправо		(bx 0100)
rcl bh, 1			; Циклический сдвиг влево с переносом числа из флага ‘cf’

jmp far ptr exit		; Переход в точку exit в другой сегмент кода 

c_s2 ends

c_s3 segment
assume cs:c_s3

begin:			; Начало программы
mov ax, d_s1
mov ds, ax
assume ds:d_s1
mov ax,0
mov al, num1		; Передача в рег ‘al’ число из яч. num1
shl al, 1			; Логический сдвиг влево (умножение на 2) (al = 8)

mov ax, d_s3
mov ds, ax
assume ds:d_s3
mov ax,0
mov al, num2		; Передача в рег ‘al’ число из яч. num2
shr al, 2			; Логический сдвиг вправо (деление на 4) (al = 6)

mov ax, d_s2
mov ds, ax			; Передаём процессоры данные из data-сегмента d_s2
assume ds:d_s2

jmp a			; Переход по адресу, записанному в ячейке памяти ‘a’

exit label far 		; Определение типа точки exit
mov ah, 4ch
int 21h			; Вызов системного завершения программы
c_s3 ends
end begin
