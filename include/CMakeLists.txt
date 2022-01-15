message(STATUS "Creating libraries targets")

add_library(R_app ruffini/App.hpp ../src/ruffini/App.cpp)

# set_property(TARGET R_app PROPERTY CXX_STANDARD 20)
target_compile_features(R_app PUBLIC cxx_std_20)

# include_directories(${CMAKE_BINARY_DIR}/src)

#[============================================================================[
# Adding libraries to #include
#]============================================================================]
message(STATUS "Adding libraries to include")
include_directories(R_app PUBLIC "${CMAKE_CURRENT_LIST_DIR}")
