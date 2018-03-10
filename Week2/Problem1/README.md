An example run result:
=====================================

```
poly_naive: Begin testing.
poly_naive: Test run answer: 6779936416854088683849259155456.00
poly_naive: 1778368.00 time elapsed.
poly_qinjiushao: Begin testing.
poly_qinjiushao: Test run answer: 6779936416854088683849259155456.00
poly_qinjiushao: 39887.00 time elapsed.
Boost: 0.98
posy_naive: Begin testing.
posy_naive: Test run answer: 10.42
posy_naive: 2723365.00 time elapsed.
posy_qinjiushao: Begin testing.
posy_qinjiushao: Test run answer: 10.42
posy_qinjiushao: 72091.00 time elapsed.
Boost: 0.97
```


Cross-compiling with MinGW-W64:
==========================

```shell
make CC=x86_64-w64-mingw32-g++
```
