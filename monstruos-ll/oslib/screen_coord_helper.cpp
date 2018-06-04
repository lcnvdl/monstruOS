#include "common.h"
#include "screen_coord.h"
#include "screen_coord_helper.h"

MOS::ScreenCordHelper::ScreenCordHelper(int width, int height) {
    this->width = width;
    this->height = height;
}

int MOS::ScreenCordHelper::toOffset(MOS::ScreenCord c) {
    return 2 * (c.row * this->width + c.column);
}

void MOS::ScreenCordHelper::fromOffset(int offset, MOS::ScreenCord& c) {
    c.column = offset / (2 * this->width);
    c.row = (offset - (c.column * 2 * this->width)) / 2;
}