# Data structures

My personal implementation of common data structures

## Requirements

You'll need **SCons** to build it. You can install it with **pip**, **brew**, or almost any package manager.

Otherwise you can build the following Docker image

```bash
docker build -t data-structures .
```

Then run the executables

```bash
docker run -it data-structures ./linked_list
```

```bash
docker run -it data-structures ./dynamic_array
```

```bash
docker run -it data-structures ./stack
```

## Usage

Compile the source

```bash
scons -j3
```

Run the binaries

```bash
./linked_list
```

```bash
./dynamic_array
```

```bash
./stack
```