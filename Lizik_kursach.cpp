#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>

using namespace std;

class Employe
{
public:
    void set_num(int number)
    {
        num = number;
    }

    int get_num()
    {
        return num;
    }

    void set_money(float mon)
    {
        money = mon;
    }

    float get_money()
    {
        return money;
    }

    void display()
    {
        cout << "Number: " << num <<" " << "Money: " << money << endl;
    }
    void class_read(string n)
    {
        ifstream str(n + ".txt");
        if (str.is_open())
        {
            str >> num >> money;
            str.close();
        }
        else
            cout << "employee not found" << endl;

    }
    void class_write(string n)
    {
        ofstream str(n + ".txt");
        str << num << " " << money;
        str.close();
    }
    void redact (string n)
    {
        cout << "Print money" << endl;
        cin >> money;
        this->set_num(atoi(n.c_str()));
        this->display();
        this->class_write(n);

    }

private:
    int num;
    float money;
};


int main()
{
    while(1)
    {
        Employe a;
        char t;
        int number;
        float mon;
        string n;
        cout << "Would you like to find an employer or add or exit? (F/A/E)" << endl;
        cin >> t;
        if (t == 'e' || t == 'E')
            break;
        else if (t == 'f' || t == 'F')
        {
            cout << "Print number of employer" << endl;
            cin >> n;
            a.class_read(n);
            a.display();
            cout << "Would you like to redact file? (Y/N)" << endl;
            cin >> t;
            if (t == 'n' || t == 'N')
                continue;
            else
            {
                a.redact(n);
            }
        }
        else if(t == 'A' || t == 'a')
        {
            cout << "Print employer number and money" << endl;
            cin >> number >> mon;
            a.set_money(mon);
            a.set_num(number);
            a.class_write(to_string(number));
        }
        system("PAUSE");
        system("CLS");
    }
}
