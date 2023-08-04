#include "loader/loader.h"

int main(int argc, char **argv)
{
    auto loader = Updateable::createLoader();
    loader->run();
    delete loader;
    return 0;
}