#ifndef __TASK_MQTT_H__
#define __TASK_MQTT_H__

#include <mosquittopp.h>
#include "../ak/message.h"

#define MQTT_HOST "118.69.135.199"
#define MQTT_PORT 1883

extern q_msg_t gw_task_mqtt_mailbox;
extern void* gw_task_mqtt_entry(void*);

#endif //__TASK_MQTT_H__
