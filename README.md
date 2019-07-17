# URLENC

url encoding and decoding utility

### build and install

it requires no dependencies just run the following

```bash
git clone https://github.com/M1cR0xft/urlenc.git

cd urlenc
make
sudo make install

# try it

echo "testing the new urldec utility\nit seems to be fun" | urlenc
# %74%65%73%74%69%6e%67%20%74%68%65%20%6e%65%77%20%75%72%6c%64%65%63%20%75%74%69%6c%69%74%79%0a%69%74%20%73%65%65%6d%73%20%74%6f%20%62%65%20%66%75%6e

echo "%74%65%73%74%69%6e%67%20%74%68%65%20%6e%65%77%20%75%72%6c%64%65%63%20%75%74%69%6c%69%74%79%0a%69%74%20%73%65%65%6d%73%20%74%6f%20%62%65%20%66%75%6e" | urldec
# testing the new urldec utility
# it seems to be fun

echo "this is just a %74%65%73%74." | urldec
# this is just a test.
```

## FAQ
**why another one**
i wrote cause i do not want to use burp suite for this kind of encoding, and
command line binaries are faster and more portable.

**why in C, in python you can do it in 2 lines**
C is faster, python is slower. another reason is i want to sharp my C skills

# LICENSE
Public Domain
