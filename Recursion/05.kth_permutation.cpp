/*
    The set [1,2,3,…,n] contains a total of n! unique permutations.

    Given n and k, return the kth permutation sequence.

    Note:
        What if n is greater than 10. How should multiple digit numbers be represented in string?
            In this case, just concatenate the number to the answer.
            so if n = 11, k = 1, ans = "1234567891011"
        Whats the maximum value of n and k?
            In this case, k will be a positive integer thats less than INT_MAX.
            n is reasonable enough to make sure the answer does not bloat up a lot. 

    For example, given n = 3, k = 4, ans = "231"
*/

#include<bits/stdc++.h>
using namespace std;

int fact[13];
void generate_factorials() {
    fact[0] = 1;
    int p = fact[0];
    for(int i = 1; i <= 12; i++) {
        p *= i;
        fact[i] = p;
    }
}

int factorial(int n) {
    if(n > 12) {
        return INT_MAX;
    }
    return fact[n];
}

string kthPermutation(vector<string> nums, int k) {
    int n = nums.size();
    if(n == 0) {
        return "";
    }
    
    int first_index = k / factorial(n - 1);
    string first_digit = nums[first_index];
    k %= factorial(n - 1);
    nums.erase(nums.begin() + first_index);
    
    return first_digit.append(kthPermutation(nums, k));
}

int main()
{
    int A = 3, B = 4;
    vector<string> nums(A);
    for(int i=0; i<A; i++) 
        nums[i] = to_string(i+1);

    generate_factorials();
    cout << kthPermutation(nums, B-1) << endl;
}
