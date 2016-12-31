#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    double findKth(vector<int>::iterator a,int m,vector<int>::iterator b,int n,int k){
        if(m>n) return findKth(b,n,a,m,k);
        if(m==0) return b[k];
        if(k==1) return min(a[0],b[0]);
        int pa = min(m,k/2) , pb = n-pa;

        if(a[pa-1]<b[pb-1]) return findKth(a+pa,m-pa,b,n,k);
        if(a[pa-1]>b[pb-1]) return findKth(a,m,b+pb,n-pb,k);
        if(a[pa-1]==b[pb-1]) return a[pa-1];
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int total = size1 + size2;
        vector<int>::iterator a = nums1.begin();
        vector<int>::iterator b = nums2.begin();
        if(total&0x1)
            return findKth(a,size1,b,size2,total/2);
        else
            return (findKth(a,size1,b,size2,total/2)+findKth(a,size1,b,size2,total/2+1))/2;
    }
};

int main()
{
    return 0;
}
