cmake_minimum_required(VERSION 3.8)
project(dummy2_dual_arm_config)

# 查找依赖
find_package(ament_cmake REQUIRED)

# 安装配置文件
install(DIRECTORY config/
  DESTINATION share/${PROJECT_NAME}/config
)

# 安装 setup assistant 文件
install(FILES .setup_assistant
  DESTINATION share/${PROJECT_NAME}
)

ament_package()