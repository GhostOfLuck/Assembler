.486
public Maxsum
.model flat
.code
Maxsum proc stdcall a:dword, b:dword
local k: dword, n: dword

  xor eax, eax
  xor edx, edx
  mov ebx, a
  mov n, 0
  mov k, ebx
  inc b
start:
  cmp ebx, b
  je end1
  call Sumnum
  cmp eax, n
  jl s1
  mov n, eax
  mov k, ebx
s1:
  inc ebx
  jmp start

end1:
  mov eax, k

ret 
Maxsum endp



Sumnum proc stdcall
  xor ecx, ecx
  mov edi, 10
  mov eax, ebx
cycle:
  cdq
  idiv edi
  add ecx, edx
  cmp eax, 0
  je endsum
  jmp cycle
endsum:
  mov eax,ecx
ret
Sumnum endp


end