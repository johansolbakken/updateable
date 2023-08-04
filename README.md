# An updatable piece of software

* I will use Github to store versions of the program.
* The main program will consist of a main loop that will load the actual application as a dynamically linked library.
* When we are updating, the application will reload itself. 
* The main function should be able to build the application and pull new versions.

## Sandbox
Current example defines a dylib and where its source is. It makes a main.cpp that sets up the loader and a sandbox app that is the app. To run sandbox you need to be in the same folder as libsandboxapp.dylib.

### Build and run sandbox
~~~bash
git clone https://github.com/johansolbakken/updateable
cd updateable
mkdir build
cd build
cmake .. -DBUILD_EXAMPLES=On
make
cd examples/sandbox
./sandbox
~~~