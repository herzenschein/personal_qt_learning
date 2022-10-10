To run this project:

```
cmake -B build/ -DCMAKE_INSTALL_PREFIX=~/kde/usr
cmake --build build
cmake --install build
source build/prefix.sh
kcmshell5 kcm_time
```

Or in a single command:

    cmake -B build/ -DCMAKE_INSTALL_PREFIX=~/kde/usr && cmake --build build && cmake --install build && source build/prefix.sh && kcmshell5 kcm_time
