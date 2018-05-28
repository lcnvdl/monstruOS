#include "common.h"
#include "console_screen.h"
#include "../cpu/isr.h"
#include "../cpu/idt.h"
#include "../cpu/ports.h"

MOS::Drivers::ConsoleScreen::ConsoleScreen() {
    this->helper = new MOS::ScreenCordHelper(MAX_COLS, MAX_ROWS);
}

MOS::Drivers::ConsoleScreen::~ConsoleScreen() {
    delete this->helper;
}

int MOS::Drivers::ConsoleScreen::getSize() {
    return MAX_ROWS * MAX_COLS;
}

void MOS::Drivers::ConsoleScreen::clear() {
    uint8_t *screen = (uint8_t*) VIDEO_ADDRESS;

    for (int i = 0; i < this->getSize(); i++) {
        screen[i*2] = ' ';
        screen[i*2+1] = WHITE_ON_BLACK;
    }

    this->resetCursor();
}

void MOS::Drivers::ConsoleScreen::print(char* message) {

}

void MOS::Drivers::ConsoleScreen::print(char* message, MOS::ScreenCord c) {

}

void MOS::Drivers::ConsoleScreen::setCursor(MOS::ScreenCord c) {
    this->cursor = c;
    this->applyCursor();
}

void MOS::Drivers::ConsoleScreen::resetCursor() {
    this->cursor.column = 0;
    this->cursor.row = 0;
    this->applyCursor();
}

void MOS::Drivers::ConsoleScreen::applyCursor() {
    int offset = this->helper->toOffset(this->cursor);
    offset /= 2;
    port_byte_out(REG_SCREEN_CTRL, 14);
    port_byte_out(REG_SCREEN_DATA, (uint8_t)(offset >> 8));
    port_byte_out(REG_SCREEN_CTRL, 15);
    port_byte_out(REG_SCREEN_DATA, (uint8_t)(offset & 0xff));
}

MOS::ScreenCord MOS::Drivers::ConsoleScreen::getCursor() {
    return this->cursor;
}