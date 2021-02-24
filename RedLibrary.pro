QT -= gui

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++17

SOURCES += \
    EncryptionAlgorithms/AesCBC128.cpp \
    EncryptionAlgorithms/AesCBC192.cpp \
    EncryptionAlgorithms/AesCBC256.cpp \
    EncryptionAlgorithms/AesECB128.cpp \
    EncryptionAlgorithms/AesECB192.cpp \
    EncryptionAlgorithms/AesECB256.cpp \
    HashFunctions/Sha256.cpp \
    RedConfig.cpp \
    RedDataBase/Backup.cpp \
    RedDataBase/Column.cpp \
    RedDataBase/Database.cpp \
    RedDataBase/Exception.cpp \
    RedDataBase/Statement.cpp \
    RedDataBase/Transaction.cpp \
    RedEncryptionAlgorithms/ResCBC1024.cpp \
    RedEncryptionAlgorithms/ResCBC1536.cpp \
    RedEncryptionAlgorithms/ResCBC512.cpp \
    RedEncryptionAlgorithms/ResECB1024.cpp \
    RedEncryptionAlgorithms/ResECB1536.cpp \
    RedEncryptionAlgorithms/ResECB512.cpp \
    RedEncryptionAlgorithms/Va1.cpp \

HEADERS += \
    DiffieHellman.h \
    EncryptionAlgorithms/AesCBC128.h \
    EncryptionAlgorithms/AesCBC192.h \
    EncryptionAlgorithms/AesCBC256.h \
    EncryptionAlgorithms/AesECB128.h \
    EncryptionAlgorithms/AesECB192.h \
    EncryptionAlgorithms/AesECB256.h \
    EncryptionAlgorithms/_private/AesDeclarations.h \
    ExecutionTime.h \
    FileBuffer.h \
    HashFunctions/Sha256.h \
    Hex.h \
    InsensitiveMap.h \
    Ipv4.h \
    MemoryChecker.h \
    PassGenerator.h \
    PermissionsLib.h \
    ProgressBar.h \
    RedConfig.h \
    RedConfig/Exceptions.h \
    RedDataBase.h \
    RedDataBase/Assertion.h \
    RedDataBase/Backup.h \
    RedDataBase/Column.h \
    RedDataBase/Database.h \
    RedDataBase/Exception.h \
    RedDataBase/ExecuteMany.h \
    RedDataBase/Statement.h \
    RedDataBase/Transaction.h \
    RedDataBase/Utils.h \
    RedDataBase/VariadicBind.h \
    RedEncryptionAlgorithms/ResCBC1024.h \
    RedEncryptionAlgorithms/ResCBC1536.h \
    RedEncryptionAlgorithms/ResCBC512.h \
    RedEncryptionAlgorithms/ResECB1024.h \
    RedEncryptionAlgorithms/ResECB1536.h \
    RedEncryptionAlgorithms/ResECB512.h \
    RedEncryptionAlgorithms/Va1.h \
    RedEncryptionAlgorithms/_private/ResDeclarations.h \
    RedTypes.h \
    RedTypes/BigInt_definitions.h \
    RedTypes/Int128_t.h

QMAKE_CXXFLAGS += "-Wno-old-style-cast"

macx {
# Boost.
QMAKE_CXXFLAGS += -std=c++17

INCLUDEPATH += "/usr/local/Cellar/boost/1.75.0_1/include/"
LIBS += -L/usr/local/Cellar/boost/1.75.0_1/lib/
## Use only one of these:
LIBS += -lboost_filesystem -lboost_system# -lboost_asio# using dynamic lib
#LIBS += $${_BOOST_PATH}/lib/libboost_chrono-mt.a # using static lib

# Openssl.
INCLUDEPATH += "/usr/local/Cellar/openssl@1.1/1.1.1i/include/"
LIBS += -L/usr/local/Cellar/openssl@1.1/1.1.1i/lib/
LIBS += -lssl
LIBS += -lcrypto

# Fmt.
INCLUDEPATH += "/usr/local/Cellar/fmt/7.1.3/include/"
LIBS += -L/usr/local/Cellar/fmt/7.1.3/lib/
LIBS += -lfmt

# Sqlite.
INCLUDEPATH += "/usr/local/Cellar/sqlite/3.34.0/include/"
LIBS += -L/usr/local/Cellar/sqlite/3.34.0/lib/
LIBS += -lsqlite3

# Unicode.
INCLUDEPATH += "/usr/local/Cellar/icu4c/67.1/include/"
LIBS += -L/usr/local/Cellar/icu4c/67.1/lib/
LIBS += -licuuc

# Gsasl.
INCLUDEPATH += "/usr/local/Cellar/gsasl/1.10.0/include/"
LIBS += -L/usr/local/Cellar/gsasl/1.10.0/lib/
LIBS += -lgsasl.7
}

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target
