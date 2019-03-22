# brainfuckCompiller

## Compilation

```
make
```

## Usage

```
bf <filename.b>
```

Available switches:
--int   Displays numbers from cells instead of the
corresponding ASCII characters
--ext   Includes the interpretation of my extended brainfuck
--dev   After each instruction, the program stops, displays the contents of the current cell and instruction, then waits for any key to be pressed. To finish press 'q'

### Normal brainfuck

Available chars: -+[]<>,.

### My extended bf = Normal brainfuck plus:

- stack I/O operation

  - push value from current cell ':'
  - get value from stack(and pop) ';'

- Functions

  - Function have this same stack what is your, so you can passed the parameters and get result from stack

  - Functions have another than program memory

  - Executing function is like this:

    ```(rd);.```

    After this operation will be printed random char (or number, if passed --int switch)

    Predefined functions:

    - rd - set on stack one random number
    - exit - pop from stack one number and exit from the program. Status is equal to passed parameter

  - Declare yourself functions is like

    ```"foo"{;++:}```

    You declare function, when you invoke this to top value on stack will be added 2

    To invoke this function you can do this:

    ```+:(add2);.```

    on screen will be printed '3' (if passed --int switch)

- Arithmetic

  -  modulo, divide and multiply operation (%/*). Execute operation e.g. multiply with value from current cell by __one next digit__. E.g.  after this operation in currect cell will be 4

    ```++*2```
