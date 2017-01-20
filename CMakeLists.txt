cmake_minimum_required(VERSION 3.0)

project(AutoCanny
        LANGUAGES CXX
        VERSION 0.1.0.0)

include(GNUInstallDirs)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

### OPTIONS ###

option(BUILD_SHARED_LIBS "Build libraries as shared as opposed to static" ON)

option(BUILD_TESTING "Create tests" OFF)
if(BUILD_TESTING)
    enable_testing()
endif(BUILD_TESTING)

option(ENABLE_RPATH "Enable RPATH for this library" ON)
mark_as_advanced(ENABLE_RPATH)
include(AddInstallRPATHSupport)
add_install_rpath_support(BIN_DIRS "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_BINDIR}"
                          LIB_DIRS "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}"
                          DEPENDS ENABLE_RPATH
                          USE_LINK_PATH)

### COMPILE/INSTALL COMMANDS ###
add_subdirectory(src)

# Install the files necessary to call find_package(AutoCanny) in CMake projects
include(InstallBasicPackageFiles)
install_basic_package_files(${PROJECT_NAME} VARS_PREFIX ${PROJECT_NAME}
                                            VERSION ${${PROJECT_NAME}_VERSION}
                                            COMPATIBILITY AnyNewerVersion
                                            TARGETS_PROPERTY ${PROJECT_NAME}_TARGETS
                                            NO_CHECK_REQUIRED_COMPONENTS_MACRO)

include(AddUninstallTarget)

if(BUILD_TESTING)
    add_subdirectory(test)
endif()
