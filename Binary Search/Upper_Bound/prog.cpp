#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    //upper_bound returns the first element which is greater than x
    vector<int>arr={1,3,4,6,6,7,9};
    //first element which is greater than x 
    //since no element exists which is greater than 9 so it return size of the array
    cout<<upper_bound(arr.begin(),arr.end(),9)-arr.begin()<<endl;

    //this prints the index of the element whoch is greater than 8
    cout<<upper_bound(arr.begin(),arr.end(),8)-arr.begin()<<endl;

}