# Glitch Bunny
### To run:
__Linux__:
This project builds through cmake. JUCE requires the following packages for compilation:
```
libasound2-dev
libjack-jackd2-dev
ladspa-sdk
libcur14-openssl-dev
libfreetype6-dev
libxl11-dev
libxcomposite-dev
libxcursor-dev
libxext-dev
libxinerama-dev
libxrandr-dev
libxrender-dev
libwebkit2gtk-4.0-dev
libglu1-mesa-dev
mesa-common-dev
```
Next, create a build directory and run cmake:
```
mkdir build
cmake -S . -B build
```