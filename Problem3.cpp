#include <iostream>
using namespace std;

int main()
{
    int a;
    int b;
    int c;
    for (a=1; a<=500; a++)
    {
        for (b=1; b<=500; b++)
        {
            c=1000-b-a;
            if (a*a+b*b-c*c == 0 && a<b )
            {
                cout<<a<<" "<<b<<" "<<c<<" "<<a*b*c<<endl;
            }
        }
    }
    return 0;
}