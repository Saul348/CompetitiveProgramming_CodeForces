#include<bits/stdc++.h>
#define ll long long

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::string s;
  std::cin>>s;
  int A[9];
  int rep[9];
  std::vector<int> quitados (1000, 0);
  std::vector<std::vector<int>> lugares (9);
  for (int i = 0; i < 9; i++){
    std::cin>>A[i]; 
    rep[i] = 0;
  } 
  int len = s.size();
  int aux;
  int mp = 8;
  int mg = 0;
  int extra = 0;
  for (int i = 0; i < len; i++){
    aux = s[i]-'1';
    lugares[aux].push_back(i);
    rep[aux]++;
    if(aux < mp) mp = aux;
    if(aux > mg) mg = aux;
  }

  for (int i = 0; i < 9; i++)
  {
    if(A[i] == rep[i]){
        for (auto &e : lugares[i]) quitados[e] = 1; 
        rep[i] = 0;

        if(i == mp){
        while(rep[mp]==0 || mp==9){
            mp++;
            extra+=A[i];
            //std::cout << "mp " << mp << std::endl;
        }
        }
        
        if(i == mg){
            while(rep[mg]==0||mg == 0){
                mg--;
                extra+=A[i];
                //std::cout << "mg "<< mg << std::endl;
            } 
        }
    }
  }

  if(mp == mg){
    //std::cout << len-A[mp]-extra << std::endl;
    for (int i = 0; i < len - A[mp] - extra; i++) std::cout << mp+1;
    std::cout << std::endl;
    return 0;    
  }
  

  //std::cout << "mp: " << mp << "   mg: "<< mg<< std::endl;
  //for (int i = 0; i < 9; i++) std::cout << rep[i]<< " ";
  //std::cout<< std::endl;

//una vez sin casos obvios, quitar lo que se debe
//quitar los mas chicos de adelante
for (int j = 0; j < A[mp]; j++)
{
    quitados[lugares[mp][j]] = 1;
}

for (int j = 0; j < A[mg]; j++)
{
    int len_mg = lugares[mg].size();
    quitados[lugares[mg][len_mg - j-1]] = 1;
}

// for (int i = mp+1; i < mg; i++)
  

  //NECESARIO 
  for (int i = 0; i < len; i++) if(quitados[i] == 0)std::cout << s[i];

  return 0;
}