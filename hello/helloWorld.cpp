// #include<stdio.h>
#include<iostream>

using namespace std;

int factorial(int);

main(){
    int x = factorial(5);
    cout << " factorial of 5: " << x;
}

int factorial(int x){
    if (x==0){
        return 1;
    }
    return x*factorial(x-1);
}