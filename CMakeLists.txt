# CMakeList.txt : CMake project for Primitives, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()


project ("Graphics")


# Add source files to this project's executable.
# Visual Studio and CLion should update this line for you. VS Code will not; for each 
# .h or .cpp file you add to the project, you must add its path to this command.
add_executable (Graphics "src/main.cpp"      )


# Find and link external libraries, like SFML.
# This only works if Vcpkg has been configured correctly.
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(Graphics PRIVATE sfml-system sfml-network sfml-graphics sfml-window)

# Set up our own "/include" folder as the root for #include "...." statements.
target_include_directories(Graphics PUBLIC "./include")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Graphics PROPERTY CXX_STANDARD 20)
endif()
