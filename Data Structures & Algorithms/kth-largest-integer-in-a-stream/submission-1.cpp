class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> heap;

public:
    KthLargest(int input_k, vector<int>& nums) {
        k = input_k;
        
        for (int num : nums) {
            heap.push(num);

            if (heap.size() > k) {
                heap.pop();
            }
        }
    }
    
    int add(int val) {
        heap.push(val);

        if (heap.size() > k) {
            heap.pop();
        }

        return heap.top();
    }
};