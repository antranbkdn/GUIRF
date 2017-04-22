#-------------------------------------------------
#
# Project created by QtCreator 2017-04-19T15:01:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app
#OPTIMIZE	= -g -Os

SOURCES += main.cpp\
        mainwindow.cpp \
    ak/tsm.cpp \
    ak/timer.cpp \
    ak/message.cpp \
    ak/fsm.cpp \
    ak/ak.cpp \
    sys/sys_dbg.cpp \
    driver/rc-switch/RCSwitch.cpp \
    common/jsmn.cpp \
    common/firmware.cpp \
    common/fifo.cpp \
    common/cmd_line.cpp \
    app/task_snmp.cpp \
    app/task_sm.cpp \
    app/task_sensor.cpp \
    app/task_rf433.cpp \
    app/task_mqtt.cpp \
    app/task_list.cpp \
    app/task_if.cpp \
    app/task_firmware.cpp \
    app/task_console.cpp \
    app/if_rf433.cpp \
    app/if_rf24.cpp \
    app/if_console.cpp \
    app/app_data.cpp \
    app/app.cpp \
    app/mqtt/mqtt_setting.cpp \
    app/mqtt/mqtt_sensor.cpp \
    app/mqtt/mqtt_control.cpp \
    thread.cpp

HEADERS  += mainwindow.h \
    ak/timer.h \
    ak/message.h \
    ak/fsm.h \
    ak/ak_dbg.h \
    ak/ak.h \
    sys/sys_dbg.h \
    driver/rc-switch/RCSwitch.h \
    common/jsmn.h \
    common/firmware.h \
    common/fifo.h \
    common/cmd_line.h \
    app/task_snmp.h \
    app/task_sm.h \
    app/task_sensor.h \
    app/task_rf433.h \
    app/task_mqtt.h \
    app/task_list_if.h \
    app/task_list.h \
    app/task_if.h \
    app/task_firmware.h \
    app/task_console.h \
    app/if_rf433.h \
    app/if_rf24.h \
    app/if_console.h \
    app/app_if.h \
    app/app_dbg.h \
    app/app_data.h \
    app/app.h \
    app/mqtt/mqtt_setting.h \
    app/mqtt/mqtt_sensor.h \
    app/mqtt/mqtt_control.h \
    thread.h

#CXX compiler option
QMAKE_CXXFLAGS	+=	-g -Os\
                -std=c++11		\
                -Wall			\
                -Winline		\
                -pipe			\
                -g			\
                -DRPI
# Library paths
QMAKE_LFLAGS	+= -L/usr/local/lib
QMAKE_LFLAGS	+= -L/usr/include
#Library libs
LIBS	+=	-lpthread		\
                -lrt			\
                -lwiringPi		\
                -lwiringPiDev		\
                -lm			\
                -lrf24-bcm		\
                -lrf24network		\
                -lmosquittopp		\
                -lmosquitto
QMAKE_LFLAGS    += -L/usr/local/lib
QMAKE_LFLAGS    += -L/usr/include

FORMS    += mainwindow.ui

OTHER_FILES += \
    ak/Makefile.mk \
    sys/Makefile.mk \
    driver/rc-switch/Makefile.mk \
    common/Makefile.mk \
    app/Makefile.mk \
    app/mqtt/Makefile.mk \
    ../../getway_raspberry/Makefile
