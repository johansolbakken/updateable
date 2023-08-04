# An updatable piece of software

- I will use Github to store versions of the program.
- The main program will consist of a main loop that will load the actual application as a dynamically linked library.
- When we are updating, the application will reload itself.
- The main function should be able to build the application and pull new versions.

## Updateable

An application library that can get loaded as dylib by loader.

## Loader

A library that provides loading of Updateable applications.

## Examples

### Sandbox

Current example defines a dylib and where its source is. It makes a main.cpp that sets up the loader and a sandbox app that is the app. To run sandbox you need to be in the same folder as libsandboxapp.dylib.

#### Build and run sandbox

```bash
git clone https://github.com/johansolbakken/updateable
cd updateable
mkdir build
cd build
cmake .. -DBUILD_EXAMPLES=On
make
cd examples/sandbox
./sandbox
```

## How to make an application

This example consists of three files. CMakeLists.txt, myproject and myprojectapp. _myproject_ is the loader. _myprojectapp_ is the application code.

**CMakeLists.txt**

```cmake
cmake_minimum_required(VERSION 3.10)

project(myproject)

add_executable(myproject myproject.cpp)
target_include_directories(myproject PRIVATE path/to/loader/src)
target_link_libraries(myproject PRIVATE updatableloader)

add_library(myprojectapp SHARED myprojectapp.cpp)
target_include_directories(myprojectapp PRIVATE path/to/updateable/src)
target_link_libraries(myprojectapp PRIVATE updateable)
```

**myproject.cpp**

```c++
 #include <loader/entrypoint.h>

// "Boilerplate" for setting up the loader
Updateable::Loader *Updateable::createLoader()
{
    Updateable::LoaderSpecification spec;
    spec.name = "myprojectapp";
    return new Updateable::Loader(spec);
}
```

**myprojectapp**

```c++
 #include <updateable/updateable.h>

// Main logic in the layers
class Layer : public Updateable::Layer
{
public:
    ~Layer override = default;

    void onUpdate() override {
        // app logic every frame
    }
};

// Application subclass
class App : public Updateable::Application
{
public:
    App(const Updateable::ApplicationSpecification &spec)
        : Updateable::Application(spec)
    {
        pushLayer(new Layer());
    }

    ~App() override = default;
};

// The function that lets loader create the application
extern "C" Updateable::Application *createApplication()
{
    Updateable::ApplicationSpecification spec;
    spec.name = "App";
    return new App(spec);
}
```
