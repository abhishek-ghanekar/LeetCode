class Solution {
private:
    void dfs(string a , string b,unordered_map<string,list<pair<string,double>>> adj,unordered_map<string,bool> &visited,bool &found,double &val) {
        visited[a] = true;
        if(found) {
            return ;
        }
        for(auto edge:adj[a]) {
            if(!visited[edge.first]) {
                val *= edge.second;
                if(edge.first == b) {
                    found = true;
                    return;
                }
                dfs(edge.first,b,adj,visited,found,val);
                if(found == true) {
                    return ;
                }else {
                    val /= edge.second;
                }
            }
        }
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    //    we can try to imagine this as a graph , wehre the equations are the nodes and direction

      unordered_map<string,list<pair<string,double>>> adj;

      for(int i=0;i<equations.size();i++) {
          string u = equations[i][0];
          string v = equations[i][1];
          double w = values[i];
          adj[u].push_back(make_pair(v,w));
          adj[v].push_back(make_pair(u,1/w));
      }

      vector<double> ans;
      for(int i=0;i<queries.size();i++) {
          string a = queries[i][0];
          string b = queries[i][1];
          if(adj.find(a)==adj.end()||adj.find(b)==adj.end()) {
              ans.push_back(-1);
          }else {
              double val = 1;
              unordered_map<string,bool> visited;
              bool found = false;
              if(a == b) {
                  found = true;
              }else {
                  dfs(a,b,adj,visited,found,val);  
              }
              if(found == true) {
                    ans.push_back(val);
                  }else {
                    ans.push_back(-1);
            }
          }
          
      }
      return ans;
    }
};