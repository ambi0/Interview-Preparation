/* You are given an array representing integer. Write a function which increments this integer.
 * Example: input [1,2,3] (represents 123) -> output [1,2,4]
 * Time: O(n)
 * Space: 0(1)
 */
#include <iostream>
#include <string>
#include <vector>

void increment(std::vector<int> &);
void printArray(std::vector<int>);

int main()
{
    std::vector<int> a {9,9,9};
    printArray(a);
    increment(a);
    printArray(a);
}

void increment(std::vector<int> &a){
    for(int i = a.size() - 1; i >= 0; --i){
        if(a[i] == 9){
            a[i] = 0;
        }
        else{
            a[i]++;
            break;
        }
    }
}

void printArray(std::vector<int> a){
    for(auto i: a){
        std::cout << i << ", " <<std::endl;
    }
    std::cout << "\n";
}
