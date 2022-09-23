#include<bits/stdc++.h>
using namespace std;

/*
question:- Count the number of ways to reach ground(0th step) from Nth step.
At a time you can move 1 or 2 or 3 steps from the current step.
*/

int getStairsPath(int n)
{
    if(n<0) return 0;       //If we get a negative number , which means we have no path , so return 0
    if(n==0) return 1;      //If we reach the ground then we can add it as one valid path.
    int paths=0;
    for(int i=1;i<=3;i++)
    {
        paths += getStairsPath(n-i);      //moving 1,2,3 steps and adding the result to paths variable.
    }
    return paths;   // return the answer.
}

int main()
{
    int n;
    cin>>n;
    cout<<getStairsPath(n);
    return 0;
}


/*
for example :-
n=3
from 3 you can go to =>{2(since 3-1),1(since 3-2),0(since 3-3)}
which means steps(3) = steps(2)+steps(1)+steps(0).
now we can calculate similarly for 2,1,0 and return the answer.
*/