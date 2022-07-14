//! simple way
#include<bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int>& heights) {
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


int main(){
    vector<int> heights = {2,4};
    cout<<largestRectangleArea(heights)<<endl;
    return 0;
}



// #include<bits/stdc++.h>
// using namespace std;
// int largestRectangleArea(vector<int>& arr) {
//         if(arr.size()==1) return arr[0];
//         int n = arr.size();
//         vector<int> left,right;
//         stack<pair<int,int>> s;
//         int pseudo_index =-1;
//         int pseudo_index1 =n;
//         for (int i=0;i<n;i++) //code for finding nextGreatestToLeft
//         {
//             if (s.empty())
//                 left.push_back(pseudo_index);
//             else if (!s.empty() && s.top().first<arr[i])
//                 left.push_back(s.top().second);
//             else if (!s.empty() && s.top().first>=arr[i])
//             {
//                 while(!s.empty() && s.top().first>=arr[i])
//                    s.pop();
//                 if (s.empty())
//                     left.push_back(pseudo_index);
//                 else
//                     left.push_back(s.top().second);
//             }
//             s.push({arr[i],i});
//         }
//         while(!s.empty()) s.pop();
//         for (int i=n-1;i>=0;i--)        //code for finding nextGreatestToRight
//         {
//             if (s.empty())
//                 right.push_back(pseudo_index1);
//             else if (!s.empty() && s.top().first<arr[i])
//                 right.push_back(s.top().second);
//             else if (!s.empty() && s.top().first >= arr[i])
//             {
//                 while(!s.empty() && s.top().first >= arr[i])
//                     s.pop();
//                 if (s.empty())
//                     right.push_back(pseudo_index1);
//                 else
//                     right.push_back(s.top().second);
//             }
//             s.push({arr[i],i});
//         }
//         reverse(right.begin(),right.end());
//         int m=INT_MIN;
//         for (int i=0;i<n;i++)
//         {
//             m=max(m,(right[i]-left[i]-1)*arr[i]); // taking maximum  after finding area
//         }
//         return m; 
// }

// int main(){

//     return 0;
// }
