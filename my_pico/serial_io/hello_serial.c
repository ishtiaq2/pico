#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"

#define LED_PIN 19

int main() {
	stdio_init_all();
	char buffer[1024];

	gpio_init(LED_PIN);
	gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 1);    
	while(1) {
        printf("%s\n", "Hello serial!");
		//scanf("%1024s", buffer);
        //char c = getchar();
		printf("%s\n", buffer);
		/**if (strcmp(buffer, "ON") == 0)
		{
			gpio_put(LED_PIN, 1);
		} else if (strcmp(buffer, "OFF") == 0)
		{
			gpio_put(LED_PIN, 0);
		} else if (strcmp(buffer, "REBOOT") == 0)
		{
			reset_usb_boot(0,0);
		}*/
        sleep_ms(1000);
	}	

}