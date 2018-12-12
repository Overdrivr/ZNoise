# ZNoise
ZNoise is a fast and easy-to-use open-source C++ noise library.

This library is a very useful framework for people who want to generate procedural images, heightmaps and textures.

Author : Rémi Bèges ([twitter](https://twitter.com/remibgs))

## Noise algorithms

Noise algorithms are density functions. For any given point in space, they will return a density value.
This value is not random, noise algorithms are always deterministic.
In other words, calling the function multiple times for the same point will always return the same value.
However, computing the noise for different coordinates will yield different densities.

## Noises
### Usage
```c
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
### List of supported algorithms

The following table details the implemented noises to date :

[Perlin2D]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/perlin2d.bmp "Perlin 2d"
[Perlin3D]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/perlin3d.bmp "Perlin 3d"
[Perlin4D]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/perlin4d.bmp "Perlin 4d"
[Simplex2D]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/simplex2d.bmp "Simplex 2d"
[Simplex3D]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/simplex3d.bmp "Simplex 3d"
[Simplex4D]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/simplex4d.bmp "Simplex 4d"
[Worley2DF1]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/worley2d.bmp "Worley 2d"
[FBM2D]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/fbm_h0.8_l2.5.bmp "FBM 2d"
[HMF2D]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/hybridmultifractal.bmp "HMF 2d"

Noise     | 2-D                       | 3-D (2D slice)           | 4-D (2D slice)
----------|---------------------------|--------------------------|-----
Perlin    |![Perlin2D][Perlin2D]      |![Perlin3D][Perlin3D]     |![Perlin4D][Perlin4D]    
Simplex   |![Simplex2D][Simplex2D]    |![Simplex3D][Simplex3D]   |![Simplex4D][Simplex4D]   
Worley F1 |![Worley2DF1][Worley2DF1]  |_                         |_
Worley F2 |_                          |_                         |_
Worley F3 |_                          |_                         |_
Worley F4 |_                          |_                         |_
Square    |_                          |_                         |_

## Mixers
### Usage
```c++
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

### List of supported mixers

Multiple noise layers can be assembled automatically using Mixers.
Three parameters are available to tune the noise output :
 * Lacunarity
 * Octave amount
 * Hurst coefficient

The amount of octaves is simply the total number of noise layers blended together.
Lacunarity controls the scale ratio between two successive layers.
Hurst coefficient controls relates to the weight of each layer in the final blended image.

#### Fractal Brownian Motion (FBM) - 5 octaves

[FBM2D_11]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/fbm_h0.2_l2.5.bmp
[FBM2D_12]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/fbm_h0.5_l2.5.bmp
[FBM2D_13]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/fbm_h0.8_l2.5.bmp

[FBM2D_21]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/fbm_h0.2_l3.5.bmp
[FBM2D_22]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/fbm_h0.5_l3.5.bmp
[FBM2D_23]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/fbm_h0.8_l3.5.bmp

[FBM2D_31]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/fbm_h0.2_l4.5.bmp
[FBM2D_32]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/fbm_h0.5_l4.5.bmp
[FBM2D_33]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/fbm_h0.8_l4.5.bmp

FBM            |lacunarity = 2.5f          |lacunarity = 3.5f         |lacunarity = 4.5f
---------------|---------------------------|--------------------------|-----------------------
hurst = 0.2f   |![FBM2D][FBM2D_11]         |![FBM2D][FBM2D_21]        |![FBM2D][FBM2D_31]
hurst = 0.5f   |![FBM2D][FBM2D_12]         |![FBM2D][FBM2D_22]        |![FBM2D][FBM2D_32]
hurst = 0.8f   |![FBM2D][FBM2D_13]         |![FBM2D][FBM2D_23]        |![FBM2D][FBM2D_33]

[HMF2D_11]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/hybridmultifractal_h0.2_l2.5.bmp
[HMF2D_12]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/hybridmultifractal_h0.5_l2.5.bmp
[HMF2D_13]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/hybridmultifractal_h0.8_l2.5.bmp

[HMF2D_21]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/hybridmultifractal_h0.2_l3.5.bmp
[HMF2D_22]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/hybridmultifractal_h0.5_l3.5.bmp
[HMF2D_23]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/hybridmultifractal_h0.8_l3.5.bmp

[HMF2D_31]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/hybridmultifractal_h0.2_l4.5.bmp
[HMF2D_32]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/hybridmultifractal_h0.5_l4.5.bmp
[HMF2D_33]: https://github.com/Overdrivr/ZNoise/blob/master/example-images/hybridmultifractal_h0.8_l4.5.bmp


#### Hybrid Multi Fractal - 5 octaves
HMF            |lacunarity = 2.5f          |lacunarity = 3.5f         |lacunarity = 4.5f
---------------|---------------------------|--------------------------|-----------------------
hurst = 0.2f   |![HMF2D][HMF2D_11]         |![HMF2D][HMF2D_21]        |![HMF2D][HMF2D_31]     
hurst = 0.5f   |![HMF2D][HMF2D_12]         |![HMF2D][HMF2D_22]        |![HMF2D][HMF2D_32]
hurst = 0.8f   |![HMF2D][HMF2D_13]         |![HMF2D][HMF2D_23]        |![HMF2D][HMF2D_33]

## Build the library

Znoise uses the [Gradle](http://gradle.org/) build system. As a user,  you don't need to install gradle. All you need is a gcc C++11 compiler ([MinGW](http://www.mingw.org/) or [TDM-GCC](http://tdm-gcc.tdragon.net/) for instance).

On Windows, you also need to add the /bin subfolder (where you can find gcc.exe) to the PATH.

Then, run the following command in the root /Znoise folder:

```
gradlew build
```

## Build the examples
```
gradlew installDebugMainExecutable
```
Run the examples
```
\build\install\mainExecutable\debug\main.bat
```
This will generate all the images in this readme. Images will be found in \build\install\examplesExecutable\debug\

## Related implementation
ZNoise has at some point been developed for the [https://github.com/DigitalPulseSoftware/NazaraEngine](NazaraEngine) C++11 game engine.
