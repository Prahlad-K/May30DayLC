class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
     
//         int i = 0, j = 0;
//         vector<pair<int, char>> bigList;
//         vector<vector<int>> answer;
//         while(i<A.size() && j<B.size()) 
//         {
//             bigList.push_back(make_pair(std::min(A[i][0], B[j][0]), 's'));
//             if(std::min(A[i][1], B[j][1])<std::max(A[i][0], B[j][0]))
//             {
//                 bigList.push_back(make_pair(std::min(A[i][1], B[j][1]), 'e'));
//                 bigList.push_back(make_pair(std::max(A[i][0], B[j][0]), 's'));
//             }
//             else
//             {
//                 bigList.push_back(make_pair(std::max(A[i][0], B[j][0]), 's'));
//                 bigList.push_back(make_pair(std::min(A[i][1], B[j][1]), 'e'));
//             }
//             bigList.push_back(make_pair(std::max(A[i][1], B[j][1]), 'e'));
//             i++;
//             j++;
//         }
        
        
        
//         int start, end;
//         bool inter = false;
//         for(vector<pair<int, char>>::iterator it = bigList.begin();it!=bigList.end();it++)
//         {   
//             if(it->second=='s')
//             {
//                 start = it->first;
//                 inter = true;
//             }
            
//             if(inter && it->second=='e')
//             {
//                 end = it->first;
//                 inter = false;
//                 vector<int> cont;
//                 cont.push_back(start);
//                 cont.push_back(end);
//                 answer.push_back(cont);
//             }
            
//             vector<pair<int, char>>::iterator it1 = it;
//             it1++;
//             if(it1!=bigList.end() && it1->first==it->first && it->second=='e' && it1->second=='s')
//             {
//                 vector<int> cont;
//                 cont.push_back(it->first);
//                 cont.push_back(it->first);
//                 answer.push_back(cont);
//             }
            
//         }
//         return answer;
        vector<vector<int>> v;
        int i=0,j=0;
        while(i<A.size() && j<B.size()){
            int l=max(A[i][0], B[j][0]);
            int u=min(A[i][1], B[j][1]);
            if(l<=u) v.push_back({l,u});
            if(A[i][1] < B[j][1])   i++;
            else j++;
        }
        return v;
    }
};