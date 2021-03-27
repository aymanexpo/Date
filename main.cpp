#include "Date.h"

int main()
{
    Date d0; // d0 : 01/01/1970
    d0.print();
    Date d1(2020, 2, 27); // d1 : 27/02/2020
    d1.print();
    Date d2(d1); // d2 : 27/02/2020
    d2.print();
    Date d3(d2.incr()); // d2 : 28/02/2020, d3 : 28/02/2020
    d3.incr(); // d3 : 29/02/2020
    d3.incr().print(); // d3 : 01/03/2020
    Date d4(d3.decr()); // d3 : 29/02/2020, d4: 29/02/2020
    d3.print();
    d4.print();
    Date d5(-1234, 13, 320); // d5 : 01/01/1970
    d5.print();
    return 0;
}
