cmake_minimum_required(VERSION 2.8)
PROJECT(VirtualKeyboard)
# 增加一个可执行的二进制

#add c++11
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") 

# 增加opencv的依赖
FIND_PACKAGE( OpenCV REQUIRED )
SET( CMAKE_BUILD_TYPE Debug  )

# set(PCL_INCLUDE_DIRS /usr/include/pcl-1.8)
# 添加头文件和库文件
# file(GLOB_RECURSE SRC ${PROJECT_SOURCE_DIR}/*.cpp)

INCLUDE_DIRECTORIES( ${PROJECT_SOURCE_DIR}/include )

# ADD_EXECUTABLE(test ${SRC})
ADD_EXECUTABLE(deal ${PROJECT_SOURCE_DIR}/src/deal.cpp)
TARGET_LINK_LIBRARIES( deal ${OpenCV_LIBS})
ADD_EXECUTABLE(main ${PROJECT_SOURCE_DIR}/src/main.cpp ${PROJECT_SOURCE_DIR}/src/detect.cpp ${PROJECT_SOURCE_DIR}/src/player.cpp)
TARGET_LINK_LIBRARIES(main ${OpenCV_LIBS})
