# Froot
Static File generation made simple

This tool is the result of some frustration with making static webpages.
It's a command-line-tool which parses files, including the content of referenced files, and outputs the result to stdout.

Referencing a file works like this:

>>>"./includes/snippets/header.html"
>>>"includes/snippets/header.html"
>>>"../snippets/header.html"

## Functions
- Include files in files

## Unfinished Business, ToDo-s
- Needs to be tested with very large files
- Clarify/Check behavior for recursive includes, maybe prohibit going up a folder

## Build

### MacOS, Linux
gcc -froot_macos_linux.c -o froot

### Windows
(ToDo)

## Usage on MacOS, Linux

### To see the output in the terminal
./froot ./relative/path/to/sourcefile.html

### To save the output in a file
./froot ./relative/path/to/sourcefile.html > ./path/to/targetfile.html

## Usage on Windows

### To see the output in the terminal
froot.exe relative\path\to\sourcefile.html

### To save the output in a file
froot.exe relative\path\to\sourcefile.html > path\to\targetfile.html




