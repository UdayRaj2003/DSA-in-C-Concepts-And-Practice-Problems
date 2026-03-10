#include <bits/stdc++.h>
using namespace std;

vector<int> nextsmallerElement(vector<int> arr)
{

    stack<int> s;
    s.push(-1);
    vector<int> ans(arr.size());
    for (int i = arr.size(); i >=0 ; i--)
    {
        while (!s.empty() && arr[i] <= s.top())
        {
            s.pop(); 
        }
        ans[i] = s.top();
        s.push(arr[i]);
         
    }
 
    return ans;
}

vector<int> prev_smallerElement(vector<int> arr)
{

    stack<int> s;
    s.push(-1);
    vector<int> ans(arr.size());
    for (int i = 0; i <arr.size() ; i++)
    {
        while (!s.empty() && arr[i] <= s.top())
        {
            s.pop(); 
        }
        ans[i] = s.top();
        s.push(arr[i]);
         
    }
 
    return ans;
}
    int largestRectangleArea(vector<int>& heights) {
        // Append a zero to heights to ensure all elements in stack are processed
        heights.push_back(0);
        int maxArea = 0;
        stack<int> s; // Stack to store indices of heights

        // Iterate over each height in the histogram
        for (int i = 0; i < heights.size(); i++) {
            // Ensure the stack is in increasing order
            while (!s.empty() && heights[i] < heights[s.top()]) {
                int h = heights[s.top()]; // Height of the bar
                s.pop(); // Remove the top element from stack
                int width = s.empty() ? i : i - s.top() - 1; // Calculate the width
                maxArea = max(maxArea, h * width); // Update maxArea
            }
            s.push(i); // Push current index onto the stack
        }

        return maxArea;
    }

int main()
{

    vector<int> arr = {2,4,1,3};

    vector<int> result = nextsmallerElement(arr);
    vector<int> resultprev = prev_smallerElement(arr);
    cout<<"next one"<<endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout<<result[i]<<"    ";
    }
    cout<<endl;
    cout<<"previous one"<<endl;
    for (int i = 0; i < resultprev.size(); i++)
    {
        cout<<resultprev[i]<<"     ";
    }
    
    // creation
    stack<int> st;

    return 0;
}