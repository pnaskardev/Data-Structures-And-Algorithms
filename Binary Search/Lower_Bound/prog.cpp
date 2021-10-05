#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    vector<int>arr={1,3,5,7,9,10};
    //first element which is greater than or equal to x 
    //this prints the index of 9 because 9 exists in the array
    cout<<lower_bound(arr.begin(),arr.end(),9)-arr.begin()<<endl;

    //this prints the index of the element which is greater than x 
    //because x does not belong to the array
    cout<<lower_bound(arr.begin(),arr.end(),8)-arr.begin()<<endl;

    //If lowerbound doesnt exists lowerbound will point to the nth index 
    // int lb=n on running lower_bound(arr.begin(),arr.end(),10);
    //n is also the size of the array 
    cout<<lower_bound(arr.begin(),arr.end(),25)-arr.begin()<<endl;
}
