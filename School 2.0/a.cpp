#include <bits/stdc++.h>
using namespace std;
class A
{
protected:
    int a;

public:
    void get();
    void put();
    int get_num();
};
void A::get()
{
    cout << "\nenter number\n";
    cin >> a;
}
void A::put()
{
    cout << a << endl;
}
int A::get_num()
{
    return a;
}
void file()
{
    A t;
    int n, i;
    cout << "\nenter no of records you want to enter\n";
    cin >> n;
    fstream fout("abc.dat", ios::binary | ios::app);
    if (!fout)
    {
        cout << "\nerror";
    }
    for (i = 0; i < n; i++)
    {
        t.get();
        fout.write((char *)&t, sizeof(t));
    }
}
void d()
{
    A t;
    fstream fin("abc.dat", ios::binary | ios::in);
    while (fin.read((char *)&t, sizeof(t)))
    {
        t.put();
    }
}
void kaam()
{
    A t, t1;
    int min, r = 0, f = 0;
    fstream fin("abc.dat", ios::binary | ios::in | ios::out);
    while (fin.read((char *)&t, sizeof(t)))
    {
        r++;
        if(t.get_num()>t1.get_num()){
            
        }
    }
}
main()
{
    kaam();
}