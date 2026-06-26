# Project26_3

This project implements a simple Unix shell called `wish`.

The shell supports:
- Running external programs using `execv`
- Built-in commands: `exit`, `cd`, `path`
- Input from interactive mode (terminal) and batch files
- Output redirection using `>`
- Parallel execution using `&`

---

## Build

```bash
make
```

# wish.c

## Interactive mode:
```bash
./wish
```
Result:
```
wish> ls
wish> cd ..
wish> exit
```

## Batch mode:
```bash
./wish batchfile.txt
```
Result:
```
third line
second line
first line
```

## Features:
### 1. Built-in commands
exit
Terminates the shell.
```
wish> exit
```
cd
Changes the current directory.
```
wish> cd /usr/bin
```
path
Sets the search path for executables.
```
wish> path /bin /usr/bin
```
### 2. External commands
Runs programs found in configured paths.
```
wish> ls
wish> echo hello
```
### 3. Output redirection (>)
Redirects stdout and stderr to a file.
```
wish> ls > out.txt
```
If the file does not exist, it is created.
4. Parallel execution (&)
Runs multiple commands concurrently.
```
wish> sleep 3 & echo hello
```

### Edge cases / Error handling
Run the provided test suite:
```bash
./test-wish.sh
```
