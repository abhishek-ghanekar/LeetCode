// we use bitmasks to represent the subset of a set 
// 0 0 0 0 0 1 0 1
// the above represents a subset with 1,3
// we can have a subset of 32 bits
#include<iostream>
using namespace std;
void display(int subset) {
    // we need to check all the bits
    
    for(int i=0;i<32;i++) {
        if(subset & (1 << i)) {
            cout << i+1 << " ";
        }
    }
}
void remove(int &subset, int bit) {
    subset = subset ^ (1 << bit-1);
}
void add(int &subset,int bit) {
    subset = subset ^ (1 << bit-1);
}
int main()
{
    int subset = 15;
    add(subset,5);
    remove(subset,2);
    display(subset);
    return 0;
}