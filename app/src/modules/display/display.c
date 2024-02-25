#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/display.h>
#include <zephyr/zbus/zbus.h>
#include <lvgl.h>
#include <app_version.h>

#include "message_channel.h"

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(display, CONFIG_DISPLAY_MODULE_LOG_LEVEL);

static const struct device *display = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));

static int init(void)
{
	int ret;
	char line1_str[32] = {0};
	lv_obj_t *line1_label;

	if (!device_is_ready(display)) {
		LOG_ERR("Display device not ready");
		return 0;
	}

	line1_label = lv_label_create(lv_scr_act());
	sprintf(line1_str, "%s: %s", CONFIG_BOARD, APP_VERSION_STRING);
	lv_label_set_text(line1_label, line1_str);
	lv_obj_align(line1_label, LV_ALIGN_CENTER, 0, 0);

	lv_task_handler();

	return 0;
}

SYS_INIT(init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);