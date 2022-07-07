add_executable(uart
        uart.c
        )

# pull in common dependencies
target_link_libraries(uart pico_stdlib)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(uart)

# add url via pico_set_program_url
#example_auto_set_url(uart)
