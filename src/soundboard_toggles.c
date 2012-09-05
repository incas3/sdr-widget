#include "soundboard_toggles.h"
#include "print_funcs.h"
#include "features.h"
#include "gpio.h"

uint8_t last_feature = 0;

void feature_changed(uint8_t index,uint8_t feature) {
	switch(index) {
		case feature_phantom_index:
			switch (feature) {
				case feature_phantom_on:
					gpio_set_gpio_pin(AT1201_PHANTOM);  //enable phantom power
					print_dbg("Feature changed to phantom on\n");
				break;

				case feature_phantom_off:
					gpio_clr_gpio_pin(AT1201_PHANTOM);  //enable phantom power
					print_dbg("Feature changed to phantom off\n");
				break;
			}
		break;
		case feature_high_pass_index:
			switch (feature) {
				case feature_high_pass_on:
					gpio_clr_gpio_pin(AT1201_HPFE); 
					print_dbg("Feature changed to high pass on\n");
				break;

				case feature_high_pass_off:
					gpio_set_gpio_pin(AT1201_HPFE); 
					print_dbg("Feature changed to high pass off\n");
				break;
			}
		break;
		case feature_test_signal_index:
			switch (feature) {
				case feature_test_signal_ch1:
					gpio_set_gpio_pin(AT1201_TEST_SIG1); // test sig 1
					gpio_clr_gpio_pin(AT1201_TEST_SIG2); // test sig 2
					print_dbg("Feature test_signal_ch1\n");
				break;

				case feature_test_signal_ch2:
					gpio_clr_gpio_pin(AT1201_TEST_SIG1); // test sig 1
					gpio_set_gpio_pin(AT1201_TEST_SIG2); // test sig 2
					print_dbg("Feature test_signal_ch2\n");
				break;

				case feature_test_signal_both:
					gpio_set_gpio_pin(AT1201_TEST_SIG1); // test sig 1
					gpio_set_gpio_pin(AT1201_TEST_SIG2); // test sig 2
					print_dbg("Feature test_signal_both\n");
				break;

				case feature_test_signal_off:
					gpio_clr_gpio_pin(AT1201_TEST_SIG1); // test sig 1
					gpio_clr_gpio_pin(AT1201_TEST_SIG2); // test sig 2
					print_dbg("Feature test_signal_off\n");
				break;
			}
		break;
	}
	
}