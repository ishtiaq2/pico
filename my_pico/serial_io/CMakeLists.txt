add_executable(hello_serial
	hello_serial.c)

target_link_libraries(hello_serial pico_stdlib hardware_gpio pico_bootrom)
pico_enable_stdio_usb(hello_serial 1)
pico_enable_stdio_uart(hello_serial 0)

pico_add_extra_outputs(hello_serial)

