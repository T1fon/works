#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <sstream>

using namespace std;

class Employe
{
public:
    string a[3];
    int j = 0;
    void getemploy(int number, float mon, string position, string d)
    {
       num = number;
       money = mon;
       pos = position;
       date = d;
    }

    void display()
    {
        cout << "Number: " << num <<" " << "Money: " << money << " " << "Position: " << pos << " " << "Date: " << date << " "<< endl;
    }
    void putemploy()
    {

        string q;
        stringstream ss;
        ss << num;
        ss >> q;
        a[j] = a[j] +  "Number: " + q;
        ss << money;
        ss >> q;
        a[j] = a[j] + " "  + "Money: "+ q + " " +"Position: " + pos + " " + "Date: " + " " + date;
        j++;
    }
    void print_put()
    {
        for (int i = 0; i < 3; i++)
        {
            cout << a[i];
            cout << endl;

        }
        j = 0;
    }
    void add_file(string n)
    {
        ofstream f;
        f.open(n + ".txt");
        for (int i = 0; i < 3; i++)
            f << a[i] << endl;
        f.close();
    }

private:
    int num;
    float money;
    string pos;
    string date;
};


int main()
{
    while(1)
    {
        Employe a;
        int number;
        float mon;
        string position, d;
        string n;
        char t;
        cout << "Add new file, or you have got one? (A/F/E) (find is not ready yet)" << endl;
        cin >> t;
        if (t == 'e' || t == 'E')
            break;
        else if (t == 'A' || t == 'a')
        {
            cout << "Write name of file" << endl;
            cin >> n;
            for (int i = 0; i < 3; i++)
            {
                cout << "Write num ";
                cin >> number;
                cout << "Write money ";
                cin >> mon;
                cout << "Write position ";
                cin >> position;
                cout << "Write date ";
                cin >> d;
                a.getemploy(number, mon, position, d);
                cout << endl;
                a.display();
                a.putemploy();
            }
            cout << endl;
            a.print_put();
            a.add_file(n);

        }
        system("PAUSE");
        system("CLS");
    }
}

