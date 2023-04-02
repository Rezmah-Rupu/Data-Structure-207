#include<bits/stdc++.h>
using namespace std;
int main()
{

    int adj_matrix[13][13]=
    {
      // 0  1  2  3  4  5  6  7  8  9 10 11 12
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //0
        {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //1
        {0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0}, //2
        {0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0}, //3
        {0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0}, //4
        {0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0}, //5
        {0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0}, //6
        {0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0}, //7
        {0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}, //8
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}, //9
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1}, //10
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1}, //11
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0}, //12
    };

    int node;
    cout<<"Please Enter The Node:";
    cin>>node;

    int flag[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};

    vector<int> ans;


    for(int i=1; i<=12; i++)
    {
        int friend_node_exis= adj_matrix[node][i];

        if(friend_node_exis==1)
        {
            for(int j=1; j<=12; j++)
            {
                int friend_of_friend_exis=adj_matrix[i][j];
                if(friend_of_friend_exis)
                {
                    if(j!=node && flag[j]!=1 ){
                        ans.push_back(j);
                        flag[j]=1;
                    }
                }
            }
        }
    }

    // now the array consists of friends and friends of friends list
    // we need to eliminate friends list

          int friend_list[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
          for(int i=1;i<=12;i++){
            if(adj_matrix[node][i]){
                friend_list[i]=1;
            }
          }
      for(int i=0;i<ans.size();i++){
            if( friend_list[ ans[i]] !=1){
                cout<<ans[i]<<" ";
            }
      }

}

