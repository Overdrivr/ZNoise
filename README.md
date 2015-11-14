# ZNoise
ZNoise is a fast and easy-to-use open-source C++ noise library.

This library is a very useful framework for people who want to generate procedural images, heightmaps and textures.

Author : Rémi Bèges [twitter](https://twitter.com/remibgs)

## Noise algorithms

Noise algorithms are density functions. For any given point in space, they will return a density value.
This value is not random, noise algorithms are always deterministic.
In other words, calling the function multiple times for the same point will always return the same value.
However, computing the noise for different coordinates will yield different densities.

# Noises
## Usage
```
Perlin perlin;

for(int x = 0 ; x < image.width() ; x++)
    for(int y = 0 ; y < image.height() ; y++)
    {
        // returned noise value is between -1 and 1
        // Set noise scale with the last parameter
        float value = perlin.Get({x , y},0.01f);

        // Do whatever you want with it
        // ex : generate a pixel intensity, use in a colormap ...
        // ...
    }

```
# List

The following table details the implemented noises to date :

[Perlin2D]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/perlin2d.bmp "Perlin 2d"
[Perlin3D]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/perlin3d.bmp "Perlin 3d"
[Perlin4D]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/perlin4d.bmp "Perlin 4d"
[Simplex2D]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/simplex2d.bmp "Simplex 2d"
[Worley2DF1]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/worley2d.bmp "Worley 2d"
[FBM2D]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/fbm.bmp "FBM 2d"
[HMF2D]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/hybridmultifractal.bmp "HMF 2d"

Noise     | 2-D                       | 3-D (2D slice)           | 4-D (2D slice)
----------|---------------------------|--------------------------|-----
Perlin    |![Perlin 2D][Perlin2D]     |![Perlin 3D][Perlin3D]    |![Perlin 4D][Perlin4D]    
Simplex   |![Simplex 2D][Simplex2D]   |![Simplex 3D][Simplex3D]  |![Simplex 4D][Simplex4D]   
Worley F1 |![Worley F1][Simplex4D]    |_                         |_
Worley F2 |_                          |_                         |_
Worley F3 |_                          |_                         |_
Worley F4 |_                          |_                         |_
Square    |_                          |_                         |_

# Mixers
## Usage
```
// Use Perlin as mixer source
Perlin perlin;
// Mixer
FBM fbm(perlin);

for(int x = 0 ; x < image.width() ; x++)
    for(int y = 0 ; y < image.height() ; y++)
    {
        float value =  fbm.Get({x , y},0.01f);
        // ...
    }

```

## List

Multiple noise layers can be assembled automatically using Mixers.
Three parameters are available to tune the noise output :
 * Lacunarity
 * Octave amount
 * Hurst coefficient

The amount of octaves is simply the total number of noise layers blended together.
Lacunarity controls the scale ratio between two successive layers.
Hurst coefficient controls relates to the weight of each layer in the final blended image.

### Fractal Brownian Motion (FBM) - 5 octaves
               |lacunarity = 5.f           |lacunarity = 1.f          |lacunarity = 0.2f
---------------|---------------------------|--------------------------|-----------------------
hurst = 1.2f   |![FBM2D][FBM 2D]           |_                         |_    
hurst = 1.5f   |_                          |_                         |_  
hurst = 1.8f   |_                          |_                         |_


### Hybrid Multi Fractal - 5 octaves
               |lacunarity = 5.f           |lacunarity = 1.f          |lacunarity = 0.2f
---------------|---------------------------|--------------------------|-----------------------
hurst = 1.2f   |![HMF2D][HMF 2D]           |_                         |_    
hurst = 1.5f   |_                          |_                         |_  
hurst = 1.8f   |_                          |_                         |_

# Build the library

Znoise uses the [Gradle](http://gradle.org/) build system, but you don't need to install it (Actually, for now you do. Changing that soon).

All you need is a gcc C++11 compiler ([MinGW](http://www.mingw.org/) or [TDM-GCC](http://tdm-gcc.tdragon.net/) for instance).

On Windows, also add the /bin subfolder (where you can find gcc.exe) to the PATH.

Then, simply run the following command in the root /Znoise folder:

```
gradlew build
```

# Build the examples
```
gradlew installDebugMainExecutable
```
Run the examples
```
\build\install\mainExecutable\debug\main.bat
```
This will generate all the images in this readme. Images will be found in \build\install\examplesExecutable\debug\

# Related implementations
This node library is also implemented in the C++11 game engine called Nazara. It is part of the official Nazara distribution.

[https://github.com/DigitalPulseSoftware/NazaraEngine](https://github.com/DigitalPulseSoftware/NazaraEngine)
