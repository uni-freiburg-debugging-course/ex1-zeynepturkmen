[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/3MmVbb7f)
# Debugging 24/25 Exercise 1

Detailed instructions are in the exercise sheet. Following are your checkpoints:

- [x] Implement parser and evaluator
- [x] Implement a fuzzer
- [x] Generate *lots* of random instances with your fuzzer. Your evaluator and z3 must return the same result on generated instances
- [x] Provide detailed build instructions for your code so that we can evaluate it

## How to run the code

The code was written in C++ so we need the g++ compiler for it.

To start the code, first, compile both documents. Begin by compiling the fuzzer:

```sh
$ g++ fuzzer.cpp -o fuzzer
```
Next, compile the parser and evaluator:

```sh
$ g++ parser_and_evaluator.cpp -o parser_and_evaluator
```

Once both are compiled, generate a set of random expressions into a text file by running the fuzzer:

```sh
$ ./fuzzer
```

This will create an output text file named 'input.txt' that contains several 'simplify' expressions.

Afterwards, use the following command to test the generated expressions against the Z3 solver and the parser. (this is basically the command in the assignment document.)

```sh
$ ./z3 input.txt > res1 && ./parser_and_evaluator input.txt > res2 && cmp res1 res2; echo $?
```
