#!/bin/sh
package_names=("cmake" "raylib")

linux()
{
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

    # Carch based pacman
    if [ -f "/etc/arch-release" ]; then
        arch
    fi
    unixBuild
}

debian()
{
    for package_name in "${package_names[@]}"; do
        if dpkg -l | grep -w "$package_name" > /dev/null; then
            echo "$package_name already installed."
        else
            echo "$package_name is not installed."
            sudo apt-get update
            sudo apt-get install -y "$package_name"
        fi
    done
}

redHatYum()
{
    for package_name in "${package_names[@]}"; do
        if yum list installed "$package_name" > /dev/null; then
            echo "$package_name already installed."
        else
            echo "$package_name is not installed."
            sudo yum install -y "$package_name"
        fi
    done
}

redHatRpm()
{
    for package_name in "${package_names[@]}"; do
        if rpm -q "$package_name" > /dev/null; then
            echo "$package_name already installed."
        else
            echo "$package_name is not installed."
            sudo dnf install -y "$package_name"
        fi
    done
}

arch()
{
     for package_name in "${package_names[@]}"; do
        if pacman -Qs "$package_name" > /dev/null; then
            echo "$package_name already installed."
        else
            echo "$package_name is not installed."
            sudo pacman -Sy --noconfirm $package_name
        fi
    done
}

macos()
{
    # Install Homebrew, which is an open source package manager for macOS.
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    brew install cmake
    brew install raylib

    unixBuild
}

unixBuild()
{
    #check if build folder exisit
    if [ -d "./build" ]; then
        echo "the folder is already exist"
        build
    else
        echo "folder doesn't exist creating..."
        mkdir build
        build
    fi
}

build()
{
    cd build 
    cmake ..
    if [ $? -ne 0 ]; then
        echo "CMake build failed."
        exit -0
    else
        make
        if [ $? -ne 0 ]; then
            echo "Make failed."
            exit -0
        else
            ./app
        fi
    fi        
}

case "$OSTYPE" in
  darwin*)  macos;; 
  linux*)   linux;;
  *)        echo "This app didn't support: $OSTYPE" ;;
esac
