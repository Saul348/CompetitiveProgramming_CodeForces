#include<bits/stdc++.h>
#define ll long long

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int num_cases;
  std::cin>>num_cases;
  for (int l = 0; l < num_cases; l++)
  {
    int total = 0;
    std::string s;
    int k;
    std::cin>>s>>k;

    char nueva[k+3];
    int n = 0;
    bool un = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]>= '0' && s[i]<= '9'){
            n=n*10;
            n+= (s[i] - '0');      
        }else{
            //std::cout << n << std::endl;
            if(n==0){
                total++;
                n=1;
            }else{
                total+=n;
                //std::cout <<"total " <<total << std::endl;
            }
            if(total<=k){
                //std::cout << "s[i] "<< s[i] << std::endl;
                for (int j = 0; j < n; j++)nueva[total-n+j] = s[i];
                n = 0;
            }else{
                un = 1;
                std::cout << "unfeasible" << std::endl;
                break;
            }
        }
    }
    if(!un){
        nueva[total] = '\0';
        std::cout << nueva << std::endl;
    }
  }
  

  return 0;
}
