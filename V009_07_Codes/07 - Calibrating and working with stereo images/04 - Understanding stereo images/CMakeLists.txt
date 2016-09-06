cmake_minimum_required (VERSION 2.8)

# This is the name of the project
PROJECT( stereo_calib  )

# This is for recursively searching for other directories.
# add_subdirectory (DirectoryName)

# sources to include
include_directories (.)
FIND_PACKAGE( OpenCV REQUIRED )
ADD_EXECUTABLE( stereo_calib  stereo_calib.cpp)
TARGET_LINK_LIBRARIES( stereo_calib ${OpenCV_LIBS} )

