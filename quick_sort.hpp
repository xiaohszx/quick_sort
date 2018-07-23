#include <iostream>
#include <vector>

template<typename Arr>
void quick_sort_(Arr& arr,int begin,int end)
{
    if(begin<end)
    {
        int compare_base = arr[begin];
        int left_iter = begin;
        int right_iter = end;
        while(left_iter!=right_iter)
        {
            while(left_iter<right_iter)
            {
                if(arr[right_iter]<=compare_base){
                    arr[left_iter] = arr[right_iter];
                    break;
                }
                --right_iter;
            }
            while(left_iter<right_iter)
            {
                if(arr[left_iter]>=compare_base){
                    arr[right_iter] = arr[left_iter];
                    break;
                }
                ++left_iter;
            }
        }
        arr[left_iter] = compare_base;
        quick_sort_(arr,begin,left_iter-1);
        quick_sort_(arr,left_iter+1,end);
    }
};
template<typename Type,int Size>
void quick_sort(Type(&arr)[Size])
{
    quick_sort_(arr,0,Size-1);
};

template<typename Type>
void quick_sort(std::vector<Type>& arr)
{
    quick_sort_(arr,0,arr.size()-1);
}
int main()
{
    int arr[] = {10,9,20,100,0,50,78,90,88};
    std::vector<int> vec = {10,9,20,100,0,50,78,90,88};
    quick_sort(vec);
    for(int i = 0;i<9;i++)
    {
        std::cout<<vec[i]<<std::endl;
    }
    return 0;
}
