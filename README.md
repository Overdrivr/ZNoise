# ZNoise
ZNoise is a fast and easy-to-use open-source C++ noise library.

This library is a very useful framework for people who want to generate procedural images, heightmaps and textures.

# Author
Rémi Bèges (remi.beges@gmail.com)

# Features

The following table details the implemented noises to date :

[Perlin2D]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/perlin2d.bmp "Perlin 2d"
[Simplex2D]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/simplex2d.bmp "Simplex 2d"
[Worley2D]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/worley2d.bmp "Worley 2d"

Noise   | 2-D | 3-D | 4-D
--------|-----|-----|-----
Perlin  |X    |X    |X    
Simplex |X    |X    |X    
Worley  |X    |     |     

To get an idea of the kind of images that can be generated with the algorithms

| Perlin | Simplex | Worley F1 | Worley F2 | Worley F3 | Worley F4 | Square
---------|---------|-----------|-----------|-----------|-----------|--------
![Perlin image][Perlin2D]    | ![Simplex image][Simplex2D]   | ![Worley F1 image][Worley2D]     |_     |_     |_      |_


These simple noises can also be used as sources on the following fractal noises

| Fractal BrownianMotion (FBM) | Hybrid MultiFractal |
-------------------------------|----------------------
Image                          |Image


# Build the library

Znoise uses [Gradle](http://gradle.org/) build system, but you don't need to install it (Actually, for now you do. Changing that soon).

All you need is a gcc C++11 compiler ([MinGW](http://www.mingw.org/) or [TDM-GCC](http://tdm-gcc.tdragon.net/) for instance).

On Windows, also add the /bin subfolder (where you can find gcc.exe) to the PATH.

Then, simply run the following command in the root /Znoise folder:

```
gradlew build
```

# Run the examples
```
gradlew installDebugMainExecutable
```
Run the first example
```
\build\install\mainExecutable\debug\main.bat
```
It will generate perlin noise in two dimensions and output the result to \build\install\examplesExecutable\debug\perlin2d.bmp

# Related implementations
This node library is also implemented in the C++11 game engine called Nazara. It is part of the official Nazara distribution.

[https://github.com/DigitalPulseSoftware/NazaraEngine](https://github.com/DigitalPulseSoftware/NazaraEngine)
