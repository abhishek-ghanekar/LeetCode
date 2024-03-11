#include<iostream>

using namespace std;
int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    // now we need to return the operations required
    int ans = 0;
    for(int i=0;i<32;i++) {
        // we check for all the bits
        if(c & (1 << i)) {
            // c is one
            // then we need to make sure either a or b is 1
            // if both are one then its fine
            // if both are zero then theres a problem
            if(((a & (1 << i)) == 0) && ((b & (1 << i)) == 0)) {
                ans++;
            }
        }else {
            // c is zero
            if((a & (1 << i)) && (b & (1 << i))){
                ans = ans + 2;
            }else if((a & (1 << i)) != (b & ( 1 << i))) {
                ans++;
            }
        }
       
    }
     cout << "the minimum operations are  " << ans;
    return 0;
}