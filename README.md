Sangwin 3D Game Engine
======================

Sangwin is a lightweight C++ and OpenGL game engine aimed at the Android OS. It can easily be compiled for Android using the Android NDK, and is compatible with Android 2.2 and above (and possibly older versions, although it hasn't been tested). 

Using the Engine
---------
Sangwin 3D is extremely easy to use. Check out the (soon to be uploaded) Sangwin Android Framework to see how to make use of the engine code, and look at a very simple example game that shows how everything works.

The Android.mk file included in the roor directory will compile the engine into a single, static library. This can then be used with any Android project; the Usage-Android.mk shows how to go about including the compiled library.

STL
---------
Sangwin 3D uses no STL, and provides custom container classes and smart pointers to provide required behaviour. Container classes are very similar to their Java counterparts, making it easy to work with both C++ and Java.

This also keeps the size of the binary as small as possible, making the engine extremely lightweight.

Documentation
----------
The engine has been fully documented in the Javadoc style using Doxygen. This can be found in the /docs/html/ directory of the repository.
 
TODO
---------
The following describes the current, immediate plans for the engine:

* Remove template code throughout
* Upload AndroidRenderer
* Improve memory management strategy

Last of All...
---------
The Sangwin Engine is very much in its early stages, so please fork and add as much you can! We still need animation, physics and AI! 
