
# Coloricious

_A tool to colorize terminal output_

## Description

This tool is very roughly a clone of `lolcat`, but with fewer dependencies and
simpler, more predicative behavior. It is written in C and does not require any
external libraries or other programs.

## Usage

`coloricious` takes input from `stdin` and writes it colorized to `stdout`.
The saturation, brightness, and period can be controlled with the command-line
flags `-s`, `-v`, and `-p`.

### Examples

```
$ cat /etc/apt/sources.list | coloricious
$ figlet "RAINBOW" | coloricious
```

## Installation

### Prerequisites

This project is built using `meson` and `ninja`.

### Build

1. Configure the build directory with the command
   ```
   $ meson setup build --buildtype=release
   ```

2. Compile with
   ```
   $ ninja -C build
   ```

### Install

To install, copy the executable `build/coloricious` to an executable directory,
for example to `~/.local/bin` or `/usr/local/bin`.
