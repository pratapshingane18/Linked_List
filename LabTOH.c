//Write a program to solve tower of Hanoi problem.
//PRN No 2020BTEIT0050


#include<iostream>
using namespace std;

int func(int n , char initial, char   support , char final)
{
      if(n >=1)
      {
          func(n-1,initial,final, support);
          cout<<"%d disk move from %c to % c\n"<<n << initial << final;
          func(n-1,support,initial, final);
      }
}

int main()
{
    int n;
    char A,B,C;
    cout<<"Enter the number of disk"<<endl;
    cin>>n;
    cout<<endl;
    func(n,'A','B','C');
    return 0;
}