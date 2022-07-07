add_executable(pwm pwm.c)
target_link_libraries(pwm pico_stdlib hardware_pwm)
pico_enable_stdio_usb(pwm 1)
pico_enable_stdio_uart(pwm 0)
                      
# create map/bin/hex file etc.
pico_add_extra_outputs(pwm)