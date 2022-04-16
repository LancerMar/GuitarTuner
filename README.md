<h1 align="center">Guitartuner</h1>
<p align="center">
    <a href = "https://github.com/LancerMar/GuitarTuner">
        <img src="/files/guitar.png" alt="Logo" height="300">
    </a>
    <p align="center">A QT gui application that helps you tune your guitar</p>
</p>

<p align="center">
    <a href="https://www.youtube.com/watch?v=Mex_W0Kkss0">Youtube</a>
    &nbsp;
    &nbsp;
    <a href="https://www.bilibili.com/video/BV1RY4y1e7MV?pop_share=1">Bilibili</a>
</p>
<p align="center">
   
</p>

<p align="center">
    <a href="https://github.com/LancerMar/GuitarTuner/graphs/contributors" alt="Contributors">
        <img src="https://img.shields.io/github/contributors/LancerMar/Guitartuner.svg" /></a>
    <a href="https://github.com/LancerMar/GuitarTuner/issues" alt="Issues">
        <img src="https://img.shields.io/github/issues/LancerMar/Guitartuner.svg" /></a>
    <a href="https://github.com/LancerMar/Guitartuner/blob/main/LICENSE" alt="License">
        <img src="https://img.shields.io/github/license/LancerMar/Guitartuner.svg" /></a>
    <a href="https://github.com/LancerMar/Guitartuner/releases" alt="Tag">
        <img src="https://img.shields.io/github/v/release/LancerMar/Guitartuner.svg?color=blue&include_prereleases" alt="build status"></a>
</p>

## Contents
<ul>
    <li><a href="#About">About</a>
        <ul>
            <li><a href="#Functionality">Functionality</a>
            <li><a href="#Hardware">Hardware</a>
        </ul>
    <li><a href="#Quick-Start">Quick Start</a>
        <ul>
            <li><a href="#assembly-and-soldering">Assembly and Soldering</a>
            <li><a href="#raspberry-pi-for-wiring">Raspberry pi for wiring</a>
            <li><a href="#installation">Installation</a>
                <ul>
                    <li><a href="#run-the-executable">Run the program</a>
                    <li><a href="#debug">Debug program</a>
                </ul>
            <li><a href="#running-tests">Running Tests</a>
        </ul>
    <li><a href="#Usage">Usage</a>
    <li><a href="#Documentation">Documentation</a>
    <li><a href="#Stretch-Goals">Stretch Goals</a>
</ul>
            
## About
Guitartuner is a easy to run tuning application. It easily helps you tune your guitar with the help of a simple GUI.

### Functionality
 - Real-time standard tuning
 - Showing pitch frequency
### Hardware
 - Raspberry pi model 4b
 - [I2s microphone](https://www.adafruit.com/product/3421) 

## Quick Start
### Assembly and Soldering
[More details can be found here!](https://learn.adafruit.com/adafruit-i2s-mems-microphone-breakout/assembly)
### Raspberry pi for wiring 
[More datails](https://learn.adafruit.com/adafruit-i2s-mems-microphone-breakout/raspberry-pi-wiring-test), remember this is mono mic based project.
### Installation
Follow the following steps

1. Install the driver for i2s mic, [link](https://learn.adafruit.com/adafruit-i2s-mems-microphone-breakout/raspberry-pi-wiring-test), after the wiring section.

2. Install several dependenceis.

```
sudo apt-get -y update
sudo apt-get -y upgrade
```
and then install these modules
 - asound module 
 - fftw3 module
 - Qt module
 - iir filter module

```
sudo apt-get install libasound2-dev python3-pip libboost-test-dev 
sudo apt-get install libfftw3-dev 
sudo apt-get install qtdeclarative5-dev-tools libqwt-qt5-dev qtmultimedia5-dev
```

3. Configure dynamic linker run-time bindings

```
sudo ldconfig
```
4. clone this project

```linux
git clone https://github.com/LancerMar/GuitarTuner
cd GuitarTuner
```

#### Run the executable
You can compile the release version of our project by using following command on RaspberryPi
```linux 
mkdir release
cd release/
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```
The **guitartuner** is the excutable file, run it.
```linux
./guitartuner
```

#### Debug
You can compile the debug version of our project by using following command on RaspberryPi
``` linux
mkdir debug
cd debug/
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
```
The **guitartuner** is the excutable file 

You can use
``` linux
gdb -tui guitartuner
```
to debug this program 

### Running Tests
To run the unit tests

```
make test
```
## Usage

For instructions on how to use the Guitartuner application, see the [User Manual](https://github.com/LancerMar/Guitartuner/wiki/User-Manual).

# Document for Code
[GUITARTUNER DOCUMENTATION](https://lancermar.github.io/GuitarTuner/docs/html/index.html)
## Stretch Goals
- Electric machine that could tune the guitar automatically
- More precise pitches detection, remove harmonics
