#include <zephyr/zbus/zbus.h>

#include "message_channel.h"

#define LOG_LEVEL CONFIG_LOG_DEFAULT_LEVEL
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(main);

/* Boot to State Standby */
// static enum sys_states sys_state = SYS_STANDBY;


// static void led_msg(enum sys_states msg)
// {
// 	int err;

// 	err = zbus_chan_pub(&led_ch, &msg, K_SECONDS(1));
// 	if (err) {
// 		LOG_ERR("zbus_chan_pub, error: %d", err);
// 	}
// }

// static void button_msg_cb(const struct zbus_channel *chan)
// {
// 	const enum sys_events *msg_type;

// 	/* Get message from channel. */
// 	msg_type = zbus_chan_const_msg(chan);

// 	if (*msg_type != SYS_BUTTON_PRESSED) {
// 		/* Ignore other messages */
// 		return;
// 	}

// 	/* Assign new system state */
// 	switch (sys_state) {
// 	case SYS_SLEEP:
// 		sys_state = SYS_STANDBY;
// 		LOG_INF("System state standby");
// 		break;
// 	case SYS_STANDBY:
// 		sys_state = SYS_SLEEP;
// 		LOG_INF("System state sleep");
// 		break;
// 	default:
// 		return;
// 		break;
// 	}

// 	led_msg(sys_state);
// }

int main(void)
{
	/* Notify the LED module about the initial system state */
	// led_msg(sys_state);

	return 0;
}

// ZBUS_LISTENER_DEFINE(button_test, button_msg_cb);
// ZBUS_CHAN_ADD_OBS(button_ch, button_test, DEFAULT_OBS_PRIO);