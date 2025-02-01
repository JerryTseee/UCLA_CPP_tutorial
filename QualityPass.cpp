#include <iostream>
using namespace std;

int getNumber(string results, int &position){
    int start = position;
    while (start < results.size() && isdigit(results[start]))
    {
        start++;
    }
    string temp = results.substr(position, start - position);
    if(temp.size() > 1 && temp[0] == '0'){return -1;}// if there are leading zeros, then return -1
    int res = stoi(temp);
    position = start;// important to update position!
    return res;
}

bool isValidQC(string results){
    int start = 0;
    while(start < results.size()){
        if(results[start] != 'Q'){return false;}// must start with 'Q'
        start += 1; // increment start
        if(isdigit(results[start]) == false || start >= results.size()){return false;}// must have number after 'Q'
        
        int total = getNumber(results, start);
        if(total <= 0){return false;}// must larger than 0
        
        int pass = 0;
        int defect = 0;
        while (start < results.size() && results[start] != 'Q')
        {
            if(results[start] == 'p'){
                start += 1;
                if(isdigit(results[start]) == false){return false;}// must have number after 'p'
                pass += getNumber(results, start);
            }
            else if(results[start] == 'd'){
                start += 1;
                if(isdigit(results[start]) == false){return false;}// must have number after 'd'
                defect += getNumber(results, start);
            }
            else{return false;}
        }
        //check if they are not equal
        if(total != pass+defect){return false;}
    }
    return true;
}

int passQC(string results){
    int pass = 0;
    int temp = 0;
    while(temp < results.size()){
        if(results[temp] == 'p'){
            temp++;// increment temp
            pass += getNumber(results, temp);
        }
        else{
            temp++;
        }
    }
    return pass;
}

int defectQC(string results){
    int defect = 0;
    int temp = 0;
    while(temp < results.size()){
        if(results[temp] == 'd'){
            temp++;
            defect += getNumber(results, temp);
        }
        else{
            temp++;
        }
    }
    return defect;
}

int totalQC(string results){
    int total = 0;
    int temp = 0;
    while(temp < results.size()){
        if(results[temp] == 'Q'){
            temp++;
            total += getNumber(results, temp);
        }
        else{
            temp++;
        }
    }
    return total;
}

int batches(string results){
    int num = 0;
    for(char c : results){
        if(c == 'Q'){
            num++;
        }
    }
    return num;
}

int main(){
    string results = "Q3p2d1Q1d0p1";
    if (isValidQC(results)){
        cout << "number: " << batches(results) << endl;
        cout << "passed: " << passQC(results) << endl;
        cout << "defect: " << defectQC(results) << endl;
        cout << "Total: " << totalQC(results) << endl;
    }
    else{
        cout << "Invalid input" << endl;
    }
    return 0;
}