#ifndef __MOS_DRIVERS_CONSOLE_SCREEN_H
#define __MOS_DRIVERS_CONSOLE_SCREEN_H

#define VIDEO_ADDRESS 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80
#define WHITE_ON_BLACK 0x0f
#define RED_ON_WHITE 0xf4
#define REG_SCREEN_CTRL 0x3d4
#define REG_SCREEN_DATA 0x3d5

#include "screen_coord.h"
#include "screen_coord_helper.h"

namespace MOS {
    namespace Drivers {

        class ConsoleScreen {

            private:
                MOS::ScreenCord cursor;
                MOS::ScreenCordHelper* helper;

                int getSize();
                void resetCursor();
                void setCursor(ScreenCord c);
                MOS::ScreenCord getCursor();
                void applyCursor();

            public:
                ConsoleScreen();
                ~ConsoleScreen();

                void clear();
                void print(char* message);
                void print(char* message, MOS::ScreenCord c);

        };

    }
}

#endif