#include<iostream>
#include <iomanip>
using namespace std;

string name, day;
int num;
char type, extra;
float price = 0.0;

bool checkValid(string name, int num, char type, char extra, string day){
    if(islower(name[0]) || name.empty() || num<0 || (type!='r' && type!='d') || (extra!='y' && extra!='n')) return false;
    else if(day!="Monday" && day!="Tuesday" && day!="Wednesday" && day!="Thursday" && day!="Friday" && day!="Saturday" && day!="Sunday") return false;
    return true;
};

float getInfo(string name, int num, char type, char extra, string day){
    cout<<"Customer's first name: ";
    cin>>name;
    cout<<"Number of cups: ";
    cin>>num;
    cout<<"Type of coffee (r=regular, d=decaf): ";
    cin>>type;
    cout<<"Any extra items? (y/n): ";
    cin>>extra;
    cout<<"Day of the week: ";
    cin>>day;

    if (checkValid(name, num, type, extra, day)){
        if(type=='r'){price = 4.0*num;}
        else if(type=='d'){price = 4.5*num;}
        if(extra=='y'){price += 1.95;}
        if(day=="Wednesday"){price = price*0.85;}
        return price;
    }
    else{
        cout<<"Invalid input."<<endl;
        //figure out what is wrong and print the corresponding error messages
        return 0.0;
    }
};

int main(){
    price = getInfo(name, num, type, extra, day);
    cout<<"---"<<endl;
    if (price != 0.0) cout<<"Charge is $"<<fixed<<setprecision(2)<<price<<endl;
    else cout<<"get out of here!"<<endl;
    return 0;
}