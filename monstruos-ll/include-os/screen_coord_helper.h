#ifndef __MOS_SCREEN_CORD_HELPER_H
#define __MOS_SCREEN_CORD_HELPER_H

#include "common.h"
#include "screen_coord.h"

namespace MOS {
    class ScreenCordHelper {

        private:
            int width;
            int height;

        public:
            ScreenCordHelper(int, int);
            int toOffset(MOS::ScreenCord);
            void fromOffset(int, MOS::ScreenCord&);
    };
}

#endif