#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <fstream>

using namespace std;

int pinakas[100000], cities, roads;
pair <int, pair<int, int> > p[100000];

int is_parent(int n){
  int the_child, the_parent;
  the_child = n;
  the_parent = pinakas[n];
  the_parent = pinakas[the_parent];
  the_child = the_parent;
  return the_child;
}

int main(int argc, char *argv[]) {
    int a, b, weight;

    ifstream file(argv[1]);
    if(!file.is_open()) {
      cerr << "Could not open the file" << endl;
      return EXIT_FAILURE;
    }
    if(file.is_open()){
      file >> cities >> roads;
      for(int i = 0;i < roads;++i)
      {
        file >> a >> b >> weight;
        p[i] = make_pair(weight, make_pair(a,b));
      }
    }

    for(int i = 0;i < 100000 ; i++) { pinakas[i] = i; }

    sort(p, p + roads);
    int new_cost = p[0].first;

    for(int k = 0;k < roads; k++){
      weight = p[k].first;
      int parent[2];
      parent[1] = p[k].second.first; parent[2] = p[k].second.second;
      while (parent[1] != pinakas[parent[1]]) { parent[1] = is_parent(parent[1]); }
      while (parent[2] != pinakas[parent[2]]) { parent [2] = is_parent(parent[2]); }
      if (pinakas[parent[1]] != pinakas[parent[2]]) {
      //if(root(p[k].second.first) != root(p[k].second.second))  {
        if (new_cost < weight) {new_cost=weight;}
        pinakas[parent[1]] = pinakas[parent[2]];
        /*cout<<p[k].second.first<<" ---- "<<p[k].second.second<<" : "
          <<p[k].first<<endl; */
        //cout<<id[root(p[k].second.first)]<<" "<<id[root(p[k].second.second)]<<endl;
        //id[root(p[k].second.first)] = id[root(p[k].second.second)];
        //cout<<id[root(p[k].second.first)]<<" "<<id[root(p[k].second.second)]<<endl;
       }
    }
    cout << new_cost << endl;
    return 0;
}
