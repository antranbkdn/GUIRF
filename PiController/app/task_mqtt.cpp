#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../ak/ak.h"
#include "../ak/timer.h"

#include "app.h"
#include "app_dbg.h"
#include "app_data.h"

#include "mqtt/mqtt_sensor.h"
#include "mqtt/mqtt_setting.h"
#include "mqtt/mqtt_control.h"

#include "task_list.h"
#include "task_mqtt.h"


q_msg_t gw_task_mqtt_mailbox;

void* gw_task_mqtt_entry(void*) {
	task_mask_started();
	wait_all_tasks_started();

	APP_DBG("gw_task_mqtt_entry\n");

	/* config mqtt */
	mqtt_sensor*	mqttsensor	= new mqtt_sensor("sensor", MQTT_HOST, MQTT_PORT);
	mqtt_setting*	mqttsetting	= new mqtt_setting("setting", MQTT_HOST, MQTT_PORT);
	mqtt_control*	mqttcontrol	= new mqtt_control("control", MQTT_HOST, MQTT_PORT);

	while(1){
		while (msg_available(GW_TASK_MQTT_ID)) {
			/* get messge */
			ak_msg_t* msg = rev_msg(GW_TASK_MQTT_ID);

			switch (msg->header->sig) {
			case GW_MQTT_SENSOR_RES:
				APP_DBG("GW_MQTT_SENSOR_RES\n");
				mqttsensor->sensor_public((uint8_t*)"sensor", strlen("sensor"));
				break;

			case GW_MQTT_SETTING_REQ: {
				APP_DBG("GW_MQTT_SETTING_REQ\n");
				int payload_len = msg->header->len;
				char* payload = (char*)malloc(payload_len);
				get_data_dynamic_msg(msg, (uint8_t*)payload, payload_len);
				APP_DBG("SETTING:%s\n", payload);
				free(payload);
			}
				break;

			case GW_MQTT_CONTROL_REQ: {
				APP_DBG("GW_MQTT_CONTROL_REQ\n");
				int sig = 100;
				int payload_len = msg->header->len;
				uint8_t* payload = (uint8_t*)malloc(payload_len);
				get_data_dynamic_msg(msg, (uint8_t*)payload, payload_len);

				APP_DBG("CONTROL:%s\n", payload);
				sig_struct_json(payload, &sig);
				APP_DBG("SIG: %d\n", sig);

				free(payload);
			}
				break;

			case GW_MQTT_SETTING_RES:
				APP_DBG("GW_MQTT_SETTING_RES\n");
				break;

			case GW_MQTT_CONTROL_RES:
				APP_DBG("GW_MQTT_CONTROL_RES\n");
				break;

			default:
				break;
			}

			/* free message */
			free_msg(msg);
		}

		usleep(100);
	}

	return (void*)0;
}
