#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

int main() {
    const uint _PIN = 19;
    stdio_init_all();
    gpio_init(_PIN);
    gpio_set_dir(_PIN, GPIO_OUT);

    char buffer[1024];

    while (true) {
        
        scanf("%1024s", buffer);
        printf("%s\n", buffer);
        sleep_ms(500);
    }

}