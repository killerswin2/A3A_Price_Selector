
# A3A Price Selector
A QT Application Designed for Creating Static Loot list For Antistasi


# Building
Building Price Selector requires 
- CMake 3.25.1
- QT 6.4.2
- Any C++ Compiler That supports c++17

 ## Steps
 1. Clone repo
 ```
 git clone https://github.com/killerswin2/A3A_Price_Selector.git
 ```
 2. Generate CMake Configs
 ```
 cmake -S . -B build
 ```
 3. Use CMake to build
 ```
 cmake --build build
 ```
###  Build Errors or Problems
The CMakeLists currently assumes that you have installed QT in "C:/QT" directory. To change this behavior you will need to define **QT_PATH_DIR** which can be done so.
```
 cmake -S . -B build -QT_PATH_DIR="path/to/qt/dir"
``` 
