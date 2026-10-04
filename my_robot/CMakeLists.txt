cmake_minimum_required(VERSION 3.0.2)
project(my_robot)

# ---- C++ 标准：Focal 的 gcc 9 默认是 gnu++14，要 17 必须显式声明 ----
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -Wpedantic)

find_package(catkin REQUIRED COMPONENTS
  roscpp std_msgs sensor_msgs tf2_ros
)

catkin_package(CATKIN_DEPENDS roscpp std_msgs sensor_msgs tf2_ros)

include_directories(${catkin_INCLUDE_DIRS})

add_executable(my_node src/my_node.cpp)
target_link_libraries(my_node ${catkin_LIBRARIES})
# ↓ 新手第一大坑：msg/srv 生成的头文件依赖它，漏了报 "xxx/msg/y.h: No such file"
add_dependencies(my_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

install(TARGETS my_node RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
