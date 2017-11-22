TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Club.cpp \
    Player.cpp \
    DataReader.cpp \
    LeagueManager.cpp \
    ClubChangeWrapper.cpp \
    PlayerChangeWrapper.cpp \
    League.cpp \
    SeasonChangeWrapper.cpp \
    Season.cpp \
    SeasonEnrollment.cpp \
    ClubEnrollment.cpp \
    SeasonClubPair.cpp \
    ClubPlayerPair.cpp

HEADERS += \
    Player.h \
    Club.h \
    DataReader.h \
    LeagueManager.h \
    ClubChangeWrapper.h \
    PlayerChangeWrapper.h \
    League.h \
    SeasonChangeWrapper.h \
    Season.h \
    SeasonEnrollment.h \
    ClubEnrollment.h \
    SeasonClubPair.h \
    ClubPlayerPair.h
