cmake_minimum_required(VERSION 3.8)
project(dual_arm_control)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)


install(DIRECTORY 
  description
  DESTINATION share/${PROJECT_NAME}
)


install(DIRECTORY 
  description/dummy2_dual_arm_config/config/
  DESTINATION share/${PROJECT_NAME}/config
)


install(FILES 
  description/dummy2_dual_arm_config/.setup_assistant
  DESTINATION share/${PROJECT_NAME}
)

install(DIRECTORY 
  launch
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
