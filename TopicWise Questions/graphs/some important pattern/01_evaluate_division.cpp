// in this question we used the dfs function to calculate the value of the total weight between a point a and point b
// we might require this in the future


class Solution {
private:
    void dfs(string a,string b,unordered_map<string,list<pair<string,double>>> adj,unordered_map<string,bool> &visited,bool &found, double &val) {
         visited[a] = true;
         if(found == true) return ;
         for(auto edge:adj[a]) {
             if(!visited[edge.first]) {
                 val *= edge.second;
                 if(edge.first == b) {
                     found = true;
                     return ;
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
        // first make an adjacency list
        unordered_map<string,list<pair<string,double>>> adj;
        for(int i=0;i<equations.size();i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double w = values[i];
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,1/w));
        }

        // now we have the adjacency list ready
       vector<double> ans;
       //traverse thru the queries
       for(int i=0;i<queries.size();i++) {
           // for each query find the distance between a and b
           string a = queries[i][0];
           string b = queries[i][1];
           if(adj.find(a) == adj.end() || adj.find(b)==adj.end()) {
               // if we didnt find the elements in the adjacency list
               ans.push_back(-1);
           }else {
               // if we found atleast one element
               bool found = false;
               unordered_map<string,bool> visited;
               double val = 1;
               if(a == b) {
                   found = true;
               }else {
                   dfs(a,b,adj,visited,found,val);
               }
               if(!found) {
                   ans.push_back(-1);
               }else {
                   ans.push_back(val);
               }
           }
       }
       return ans;
    }
};