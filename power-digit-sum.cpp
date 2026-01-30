#include <iostream> //provides cout
#include <climits> //used to limit number of cases with overflow problems
using namespace std; //skips a lotta syntax

int main() {
    String in1;
    String in2;
    cout << "a: " << endl;
    cin >> in1;
    cout << "b: " << endl;
    cin >> in2;
    bool validInput = true;
    for(char c: in1){ //verify a is a number
        if(!isdigit(c)){
            validInput = false;
            cout << "Input must be a positive integer" << endl;
        }
    }
    for(char c: in2){ //verify b is a number
        if(!isdigit(c)){
            validInput = false;
            cout << "Input must be a positive integer" << endl;
        }
    }
    if(validInput){ //This if is to skip unnecessary checks
        //verify the numbers aren't too large
        if(in1 > SHRT_MAX || in2 > SHRT_MAX){
            validInput = false;
            cout << "Input too large" << endl;
        }
    }
    if(validInput){
        long pow = in1;
        if(in2 == 0){
            pow = 1;
        }
        else{
            for(int i = 0; i < in2-1; i++){
                pow *= in1;
            }
        }
        int sumPow = 0;
        string powString = to_string(pow); //seemed the easiest way to get the length, did have to google
        for(int i = 0; i<powString.length(); i++){
            sumPow += (pow%(10^(i+1)))/(10^(i)) //iterates across the number from right to left
        }
        cout << in1 << "^" << in2 << " = " << pow << endl << "Sum of Digits: " << sumPow << endl;
    }
}