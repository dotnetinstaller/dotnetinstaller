# SEMVER

(C) 2020 Mario Konrad

License: BSD, see [LICENSE.md](LICENSE.md)


## Introduction

Implementation of semver 2.0.0, https://semver.org/

Parital implementatoin of ranges, https://github.com/npm/node-semver#versions, https://semver.npmjs.com/
- support for hyphen ranges, e.g. `1.2.3 - 2.0.0`, `1.2 - 2`
- support for wildcards, e.g. `1.2.x`, `1.2`, `1.X.3`, `*.2.3`
- support for tile ranges, e.g. `~1.2.3`, `~1.2`
- support for caret ranges, e.g. `^1.2.3`


## Examples
### Examples `semver`

Construction from string:
```cpp
auto v = semver("1.2.3-pre.1+build.2");
```

Construction with numerical values:
```cpp
auto v = semver(1, 2, 3, "pre.1", "build.2");
```

Comparison of versions:
```cpp
auto v1 = semver("1.2.3-pre.1+build.2");
auto v2 = semver(1, 2, 3, "pre.1", "build.2");
assert(v1 == v2);

auto v3 = semver("1.2.3");
auto v4 = semver("2.3.4");
assert(v3 < v4);
```

Access individual parts:
```cpp
const auto v = semver("1.2.3-pre.1+build.2");
assert(v.major() == 1);
assert(v.minor() == 2);
assert(v.patch() == 3);
assert(v.prerelease() == "pre.1");
assert(v.build() == "build.2");
```

Convert to string:
```cpp
const auto v = semver(1, 2, 3, "pre.1", "build.2");
assert(v.str() == "1.2.3-pre.1+build.2");
assert(to_string(v) == "1.2.3-pre.1+build.2");
```

Roundtrip guarantee:
```cpp
const auto v1 = semver(1, 2, 3, "pre.1", "build.2");
const auto v2 = semver(v1.str());
assert(v1 == v2);
```

Handling of invalid construction:
```cpp
const auto v = semver("foobar");
assert(v.ok() == false);
```


### Examples `range`

Construction:
```cpp
const auto r = range(">=1.2.3 <2.0.0 || 3.0.0");
```

Testing versions against ranges:
```cpp
const auto r = range(">=1.2.3 <2.0.0 || 3.0.0");
assert(r.satisfies(semver("1.2.3")));
assert(r.satisfies(semver("1.9.0")));
assert(r.satisfies(semver("3.0.0")));
```

Find min/max satisfying version:
```cpp
const auto r = range(">=1.2.3 <2.0.0 || 3.0.0");

auto v1 = r.max_satisfying({semver("1.3.4"), semver("1.5.1"), semver("2.3.0")});
assert(v1 == semver(1, 5, 1));

auto v2 = r.min_satisfying({semver("1.3.4"), semver("1.5.1"), semver("2.3.0")});
assert(v2 == semver(1, 3, 4));
```

Find min/max version of a range:
```cpp
const auto r = range(">=1.2.3 <2.0.0 || 3.0.0");
assert(r.max() == semver(3, 0, 0));
assert(r.min() == semver(1, 2, 3));
```

Handlin of invalid construction:
```cpp
const auto r = range("foobar");
assert(r.ok() == false);
```


## Build

The build is CMake based. It requires a C++17 capable compiler.
GoogleTest is used for testing.

Tested with compilers:
- GCC-9
- GCC-10
- Clang-9
- Clang-10
- Clang-12

Build and run tests:
```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release .
cmake --build build -j 4
build/testrunner
```

Build library only:
```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release -DDISABLE_TESTS=TRUE -DDISABLE_EXAMPLES=TRUE .
cmake --build build -j 4
```

Build and install library:
```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release -DDISABLE_TESTS=TRUE -DDISABLE_EXAMPLES=TRUE -DCMAKE_INSTALL_PREFIX=`pwd`/local .
cmake --build build -j 4
cmake --install build
```

