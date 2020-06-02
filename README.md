# encode_weak_cisco
simple unix util for encoding passphrases, possibly with given salt, using the
old weak (and reversible) cisco encoding method (eg : type 7 passphrases).
useful when pushing configurations with ansible.

## Usage
```bash
encode_weak_cisco --salt=GIVENSALT the_passphrase-to_encode
 ```

## Compilation / Installation
the following should bring you to a traditional build tree :
```bash
   libtoolize --force --copy && aclocal && autoheader && automake --add-missing --copy && autoconf
```
then the traditional build sequence :
```bash
    ./configure
    make
    make install
```

## Prerequisites
a C++ compiler

## Authors
The Rezopole team (https://www.rezopole.net/en/about-rezopole/team)

