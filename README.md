# Monty

`monty` is an interpreter of Monty ByteCodes files, which is a scripting language just like Python.

## About the Monty language
This is a language that contains specific instructions to manipulate data information (stacks or queues), where each instruction (*called opcode*) is sended per line. Files which contains Monty byte codes usually have the `.m` extension.

Example (`file.m`):
```bash
$ cat file.m
# Pushing element to the stack
push 0
push 1
push 2
# Printing all elements
pall
push 3
push 4
pop
```

## Technologies
* Interpreter was written with C language
* C files are compiled using `gcc 4.8.4`
* C files are written according to the C90 standard
* Tested on Ubuntu 14.04 LTS

## Usage
To compile all files:

```bash
$gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o monty
```

The **synopsis** of the interpreter is the following:

```bash
$ ./monty [filename]
```

To run the interpreter:

```bash
$ ./monty file.m
2
1
0
0
3
2
1
```

## Features
### Opcodes
`monty` executes the following opcodes:

| Opcode | Description |
| -------- | ----------- |
| `push` | Pushes an element to the stack |
| `pall` | Prints all the values on the stack |
| `pint` | Prints the value at the top of the stack |
| `pop` | Removes the top element of the stack |
| `swap` | Swaps the top two elements of the stack |
| `add` | Adds the top two elements of the stack |
| `nop` | Doesn't do anything |

Comments, indicated with `#`, are not executed by the interpreter.

### Return value
When there is no errors, `monty` returns `0`. Otherwise, returns `1`

## Authors
* Youssef Abid [GitHub](https://github.com/yousseffabid)
* Jebeniani Aymen [GitHub](https://github.com/Jebeniani)
