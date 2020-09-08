#include <iostream>

void increment(int &rX)
{
    std::cout << "--Incrementing--" << std::endl;
    rX += 1;
}

int main()
{
    int y = 1;
    const int x = 0;
    const int *pX = &x; // doesn't matter if what it's pointer to is const
                        // it "thinks" whatever it's pointer to is const

    int k = 3, *pK = &k; // base type is int
    const int j = 2, *pJ = &j; // base type is const int

    // pointer to int, (int) pointer, (int) (*)
    // can only point to nonconst
    // can be used to changed the value to which it points
    //pK = &j; // illegal, j is const

    // pointer to const int, (const int) pointer, (const int) (*)
    // can point to nonconst and const
    // cannot be used to change the value to which it points
    pJ = &k;

    int b = 4, *const pB = &b;
    const int c = 5, *const pC = &b;

    // constant pointer to int, (int) const pointer, (int) (*const)
    // cannot be changed to point somewhere else
    // can only point to nonconst
    // can be used to change the value to which it points
    //pB = &k; // illegal, pB is a const pointer

    // constant pointer to const int, (const int) (*const)
    // cannot be changed to point somewhere else
    // can point to nonconst and const
    // cannot be used to change value to which it points
    //pC = &c; // illegal, pC is a const pointer

    // int *            pointer to int, (int) pointer
    // const int *      pointer to const int, (const int) pointer, (const int) *
    // int *const       constant pointer to int, int (const pointer) (int) (*const)
    // const int *const constant pointer to constant int, (const int) (const pointer)
    //                  (const int) (*const)

    int myInt = 0;
    std::cout << "myInt: " << myInt << std::endl;
    increment(myInt);
    std::cout << "myInt: " << myInt << std::endl;
    increment(myInt);
    std::cout << "myInt: " << myInt << std::endl;



    return 0;
}
