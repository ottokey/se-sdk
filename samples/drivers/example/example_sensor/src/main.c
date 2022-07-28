/*
 * Copyright (c) 2021 Antmicro <www.antmicro.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <kernel.h>
#include <device.h>
#include <drivers/sensor.h>
#include <example/example.h>
#include <project_version.h>

void main(void)
{
	printk("Sample started (v%s)\n", PROJECT_VERSION_STRING);

	while (true) {
		const struct device *dev = device_get_binding("EXAMPLE_SENSOR");
		struct sensor_value val;

		printk("Fetching sample...\n");
		sensor_sample_fetch(dev);
		if (sensor_channel_get(dev, SENSOR_CHAN_AMBIENT_TEMP, &val) == 0) {
			printk("Temperature: %d.%d\n", val.val1, val.val2);
		} else {
			printk("Failed to read sensor\n");
		}
	}
};