project(QtPptXml C CXX Java)
cmake_minimum_required(VERSION 2.6)

SET (CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -fexceptions -Wall")

FIND_PACKAGE(Qt4 4.5.0 REQUIRED)
SET(QT_DONT_USE_QTGUI 1)
SET(QT_USE_QTXML 1)
SET(QT_USE_QTXMLPATTERNS 1)
INCLUDE(${QT_USE_FILE})

QT4_ADD_RESOURCES(MSO_RCC_SRCS mso.qrc)

ADD_LIBRARY(qtppt pole.cpp leinputstream.cpp generatedclasses.cpp)

ADD_EXECUTABLE(qtpptxml qtpptxml.cpp deepfiletree.cpp)
TARGET_LINK_LIBRARIES(qtpptxml qtppt ${QT_LIBRARIES})

ADD_EXECUTABLE(qtparseppt qtparseppt.cpp)
TARGET_LINK_LIBRARIES(qtparseppt qtppt ${QT_LIBRARIES})

ADD_EXECUTABLE(pptstructureprinter pptstructureprinter.cpp ${MSO_RCC_SRCS})
TARGET_LINK_LIBRARIES(pptstructureprinter qtppt ${QT_LIBRARIES})

ADD_EXECUTABLE(ppttoxml ppttoxml.cpp)
TARGET_LINK_LIBRARIES(ppttoxml qtppt ${QT_LIBRARIES})

ADD_EXECUTABLE(toxmlandback toxmlandback.cpp)
TARGET_LINK_LIBRARIES(toxmlandback qtppt ${QT_LIBRARIES})
