// ex. 7.43 pg 381

class NoDefault
{
    public:
        //NoDefault() = default;
        NoDefault(int) {};
};

class C
{
    public:
        C() : mem(-1) {}
    private:
        NoDefault mem;
};
