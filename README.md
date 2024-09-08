# Használata

## download

``` bash
git clone --recursive https://github.com/andris1177/cpp-raylib-pong.git
cd cpp-raylib-pong
git checkout dev
git pull --recurse-submodules
```

## Linux

### Run

``` bash
mkdir build
cd build
cmake ../
make
./pong
```

## Windows

### Run

``` bash
mkdir build
cd build
cmake ../
msbuild pong.sln /p:Configuration=Release
cd Relase
pong.exe
```

## for nvim use:
``` bash
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ../
```
