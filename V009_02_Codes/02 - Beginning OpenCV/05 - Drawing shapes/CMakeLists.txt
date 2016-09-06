cmake_minimum_required (VERSION 2.8)

# This is the name of the project
PROJECT( drawShapes  )

# This is for recursively searching for other directories.
# add_subdirectory (DirectoryName)

# sources to include
include_directories (.)
FIND_PACKAGE( OpenCV REQUIRED )
ADD_EXECUTABLE( drawShapes  main.cpp)
TARGET_LINK_LIBRARIES( drawShapes ${OpenCV_LIBS} )

