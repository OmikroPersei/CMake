###################
### Base config ###
cmake_minimum_required(VERSION 3.28.3)                                                      ### Cmake version
project(YETI VERSION 2.3.6)                                                                 ### Project name and version
add_executable(${PROJECT_NAME} main.cpp)                                                    ### Make executable

#################
### Libraries ###
add_library(compiler INTERFACE)                                                             ### Add library

################
### Compiler ###
target_compile_features(compiler INTERFACE cxx_std_11)                                      ### Cxx version

############
### Test ###
include(CTest)                                                                              ### Include module


#########################
### Options - (ifdef) ###
if(CONFIG)                                                                                  ### If option CONFIG=ON
    add_subdirectory(config)                                                                ### Add config dir
    target_link_libraries(${PROJECT_NAME} PUBLIC config)                                    ### Link config dir
    if(VCR)                                                                                 ### If option VCR=ON
        function(make_test target arg result)                                               ### Test function
        add_test(NAME Test:${arg} COMMAND ${target} ${arg})                                 ### Call test function(s)
        set_tests_properties(Test:${arg} PROPERTIES PASS_REGULAR_EXPRESSION ${result})      ### Compare result
        endfunction()
        target_compile_definitions(config INTERFACE TST)                                    ### Activate TST
    endif()
endif()

######################
### Test functions ###
make_test(${PROJECT_NAME} 2 "True")                                                         ### Test function 1
make_test(${PROJECT_NAME} 3 "True")                                                         ### Test function 2

##############
### Linker ###
target_link_libraries(${PROJECT_NAME} PUBLIC compiler)                                      ### Target libarary

#################
### Installer ###
install(TARGETS ${PROJECT_NAME} DESTINATION ${PROJECT_BINARY_DIR}/bin)                      ### Installer 

#################
### Packaging ###
include(InstallRequiredSystemLibraries)                                                     ### Includes
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")                  ### License
set(CPACK_PACKAGE_VERSION_MAJOR "${YETI_VERSION_MAJOR}")                                    ### Pack major version
set(CPACK_PACKAGE_VERSION_MINOR "${YETI_VERSION_MINOR}")                                    ### Pack minor version
set(CPACK_SOURCE_GENERATOR "TGZ")                                                           ### Type
include(CPack)                                                                              ### Includes
