#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() 
{
    int a,b;
    cin>>a;
    int userid[100],balance[100];
    for (int i=0;i<a;i++) 
    {
        cin>>userid[i]; 
        cin>>balance[i];
    }
    cin>>b;
    for (int i=0;i<b;i++) 
    {
        int from_userid,to_userid,amount;
        cin >>from_userid>>to_userid>>amount;
        int from_index = -1;
        int to_index = -1;
        for (int j=0;j<a;j++) 
        {
            if (userid[j]==from_userid)
                from_index = j;
            if (userid[j]==to_userid) 
                to_index = j;
        }
        if (from_index != -1 && to_index != -1 && balance[from_index] >= amount) 
        {
            balance[from_index] -= amount;
            balance[to_index] += amount;
            cout<<"Success"<<endl;
        } 
        else 
        cout<<"Failure"<<endl;
    }
    cout << endl;
    for (int i=0;i<a-1;i++) 
    {
        for (int j=0;j<a-i-1;j++) 
        {
            if (balance[j] > balance[j + 1])
            {
                int tempBalance = balance[j];
                balance[j] = balance[j + 1];
                balance[j + 1] = tempBalance;
 
                int tempUserid= userid[j];
                userid[j] = userid[j + 1];
                userid[j + 1] = tempUserid;
            }
        }
    }
    for (int i=0;i<a;i++) 
    {
        cout<<userid[i]<< " " << balance[i]<<endl;
    }
    return 0;
}
