## Super-Pac Man

Software Development II - Course Project

When I first wrote this code I was using windows. But I have now switched to
linux, which means that this code can be complite for both, Linux and Windows.
the problem is that as I'm writing this `README`, I'm on Linux, So I will only
gave a guideline on how to run it on windows without going deep in details.
I hope that I will find time in the future to write a readme that caters for
both operating system.

## Prerequisite to build the code

`make`, `C++ complier, i.e g++`, `SFML library`, `Doctest`

### Prerequisite installation

```bash
 $ sudo apt update
```

check if you have `make installed`

```bash
 $ make -v
```

```bash
 $ g++ -v
```

if you don't get a version number, that make their are not installed. Install
install `g++` and `make` by running:

```bash
 $ sudo apt install g++ make
```

You can get the latest version of SFML from their [download page](), or install from the package manager by running:

```bash
 $ sudo apt install libsfml-dev
```

Install `Doctest` for C++

```bash
 $ sudo apt install doctest-dev
```

## A readme for building the project

## side notes

- **SFML**:
  SFML includes are located at `/usr/include/SFML`
  SFML shared libraries are located at `/usr/lib/x86_64-linux-gnu`

- **Doctest**
  To locate a shared libraries in Ubuntu, type

```bash
 $ dpkg -L package_name
```

i.e

```bash
 $ dpkg -L doctest-dev
```

```bash
 # output
 /usr/include/doctest
```

```C
/* main.cpp */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

int fact(int n) {
    return n <= 1 ? 1 : n * fact(n - 1);
}

TEST_CASE("testing the factorial function") {
    CHECK(fact(1) == 1);
    CHECK(fact(2) == 2);
    CHECK(fact(3) == 6);
    CHECK(fact(10) == 3628800);
}
```

run test:

```bash
 $ g++ -o tests main.cpp -I/usr/include/doctest
```

then run:

```bash
 $ ./tests
```
Windows executable are located in:
`/home/kaddy120/workspace/student number 1416262 - student number 1607360/executables`
