extern printf 
extern scanf 

global main
section .text
 
main:
    push rbp
    mov rbp, rsp
    sub rsp,16

    xor eax,eax
    mov rdi, input_integer    
    call printf 

    xor eax,eax
    mov rdi, int_input  
    mov  rsi, number 
    call scanf

    xor eax,eax
    mov  rdi, output_int
    mov rsi, [number]
    call printf

    xor eax,eax
    mov rdi, input_string    
    call printf 

    xor eax,eax
    mov rdi, string_input  
    mov rsi, stringu     
    call scanf       

    xor eax,eax
    mov rdi, output_string  
    mov rsi, stringu 
    call printf 
    mov eax,0
 
    add rsp,16
    leave 
    ret   


section .data
    input_string db "Enter input String:  ", 0  
    string_input db "%s", 0 
    output_string db "%s ",10,0  
    input_integer : db "Enter input integer: ",0
    output_int : db "%d",10,0
    int_input :db "%d",0    
section .bss
    stringu resb 10000    
    number resb 4