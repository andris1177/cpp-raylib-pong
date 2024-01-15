# Használata

## download

``` bash
git clone --recursive https://github.com/andris1177/cpp-raylib-pong.git
cd cpp-raylib-pong
```

## Linux

### Run

``` bash
mkdir build
cd build
cmake ../
make
./app
```

## Windows

### Run

``` bash
mkdir build
cd build
cmake ../
msbuild pong.sln /p:Configuration=Release
cd Relase
app.exe
```
