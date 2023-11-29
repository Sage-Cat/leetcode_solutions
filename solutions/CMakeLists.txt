# Define the project
project(SolutionsLib)

# Collect all header and source files
file(GLOB_RECURSE SOLUTION_HEADERS "*.hpp")

# Create a library target for the solutions
add_library(SolutionsLib INTERFACE)
target_include_directories(SolutionsLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
