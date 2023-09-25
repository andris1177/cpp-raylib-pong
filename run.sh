#!/bin/sh

raylib_location="/usr/local/lib/libraylib.a"

linux() {
    # debian based apt
    if [ -f "/etc/debian_version" ]; then
        debian
    fi

    # red hat based
    if [ -f "/etc/redhat-release" ]; then
        if [ -f "/usr/bin/yum" ]; then
            redHatYum
        elif [ -f "/usr/bin/dnf" ]; then
            redHatRpm
        fi
    fi

    # Arch based pacman
    if [ -f "/etc/arch-release" ]; then
        arch
    fi

    unixBuild
}

debian() {
    sudo apt-get install -y libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev cmake
    installRaylib
}

arch() {
    sudo pacman -S --noconfirm alsa-lib mesa libx11 libxrandr libxi libxcursor libxinerama cmake
    installRaylib
}

macos() {
    # Install Homebrew, which is an open source package manager for macOS.
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    brew install cmake
    brew install raylib

    unixBuild
}

installRaylib() {
    if [ -f "$raylib_location" ]; then
        echo "raylib is installed"
    else
        git clone https://github.com/raysan5/raylib.git raylib
        cd raylib/src/
        make PLATFORM=PLATFORM_DESKTOP
        sudo make install
        cd ../..
        rm -r raylib/ -y
    fi
}

unixBuild() {
    # Check if the build folder exists
    if [ -d "./build" ]; then
        echo "the folder already exists"
        build
    else
        echo "folder doesn't exist, creating..."
        mkdir build
        build
    fi
}

build() {
    cd build
    cmake ..
    if [ $? -ne 0 ]; then
        echo "CMake build failed."
        exit 1
    else
        make
        if [ $? -ne 0 ]; then
            echo "Make failed."
            exit 1
        else
            ./app
        fi
    fi
}

case "$OSTYPE" in
  darwin*)  macos;;
  linux*)   linux;;
  *)        echo "This app doesn't support: $OSTYPE" ;;
esac
