# ImageHlp.dll test utility

The `MapAndLoad()` function has been known to erroneously fail on some
older versions of the iPXE and wimboot binaries (see
e.g. https://github.com/ipxe/ipxe/commit/7b976dd30 and
https://github.com/ipxe/wimboot/commit/670c7e2).

This is a quick and dirty tool to invoke the `MapAndLoad()` function
on an arbitrary list of binaries, in order to allow this function to
be tested in isolation from the rest of the Secure Boot signing
process.

# Quick start

- Place a copy of `ImageHlp.dll` in this directory

- ```
  ./autogen.sh
  ./configure --build= --host=x86_64-w64-mingw32
  make && sudo make install
  ```

- Invoke as `imagehlptest-wine bin-x86_64-efi/ipxe.efi` or similar
