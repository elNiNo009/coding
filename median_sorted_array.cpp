#include<bits/stdc++.h>
using namespace std;

  float median2(int a, int b)
{ return ( a + b ) / 2.0; }

// A utility function to find median of three integers
float median3(int a, int b, int c)
{
  cout<<"a "<<a<<" b "<<b<<" c "<<c<<endl;
    return a + b + c - max(a, max(b, c))
                     - min(a, min(b, c));
}

// A utility function to find a median of four integers
float median4(int a, int b, int c, int d)
{
    int Max = max( a, max( b, max( c, d ) ) );
    int Min = min( a, min( b, min( c, d ) ) );
    return ( a + b + c + d - Max - Min ) / 2.0;
}

// Utility function to find median of single array
float median(vector<int> arr)
{
    int n=arr.size();
   if (arr.size() == 0)
      return -1;
   if (arr.size()%2 == 0)
        return (double)(arr[n/2] + arr[n/2-1])/2;
   return arr[n/2];
}
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        if(nums1.size()>nums2.size())
        {
      //    cout<<"switching"<<endl;
        return  findMedianSortedArrays(nums2,nums1);
       }
        if(nums1.size()==0)
            return median(nums2);

        if(nums1.size()==1)
          {
            if(nums2.size()==1)
             {
                return median2(nums1[0],nums2[0]);
             }
            if(nums2.size()%2==1)
                return median2(nums2[nums2.size()/2],median3(nums1[0],nums2[(nums2.size()/2)+1],nums2[(nums2.size()/2)-1]));

            cout<<"median of 3"<<endl;
             return median3(nums2[nums2.size()/2],nums2[(nums2.size()/2)-1],nums1[0]);
          }
          if(nums1.size()==2)
            {
              if(nums2.size()==2)
               {
                  return median4(nums1[0],nums2[0],nums1[1],nums2[1]);
               }
              if(nums2.size()%2==1)
                  return median3(nums2[nums2.size()/2],max(nums1[0],nums2[(nums2.size()/2)-1]),min(nums1[1],nums2[(nums2.size()/2)+1]));

               return median4(nums2[(nums2.size()/2)],nums2[(nums2.size()/2)-1],max(nums1[0],nums2[(nums2.size()/2)-2]),min(nums1[1],nums2[(nums2.size()/2)+1]));
            }

        int mid1=(nums1.size()-1)/2;
        int mid2=(nums2.size()-1)/2;



     if(nums1[mid1]<=nums2[mid2])
        {
vector<int>num1(nums1.begin()+mid1,nums1.end());
         vector<int>num2(nums2.begin(),nums2.begin()+mid2);
return findMedianSortedArrays(num1,num2);
        }

vector<int>num1(nums1.begin(),nums1.begin()+mid1);
         vector<int>num2(nums2.begin()+mid2,nums2.end());
return findMedianSortedArrays(num1,num2);


    }

    int main()
    {
      cout<<"finding median"<<endl;
      vector<int> nums1{1,2,3,6};
      vector<int> nums2{3,5,7,9};
cout<<findMedianSortedArrays(nums1,nums2);

    }
