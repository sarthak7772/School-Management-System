#include <bits/stdc++.h>
using namespace std;
void admin();
void main_menu();
void view_teacher();
void view_student();
void admin_after_login(int);
void admin_create();
void input(int);
void display_admin_details();
void teacher_after(int);
void student_after(int);
void teacher_login();
void student_login();
void Dheke(int);
int find(int);
void display(int);
void update(int);
void del(int);
class school
{
protected:
    int pin;
    long long int phone;
    char add[40], doj[20], dob[20], name[20], id[20], pass[20];

public:
    void get();
    void disp();
    char *get_id();
    char *get_pass();
    void display();
};
void school::disp()
{
    cout << id << " " << pass << "\n";
}
void school::display()
{
    cout << "\n****************************************Welcome to***************************************************\n";
    cout << "\n************************************HOly angels school************************************************\n";
    cout << "\n*****************************************About Us******************************************************\n";
}
void school::get()
{
    cout << "\nEnter ID\n";
    cin >> id;
    cout << "\nEnter PASSWORD\n";
    cin >> pass;
}
char *school::get_id()
{
    return id;
}
char *school::get_pass()
{
    return pass;
}
class student : public school
{
protected:
    int roll, h, e, s;

public:
    void get();
    void put();
    void login();
    int get_roll();
    char *get_dob();
    void disp();
};
void student::login()
{
    cout << "\nEnter roll number\n";
    cin >> roll;
    cout << "\nEnter dob\n";
    cin.ignore();
    gets(dob);
}
int student::get_roll()
{
    return roll;
}
char *student::get_dob()
{
    return dob;
}
void student::disp()
{
    cout << name << " " << doj << endl;
}
class teacher : public school
{
protected:
    int code, hra, vda, basic;

public:
    void get();
    void put();
    void login();
    int get_code();
    char *get_dob();
    void disp();
};
void teacher::login()
{
    cout << "\nEnter code\n";
    cin >> code;
    cout << "\nEnter dob\n";
    cin.ignore();
    gets(dob);
}
int teacher::get_code()
{
    return code;
}
char *teacher::get_dob()
{
    return dob;
}
void teacher::disp()
{
    cout << name << " " << doj << endl;
}
void student::get()
{
    cout << "\nEnter  name =  ";
    cin.ignore();
    gets(name);
    cout << "\nEnter  roll number = ";
    cin >> roll;
    cout << "\nEnter  pin =  ";
    cin >> pin;
    cout << "\nEnter  Phone number = ";
    cin >> phone;
    cout << "\nEnter Address = ";
    cin.ignore();
    gets(add);
    cout << "\nEnter Date of birth = ";
    gets(dob);
    cout << "\nEnter Date of joining = ";
    gets(doj);
    cout << "\nEnter marks of hindi";
    cin >> h;
    cout << "\nEnter marks of english";
    cin >> e;
    cout << "\nEnter marks of science";
    cin >> s;
}
void student::put()
{
    cout << name << "           " << roll << "           " << pin << "           " << phone << "           " << add << "           " << dob << "           " << doj << "           " << h << "           " << e << "           " << s << "           " << (e + h + s) << endl;
}
void teacher::get()
{
    cout << "\nEnter  name =  ";
    cin.ignore();
    gets(name);
    cout << "\nEnter  code = ";
    cin >> code;
    cout << "\nEnter  pin =  ";
    cin >> pin;
    cout << "\nEnter  Phone number = ";
    cin >> phone;
    cout << "\nEnter Address = ";
    cin.ignore();
    gets(add);
    cout << "\nEnter Date of birth = ";
    gets(dob);
    cout << "\nEnter Date of joining = ";
    gets(doj);
    cout << "\nEnter basic salary =";
    cin >> basic;
    cout << "\nEnter HRA =";
    cin >> hra;
    cout << "\nEnter VDA =";
    cin >> vda;
}
void teacher::put()
{
    cout << name << "           " << code << "           " << pin << "           " << phone << "           " << add << "           " << dob << "           " << doj << "           " << basic << "           " << hra << "           " << vda << "           " << (basic + hra + vda) << endl;
}
void input(int x)
{
    if (x == 1)
    {
        student t;
        cout << "\nFor Student";
        ofstream fout("student.dat", ios::binary | ios::app);
        if (!fout)
        {
            cout << "\nerror in opening\n";
        }
        int n, i;
        cout << "\nEnter number of records you have to enter\n";
        cin >> n;
        for (i = 0; i < n; i++)
        {
            t.get();
            fout.write((char *)&t, sizeof(t));
        }
        fout.close();
    }
    else
    {
        cout << "\nFor Teacher";
        teacher t;
        ofstream fout("teacher.dat", ios::binary | ios::app);
        if (!fout)
        {
            cout << "\nerror in opening\n";
        }
        int n, i;
        cout << "\nEnter number of records you have to enter\n";
        cin >> n;
        for (i = 0; i < n; i++)
        {
            t.get();
            fout.write((char *)&t, sizeof(t));
        }
        fout.close();
    }
}
void display(int x)
{
    if (x == 1)
    {
        student t;
        ifstream fin("student.dat", ios::binary | ios::in);
        if (!fin)
        {
            cout << "\nerror in opening\n";
        }
        cout << "\nStudents Data";
        cout << "\nNAME"
             << "           "
             << "Roll"
             << "           "
             << "PIN"
             << "           "
             << "PH NUMBER"
             << "           "
             << "ADDRESS"
             << "           "
             << "DATE OF BIRTH"
             << "           "
             << "DATE OF JOINING"
             << "           "
             << "Hindi"
             << "           "
             << "English"
             << "           "
             << "Science"
             << "           "
             << "Totoal\n";
        while (fin.read((char *)&t, sizeof(t)))
        {
            t.put();
        }
        fin.close();
    }
    else
    {
        teacher t;
        ifstream fin("teacher.dat", ios::binary | ios::in);
        if (!fin)
        {
            cout << "\nerror in opening\n";
        }
        cout << "\nteacher's Data";
        cout << "\nNAME"
             << "           "
             << "CODE"
             << "           "
             << "PIN"
             << "           "
             << "PH NUMBER"
             << "           "
             << "ADDRESS"
             << "           "
             << "DATE OF BIRTH"
             << "           "
             << "DATE OF JOINING"
             << "           "
             << "Basic Salary"
             << "           "
             << "HRA"
             << "           "
             << "VDA"
             << "           "
             << "Total Salary\n";
        while (fin.read((char *)&t, sizeof(t)))
        {
            t.put();
        }
        fin.close();
    }
}
// *******************************************************teacher's section**************************************************
void view_teacher()
{
    teacher t;
    cout << "\n Welcome to Teacher's section\n";
    int n;
    cout << "\nPress\n- 3 to login\n- 0 to return to previous menu\n";
    cin >> n;
    if (n == 3)
    {
        teacher_login();
    }
    else if (n == 0)
    {
        main_menu();
    }
    else
    {
        cout << "\n*********************WRONG INPUT*************************";
        view_teacher();
    }
}
void teacher_login()
{
    cout << "\nFor login";
    teacher t, t1;
    int f = 0;
    t.login();
    fstream fin("teacher.dat", ios::binary | ios::in);
    while (fin.read((char *)&t1, sizeof(t1)))
    {
        if ((t.get_code() == t1.get_code()) && strcmp(t.get_dob(), t1.get_dob()) == 0)
        {
            cout << "\nLogined Successfully";
            f = 1;
            break;
        }
        else if (t.get_code() == t1.get_code())
        {
            f = 2;
            break;
        }
        else
        {
            f = 3;
        }
    }
    fin.close();
    teacher_after(f);
}
void teacher_after(int x)
{
    int l;
    if (x == 1)
    {
        cout << "\npress\n";
        cin >> l;
        if (l == 1)
        {
            Dheke(1);
            teacher_after(1);
        }
        else if (l == 2)
        {
            cout << "\nFor find";
            int c = find(1);
            if (c > 0)
            {
                cout << "\nRecord found";
            }
            else
            {
                cout << "\nRecord not found";
            }
            teacher_after(1);
        }
        else if (l == 0)
        {
            main_menu();
        }
        else
        {
            teacher_after(1);
        }
    }
    else if (x == 2)
    {
        cout << "\nWrong Code";
        cout << "\nfor re-login press 1 or press 0";
        cin >> l;
        if (l == 1)
        {
            teacher_login();
        }
        else if (l == 0)
        {
            main_menu();
        }
        else
        {
            cout << "\nwrong input";
            teacher_after(2);
        }
    }
    else
    {
        cout << "\nwrong Credinals";
        cout << "\nfor re-login press 1 or press 0";
        cin >> l;
        if (l == 1)
        {
            teacher_login();
        }
        else if (l == 0)
        {
            main_menu();
        }
        else
        {
            cout << "\nWrong Input";
            teacher_after(3);
        }
    }
}
// ****************************************************students section*********************************************************
void view_student()
{
    teacher t;
    cout << "\n Welcome to Student's section\n";
    int n;
    cout << "\nPress\n- 3 to login\n- 0 to return to previous menu\n";
    cin >> n;
    if (n == 3)
    {
        student_login();
    }
    else if (n == 0)
    {
        main_menu();
    }
    else
    {
        cout << "\n*********************WRONG INPUT*************************";
        view_student();
    }
}
void student_login()
{
    cout << "\nFor login";
    student t, t1;
    int f = 0;
    t.login();
    fstream fin("student.dat", ios::binary | ios::in);
    while (fin.read((char *)&t1, sizeof(t1)))
    {
        if ((t.get_roll() == t1.get_roll()) && strcmp(t.get_dob(), t1.get_dob()) == 0)
        {
            cout << "\nLogined Successfully";
            f = 1;
            break;
        }
        else if (t.get_roll() == t1.get_roll())
        {
            f = 2;
            break;
        }
        else
        {
            f = 3;
        }
    }
    fin.close();
    student_after(f);
}
void student_after(int x)
{
    int l;
    if (x == 1)
    {
        cout << "\nFor display all student details press 1 or to find your data press 2 for previus menu press 0 ";
        cin >> l;
        if (l == 1)
        {
            Dheke(2);
            student_after(1);
        }
        else if (l == 2)
        {
            cout << "\nFor find";
            int c = find(2);
            if (c > 0)
            {
                cout << "\nRecord found";
            }
            else
            {
                cout << "\nRecord not found";
            }
            student_after(1);
        }
        else if (l == 0)
        {
            main_menu();
        }
        else
        {
            student_after(1);
        }
    }
    else if (x == 2)
    {
        cout << "\nWrong Code";
        cout << "\nfor re-login press 1 or press 0";
        cin >> l;
        if (l == 1)
        {
            student_login();
        }
        else if (l == 0)
        {
            main_menu();
        }
        else
        {
            cout << "\nwrong input";
            student_after(2);
        }
    }
    else
    {
        cout << "\nwrong Credinals";
        cout << "\nfor re-login press 1 or press 0";
        cin >> l;
        if (l == 1)
        {
            student_login();
        }
        else if (l == 0)
        {
            main_menu();
        }
        else
        {
            cout << "\nWrong Input";
            student_after(3);
        }
    }
}
void Dheke(int x)
{
    if (x == 1)
    {
        teacher t;
        fstream fin("teacher.dat", ios::binary | ios::in);
        while (fin.read((char *)&t, sizeof(t)))
        {
            t.disp();
        }
        fin.close();
    }
    else
    {
        student t;
        fstream fin("student.dat", ios::binary | ios::in);
        while (fin.read((char *)&t, sizeof(t)))
        {
            t.disp();
        }
        fin.close();
    }
}
int find(int x)
{
    if (x == 1)
    {
        int n, f, r;
        cout << "\nEnter code";
        cin >> n;
        teacher t;
        fstream fin("teacher.dat", ios::binary | ios::in);
        f = 0, r = 0;
        while (fin.read((char *)&t, sizeof(t)))
        {
            r++;
            if (t.get_code() == n)
            {
                f = r;
                break;
            }
        }
        fin.close();
        return f;
    }
    else
    {
        int n, f,r;
        cout << "\nEnter Roll number";
        cin >> n;
        student t;
        fstream fin("student.dat", ios::binary | ios::in);
        f = 0,r=0;
        while (fin.read((char *)&t, sizeof(t)))
        {
            r++;
            if (t.get_roll() == n)
            {
                f = r;
                break;
            }
        }
        fin.close();
        return f;
    }
}
//*********************************************************admin section start here*************************************************************************************************
void admin_create()
{
    school t;
    cout << "\nFor creation of Admin Credinals";
    ofstream fout("admin.dat", ios::binary);
    if (!fout)
    {
        cout << "\nError in opening";
    }
    for (int i = 1; i <= 3; i++)
    {
        t.get();
        fout.write((char *)&t, sizeof(t));
    }
    fout.close();
}
void display_admin_details()
{
    school t;
    fstream fin("admin.dat", ios::binary | ios::in);
    if (!fin)
    {
        cout << "error in opening";
    }
    while (fin.read((char *)&t, sizeof(t)))
    {
        t.disp();
    }
    fin.close();
}
void admin()
{
    school t2, t1;
    cout << "\nFor Admin login";
    t2.get();
    int f = 0;
    fstream fin("admin.dat", ios::binary | ios::in);
    while (fin.read((char *)&t1, sizeof(t1)))
    {
        if (strcmp(t2.get_id(), t1.get_id()) == 0 && strcmp(t2.get_pass(), t1.get_pass()) == 0)
        {
            f = 1;
            break;
        }
        else if (strcmp(t2.get_id(), t1.get_id()) == 0)
        {
            f = 2;
            break;
        }
        else
        {
            f = 3;
        }
    }
    admin_after_login(f);
}
void admin_after_login(int x)
{
    int n, l;
    if (x == 1)
    {
        cout << "\nHELLO ADMIN\n  \nPress 4 for student  \n5 for TEACHER \nor \n0 to return to Main Menu\n";
        cin >> n;
        if (n == 4)
        {
            cout << "\nStudent's Section";
            cout << "\nPress\n 1 for display  data \n 2 for enter new data\n 3 for delete data\n 4 for update data\n 5 for find data\n and 0 to previus menu\n";
            cin >> l;
            if (l == 1)
            {
                display(1);
                admin_after_login(1);
            }
            else if (l == 2)
            {
                input(1);
                admin_after_login(1);
            }
            else if (l == 3)
            {
                del(1);
                admin_after_login(1);
            }
            else if (l == 4)
            {
                update(1);
                admin_after_login(1);
            }
            else if (l == 5)
            {
                cout << "\nFor find";
                int c = find(2);
                if (c > 0)
                {
                    cout << "\nRecord found";
                }
                else
                {
                    cout << "\nRecord not Found";
                }
                admin_after_login(1);
            }
            else
            {
                admin_after_login(1);
            }
        }
        else if (n == 5)
        {
            cout << "\ntecher's Section";
            cout << "\nPress\n 1 for display  data \n 2 for enter new data\n 3 for delete data\n 4 for update data\n 5 to find data \nand 0 to previus menu\n";
            cin >> l;
            if (l == 1)
            {
                display(2);
                admin_after_login(1);
            }
            else if (l == 2)
            {
                input(2);
                admin_after_login(1);
            }
            else if (l == 3)
            {
                del(2);
                admin_after_login(1);
            }
            else if (l == 4)
            {
                update(2);
                admin_after_login(1);
            }
            else if (l == 5)
            {
                cout << "\nFor find";
                int c = find(1);
                if (c > 0)
                {
                    cout << "\nRecord found";
                }
                else
                {
                    cout << "\nRecord not Found";
                }
                admin_after_login(1);
            }
            else
            {
                admin_after_login(1);
            }
        }
        else
        {
            main_menu();
        }
    }
    else if (x == 2)
    {
        cout << "\nWrong Password\nFor Re Enter Password Press 1 or Press 0 ";
        cin >> l;
        if (l == 1)
        {
            admin();
        }
        else
        {
            main_menu();
        }
    }
    else
    {
        cout << "\nWrong Credinals\nFor Re Enter Password Press 1 or Press 0 ";
        cin >> l;
        if (l == 1)
        {
            admin();
        }
        else
        {
            main_menu();
        }
    }
}
void update(int x)
{
    int n;
    if (x == 1)
    {
        student t;
        cout << "\nEnter Roll number for update in data";
        n = find(2);
        if (n == 0)
        {
            cout << "\nRoll number not found";
            admin_after_login(1);
        }
        else
        {
            n -= 1;
            fstream fin("student.dat", ios::binary | ios::in | ios::out);
            t.get();
            fin.seekp(n * sizeof(t), ios::beg);
            fin.write((char *)&t, sizeof(t));
            fin.close();
        }
    }
    else
    {
        teacher t;
        cout << "\nEnter code for update in data";
        n = find(1);
        if (n == 0)
        {
            cout << "\nCode not found";
            admin_after_login(1);
        }
        else
        {
            n -= 1;
            fstream fin("teacher.dat", ios::binary | ios::in | ios::out);
            t.get();
            fin.seekp(n * sizeof(t), ios::beg);
            fin.write((char *)&t, sizeof(t));
            fin.close();
        }
    }
}
void del(int x)
{
    int n;
    if (x == 1)
    {
        student t1;
        cout << "\nFor delete in student Section\n Enter roll number\n";
        cin >> n;
        int l = 0;
        ofstream fout("t.dat", ios::binary);
        ifstream fin("student.dat", ios::binary);
        while (fin.read((char *)&t1, sizeof(t1)))
        {
            if (n != t1.get_roll())
            {
                fout.write((char *)&t1, sizeof(t1));
            }
            else
            {
                l = 1;
            }
        }
        fin.close();
        fout.close();
        remove("student.dat");
        rename("t.dat", "student.dat");
        if (l == 1)
        {
            cout << "\nDeleted successfully\n";
        }
        else
        {
            cout << "\nNo record found\n";
        }
    }
    else
    {
        student t1;
        cout << "\nFor delete in teacher Section\n Enter code number\n";
        cin >> n;
        int l = 0;
        ofstream fout("t.dat", ios::binary);
        ifstream fin("teacher.dat", ios::binary);
        while (fin.read((char *)&t1, sizeof(t1)))
        {
            if (n != t1.get_roll())
            {
                fout.write((char *)&t1, sizeof(t1));
            }
            else
            {
                l = 1;
            }
        }
        fin.close();
        fout.close();
        remove("teacher.dat");
        rename("t.dat", "teacher.dat");
        if (l == 1)
        {
            cout << "\nDeleted successfully\n";
        }
        else
        {
            cout << "\nNo record found\n";
        }
    }
}
// *************************************************************************main menu********************************************************************
void main_menu()
{
    teacher t;
    student s;
    school r;
    int n, n1;
    cout << "\nEnter\n -1 If you are ADMIN\n - 2 if you are TEACHER\n - 3 if you are STUDENT\n - 4 if you are  VISITOR\n- 0 for exit\n ";
    cin >> n;
    if (n == 1)
    {
        admin();
    }
    else if (n == 2)
    {
        view_teacher();
    }
    else if (n == 3)
    {
        view_student();
    }
    else if (n == 4)
    {
        r.display();
    }
    else if (n == 0)
    {
        cout << "\nThanks for Visiting\n New features coming soon";
        exit(0);
    }
    else
    {
        cout << "\nOpps wrong input - Try again\n ";
        main_menu();
    }
}
main()
{
    main_menu();
}
