#include <iostream> //provides cout
#include <cmath> //used to limit number of cases with overflow problems
#include <string>
#include <vector>
using namespace std; //skips a lotta syntax

unsigned long long int power(unsigned int a, unsigned int b){
    unsigned long long pow = a;
    if(b == 0){
        pow = 1;
    }
    else{
        for(unsigned int i = 0; i < b-1; i++){
            pow *= a;
        }
    }
    return pow;
}

vector<int> vectorize_digits(unsigned long long n){
    vector<int> tR;
    for(unsigned int i = 0; i < n;){
        int curr = n%10;
        n /= 10;
        tR.push_back(curr);
    }
    return tR;
}

int sum_vector(vector<int> v){
    int sum = 0;
    for(int i: v){
        sum += i;
    }
    return sum;
}

string vec_to_string(vector<int> vec){
    string tR = "[";
    for(unsigned int i = 0; i<vec.size(); i++){
        tR += to_string(vec[i]);
        if(i != vec.size()-1){
            tR += ", ";
        }
    }
    tR += "]";
    return tR;
}
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
            return -1;
        }
    }
    for(char c: in2){ //verify b is a number
        if(!isdigit(c)){
            validInput = false;
            cout << "Input must be a positive integer" << endl;
            return -2;
        }
    }
    if(validInput){ //This if is to skip unnecessary checks
    	unsigned int in1Int = stoi(in1); //Now that we know they're positive, whole numbers,
    	unsigned int in2Int = stoi(in2); //make them be ints
        //verify the numbers aren't too large
        if(in2Int*log10(in1Int) >= 64*log10(2)){
            validInput = false;
            cout << "Input too large" << endl;
            return -3;
        }
        unsigned long long pow = power(in1Int, in2Int);
        int sumPow = sum_vector(vectorize_digits(pow)); 
        cout << in1 << "^" << in2 << " = " << pow << endl << "Sum of Digits: " << sumPow << endl;
    }
    return 0;
}

