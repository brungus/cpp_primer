// ex. 7.34 pg 373
#include <string>
class Screen
{
    public:
        typedef std::string::size_type pos;

    private:
        pos cursor = 0;
        pos height = 0, width = 0;
};

// ex. 7.35 pg 373
typedef std::string Type;
Type initVal();
class Exercise
{
    public:
        typedef double Type;
        Type setVal(Type);
        Type initVal();
    private:
        int val;
};

Exercise::Type Exercise::setVal(Type parm)
{
    val = parm + initVal();
    return val;
}
