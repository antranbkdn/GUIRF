CXXFLAGS	+= -I./source/app/mqtt

VPATH += source/app/mqtt

OBJ += $(OBJ_DIR)/mqtt_sensor.o
OBJ += $(OBJ_DIR)/mqtt_setting.o
OBJ += $(OBJ_DIR)/mqtt_control.o
