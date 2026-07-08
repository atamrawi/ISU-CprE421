section .data
msg db 'Owned!!',0xa
section .text
global _start
_start:
 
;write(int fd, char *msg, unsigned int len)
mov eax,4       ; kernel write command
mov ebx,1       ; set output to stdout
mov ecx,msg     ; set msg to Owned!! string
mov edx,8       ; set parameter len=8 (7 characters followed by newline character)
int 0x80        ; triggers interrupt 80 hex, kernel system call
 
;exit(int ret)
mov eax,1       ; kernel exit command 
mov ebx,0       ; set ret status parameter 0=normal
int 0x80        ; triggers interrupt 80 hex, kernel system call