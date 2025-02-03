## 1. addi sp, sp, -16  
Type: I-Type

Opcode: 0010011 (for addi)  
rd: sp = x2 = 00010 
funct3: 000 
rs1: sp = x2 = 00010    
imm[11:0]: -16 = 1111 1111 0000 (two’s complement)  
Binary: 11111111000000010000000100010011    
Hex: ff010113   


## 2. li a1, 10
Type: I-Type

Opcode: 0010011 
rd: a1 = x11 = 01011    
funct3: 000 
rs1: zero = x0 = 00000  
imm[11:0]: 0000 0000 1010   
Binary: 00000000001000000000010110010011    
Hex: 00a00593   


## 3. lui a0, 0x21    
Type: U-Type

Opcode: 0110111 (for lui)   
rd: a0 = x10 = 01010    
imm[31:12]: 0x21 = 0000 0000 0000 0010 0001   
Binary: 00000000000000100001010110110111    
Hex: 00021537   


## 4. ld ra, 8(sp)
Type: I-Type

Opcode: 0000011 (for ld)    
funct3: 011 
rd: ra = x1 = 00001 
rs1: sp = x2 = 00010    
imm[11:0]: 0000 0000 1000 (8 in binary)   
Binary: 00000000010000001011000010000011    
Hex: 00813083   


## 5. auipc a2, 0x14
Type: U-Type

Opcode: 0010111  
rd: a2 = x12 = 01100  
imm[31:12]: 0x14 = 0000 0000 0000 0001 0100  
Binary: 00000000000000010100001100010111  
Hex: 00014617  


## 6. sub a2, a2, a0
Type: R-Type

Opcode: 0110011  
rd: a2 = x12 = 01100  
funct3: 000  
rs1: a2 = x12 = 01100  
rs2: a0 = x10 = 01010  
funct7: 0100000  
Binary: 01000000101001100000001100110011  
Hex: 40a60633  

## 7. jal ra, 1036c <memset>
Type: J-Type

Opcode: 1101111  
rd: ra = x1 = 00001  
imm[20|10:1|11|19:12]: 254 = 0010 0101 0100  
Binary: 00000010010101000000000011101111  
Hex: 254000ef  


## 8. auipc a0, 0x0
Type: U-Type

Opcode: 0010111  
rd: a0 = x10 = 01010  
imm[31:12]: 0000 0000 0000 0000 0000  
Binary: 0000000000000000000001010010111  
Hex: 00000517  


## 9. lw a0, 0(sp)
Type: I-Type

Opcode: 0000011  
rd: a0 = x10 = 01010  
funct3: 010  
rs1: sp = x2 = 00010  
imm[11:0]: 0000 0000 0000  
Binary: 00000000000000010010001000000011  
Hex: 00012503  


## 10. jal ra, 100b0 <main>
Type: J-Type

Opcode: 1101111  
rd: ra = x1 = 00001  
imm[20|10:1|11|19:12]: f79 = 1111 0111 1001  


## 11. addi sp, sp, -48
Type: I-Type

Opcode: 0010011     
rd: sp = x2 = 00010 
funct3: 000 
rs1: sp = x2 = 00010    
imm[11:0]: -48 = 1111 1101 0000 (two’s complement)  
Binary: 11111101000000010000000100010011    
Hex: fd010113   


## 12. sd s0, 32(sp)
Type: S-Type

Opcode: 0100011 
funct3: 011 
rs1: sp = x2 = 00010    
rs2: s0 = x8 = 01000    
imm[11:5]: 0010000 (upper 7 bits of 32)   
imm[4:0]: 00000 (lower 5 bits of 32)    
Binary: 00100000100000010011000000100011    
Hex: 02813023   


## 13. sd s1, 24(sp)
Type: S-Type

Opcode: 0100011 
funct3: 011 
rs1: sp = x2 = 00010    
rs2: s1 = x9 = 01001    
imm[11:5]: 0011000 (upper 7 bits of 24)   
imm[4:0]: 11000 (lower 5 bits of 24)    
Binary: 00001001000100010011110000100011    
Hex: 00913c23   


## 14. sd s2, 16(sp)
Type: S-Type

Opcode: 0100011    
funct3: 011 
rs1: sp = x2 = 00010    
rs2: s2 = x18 = 10010   
imm[11:5]: 0000001 (upper 7 bits of 16)   
imm[4:0]: 00000 (lower 5 bits of 16)    
Binary: 00000010010000010011000010100011    
Hex: 01213823   

Binary: 11110111100100000000000011101111  
Hex: f79ff0ef  


## 15. blez a0, 1022c
Type: B-Type

Opcode: 1100011 (for branch)
Funct3: 100
rs1: a0 = x10 = 01010
rs2: zero = x0 = 00000
imm[12|10:5|4:1|11]: 1022c - 101b4 = 78 (offset)
Binary: 00000110100001010000101101100011
Hex: 06a05c63
