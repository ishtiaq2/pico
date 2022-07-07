#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"

#define LED_PIN 14
#define true 1
#define false 0

int main() {
    stdio_init_all();
    gpio_set_function(LED_PIN, GPIO_FUNC_PWM);
    int slice_num = pwm_gpio_to_slice_num(LED_PIN);
    pwm_set_wrap(slice_num, 255);
    pwm_set_enabled(slice_num, true);

    int pwm_value = 0;
    int inc = true;
    while(1) {
        if (pwm_value <= 0 ) {
            inc = true;
        } else if (pwm_value >= 255 ) {
            inc = false;
        }
        if (inc) {
            pwm_value = pwm_value + 1;
        } else {
            pwm_value = pwm_value - 5;
        }
        printf("PWM #### : %d \n", pwm_value);
        
        pwm_set_chan_level(slice_num, PWM_CHAN_A, pwm_value);
        sleep_ms(50);
    }
}