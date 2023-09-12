#include <iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main()
{
    vector<int> arr= {1,1,2,1,7,7,7,5,7,3,4,9,2,4,1,7,8,6};
    
    unordered_map<int, int> m;
    //inserting elements into map
    for(int i=0; i<arr.size(); i++)
    {
        m[arr[i]]++;
    }
    
    //displaying all elements and their frequency
    for(auto i: m)
    {
        cout<<i.first<<"-> "<<i.second<<endl;
    }
    
    //To display max frequency element
    int max= m[arr[0]];
    int num= arr[0];
    
    for(auto i: m)
    {
        if(i.second>max)
        {
            max= i.second;
            num= i.first;
        }
    }
    
    cout<<"Max frequency is:"<<num<<"-> "<<max;

    return 0;
}
