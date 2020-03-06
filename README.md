<!-- Required extensions: pymdown.betterem, pymdown.tilde, pymdown.emoji, pymdown.tasklist, pymdown.superfences -->

# OpenLibs

## Description

OpenLibs is a framework which integrate some libraries for simple or particular task.

## Libraries

Libraries who integrates in OpenLibs are:

* BinRes: Read and manage binary ressources
* MArgs: Get main arguments more simply
* StrTime: Represent time in ``` std::string ```
* Utils: Some utils functions
* Types: Use different types
* File: Read, write and manage Log and Conf files
* DataBase: Read, write and manage locale sqlite3 database
* OCL: Cryptographic lib

## Libraries description
### BinRes

BinRes permit to read and manage binary ressources who integrates in program.
It use pointers for represent ressource (It not necessary to know it for use lib)

### MArgs

MArgs load and store main arguments and permit to read these in ``` std::string ```.

### StrTime

StrTime get a timestamp and use ``` strftime() ``` to represent the time in system language.

### Utils

Utils is a simple library for utils functions, for exemple converting char to ascci byte.

### Types

Types include typedef for fixed size types (``` BYTE ``` => ``` uint8_t ```), 
bitwise operations and converting functions (``` std::string ``` <=> types)

### File

File get a log or conf file and store there entity for permit read, write and save these.

### DataBase

DataBase use sqlite3 to send command to a locale database (Insert, Select, ..)

### OCL

OCL is OPEN Cryptographic Library. It include these algorithms:

* SHA256
* Blowfish
* RSA
* Random generator (Entropy => SHA256 => DWORD cryptographic pseudo-random numbers)


## Coding phylosophy

OpenLibs was coding to respect OPEN Code Standard (a code phylosophy invented by me) who described in pdf sheet in doc directory after install framework.