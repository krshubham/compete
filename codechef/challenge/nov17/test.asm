data segment
text db 'hellod world'
data ends

code segment
assume cs:code,ds:data
begin:  mov ax,data
        mov ds,ax
        mov es,ax
        mov dx,text
        mov ah,09h
        int 21h
        mov ah,4ch
        int 21h
        code ends
        end begin