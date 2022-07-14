#include<bits/stdc++.h>
using namespace std;
int histogramArea(vector<int>& heights) {
    stack<int> st; 
    int maxArea = 0; 
    int hSize = heights.size(); 
    for(int i = 0;i<=hSize;i++) {
        while(!st.empty() && (i==hSize || heights[st.top()] >= heights[i])) {
            int height = heights[st.top()];
            st.pop(); 
            int width; 
            if(st.empty()) width = i; 
            else width = i - st.top() - 1; 
            maxArea = max(maxArea, width * height); 
        }
        st.push(i); 
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> hist;
        int maxRectangle =0;
        for(int j=0;j<matrix[0].size();j++){
            hist.push_back(matrix[0][j]);
        }
        maxRectangle = histogramArea(hist);
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0) hist[j]=0;
                else hist[j]=hist[j]+matrix[i][j];
            } 
            maxRectangle = max(maxRectangle,histogramArea(hist));
        }
        return maxRectangle;
}

int main(){
    vector<int> heights = {2,4};
    return 0;
}




// class Solution {
// public:
//     int histogramArea(vector<int>& heights) {
//         stack<int> st; 
//         int maxArea = 0; 
//         int hSize = heights.size(); 
//         for(int i = 0;i<=hSize;i++) {
//             while(!st.empty() && (i==hSize || heights[st.top()] >= heights[i])) {
//                 int height = heights[st.top()];
//                 st.pop(); 
//                 int width; 
//                 if(st.empty()) width = i; 
//                 else width = i - st.top() - 1; 
//                 maxArea = max(maxArea, width * height); 
//             }
//             st.push(i); 
//         }
//         return maxArea;
//     }
//     int maximalRectangle(vector<vector<char>>& matrix) {
//         vector<int> hist;
//         int maxRectangle =0;
//         for(int j=0;j<matrix[0].size();j++){
//             hist.push_back((int)matrix[0][j]-48);
//         }
//         maxRectangle = histogramArea(hist);
//         for(int i=1;i<matrix.size();i++){
//             for(int j=0;j<matrix[0].size();j++){
//                 if((int)matrix[i][j]-48==0) hist[j]=0;
//                 else hist[j]=hist[j]+(int)matrix[i][j]-48;
//             } 
//             maxRectangle = max(maxRectangle,histogramArea(hist));
//         }
//         return maxRectangle;
//     }
// };