Yet Another Pokemon Online Game
===============================

Travis: [![Build Status](https://secure.travis-ci.org/Noxalus/YAPOG.png?branch=travis)](http://travis-ci.org/Noxalus/YAPOG)

What is YAPOG?
--------------

Yet Another Pokemon Online Game (abbreviated into YAPOG)
is a video game project, massively multiplayer online,
in 2D and multiplatform based on the world of Pokemon game series.

Technical specifications
------------------------

YAPOG is developed in C++ and uses the SFML (v2.0) library for multimedia purpose and Boost (v1.49)
library.

As an MMORPG, this project has a database, and we choose PostgreSQL. We use pg_stream, a C++ wrapper of
the official C API of PostgreSQL to communicate with the database.

YAPOG is multiplatform, it can run on Windows and Linux,
we didn't compile it on Mac OS, but it will be fine.
We use the CMake tool to ensure the compatibility
between the different operating systems.

Documentation
-------------

A complete documentation can be generated from our source code with Doxygen, and if you want to read it,
you can go to the current official web site: [here][1].

[1]: http://yapog.free.fr/doc/index.html
