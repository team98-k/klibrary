# klibrary

## Requirements
* [CMake](https://cmake.org/)

## Build
```
git clone https://github.com/team98-k/klibrary
cd klibrary
cmake -B build -S .
```

## Install
```
cmake --install ./build
```

## Example
```cmake
# CMakeLists.txt
cmake_minimum_required(VERSION 3.11)

project(
    exampleproject
    VERSION 1.0.0
    DESCRIPTION "example"
    LANGUAGES CXX
)

find_package(klibrary CONFIG REQUIRED)

add_executable(
    ${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/example.cpp
)

target_link_libraries(
	${PROJECT_NAME}
	PRIVATE
    klibrary::klibrary
)
```

```cpp
// example.cpp
#include "klibrary/klibrary.h"

int main()
{
    hashtable::hashtable<int> table(10);

    table.save(1, "key1");
    table.save(2, "key2");

    table.tablelist(false);

    return 0;
}
```