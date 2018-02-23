# EECE-437-Assignment 1

## How to run
---

### On OSX, linux:
Navigate to the project directory /assignment1
To run the test file, enter the following to execute the test executable:
```shell
bin/run
```
To re-build from source, run:
```shell
make clean
make
```


This will rebuild the project from the source files in /src, and output the executable to bin/ calling it run.

### On Windows:
If make is not installed, the easy way is to install make and run the commands mentioned above.

### Cross-platform:
To build yourself using g++:
```
g++ *.cpp *.h
```
(Might need manual entry on windows)
