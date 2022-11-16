#include<iostream>

//Sorting Algorithm aims for char array and int array
template<class T>
void MySort(T* arr, int len)
{
    for(int i = 0; i<len; i++)
    {
        for(int j=i+1; j<len;j++)
        {
            if(arr[i]<arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

//print array
template<class T>
void PrintArray(T* arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        std::cout<<arr[i]<<'\n';
    }
}


int main()
{

    int arr[] = {1,5,4,3,6,8,2,4};
    int len = sizeof(arr)/sizeof(int);
    MySort(arr,len);
    PrintArray(arr,len);
    return EXIT_SUCCESS;
}