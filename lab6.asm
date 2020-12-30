;lea di, pt1
;lea si, [di].string
;mov cx, 6
;m1:
;lods
;Loop m1

;Зарезервируем в Stack 20 эл-в
s_s segment 
db 100 dup('0')
s_s ends

Person STRUC

    ;Карта, пол, год рождения, даты нач/конц лечения.
    nCard   dw  0
    sex     db  ?
    bYear   dw  0
    dtAd    db  '  /  /  '
    dtLv    db  '  /  /  '

Person ENDS

d_s SEGMENT

    ;Определяем данные 3-х пациентов.
    ;pt1 Person <44,'m',1990, '10/10/19','30/10/19'>
    ;pt2 Person <45,'m',1990, '10/10/19','31/10/19'>
    ;pt3 Person <46,'f',1995, '23/10/19','31/10/19'>

    mas Person <44,'m',1990, '10/10/19','30/10/19'>, <45,'m',1990, '10/10/19','31/10/19'>, <46,'f',1995, '23/10/19','31/10/19'> 

    ;Конкретные даты нач/конц лечения для поиска.
    dtAdSrch    db '10/10/19', '$'
    dtLvSrch    db '31/10/19', '$'
    dtBYearSrch dw 1990,       '$'
    nCardSrch   dw 45,         '$'

    ;Результаты выполнения программы:
    task1 db 0
    task2 db 0
    task3 dw 0
    task4 db 0

d_s ENDS


c_s SEGMENT
ASSUME ds:d_s,cs:c_s,ss:s_s

    ;Скрыть внешний цикл
    pushcx PROC NEAR

    RET
    pushcx ENDP

BEGIN: ; начало программы
mov ax,d_s
mov ds,ax
xor ax,ax

;1)Количество пациентов поступивших 10/10/19?
;Внешний цикл для 3-х пациентов (pt1-pt2) -> call
;Внутренний цикл для проверки 8 символов даты

    ;Передаём в al данные о 1-м пациенте
    lea di, mas[0]
    mov cx, 3
nxtPt:
    push cx

    ;Передаём дату пациента
    mov cx, 8

    lea si, [di].dtAd
rdNxt:
    lodsb
    mov bl, al
    xor ax, ax
    push si

    ;Кастыль для работы со второй датой
    cmp dl, 0
    jz cont   ;=
    mov si, bp
    jmp more

    ;Передаём дату для поиска
cont:
    lea si, dtAdSrch
more:
    lodsb
    mov bp, si ;Сохраняем новую si

    ;Сравниваем полученные даты
    cmp al, bl
    jz  same
    jmp difer

    ;Даты совпали - +1 совпадение
    same:
    inc dl

    ;Если совпали все 8 цифр
    cmp dl, 8
    je yes
    jmp no

    ;Мы нашли искомого пациента, ищем след.
    yes:
    inc dh ;Пациентов +1 совпало
    jmp difer

    ;Мы не нашли пациета, читаем след. запись
    no:
    jmp difer

difer:
    pop si
    Loop rdNxt

    ;Проверяем дату следующего пациента
    pop cx
    add di, type Person
    xor dl, dl
    Loop nxtPt

    mov task1, dh 

;2)Количество женщин, выписанных 31/10/19?
;Внешний цикл для 3-х пациентов (pt1-pt2) -> call
;Внутренний цикл для проверки поля 'sex'

    ;Нулируем регистры
    xor ax, ax
    xor bx, bx
    xor dx, dx

    ;Передаём в al данные о 1-м пациенте
    lea di, mas[0]
    mov cx, 3
nxtPt1:
    push cx

    ;Передаём дату выписки пациента
    mov cx, 8

    lea si, [di].dtLv
rdNxt1:
    lodsb
    mov bl, al
    xor ax, ax
    push si

    ;А может это и не костыль, а часть проги?
    cmp dl, 0
    jz cont1
    mov si, bp
    jmp more1

    ;Передаём даты выписки для поиска
cont1:
    lea si, dtLvSrch
