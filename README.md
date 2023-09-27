# 42 get_next_line
A function which allows to read a line from a file descriptor

## Description
Function should read a line ending with `\n` from file descriptor. If there is nothing to read or there is an error function returns null. 
`BUFFER_SIZE` can be specified either when compiling or in the header file. If `BUFFER_SIZE` is not specified function will use the value from header file.

## Bonus
Bonus part is to make a function using only one static variable and also to make the function manage multiple file descriptors at the same time.
Bonus files are absolutely same as mandatory ones. It just was a task to separate them.

## How to use
To use the function you shoud just copy source and header files to the project and include `get_next_line.h` to the file you want to use the function in.
Each time you call the function it will return the read line.
