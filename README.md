# 0x19. C - Stacks, Queues - LIFO, FIFO

## Description
The goal of this project is to create an interpreter for Monty ByteCodes files.


## General Requirements
- Allowed editors: `vi, vim, emacs`
- All C files are compiled on `Ubuntu 20.04 LTS` using `gcc, using the options -Wall -Werror -Wextra -pedantic -std=c89`
- All files ends with a new line
- A `README.md` file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using `betty-style.pl` and `betty-doc.pl`
- a maximum of one global variable is allowed
- No more than 5 functions per file
- the use the C standard library is allowed
- The prototypes of all your functions should be included in your header file called `monty.h`
- All header files should include guards

## Compilation & Output
- the code are compiled this way:
```bash
 gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```
- All output are printed on `stdout`
- All error message are printed on `stderr`

## The Monty language
`Monty 0.98` is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. 

#Monty byte code files

Files containing Monty byte codes usually have the `.m` extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```bash
Wills@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
Wills@ubuntu:~/monty$
```
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:
```bash
Wills@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
Wills@ubuntu:~/monty$
The monty program
```

# - Usage: `monty file`

-- where `file` is the path to the file containing Monty byte code
- If the user does not give any file or more than one argument to your program, print the error message `USAGE: monty file`, followed by a new line, and exit with the status `EXIT_FAILURE`
- If, for any reason, it’s not possible to open the file, print the error message `Error: Can't open file <file>`, followed by a new line, and exit with the status `EXIT_FAILURE`
-- where `<file>` is the name of the file
- If the file contains an invalid instruction, print the error message `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with the status `EXIT_FAILURE`
-- where is the line number where the instruction appears.
-- Line numbers always start at 1
- The monty program runs the bytecodes line by line and stop if either:
-- it executed properly every line of the file
-- it finds an error in the file
-- an error occured
- If you can’t malloc anymore, print the error message `Error: malloc failed`, followed by a new line, and exit with status `EXIT_FAILURE`.
- You have to use `malloc` and `free` and are not allowed to use any other function from `man malloc` (realloc, calloc, …)

## Author

Savwede Godswill Eguolor [GitHub](https://github.com/Savwede)
