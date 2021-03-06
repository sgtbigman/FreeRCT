FreeRCT aims to be a free and open source game which captures the look, feel and gameplay of the popular games RollerCoaster Tycoon 1 and 2.

.. image:: doc/images/20150609-freerct.png

Building the program
--------------------

Currently only Linux is officially supported, although Windows *should* work. Let us know if it's broken.

Almost everything is written in C++, which means you need *g++* or *clang++* to compile it. FreeRCT uses C++11 features, so g++ 4.8+ or clang 3.3+ is recommended.
In addition, you need:

* *lex/flex* - Scanner generator for generating RCD input files. (optional)
* *yacc/bison* - Parser generator for generating RCD input files. (optional)
* *libpng* - Making the RCD data files that contain the graphics and other data read by the program.
* *SDL2* & *SDL2-ttf* - Displaying graphics of the program. Note that SDL2 versions of both libraries are needed.
* *CMake* & *make* - Building the program.

The existence of these programs/libraries is checked by ``cmake``.

Building is as simple as

::

        $ git clone https://github.com/FreeRCT/FreeRCT.git
        $ cd FreeRCT # Go into the downloaded source directory.
        $ cmake .    # Checks libraries are where they're supposed to be and replaces some strings
        $ make       # Let make do the heavy work.


-  **src** directory contains the source code of the FreeRCT program itself.
-  **src/rcdgen** directory contains the source code of the *rcdgen* program, that builds RCD files from source (which are read by *freerct*).
- **graphics/rcd** directory contains the source files of the RCD data files, except the graphics.
- **graphics/sprites** directory contains all the graphics of the game.
- **bin** directory contains the actual *freerct* executable along with some other files required to actually run the program.

The *cmake/make* commands above will generate the *rcdgen* program, the rcd files and build the 'freerct' program in the src directory.

Config file
-----------

Finally, you need a 'freerct.cfg' INI format file next to the 'freerct' program in the **bin** directory, containing the path to the font file you want to use. It looks like

::

        [font]
        medium-size = 12
        medium-path = /usr/share/fonts/gnu-free/FreeSans.ttf

This means the medium sized font is 12 points high, and its source font definition file is at the indicated path. Make sure you use a path that actually exists.

The actual file is not that critical, as long as it contains the ASCII characters, in the font-size you mention in the file.

Running the program
-------------------

Now run the program

::

        $ cd bin
        $ ./freerct

or

::

        $ make run

which should open a window containing a piece of greenly coloured flat world, and a toolbar near the left top (see also the pictures in the blog).

Pressing 'q' quits the program.
