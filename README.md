# ZNoise
ZNoise is a fast and easy-to-use open-source C++ noise library. 

This library is a very useful framework for people who want to generate procedural content such as images, heightmaps, textures, etc.

# Author
Rémi Bèges 
[twitter](https://twitter.com/remibgs)

# Features

The following table details the implemented noises to date :



[Perlin2D]: https://github.com/Overdrivr/ZNoise/blob/master/tests/generate_all_noises/perlin2d.bmp "Perlin 2d"
[Simplex2D]: https://github.com/Overdrivr/ZNoise/blob/master/tests/generate_all_noises/simplex2d.bmp "Simplex 2d"
[Worley2D]: https://github.com/Overdrivr/ZNoise/blob/master/tests/generate_all_noises/worley2d.bmp "Worley 2d"

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


# Installation, Documentation and exemples

Installing the library is simply done by placing the /include and /src folders inside your project, but there are a few things to know related to your compiler. See the [wiki](https://github.com/Overdrivr/ZNoise/wiki) for detailed information.

Other topics are covered such as how to run the exemples, advanced use of the algorithms, etc.

# Related implementations
This node library is also implemented in the C++11 game engine called Nazara. It is part of the official Nazara distribution.

[https://github.com/DigitalPulseSoftware/NazaraEngine](https://github.com/DigitalPulseSoftware/NazaraEngine)
