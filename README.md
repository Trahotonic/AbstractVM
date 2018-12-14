# AbstractVM

## Description
AbstractVM is a machine that uses a stack to compute simple arithmetic expressions.<br />
These arithmetic expressions are provided to the machine as basic assembly programs.

### The assembly language example:
```diff
; -------------
; example.avm -
; -------------

push int32(42)
push int32(33)

add

push float(44.55)

mul

push double(42.42)
push int32(42)

dump

pop

assert double(42.42)

exit
```

### The assembly language description:
The language of AbstractVM is composed of a series of
instructions, with one instruction per line. However, AbstractVM’s assembly language
has a limited type system, which is a major difference from other real world assembly
languages.<br />
• Comments: Comments start with a ’;’ and finish with a newline. A comment can
be either at the start of a line, or after an instruction.<br /><br />
• push v: Pushes the value v at the top of the stack. The value v must have one of
the following form:<br />
◦ int8(n) : Creates an 8-bit integer with value n.<br />
◦ int16(n) : Creates a 16-bit integer with value n.<br />
◦ int32(n) : Creates a 32-bit integer with value n.<br />
◦ float(z) : Creates a float with value z.<br />
◦ double(z) : Creates a double with value z.<br /><br />
• pop: Unstacks the value from the top of the stack. If the stack is empty, the
program execution must stop with an error.<br />
• dump: Displays each value of the stack, from the most recent one to the oldest
one WITHOUT CHANGING the stack. Each value is separated from the next one
by a newline.<br /><br />
• assert v: Asserts that the value at the top of the stack is equal to the one passed
as parameter for this instruction. If it is not the case, the program execution must
stop with an error. The value v has the same form that those passed as parameters
to the instruction push.<br /><br />
• add: Unstacks the first two values on the stack, adds them together and stacks the
result. If the number of values on the stack is strictly inferior to 2, the program
execution must stop with an error.<br /><br />
• sub: Unstacks the first two values on the stack, subtracts them, then stacks the
result. If the number of values on the stack is strictly inferior to 2, the program
execution must stop with an error.<br /><br />
• mul: Unstacks the first two values on the stack, multiplies them, then stacks the
result. If the number of values on the stack is strictly inferior to 2, the program
execution must stop with an error.<br /><br />
• div: Unstacks the first two values on the stack, divides them, then stacks the result.
If the number of values on the stack is strictly inferior to 2, the program execution
must stop with an error. Moreover, if the divisor is equal to 0, the program execution
must stop with an error too. Chatting about floating point values is relevant a this
point. If you don’t understand why, some will understand. The linked question is
an open one, there’s no definitive answer.<br /><br />
• mod: Unstacks the first two values on the stack, calculates the modulus, then
stacks the result. If the number of values on the stack is strictly inferior to 2, the
program execution must stop with an error. Moreover, if the divisor is equal to 0,
the program execution must stop with an error too. Same note as above about fp
values.<br /><br />
• print: Asserts that the value at the top of the stack is an 8-bit integer. (If not,
see the instruction assert), then interprets it as an ASCII value and displays the
corresponding character on the standard output.<br /><br />
• exit: Terminate the execution of the current program. If this instruction does not
appears while all others instruction has been processed, the execution must stop
with an error.<br /><br />

## Execution
Machine is able to run programs from a file passed as a parameter and from the standard input.
When reading from the standard input, the end of the program is indicated by the special symbol ";;" otherwise absent.

### Examples:
```diff
./abstractVM
push int32(2)
push int32(3)
add
assert int32(5)
dump
exit
;;
5
```
```diff
cat sample.avm
; -------------
; sample.avm -
; -------------
push int32(42)
push int32(33)
add
push float(44.55)
mul
push double(42.42)
push int32(42)
dump
pop
assert double(42.42)
exit
./abstractVM sample.avm
42
42.42
3341.25
```
```diff
./abstractVM
pop
exit
;;
Line 1 : Error : Cannot pop - Stack is empty
```

## Visualization
Program can be run with -v flag to vizualize calculations using ncurses library.
```diff
 ---------------------------------------------------------------------------------------------------
|              STACK              |                          NEXT OPERATION                         |
|---------------------------------|-----------------------------------------------------------------|---
|int8   65                        |exit                                                             | A |
|                                 |-----------------------------------------------------------------|---
|                                 |print                                                            |
|                                 |add                                                              |
|                                 |push int8(25)                                                    |
|                                 |push int8(40)                                                    |
|                                 |                                                                 |
|                                 |                                                                 |
|                                 |                                                                 |
|                                 |                                                                 |
|                                 |                                                                 |
|                                 |                                                                 |
|                                 |                                                                 |
|                                 |                                                                 |
|                                 |                                                                 |
|                                 |                                                                 |
|                                 |                                                                 |
 ---------------------------------------------------------------------------------------------------
                                                                    'ENTER' - continue; 'ESC' - exit
```

## Installation
Run `make` in project directory to compile executable file called abstractVM.<br />
Run `make clean` to delete object files.<br />
Run `make fclean` to delete object files and executable.
