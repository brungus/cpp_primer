#include <vector>
#include "Screen.h"

class Window_mgr
{
    private:
        // Screens this Window_mgr is tracking
        // by default, a Window_mgr has one standard sized blank Screen
        std::vector<Screen> screens{ Screen(24, 80, ' ') };
};
