#include <gb/gb.h>
#include "vwf.h"
#include "vwf_font.h"
#include "vwf_font_bold.h"
#include "vwf_font_ru.h"

void main() {
    fill_bkg_rect(0, 0, 20, 18, 0x00u);
    SHOW_BKG;

    vwf_load_font(0, vwf_font, (UBYTE)&__bank_vwf_font);
    vwf_load_font(1, vwf_font_bold, (UBYTE)&__bank_vwf_font_bold);
    vwf_load_font(2, font_ru, (UBYTE)&__bank_font_ru);
    vwf_activate_font(2);

/*
    UBYTE buf[17];
    UBYTE k = 0x20;
    for(UBYTE i = 0; i != 14; i++) {
        for(UBYTE j = 0; j != 16; j++) buf[j] = k++;
        buf[16] = 0;
        vwf_draw_text(0, i, (i * 16) + 1, buf);   
    } 
*/
    vwf_draw_text(3, 3, 1, "Hello, world!\n\x01\x01\BOLD\x01\x00\n\x03\xffthis is a \x01\x01test\x01\x00\x03\x00\nof the new line\ncontrol symbol");
    vwf_draw_text(8, 9, vwf_next_tile(), "This is another\ntext block that is\nprinted in the other\nplace on screen");
    vwf_draw_text(12, 1, vwf_next_tile(), "The third\ntext block\nto the right\nof the first\none");
}

