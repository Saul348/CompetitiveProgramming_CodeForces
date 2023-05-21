#include<bits/stdc++.h>
#define ll long long
using namespace std;

int clases[100000];
int clases_cnt[100000];
 
 int find(int i){
     if(clases[i] == i){
         return i;
     }else{
         return find(clases[i]);
     }
 }

 void unio(int i, int j){
  int aux_1 = find(i);
  int aux_2 = find(j);
  if(aux_1 != aux_2){
    if(clases_cnt[aux_1] >= clases_cnt[aux_2]){
        clases_cnt[aux_1] += clases_cnt[aux_2];
        clases[j] = aux_1;
    }else{
        clases_cnt[aux_2] += clases_cnt[aux_1];
        clases[i] = aux_2;
    }
  }
 }

vector<int> getVisibleProfilesCount(int connection_nodes, vector<int> connection_from, vector<int> connection_to, vector<int> queries) {
    for (int i = 0; i<connection_nodes; i++){
        clases[i] = i;
        clases_cnt[i] = 1;
    }

    for (int i = 0; i < connection_from.size(); i++){
        unio(connection_from[i]-1, connection_to[i]-1);
    }

    vector<int> results;
    for (int i = 0; i < queries.size(); i++) {
        results.push_back(clases_cnt[clases[find(queries[i]-1)]]);
        //results.push_back(clases_cnt[i]);
    }
    return results;
}

int main(){
  int connected;
  int edges;
  int queries;
  cin>>connected>>edges>>queries;
  vector<int> from(edges);
  vector<int> to(edges);
  vector<int> Q(queries);
  for (int i = 0; i < edges; i++)
    cin>>from[i];
  for (int i = 0; i < edges; i++)
    cin>>to[i];
  for (int i = 0; i < queries; i++)
    cin>>Q[i];
  vector<int> results = getVisibleProfilesCount(connected, from, to, Q);

  for (int i = 0; i < results.size(); i++)
  {
    std::cout << results[i] << std::endl;
  }
  

  return 0;
}
