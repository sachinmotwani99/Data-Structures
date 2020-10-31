#include <stdio.h>
void shiftArr(int arr[],int n)
{


}
int maxArr(int arr[],int n)
{
    int i,m = 0;
    for ( i = 0; i < n; i++)
    {
        if (m<arr[i])
        {
            m = arr[i];
        }
        
    }
    
    return m;

}
int minArr(int arr[],int n)
{
    int i,m = 10000000;
    for ( i = 0; i < n; i++)
    {
        if (m>arr[i])
        {
            m = arr[i];
        }
        
    }
    
    return m;

}

int reverseArr(int arr[],int n)
{

}
int main()
{
    int arr[10] = {0,5,2,1,5,6,7,8,3,1};
    int n = 10;
    printf("%d\n",maxArr(arr,n));
    printf("%d",minArr(arr,n));
    return 0;
}