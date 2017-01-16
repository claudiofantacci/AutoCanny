set(TEST_TARGET_NAME AutoCannyTest)
file(GLOB ${TEST_TARGET_NAME}_SRC *.cpp)

find_package(OpenCV REQUIRED)

foreach(TEST_NAME_SRC ${${TEST_TARGET_NAME}_SRC})
    get_filename_component(TEST_NAME ${TEST_NAME_SRC} NAME_WE)

    add_executable(${TEST_NAME} ${TEST_NAME_SRC})
    target_link_libraries(${TEST_NAME} AutoCanny
                                       ${OpenCV_LIBS})

    add_test(NAME ${TEST_NAME} COMMAND $<TARGET_FILE:${TEST_NAME}>)
endforeach()

file(GLOB RESOURCE_FILES *.png)
add_custom_command(TARGET  ${TEST_TARGET_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy ${RESOURCE_FILES} $<TARGET_FILE_DIR:${TEST_NAME}>)
