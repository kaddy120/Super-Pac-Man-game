# Super-Pac Man

An implementation of [Super-Pac Man](https://en.wikipedia.org/wiki/Super_Pac-Man) game in `C++` for Software Development II - Course Project. [Super-Pac Man](https://en.wikipedia.org/wiki/Super_Pac-Man) is a spin off of the classic [Pac-Man](https://en.wikipedia.org/wiki/Pac-Man) game released in 1980. Its gameplay mechanics were altered radically from the first two entries into the Pac-Man series -- instead of eating dots, the player is required to eat keys in order to open doors, which open up sections of the maze that contain what in earlier games were known as “fruits”, the basic items that must be cleared. Once all the food is eaten, the player advances to the next level, in which the food is worth more points.

<iframe width="560" height="315" src="https://www.youtube.com/embed/JrmWflmov2U?si=36SLR-1kqGtmkUww" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

## Build and testing the source code
This code is developed in Windows machine, but I have since switched to
Linux, and this code have compiled in both system, Windows and Linux, without modifying the code. The problem is that as I'm writing the `README`, I'm on Linux, So I'll only provide a thorough guide for compiling and testing the source code in `Linux`. 

##### Prerequisite:

`make`, `C++ complier, i.e g++`, `SFML library`, `Doctest`

### Installation in Debian system

```bash
 $ sudo apt update
```
Install all the prerequisites:
```bash
 $ sudo apt-get install make g++ libsfml-dev doctest-dev 
```

To verify that you have installed `make` and `g++`, run:
```bash
 $ make -v 
```
```bash
 $ g++ -v
```
And to check the list files installed to your system from package-name
```bash
 $ dpkg -L <package-name>
```
Then check `libsfml-dev` and `doctest-dev` using the above command.

### Build
Change directory to the source code:
```bash
 $ cd game-source-code/
```

Build the game source code:
```
 $ make
```
If your machine has multiple core processor,  you can speed the build process by running `make` in multiple threads. To run `make` in N threads, use:
```bash
 $ make -jN
```
Run the game executable:
```
 $ ./game.out
```

### Testing
The code is thorough tested using Unit tests to 
limit regression bugs during development. The test are in `test-source-code` directory.

Change directory to the tests 
```bash
 $ cd test-source-code/
```

Build the tests
```bash
 $ make
```
run the tests executable:
```
 $ ./test.out
```

## Download the game

- Windows, [64-bit binaries](https://github.com/kaddy120/Super-Pac-Man-game/releases/download/v1.0/super-pac-man-windows.zip).
- Linux, [x64-bit binaries](https://github.com/kaddy120/Super-Pac-Man-game/releases/download/v1.0/super-pac-man-linux.zip).