more1:
    lodsb
    mov bp, si

    ;Сравниваем полученные даты
    cmp al, bl
    jz same1
    jmp difer1

    ;Цифры дат совпали - +1 совпадения
    same1:
    inc dl

    ;Если совпали все 8 цифр
    cmp dl, 8
    je wom1
    jmp no1

    ;Проверяем, является ли пациент женщиной
    wom1:
    mov bl, 'f'
    mov al,[di].sex
    cmp bl, al
    je yes1
    jmp no1

    ;Мы нашли искомого пациента, ищем след.
    yes1:
    inc dh ;Пациентов +1 совпало
    jmp difer1

    ;Мы не нашли пациета, читаем след. запись
    no1:
    jmp difer1

difer1:
    pop si
    Loop rdNxt1

    ;Проверяем дату следующего пациента
    pop cx
    add di, type Person
    xor dl, dl
    Loop nxtPt1

    mov task2, dh 

;3)Год рождения пациента с номером карты (45)?
;Внешний цикл для 3-х пациентов (pt1-pt2)
;Внутренний цикл для проверки номера карты

    ;Нулируем регистры
    xor ax, ax
    xor bx, bx
    xor dx, dx

    ;Передаём в al данные о 1-м пациенте
    lea di, mas[0]
    mov cx, 3
nxtPt2:
    push cx

    ;Передаём дату выписки пациента
    mov cx, 2

    lea si, [di].nCard
rdNxt2:
    lodsb
    mov bl, al
    xor ax, ax
    push si

    ;Не кастыль, а фича!
    cmp dl, 0
    jz cont2
    mov si, bp
    jmp more2

    ;Передаём даты выписки для поиска
cont2:
    lea si, nCardSrch
more2:
    lodsb
    mov bp, si

    ;Сравниваем полученные даты
    cmp al, bl
    jz same2
    jmp difer2

    ;Цифры дат совпали - +1 совпадения
    same2:
    inc dl

    ;Если совпали все 2 цифры
    cmp dl, 2
    je year2
    jmp no2

    ;Проверяем, является ли пациент женщиной
    year2:
    mov bl, 45
    mov ax,[di].nCard
    cmp bl, al
    je yes2
    jmp no2

    ;Мы нашли искомого пациента, ищем след.
    yes2:
    inc dh ;Пациентов +1 совпало

        ;Записываем год рождения
        lea si, [di].bYear
        lodsw
        mov task3, ax

    ;Мы не нашли пациета, читаем след. запись
    no2:
    jmp difer2

difer2:
    pop si
    Loop rdNxt2


    ;Проверяем дату следующего пациента
    pop cx
    add di, type Person
    xor dl, dl
    Loop nxtPt2 


    ;4)Количество мужчин 1990 года рождения?
    ;Внешний цикл для 3-х пациентов (pt1-pt2)
    ;Внутренний цикл для проверки года рождения и поля 'sex'

    ;Нулируем регистры
    xor ax, ax
    xor bx, bx
    xor dx, dx

    ;Передаём в al данные о 1-м пациенте
    lea di, mas[0]
    mov cx, 3
nxtPt3:
    push cx

    ;Передаём дату выписки пациента
    mov cx, 2

    lea si, [di].bYear
rdNxt3:
    lodsb
    mov bl, al
    xor ax, ax
    push si

    ;Не кастыль, а фича!
    cmp dl, 0
    jz cont3
    mov si, bp
    jmp more3

    ;Передаём даты выписки для поиска
cont3:
    lea si, dtBYearSrch
more3:
    lodsb
    mov bp, si

    ;Сравниваем полученные даты
    cmp al, bl
    jz same3
    jmp difer3

    ;Цифры дат совпали - +1 совпадения
    same3:
    inc dl

    ;Если совпали все 8 цифр
    cmp dl, 2
    je man3
    jmp no3

    ;Проверяем, является ли пациент женщиной
    man3:
    mov bl, 'm'
    mov al,[di].sex
    cmp bl, al
    je yes3
    jmp no3

    ;Мы нашли искомого пациента, ищем след.
    yes3:
    inc dh ;Пациентов +1 совпало
    jmp difer3

    ;Мы не нашли пациета, читаем след. запись
    no3:
    jmp difer3

difer3:
    pop si
    Loop rdNxt3

    ;Проверяем дату следующего пациента
    pop cx
    add di, type Person
    xor dl, dl
    Loop nxtPt3

    mov task4, dh 


mov ah,4ch
int 21h
c_s ends
end begin