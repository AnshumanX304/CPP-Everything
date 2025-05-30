#include<iostream>
using namespace std;
class heap
{
    public:
    int arr[100];
    int size;
    heap()
    {
        arr[0]=-1;
        size=0;
    }
    void insert(int val)
    {
        size=size+1;
        int index=size;
        arr[index]=val;
        while(index>1)
        {
            int parent=index/2;
            if(arr[parent]<arr[index])
            {
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else
                return;
        }
    }
    void print()
    {
        for(int i=1;i<=size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void deleteele()
    {
        if(size==0)
        {
            cout<<"No element to delete !!"<<endl;
            return;
        }
        arr[1]=arr[size];
        size--;
        int pos=1;
        while(pos<size)
        {
            int left=pos*2;
            int right=2*pos+1;
            if(arr[pos]<arr[left] && left<size)
            {
                swap(arr[pos],arr[left]);
                pos=left;
            }
            else if(right<size && arr[pos]<arr[right])
            {
                swap(arr[pos],arr[right]);
                pos=right;

            }
            else
                return;
        }
    }
};
//heapify algorithm
void heapify(int arr[],int n,int i)
{
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n && arr[largest]<arr[left])
    {
        largest=left;
    }
    if(right<=n && arr[largest]<arr[right])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
    }
}
int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    cout<<endl;
    h.deleteele();
    h.print();
    int arr[6]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--)
    {
        heapify(arr,n,i);
    }
    cout<<"printing the array now :"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;


}
