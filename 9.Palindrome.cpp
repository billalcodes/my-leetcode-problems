#include<iostream>
using namespace std;

bool palindrome(int x){
    if(x < 0){  //if number is negative it can not be palindrome
        return false;
    }
    else{
        int reverse = 0;    
        int original = x;   // to store the original number
        while(x > 0){
            int temp = x % 10;  // get the right most digit
            reverse = reverse * 10 + temp; //reversing the origina number
            x = x / 10; // get rid of the right most digit
        }
        return original == reverse; //returns true if condition is met
    }
}

int main(){

}