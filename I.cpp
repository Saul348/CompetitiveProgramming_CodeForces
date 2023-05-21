#include<bits/stdc++.h>
#define ll long long

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int A[3];
    std::cin>>A[0]>>A[1]>>A[2];
    std::sort(A,A+3);
    int desc = 0;

    if(A[0]>=500 && A[1]>=500 && A[2]>=500 ){
        desc = 300;
    }
    if(A[0]<500 && A[1]>=500 && A[2]>=500 ){
        desc = 200;
    }
    if(A[0]<500 && A[1]<500 && A[2]>=500 ){
        desc = 100;
        if(A[0] + A[1] >= 500){
            desc +=100;
        }
    }
    if(A[0]<500 && A[1]<500 && A[2]<500 ){
        if(A[0] + A[1] >= 500|| A[1] + A[2] >= 500 || A[0] + A[2] >= 500){
            desc =100;
        }else{
            if(A[0] + A[1] + A[2] >= 500){
            desc =100;
            }
        }
    }
    
    std::cout << A[0]+A[1]+A[2] - desc << std::endl;

    return 0;
}