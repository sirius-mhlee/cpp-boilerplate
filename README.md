# C++ Boilerplate

C++ Boilerplate using CMake, Gcov, LCOV and GTest

## Requirement

- CMake (3.16.3)
- g++/Gcov (9.4.0)
- LCOV (1.14)
- GTest (1.11.0)
- Ninja (1.10.0)

```shell
sudo apt install build-essential cmake ninja-build lcov
```

## Generate

```shell
cmake -S . -B build -G Ninja
```

![generate_result.png](./example/generate_result.png)

## Build

```shell
cd build
cmake --build . --target all
```

## Test

```shell
cd build
ctest -j2 --output-on-failure
```

![test_result.png](./example/test_result.png)

## Coverage

``` shell
cd build
cmake --build . --target test1_cov
```

![coverage_result.png](./example/coverage_result.png)
