Sangwin 3D Game Engine
======================

Sangwin 3D is a lightweight C++ and OpenGL game engine aimed at the Android OS. It can easily be compiled for Android using the Android NDK, and is compatible with Android 2.2 and above (and possibly older versions, although it hasn't been tested). 

STL
---------
Sangwin 3D uses no STL, and provides custom container classes and smart pointers to provide required behaviour. Container classes, are very similar to their Java counterparts, making it easy to work with both C++ and Java.

STL implementations have recently become available for Android, and so these can be used if preferred.

Using the Engine
---------
Sangwin 3D is extremely easy to use. Check out the (soon to be uploaded) Sangwin Android Framework to see how to make use of the engine code, and look at a very simple example game that shows how everything works.

Netbeans
---------
Sangwin 3D has been developed using Netbeans, and the Netbeans project files are included in the repository. Netbeans is an excellent open source IDE, so make use of the project files if you easily want to import the engine.
 
Redesign
---------
Currently, Sangwin is full of template code that allows both 2D and 3D games to be built. In the near future, this template code will be removed to make the engine simpler and lighter. 2D games will still easily be able to be built, but the code will be far less nasty.