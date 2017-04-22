#ifndef __IF_RF24_H__
#define __IF_RF24_H__

#include "../ak/message.h"

#include <wiringPi.h>
#include <RF24/RF24.h>
#include <RF24Network/RF24Network.h>
#include <RF24Network/RF24Network_config.h>

#define RF24_BUFFER_SIZE		128

extern q_msg_t gw_task_if_rf24_mailbox;
extern void* gw_task_if_rf24_entry(void*);

#endif //__IF_RF24_H__
