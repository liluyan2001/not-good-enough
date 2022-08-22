#include <iostream>

using namespace std;


void insert(int array[],int len) {//插入排序
    int i, j, key;
    for (i = 1; i < len; i++) {
        j = i - 1;
        key = array[i];
        while ((j >= 0) && (key< array[j])) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}
void bubble(int array[], int len) {//冒泡排序
    for (int i = 0; i < len-1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (array[j] > array[j + 1])
                swap(array[j], array[j+1]);
        }
    }
}
void quick_sort(int array[],int left,int right) {//快速排序
    if(right<=left) return;
    int key = array[left];
    int l = left;
    int r = right;
    while (l < r) {
        while (l<r && array[r]>key) {
            r--;
        }
        if (l < r) {
            array[l] = array[r];
            l++;
        }

        while (l < r && array[l] < key) {
            l++;
        }
        if (l < r) {
            array[r] = array[l];
            r--;
        }
    }
    array[l] = key;
    quick_sort(array,left, l - 1);
    quick_sort(array, r + 1, right);

}
int selectpivot(int left, int right) {//挑选比较值的位置，比如随机，开头，中间等
    return (left + right) / 2;
}

int Partition(int array[], int left, int right) {
    int l = left;//l是左指针
    int r = right;//r是右指针
    int temp = array[r];//轴值存在临时变量（上面已经将轴值移动到了最右边）
    while (l != r) {
        while (array[l] <= temp && r > l)
            l++;
        if (l < r) {
            array[r] = array[l];
            r--;
        }//r指针向左移动，越过那些大于轴值得记录，直到找到一个小于轴值的记录
        while (array[r] >= temp && r > l)
            r--;
        if (r > l) {
            array[l] = array[r];
            l++;
        }
    }//end while
    array[l] = temp;
    return l;

}

void Merge(int a[], int low, int mid, int high)// 合并函数
{
    int j, k, h;
    int b[100] = { 0 };//辅助数组
    j = low;
    h = mid + 1;
    k = low;
    while (j <= mid && h <= high)	// 将左右两端数据进行比较，放入辅助数组b中
    {
        if (a[j] < a[h])
            b[k++] = a[j++];
        else
            b[k++] = a[h++];
    }
    // 将剩余的数据加入到辅助数组中
    while (j <= mid)
    {
        b[k++] = a[j++];
    }
    while (h <= high)
    {
        b[k++] = a[h++];
    }
    for (k = low; k <= high; k++)// 将辅助数组的数据复制到原数组的对应位置上
    {
        a[k] = b[k];
    }
}

void quicksort(int array[], int left, int right) {
    if (right <= left) return;//0或1不需要排序
    int pivot = selectpivot(left, right);
    swap(array[pivot], array[right]);//分割前先将轴值放到末端
    pivot = Partition(array, left, right);//分割后轴值已经到了正确位置
    quicksort(array, left, pivot - 1);
    quicksort(array, pivot + 1, right);
}



void MergeSort(int array[], int low, int high)	// 递归分组函数
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(array, low, mid);
        MergeSort(array, mid + 1, high);
        Merge(array, low, mid, high);// 调用Merge函数，合并两组数据 
    }
}

int main()
{
    int a[8] = { 5,1,6,2,8,3,4,7 };
    int len = sizeof(a) / sizeof(a[0]);
    //insert(a,len);
    //bubble(a, len);
    //quick_sort(a, 0, 7);
    MergeSort(a, 0, 7);
    for (int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
}

