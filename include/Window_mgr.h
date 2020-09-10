#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <string>
#include <vector>
//#include "Screen.h"

class Screen;

class Window_mgr
{
    public:
        // location ID for each screen on the window
        using ScreenIndex = std::vector<Screen>::size_type;
        // reset the screen at the given position to all blanks
        void clear(ScreenIndex);
    private:
        // Screens this Window_mgr is tracking
        std::vector<Screen> screens{};
};

#endif
