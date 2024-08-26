#include<led.h>

BitAction Led::update_led() {
	if(this->_current_frame == 0){
		this->_current_frame = this->calls_per_cycle;
		this->_state = Bit_SET;
	} else {
		this->_current_frame--;
	}

	if(this->_switch_frame == this->_current_frame){
		this->_state = Bit_RESET;
	}

	return this->_state;
}

void Led::set_brightness(uint8_t level) {
	this->level = level;
	this->_switch_frame = uint64_t(this->calls_per_cycle / 255 * this->level);
}

Led::Led(uint64_t calls_per_cycle) {
	this->calls_per_cycle = calls_per_cycle;
}

Led::~Led() {
}
