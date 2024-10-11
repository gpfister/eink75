//
// gp-pico-template
// Copyright © 2024, Greg PFISTER. MIT License.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the “Software”), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

#include "global.h"
#include "led.h"

// #include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

int main()
{
    int ret = 0; // Return code

    // Initialize led
    ret = pico_led_init();
    hard_assert(ret == PICO_OK);

    // Initialize output
    // ret = stdio_init_all();
    // hard_assert(ret == PICO_OK);

    // Main loop
    const uint32_t currentMS = to_ms_since_boot(get_absolute_time());
    while (ret == 0) {
        // printf("Blink !");
        pico_set_led(true);
        sleep_ms(LED_BLINK_DURATION_MS);

        pico_set_led(false);
        sleep_ms(LED_DELAY_MS);

        ret = (to_ms_since_boot(get_absolute_time()) - currentMS) > 60000;
    }

    return ret;
}
