##
## make both the widget
## and the widget-control that matches
## the features in the widget
##
## assumes that you've set the AVR32BIN environment
## to point to the directory containing avr32-gcc
all:: Release/widget.elf widget-control

Release/widget.elf::
	./make-widget

audio-widget::
	rm -f Release/widget.elf Release/src/features.o
	CFLAGS=-DFEATURE_DEFAULT_BOARD=feature_board_dib ./make-widget

sdr-widget::
	rm -f Release/widget.elf Release/src/features.o
	CFLAGS=-DFEATURE_DEFAULT_BOARD=feature_board_widget ./make-widget

widget-control: widget-control.c src/features.h
	gcc -o widget-control widget-control.c -lusb-1.0

program:
	cd Release && make program

clean::
	cd Release && make clean
	rm -f widget-control
