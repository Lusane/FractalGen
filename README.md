# FractalGen
# The program I used to teach Myself C++

# Current Program Version: v0.5.0_beta_r53
# Current Fractal System Version: v0.8a

# I don't plan on making any money with this program.

# [x32 NOTICE]
## I have the x32 version of the program large address aware, but even then it is limited to 4GB of ram.
## If you want to generate images larger then 4GB you have to use the x64 version
## p.s Don't worry about going to large and breaking the program. I have limited it to a 4GB image.(12288x12288)

## This program outputs the fractal images in *.ppm format.(More formats coming soon)
## To veiw *.ppm's download gimp Here https://www.gimp.org/downloads/ or another image editing/veiwing program capable of loading *.ppm's.

## Program.ini Explained
### [Protocol]
#### ThreadCount is the amount of threads used for generation of the fractals.
#### coutProgress controls whether or not the program outputs the total progress of the fractal generation.
#### skipPauses controls whether or not the program pauses in key places.
### [File]
#### name is the 'Name' of the image to be.
#### width is the image's width.
#### height is the image's height.
#### fileExtension controls the format of the image.(Remeber only *.ppm right now)

## Fractal.ini Explained
### [Main]
#### SetCount is the amount of fractal sets being used in the image.
#### useDefaults controls whether or not to use the defaults for the colors and sets.
#### useSetDefaults contols whether or not to use the defaults for the sets.
#### randomColorValues controls whether or not to use random color values.
#### Inverted... is hard to explain... it can invert the colors but it can also invert the order in which the fractals are visable... just try it.
#### Intensify Intensifies the end colors to make them brighter or darker, if used right.
#### Intensity self Explanatory.
### [Sets]
#### set1-8 controls the fractal equations being used for each set.
#### set choices are 0/MandelBrot, 1/Castle, 2/HalCorrupted, 3/HourGlass, 4/StarBurst

## Sets.ini Explained
### [Set1-8]
#### zr set this to different values for a different outcome. p.s works for the x axis.
#### zi set this to different values for a different outcome. p.s works for the y axis.
#### maxR can control fractal(not image) width from the left side.
#### minR can control fractal(not image) width from the right side.
#### maxI can control fractal(not image) height from the top side.
#### minI can control fractal(not image) height from the bottom side.
#### maxN is the max number of iterations for the while loop the runs the set equations.  addes more detail to the fractal
#### z this is a key value for the fractal changing this has varying results.
#### maxZ not the max for z it is used like so 'zr * zr + zi * zi < maxZ' in the while loop the runs the set equations.
#### rMlt the red multiplier used in coloring.
#### rDiv the red divisor used in coloring.
#### gMlt the green multiplier used in coloring.
#### gDiv the green divisor used in coloring.
#### bMlt the blue multiplier used in coloring.
#### bDiv the blue divisor used in coloring.

## If you have any questions or complaints join the discord I set up for this project --> https://discord.gg/973vnHe


# More information for this README is coming soon.
