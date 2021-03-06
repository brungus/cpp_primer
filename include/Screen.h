#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include "Window_mgr.h"

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

        // ex. 7.33 pg 368
        pos size() const;

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

// ex. 7.33 pg 368
//Screen::pos Screen::size() const
//{
    //return height * width;
//}

#endif
