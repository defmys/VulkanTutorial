#include <iostream>
#include <stdexcept>
#include <cstdlib>

#include "application.h"


int main(int argc, char* argv[])
{
    HelloTriangleApplication app;

    std::string argvStr(argv[0]);
    std::string baseDir = argvStr.substr(0, argvStr.find_last_of("/"));
    app.setExePath(baseDir);

    try
    {
        app.run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}
