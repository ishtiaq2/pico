add_executable(adc_example
        adc_example.c
        )

# pull in common dependencies
target_link_libraries(adc_example 
                      hardware_gpio          
                      pico_stdlib 
                      hardware_adc
                      hardware_pwm)

pico_enable_stdio_usb(adc_example 1)
pico_enable_stdio_uart(adc_example 0)
                      
# create map/bin/hex file etc.
pico_add_extra_outputs(adc_example)

