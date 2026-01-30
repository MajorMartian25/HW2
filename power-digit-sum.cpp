#include <iostream> //provides cout
#include <climits> //used to limit number of cases with overflow problems
#include <string>
using namespace std; //skips a lotta syntax

int main() {
    string in1;
    string in2;
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
    unsigned int in1Int = stoi(in1); //Now that we know they're numbers,
    unsigned int in2Int = stoi(in2); //make them be ints
    if(validInput){ //This if is to skip unnecessary checks
        //verify the numbers aren't too large
        if(in1Int > SHRT_MAX || in2Int > SHRT_MAX){
            validInput = false;
            cout << "Input too large" << endl;
        }
    }
    if(validInput){
        unsigned long pow = stol(in1);
        
        if(in2Int == 0){
            pow = 1;
        }
        else{
            for(int i = 0; i < in2Int-1; i++){
                pow *= in1Int;
            }
        }
        unsigned long toPrint = pow; //so I can change pow in the next part
        int sumPow = 0;
        string powString = to_string(pow); //seemed the easiest way to get the length, did have to google
        for(int i = 0; i < powString.length(); i++){
            int toAdd = pow%10;
            pow /= 10;
            //cout << toAdd << endl; twas testing
            sumPow += toAdd;
        }
        cout << in1 << "^" << in2 << " = " << toPrint << endl << "Sum of Digits: " << sumPow << endl;
    }
    return 0;
}
