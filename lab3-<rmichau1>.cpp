//
//  lab3-<rmichau1>.cpp
//  Lab 3
//
//  Created by Robert Bryce Michaud on 9/25/17.
//  Copyright © 2017 Bryce Michaud. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <limits.h>

using namespace std;

//SUM------------------------------------------------------
long sum(long n){
    
    long temp = (n*(n+1))/2; //no need for a loop here, this formula computes the sum (Gauss's Trick)
    
    if(temp >= LONG_MAX){ //Checks for overflow
        
        cout << "Sum Overflow" << endl;
        return 0;
        
    }else{
        
    return temp;
        
    }
    
}

//FACTORIAL------------------------------------------------
double factorial(long n){
    float val = n;
    
    for (int i = 1; i < n; i++) { //we start at value n, and multiply by 1 - n until we reach 0
        val = val*(n-i);
        
        if(val >= numeric_limits<double>::max()){ //Checks for overflow
            
            cout << "Factorial Overflow" << endl;
            return val;
            
        }
    }
    
    return val;
}

//STRANGE--------------------------------------------------

float strange(float n){
    float temp = 0;
    
    for (int i = 0; i < n; i++) { //adds 1/n, n times. we expect temp to reach value 1
        temp += 1/n;
    }
    
    return temp;
}


//MAIN-----------------------------------------------------
int main(int argc, const char * argv[]) {
    
    //if it is type short, entries of 256+ create an overflow error
    //if type is long, entries over 4.295 x 10^9 will create an overflow error
    long num1 = 500;
    long totalSum = sum(num1);
    
    //value of 13 is an overflow for float result
    //value of 35 returns an overflow for double result
    long num2 = 34;
    float totalFactorial = factorial(num2);
    
    //Strange
    //We should expect the strange sum to always be 1, by simple arithmetic
    //Results: When using the float data type, we experience inaccuracies
    //when using large numbers (the result is slightly larger than 1), but not with double.
    //I belive this is because there is a larger margin of error when dealing with floats,
    //especially when we reach large numbers.
    float num3 = 3454563;
    float totalStrange = strange(num3);

    
    cout << "Total of " << num1 << " sum is [" << totalSum << "]" << endl;
    cout << "Factorial of " << num2 << " is [" << totalFactorial << "]" << endl;
    cout << "Strange of " << num3 << " is [" << totalStrange << "] Num ratio: " << 1/num3 << endl;
    
    //PUZZLE
    
    for (double i = 3.4; i < 4.4; i += 0.2){
        
        cout << "i = " << i << endl;
        
    }
    
    //What I noticed above: When float was used it worked fine up to 4.4, but 4.0 was printed
    //as just "4", which shouldn't be a problem.  When double was used, the same was printed but
    //it only iterated up to "4.2".
    
    //Now, when using the higher ceilings for the iteration when using the float data type, the results
    //began to reach several more significant digits than just the two expected (ex. 9.39999 should be 9.4)
    //The reason for this is because we're using a floating point variable, which have small inaccuracies that
    //add up and eventually (quickly) become a problem.
    
    return 0;
}
