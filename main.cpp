#include <iostream>
#ifdef CONFIG
    #include "config.h"
#endif
#ifdef VCR
    #include <vector>
#endif

int main(int argc, char** argv)
{
    std::cout << "Start Test" << std::endl; // start project test

    #ifdef CONFIG   // if CONFIG=ON
        std::cout << "Min Version: " << YETI_VERSION_MINOR << std::endl;    // PROJECT VERSION MINOR
        std::cout << "Max Version: " << YETI_VERSION_MAJOR << std::endl;    // PROJECT VERSION MAJOR
    #endif

    #ifdef VCR  // if VCR=ON && std::<vector> existe
        std::vector<int> version;
        version.push_back(YETI_VERSION_MAJOR);  // add some value
        version.push_back(YETI_VERSION_MINOR);  // add some value

        std::cout << "Version is: ";
        for(int i : version)    // print project version from vector
        {
            std::cout << i << ".";
        }
        std::cout << "patch" << std::endl;  // termine by patch

        #ifdef TST
            bool donce = false;     // init donce bool
            for(int i : version)    // print project version from vector
            {
                if(argc > 1 && donce != true)   // if any arg passed
                {
                    if(i == std::stoi(argv[1])) // if arg passed = arg in vector
                    {
                        std::cout << "True" << std::endl;   // send True to test
                        donce = true;
                    }
                }
            }
        #endif
    #endif

    #ifdef GEN // if GEN=ON
        int unused; // unused variable 
    #endif
    
    std::cout << "End Test" << std::endl; // end project test
    return 0;
}