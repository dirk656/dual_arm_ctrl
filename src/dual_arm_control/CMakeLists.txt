cmake_minimum_required(VERSION 3.22)
project(dual_arm_control)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)

# Install launch files
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/launch")
  install(
    DIRECTORY launch
    DESTINATION share/${PROJECT_NAME}
    PATTERN "setup_assistant.launch" EXCLUDE)
endif()

# Install config directory
install(DIRECTORY description/dummy2_dual_arm_config/config DESTINATION share/${PROJECT_NAME})

# Install setup assistant file if exists
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/description/dummy2_dual_arm_config/.setup_assistant")
  install(FILES description/dummy2_dual_arm_config/.setup_assistant DESTINATION share/${PROJECT_NAME})
endif()

ament_package()
