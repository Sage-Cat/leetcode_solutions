find_package(GTest REQUIRED)

file(GLOB TEST_SOURCES CONFIGURE_DEPENDS "*.cpp")
foreach(SOURCE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${SOURCE} NAME_WE)
    add_executable(${TEST_NAME} ${SOURCE})
    target_link_libraries(${TEST_NAME} GTest::GTest GTest::Main SolutionsLib) 
    target_include_directories(${TEST_NAME} PRIVATE ${SOLUTIONS_DIR})

    # Register the test with CMake's testing system
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()
