add_executable(input
        input.c
        )

add_executable(onoff
	onoff.c)

add_executable(output
	output.c)

# pull in common dependencies
target_link_libraries(input pico_stdlib hardware_gpio)
target_link_libraries(onoff pico_stdlib hardware_gpio)
target_link_libraries(output pico_stdlib hardware_gpio)
pico_enable_stdio_usb(input 1)
pico_enable_stdio_uart(input 0)
pico_enable_stdio_usb(onoff 1)
pico_enable_stdio_uart(onoff 0)
pico_enable_stdio_usb(output 1)
pico_enable_stdio_uart(output 0)

pico_add_extra_outputs(input)
pico_add_extra_outputs(onoff)
pico_add_extra_outputs(output)

