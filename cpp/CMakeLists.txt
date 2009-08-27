project(QtPptXml CXX Java)
cmake_minimum_required(VERSION 2.6)

FIND_PACKAGE(Qt4 4.5.0 REQUIRED)
SET(QT_DONT_USE_QTGUI 1)
SET(QT_USE_QTXML 1)
SET(QT_USE_QTXMLPATTERNS 1)
INCLUDE(${QT_USE_FILE})

ADD_EXECUTABLE(qtpptxml qtpptxml.cpp deepfiletree.cpp pole.cpp leinputstream.cpp)
TARGET_LINK_LIBRARIES(qtpptxml ${QT_LIBRARIES})
