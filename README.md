# Assembly-Interpreter
### Version 4.0.0
This project is an assembly language interpreter in a 32-bit version,
The interpreter is very friendly and suitable for beginners who want to feel assembly language and understand the meaning of registers and the work of the processor.

### Additional Features:
Stack, Flags register, Interrupts, Labels.

# Commands 
### Available commands:
- help - print the commands
- opc \ opcodes - print all the available instructions
- mem - print the registers values and names
- exit - exit from the Interpreter

# Opcodes
### Available Opcodes:
```
MOV, ADD, SUB, MUL, DIV, INC,
DEC, OR, AND, XOR, NOT, NOP,
SHL, SHR, ROL, ROR, PUSH, POP,
CMP, JNZ, JZ, JNE, JE, JNS,
JS, JNO, JO, JNP, JP, JAE, JBE,
STI, CLI, XCHG, LOOP
```

# Registers
### Available Registers:
```
EAX, AX, AL,
EBX, BX, BL,
ECX, CX, CL,
EDX, DX, DL
ESP, EBP
```

# Flag Register
### Available Flags:
```
CF, ZF, SF, OF,
PF, AF, IF, DF
```
