#include<iostream>
using namespace std;
class name{
    int k;
    public:
        name();
        void h();
        void h2();
};
name ::name(){
    k=1;
}
void name:: h(){
    k++;
    cout<<k;
}
void name::h2(){
    k++;
    cout<<k;
}
main(){
    name t;
    t.h();
    t.h2();
}