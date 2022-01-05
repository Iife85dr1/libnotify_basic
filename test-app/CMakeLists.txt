set(APP-NAME test-app)

add_executable(${APP-NAME} main.cpp)
target_link_libraries(${APP-NAME} PRIVATE ${PROJECT_NAME})
