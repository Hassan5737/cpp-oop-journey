#include <iostream>
using namespace std;

class Dontworry
{
    private:
        int x = 0;
    public:
        void setval()
        {
            cout << "enter the value: " << endl;
            cin >> x;
        }
};

int main()
{
    return 0;
}