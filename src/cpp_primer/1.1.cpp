#include <iostream>

void nested_read()
{
    int currVal = 0, val = 0;
    if (std::cin >> currVal)
    {
        int cnt = 1;
        while (std::cin >> val)
        {
            if (val == currVal)
                ++cnt;
            else
            {
                std::cout << currVal << " occurs "
                          << cnt << " times" << std::endl;
                currVal = val;
                cnt = 1;
            }
        }
    }
}

void read_until_line()
{
    int sum = 0, val = 0;

    // read until end of file, calculating a running total of all values read
    while (std::cin >> val)
    {
        sum += val;
    }

    std::cout << "sum is " << sum << std::endl;
}

void read()
{
    int a = 0, b = 0;

    std::cout << "please enter two value" << std::endl;
    std::cin >> a >> b;
    std::cout << " the multiplication of " << a << " multiplied by " << b << " is " << a * b << std::endl;
}

int main()
{
    // read_until_line();
    // nested_read();

    int a = 4;
    int b = 8;
    int *p1 = &a;
    int *p2 = p1;

    int **p3 = &p2; // p3 is a pointer to pointer p2
    int *&r = p1; // r is a reference to pointer p1;
    r = &b; // makes p1 point to b; 

    std::cout << *p1 << std::endl;
    std::cout << *p2 <<std::endl;
    return 0;
}