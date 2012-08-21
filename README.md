Yet Another Pokemon Online Game
===============================

[![Build Status](https://secure.travis-ci.org/Noxalus/YAPOG.png?branch=master)](http://travis-ci.org/Noxalus/YAPOG)

What is YAPOG?
--------------

Yet Another Pokemon Online Game (abbreviated into YAPOG) 
is a video game project, massively multiplayer online, 
in 2D and multiplatform based on the world of Pokémon game series.

Technical specifications
------------------------

YAPOG is developed in C++ and use the SFML (v2.0) library for multimedia purpose and Boost (v1.49) 
library.

As an MMORPG, this project have a database, and we choose PostgreSQL. We use pg_stream, a C++ wrapper of
the official C API of PostgreSQL to communicate with the database.

YAPOG is multiplatform, it can run on Windows and Linux, 
we didn't compile it on Mac OS, but it will be fine.
We use the CMake tool to ensure the compatibility
between the different operating systems.

Documentation
-------------

A complete documentation can be generate from our source code with Doxygen, and if you want to read it,
you can go to the current official web site: [here][1].

[1]: http://yapog.free.fr/doc/index.html