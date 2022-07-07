#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"

#define true 1
#define false 0

#define LED_PIN 14

int main() {

   stdio_init_all();
   adc_init();
   gpio_set_function(LED_PIN, GPIO_FUNC_PWM);
   uint slice_num = pwm_gpio_to_slice_num(LED_PIN);

   pwm_set_wrap(slice_num, 3);
   pwm_set_enabled(slice_num, true);

   uint pwm_value = 0;
   uint inc = true;
   while(1) {
      if (pwm_value < 0 ) {
         inc = true;
      } else if (pwm_value > 3 ) {
         inc = false;
      }
      if (inc) {
         pwm_value = pwm_value + 1;
      } else {
         pwm_value = pwm_value - 1;
      }
      printf("PWM #### : %d \n", pwm_value);
      
      pwm_set_chan_level(slice_num, PWM_CHAN_A, pwm_value);
      sleep_ms(100);
   }
}