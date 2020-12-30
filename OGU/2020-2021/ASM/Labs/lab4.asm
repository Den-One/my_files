d_s segment
  mas dw 18 dup(0)
  min dw 0	; Резервируем ячейки памяти для хранения данных
  max dw 0
d_s ends
c_s segment
assume ds:d_s,cs:c_s
begin:		; сегменты видимы, программа началась
mov ax, d_s
mov ds, ax
mov ax, 0

mov si, 0	; n = 0
mov mas[si], 1	; Определяем 1-е число фиб (n+=1)
mov ax, mas[si]	; (fib 1)
mov si, 2
mov mas[si], 1	; Определяем 2-е число фиб (n+=1)
mov bx, mas[si] 
mov cx, -2	; while i < (n-2) - без учёта пред. чис.
add cx, 18	; Ищем 18 элемент мас-ва (n = 16)
mov si, 4	; Определяем значение i

Fib:		; Начало цикла
mov dx, ax	; Сумма чисел двух предыдущ.
add dx, bx
mov mas[si], dx	; Сохраняем нов. число фиб
mov ax, bx	; fib1:= fib2
mov bx, dx	; fib2:= fib_sum
add si, 2	; Рассматриваем следующий эл. [si+2]
Loop Fib	; Конец цикла (cx-1)
		; dx = A18 (2584)
mov si, 22	; Перех. в кон. 2-й стр. (3x6 mas) (22 эл. +2)
mov ax, 0
mov bx, 0	; Сбрасываем регистры
mov dx, 0
mov cx, 6	; 6 эл-в массива проверяем на услов-е (2-ю стр)
 
searchMin:
mov min, 9fffh	; минимуму присв. max знач.
mov ax,mas[si]
rcr ax, 1	; Сдвиг вправо (CF = 0\1)
jc minTrue1	; Переход если CF=1
jmp exitMin	; Иначе расматрив. след. элем (CF=0)

minTrue1:
rcl ax, 1	; Цикл. сдвиг влево, возвращ. исх числ.x
cmp ax, min
jb minTrue2	; Переход, если (ax < min)
jmp exitMin	; Иначе расматрив. след. элем (CF=0)

minTrue2:
mov min, ax	; Присваиваем новый min

exitMin:
sub si, 2	; Переходим к след. элем.
Loop searchMin	; Рассматрив. след. элем


mov si, 6	; Начинаем с 4-го эл. в столбе
mov cx, 3	; 3 элем. в столбце (6x3 матрицы)
mov ax, 0	; Сброс ax

searchMax:
mov ax, mas[si]	; Помещаем в ax нижн. эл. столб.
rcr ax, 1	; Сдвиг цикл. вправо/проверк. на чёт.
jnc maxTrue1	; Переход, если CF=0
jmp exitMax	; Иначе перех в нач к след. эл.
maxTrue1:   
rcl ax,1	; Циклич. сдвиг влево, возвр. исх. числ.
cmp ax, max
jg maxTrue2	; Переход, если ax > max jg -> jns
jmp exitMax	; Иначе перех в нач к след. эл.
maxTrue2:
mov bx, ax	; Присваиваем новый max
mov max, bx

exitMax:
   add si, 12	; mas[30], mas[18], mas[6]  
   Loop searchMax	; Рассматрив. след. элем
   mov cx, min	; Проверим наш min (D = 13) {144, 89, 55, 34, 21, 13}
   mov bx, max	; Проверим наш max (0) {3, 55, 987}
 
;Персональное задание (№14)
xor ax, ax
xor bx, bx
xor cx, cx	; Сбрасываем регистры
xor dx, dx
mov max, dx	; Обнуляем max
mov si, 12	; Переходим в начало 2-й строки
mov cx, 6
search1: 
mov ax, mas[si]
rcr ax, 1	; Ищем нечётный эл-т
jnc m1
jmp newExit
m1:
cmp ax, max	; Если нашли, сверяем с max
jg m2		
jmp newExit
m2:
mov max, ax	; ax < max --> max := ax
newExit:
add si, 2
Loop search1	;Нашли нужный эл-т
xor ax, ax
xor cx, cx
mov si, 4
mov cx, 3
adding:		;Добавляем число 3-м элементам
xor ax, ax
xor bx, bx
mov ax, mas[si]
add ax, max
mov max[si], ax
add si, 4	;отнимаем элементы 5-го столбца
mov bx, mas[si]
sub bx, ax
sub si, 4
mov mas[si], bx ;Сохраняем результат в 3-й столбец.
add si, 12
Loop adding 	;Переходим к следующей паре.
mov ah, 4ch
int 21h
c_s ends
end begin

1    1  
2    3
5    8
D    15
22   37
59   90
E9   179  6*2*2 + 1*2
262  3DB
63D  A18

