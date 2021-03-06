# FreeRCT build instructions #

Currently only Linux is officially supported, but Windows support should be possible with a few minor modifications. See [BuildProgramVisualStudio](BuildProgramVisualStudio.md) for instructions on building FreeRCT on Windows using Visual Studio.

## Checkout ##

The source code is hosted on GitHub, so it is recommended you make a git clone of the repo. Alternatively, you can download a zip of the current state of the repo.

A command to make a git clone is `git clone https://github.com/FreeRCT/FreeRCT`.

## Building the program ##

Almost everything is written in C++, which means you need **g++** or **clang++** to compile it. FreeRCT uses C++11 features, so g++ 4.8+ or clang 3.3+ is recommended.
In addition, you need:

  * **libpng** - Making the RCD data files that contain the graphics and other data read by the program.
  * **SDL2** & **SDL2\_ttf** - Displaying graphics of the program. Note that SDL2 versions of the libraries are required.
  * **CMake>=2.8** & **make** - Building the program.
  * `[optional]` **lex/flex** - Scanner generator for generating RCD input files.
  * `[optional]` **yacc/bison** - Parser generator for generating RCD input files.

The existence of these programs/libraries is checked by `cmake`.

Building is as simple as

```
$ cd FreeRCT # Go into the downloaded source directory, where the README is located.
$ cmake .    # Checks libraries are where they're supposed to be and replaces some strings
$ make       # Let make do the heavy work
```

  * _src_ directory contains the source code of the FreeRCT program itself.
  * _src/rcdgen_ directory contains the source code of the _rcdgen_ program, that builds RCD files from source (which are read by _freerct_).
  * _graphics/rcd_ directory contains the source files of the RCD data files, except the graphics.
  * _graphics/sprites_ directory contains all the graphics of the game.

The _cmake/make_ commands above will generate the _rcdgen_ program, the rcd files and build the 'freerct' program in the src directory.

## Config file ##

Finally, you need a 'freerct.cfg' INI format file next to the 'freerct' program, containing the path to the font file you want to use. It looks like

```
[font]
medium-size = 12
medium-path = /usr/share/fonts/gnu-free/FreeSans.ttf
```

This means the medium sized font is 12 points high, and its source font definition file is at the indicated path. Make sure you use a path that actually exists.

The actual font file is not that critical, as long as it contains the ASCII characters, in the font-size you mention in the file.

## Running the program ##

Now run the program

```
$ cd bin
$ ./freerct
```

Running the command `make run` will work too.

which should open a window containing an oddly familiar looking piece of greenly coloured flat world.
