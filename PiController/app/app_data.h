#ifndef __APP_DATA_H__
#define __APP_DATA_H__
#include <stdint.h>

/******************************************************************************
* Data type of RF24Network
*******************************************************************************/
#define RF24_DATA_COMMON_MSG_TYPE			(1)
#define RF24_DATA_PURE_MSG_TYPE				(2)
#define RF24_DATA_REMOTE_CMD_TYPE			(3)

/******************************************************************************
* Common define
*******************************************************************************/
#define IF_RETRY_COUNTER_MAX		3

/******************************************************************************
* Commom data structure for transceiver data
*******************************************************************************/
#define FIRMWARE_PSK		0x1A2B3C4D
typedef struct {
	uint32_t psk;
	uint32_t bin_len;
	uint16_t checksum;
} firmware_header_t;

typedef struct {
	uint8_t remote_temperature;
	uint8_t humindity;
	uint32_t air_cond_current[4];
} sensor_packet_t;

typedef struct {
	uint16_t	time_air_counter;			/* time will increase when hr change*/
	uint8_t		time_air_range;				/* range time (hour) saved in epprom */
	uint8_t		total_air_cond;				/* total of air conditional*/
	uint8_t		total_air_cond_alternate;	/* total of air conditional alternate */

	uint8_t		milestone_temp_cool;		/* *C */
	uint8_t		milestone_temp_normal;		/* *C */
	uint8_t		milestone_temp_hot;			/* *C */

	uint8_t		temp_calibration;			/* *C */
	uint8_t		hum_calibration;			/* %RH */

	uint8_t		operations_calib_temp;		/*  */
	uint8_t		operations_calib_hum;		/*  */
} app_setting_t;

typedef struct {
	/* smoke sensor alarm (yes/no)*/
	uint64_t smoke_alarm_yes;
	uint64_t smoke_alarm_no;

	/* water sensor alarm (yes/no) */
	uint64_t water_alarm_yes;
	uint64_t water_alarm_no;

	/* door status (yes/no) */
	uint64_t door_opened_yes;
	uint64_t door_opened_no;
} device_decodes_t;

typedef struct {
	/* smoke sensor alarm (yes/no)*/
	uint8_t smoke_alarm;

	/* water sensor alarm (yes/no) */
	uint8_t water_alarm ;

	/* door status (yes/no) */
	uint8_t door_opened;
} environment_sensor_t;

#define RASP_LOGIN_TYPE			(0xAA)

extern int sensor_json_struct(uint8_t* js, sensor_packet_t* sensor);
extern void sensor_struct_json(uint8_t* js, sensor_packet_t* sensor);

extern void ret_json_struct(uint8_t* js, int* ret);

extern void sig_json_struct(uint8_t* js, int* sig);
extern int sig_struct_json(uint8_t* js, int* sig);

#endif //__APP_DATA_H__
