// quick

class Solution {
public:
    void sort(vector<int> &a, int low, int high){
        if (low >= high) return;
        int p = partition(a,low,high);
        sort(a, low, p -1);
        sort(a, p + 1, high);
    }

    inline void troca(vector<int> &a, int x, int y){
        int t = a[x];
        a[x] = a[y];
        a[y] = t;
    }

    inline int partition(vector<int> &a, int low, int high){
        int pivot = a[high];
        int i = low -1;
        for(int j = low; j < high; j++){
            if(a[j] <= pivot){
                troca(a, ++i,j);
            }
        }
        troca(a, i+1,high);
        return i+1;
    }

    vector<int> sortArray(vector<int>& nums) {
        // quick
        sort(nums,0,nums.size()-1);
        return nums;
    }
};