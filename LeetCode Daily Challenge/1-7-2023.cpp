// https://leetcode.com/problems/gas-station/description/
// 134. Gas Station
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //find the total gas and total count
        int totalGas = 0;
        int totalCost = 0;
        for(int i=0;i<gas.size();i++) {
           totalGas += gas[i];
           totalCost += cost[i];
        }
        //if the total cost is less than total cost then we are sure that there is no solution
        if(totalGas  < totalCost) {
            return -1;
        }
        int index = 0;
        int fuel = 0;
        //traverse thru the gas array
        for(int i=0;i<gas.size();i++) {
            //the amount of fuel left in the cat
            fuel += gas[i] - cost[i];
            //if it at any point goes below zero we can say that index is not solution , so increment the index and maybe the next is the answer
            if(fuel < 0) {
                //reset the fuel in the car
                fuel =0;
                
                index = i+1;
            }
        }
        return index;
    }
};