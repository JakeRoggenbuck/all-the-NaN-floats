# all-the-NaN-floats ![Build](https://img.shields.io/github/actions/workflow/status/jakeroggenbuck/all-the-NaN-floats/c-cpp.yml?branch=main&style=for-the-badge)

Write all of the [NaN](https://en.wikipedia.org/wiki/NaN) floats from [IEEE 754](https://en.wikipedia.org/wiki/IEEE_754) 32 bit floats to disk.

In IEEE 754, if all 8 bits of the exponent are set to 1, then the float is NaN.

This means that there are 2 ^ (32 - 8) or 16777216 possible values for NaN for the version of NaN where all exponent bits are set to 1.

These are all of the NaNs between the range of start and end as seen here:

```c
unsigned int start = (0b011111111 << 23) + 1;
unsigned int end = (1 << 31) - 1u;
```

Helpful visualization: https://www.h-schmidt.net/FloatConverter/IEEE754.html

The resulting file size is 2 ^ (32 - 8) * 4, where 4 is the amount of bytes a float 32 takes up. This results in ~67.11 Megabytes of disk space. If we compress this with something like xz with the highest level of compression, we get a file size of ~4.16 Megabytes.

That [file](https://github.com/JakeRoggenbuck/all-the-NaN-floats/blob/main/all-the-nan-floats.xz) was small enough to include in the git project.
