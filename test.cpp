// Code for Project 1
 // Report poll results
 #include <iostream>
 using namespace std;
 
/*
author: Wangpok Tse
date: 1/14/2025
*/

 int main()
 {
    // possible errors in this homework: inconsistent data types(compile error), incorrect syntax(compile error), not cover all the cases(logic error)

    int numberSurveyed;
    int forTrarris;
    int forHump;
    cout << "How many registered voters were surveyed? ";
    cin >> numberSurveyed;
    cout << "How many of them say they will probably vote for Trarris? ";
    cin >> forTrarris;
    cout << "How many of them say they will probably vote for Hump? ";
    cin >> forHump;
    double pctTrarris = 100.0 * forTrarris / numberSurveyed;
    double pctHump = 100.0 * forHump / numberSurveyed;
    cout.setf(ios::fixed);
    cout.precision(1);
    cout << endl;
    cout << pctTrarris << "% say they will probably vote for Trarris." << endl;
    cout << pctHump << "% say they will probably vote for Hump." << endl;
    
    // "one problem is that the code did not consider the case when the votes are equal!"
    // if (forTrarris > forHump)
    //     cout << "Trarris is predicted to win the election." << endl;
    // else
    //     cout << "Hump is predicted to win the election." << endl;
    
    if (forTrarris > forHump)
    {
        cout<<"Trarris is predicted to win the election."<<endl;
    }
    else if (forTrarris < forHump)
    {
        cout<<"Hump is predicted to win the election."<<endl;
    }
    else
    {
        cout<<"The election is predicted to be a tie."<<endl;
    }
    
    return 0;
 }