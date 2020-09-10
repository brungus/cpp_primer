
#include <iostream>
#include <string>
#include <vector>

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
        // by default, a Window_mgr has one standard sized blank Screen
        std::vector<Screen> screens;
};


class Screen {
    friend void Window_mgr::clear(ScreenIndex);

    public:
        typedef std::string::size_type pos;
        Screen() = default;
        Screen(pos ht, pos wd) : height(ht), width(wd),
                                            contents(ht * wd, ' '){}
        Screen(pos ht, pos wd, char c) : height(ht), width(wd),
                                            contents(ht * wd, c) {}
        Screen &set(char);
        Screen &set(pos, pos, char);

        char get() const
        {
            return contents[cursor];
        }
        inline char get(pos ht, pos wd) const;
        Screen &move(pos r, pos c);

        Screen &display(std::ostream &os)
                        { do_display(os); return *this; }
        const Screen &display(std::ostream &os) const
                        { do_display(os); return *this; }

    private:
        void do_display(std::ostream &os) const { os << contents; }

        mutable size_t access_ctr;
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents;
};

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos row, pos col, char ch)
{
    contents[row * width + col] = ch;
    return *this;
}

Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

void Window_mgr::clear(ScreenIndex i)
{
    // s is a reference to the Screen we want to clear
    Screen &s = screens[i];
    // reset the contents of that Screen to all blanks
    s.contents = std::string(s.height * s.width, ' ');
}
