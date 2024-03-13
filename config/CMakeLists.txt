#################
### Libraries ###
add_library(config INTERFACE)                                                                           ### Add library

#################
### Configure ###
configure_file(config.h.in config.h)                                                                    ### Create h file from h.in

###############
### Options ###
option(CONFIG "Show project verison" OFF)                                                               ### Config option
option(VCR "Check if vector existe" OFF)                                                                ### VCR option
option(GEN "Add expressions" OFF)                                                                       ### GEN option
option(TST "Enable testing support" OFF)                                                                ### TST option

#########################
### Options - (ifdef) ###
if(CONFIG)
    target_compile_definitions(config INTERFACE CONFIG)                                                 ### Activate CONFIG
endif()

if(VCR)
    include(CheckCXXSourceCompiles)                                                                     ### Compiler test
    check_cxx_source_compiles("                                                         
        #include <vector>
        int main()
        { std::vector<int> version;}
        " VCR_ON)                                                                                       ### Code to test
    if(VCR_ON)
        target_compile_definitions(config INTERFACE VCR)                                                ### Activate VCR
    endif()
endif()

if(GEN)
    set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")                    ### Compilers
    set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")                                                     ### Compilers
    target_compile_options(compiler INTERFACE                                                           ### Error options
        "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
        "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
    )
    target_compile_definitions(config INTERFACE GEN)                                                    ### Activate GEN
endif()

###############
### Targets ###
target_link_libraries(config INTERFACE compiler)                                                        ### Link library
target_include_directories(config INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})    ### Include SOURCE/BINARY dir