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

don't do this

```bash
./urlenc -i hello.txt -s -a
```

instead do this

```bash
./urlenc -s -a -i hello.txt
```

ensure the `-i` option is the last argument in both `urlenc` and
`urldec`

### input from stdin

```bash
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

echo "' or 1=1 limit 1 -- -+" | urlenc -s -a
# %27+or+1%3d1+limit+1+%2d%2d+%2d%2b

echo echo "This is just a test." | urlenc -a
# This%20is%20just%20a%20test%2e
```

### input from FILE

```bash
# write a message to a file
echo "Welcome My Brothers!!" > hello.txt

# encode the message inside hello.txt
./urlenc -i hello.txt
# %57%65%6c%63%6f%6d%65%20%4d%79%20%42%72%6f%74%68%65%72%73%21%21%0a

# let's redirect the input of this message to another file
./urlenc -i hello.txt > encoded.txt

# decode the message inside encoded.txt
./urldec -i encoded.txt
# Welcome My Brothers!!
```

### urlenc help
```text
Usage: echo "<data>" | urlenc [<options>...]
Usage: urlenc [<options>...]

URL encode FILE, or standard input to standard output.

<Options>
-a : ignore alphanumeric characters
-s : use + instead of %20 when encoding spaces
-i : input file to encode (must be the last argument)
-h : display this help and exit

Copyright (c) 2019-2022 Youssef Hesham
```

### urldec help
```text
Usage: echo "<data>" | urldec
Usage: urldec [<options>...]

URL decode FILE, or standard input to standard output.

<Options>
-i : input file to decode (must be the last argument)
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
