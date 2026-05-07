#include <iostream>
using namespace std;

class Stu
{
    private:
        string name;
        int mark;
    public:
        Stu(string n, int m)
        {
            name = n;
            mark = m;
        }
        Stu()
        {
            cout << "Enter the name: " << endl;
            cin >> name;
            cout << "Enter the mark: " << endl;
            cin >> mark;
        }

        friend int sum(Stu ob1, Stu ob2, Stu ob3);

        void checkMarks(Stu ob1, Stu ob2, Stu ob3)
        {
            if(ob1.mark > ob2.mark && ob1.mark > ob3.mark)
                cout << ob1.name << endl;

            else if(ob2.mark > ob1.mark && ob2.mark > ob3.mark)
               cout << ob2.name << endl;

            else if(ob3.mark > ob1.mark && ob3.mark > ob2.mark)
             cout << ob3.name << endl;

            else 
                cout << "all the marks are equal" << endl;
        }

};

int sum(Stu ob1, Stu ob2, Stu ob3)
{
    return ob1.mark + ob2.mark + ob3.mark;
}


int main()
{
    Stu ob1("Ahmed" , 50);
    Stu ob2("Ali" , 60);
    Stu ob3("nour" , 100);

}