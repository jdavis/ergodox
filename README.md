# ergodox

Layout for my Ergodox EZ. Initial keyboard layout from [Nicholas Keene][keene].

## Install

Use the Ergodox EZ fork of QMK located [here][qmk] for documentation.

The build instructions located in the [BUILD_GUIDE.md][build].


### Setup

```bash
brew tap osx-cross/avr
brew install avr-libc
brew install teensy_loader_cli
```

### Building

```bash
# Install all deps
make install

# Build
make

# Program to keyboard
make program
```


## Layout

Layers:

1. Default QWERTY (slightly customized)
2. Coding
3. Colemak
4. Media

[qmk]: https://github.com/jackhumbert/qmk_firmware
[build]: https://github.com/jackhumbert/qmk_firmware/blob/master/BUILD_GUIDE.md
[keene]: http://nicholas.rinard.us/2016/03/ergodox-ez-layout.html
