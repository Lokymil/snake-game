# Snake

Snake game made in C++in order to learn this language.

## Installation

To make it run, you will have to install:

- [gcc](https://gcc.gnu.org/)
- [SDL 2](https://www.libsdl.org/)
- [SDL Font](https://www.libsdl.org/projects/SDL_ttf/)

## Run

To start, use the following command:

```sh
make
#----- OR -----
make start
```

## Commands

### > `make build`

Build executable file without running it. Generated file is `out/snake`.

### > `make debug`

Start the program with `gdb` to have debug mode enabled.

### > `make valgrind`

Start the program with valgrind to inspect memory. Valgrind log is written in `log/valgrind-out.txt` file.

### > `make clear`

Remove all generated files including :

- `.o` files
- executable file
- valgrind log
