# URLENC

url encoding and decoding utility

## build and install

it requires no dependencies just run the following

```bash
git clone https://github.com/M1cR0xf7/urlenc.git

cd urlenc
make
make install
```

## example usage

```bash
# try it

echo "testing the new urldec utility\nit seems to be fun" | urlenc
# %74%65%73%74%69%6e%67%20%74%68%65%20%6e%65%77%20%75%72%6c%64%65%63%20%75%74%69%6c%69%74%79%0a%69%74%20%73%65%65%6d%73%20%74%6f%20%62%65%20%66%75%6e

echo "%74%65%73%74%69%6e%67%20%74%68%65%20%6e%65%77%20%75%72%6c%64%65%63%20%75%74%69%6c%69%74%79%0a%69%74%20%73%65%65%6d%73%20%74%6f%20%62%65%20%66%75%6e" | urldec
# testing the new urldec utility
# it seems to be fun

echo "this is just a %74%65%73%74." | urldec
# this is just a test.

echo "use plus please" | urlenc -s
# %75%73%65+%70%6c%75%73+%70%6c%65%61%73%65

echo "use plus please and ignore alphanumeric characters" | urlenc -s -a
# use+plus+please+and+ignore+alphanumeric+characters

```

### urlenc help
```text
$ urlenc --help

Usage: echo "<data>" | urlenc [<options>...]
Usage: urlenc [<options>...]

URL encode standard input to standard output.

<Options>
-a : ignore alphanumeric characters
-s : use + instead of %20 when encoding spaces
-h : display this help and exit

Copyright (c) 2019-2022 Youssef Hesham
```

### urldec help
```text
urldec -h
Usage: echo "<data>" | urldec
Usage: urldec [<options>...]

URL decode standard input to standard output.

<Options>
-h : display this help and exit

Copyright (c) 2019-2022 Youssef Hesham
```

## FAQ
**why another one**:
i wrote it because i do not want to open burpsuite or the web browser every time i want to use this kind of encoding.
also command line binaries are faster and more portable.

**why in C, in python you can do it in 2 lines**:
C is faster, python is slower. another reason is i want to sharp my C skills.

# LICENSE
[BSD-3-Clause license](COPYING)
