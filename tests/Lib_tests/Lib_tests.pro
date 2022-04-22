TEMPLATE = app
CONFIG -= qt
CONFIG -= app_bundle
CONFIG += console

QMAKE_CXXFLAGS += -std=c++17

isEmpty(BOOST_INCLUDE_DIR): BOOST_INCLUDE_DIR=$$(BOOST_INCLUDE_DIR)
# set by Qt Creator wizard
isEmpty(BOOST_INCLUDE_DIR): BOOST_INCLUDE_DIR="./../../libs/boost/1.76.0/include"
!isEmpty(BOOST_INCLUDE_DIR): INCLUDEPATH *= $${BOOST_INCLUDE_DIR}

isEmpty(BOOST_INCLUDE_DIR): {
    message("BOOST_INCLUDE_DIR is not set, assuming Boost can be found automatically in your system")
}

SOURCES += \
    AES_tests.cpp \
    PassGenerator_tests.cpp \
    Sha256_tests.cpp \
    Va1_tests.cpp \
    main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../build-RedLibrary-Qt_6_1_3_for_macOS-Release/release/ -lRedLibrary
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../build-RedLibrary-Qt_6_1_3_for_macOS-Release/debug/ -lRedLibrary
else:unix: LIBS += -L$$PWD/../../../build-RedLibrary-Qt_6_1_3_for_macOS-Release/ -lRedLibrary

INCLUDEPATH += $$PWD/../../
DEPENDPATH += $$PWD/../../

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../build-RedLibrary-Qt_6_1_3_for_macOS-Release/release/libRedLibrary.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../build-RedLibrary-Qt_6_1_3_for_macOS-Release/debug/libRedLibrary.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../build-RedLibrary-Qt_6_1_3_for_macOS-Release/release/RedLibrary.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../build-RedLibrary-Qt_6_1_3_for_macOS-Release/debug/RedLibrary.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../build-RedLibrary-Qt_6_1_3_for_macOS-Release/libRedLibrary.a
