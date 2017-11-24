TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    DataReader.cpp \
    LeagueManager.cpp \
    ClubChangeWrapper.cpp \
    PlayerChangeWrapper.cpp \
    League.cpp \
    SeasonChangeWrapper.cpp \
    DataWriter.cpp \
    PlayerRecord.cpp \
    ClubRecord.cpp \
    Season.cpp \
    PlayerManager.cpp \
    ClubManager.cpp \
    BestFitPlayerManager.cpp \
    FirstFitPlayerManager.cpp

HEADERS += \
    DataReader.h \
    LeagueManager.h \
    ClubChangeWrapper.h \
    PlayerChangeWrapper.h \
    League.h \
    SeasonChangeWrapper.h \
    DataWriter.h \
    PlayerRecord.h \
    ClubRecord.h \
    Season.h \
    PlayerManager.h \
    ClubManager.h \
    BestFitPlayerManager.h \
    FirstFitPlayerManager.h
