class KthLargest {
    int k;
    vector<int> heap;

    // Insert an element into the min-heap
    void push(int val) {
        heap.push_back(val);

        int x = heap.size() - 1;

        while (x > 0) {
            int parentIndx = (x - 1) / 2;

            if (heap[x] < heap[parentIndx]) {
                swap(heap[x], heap[parentIndx]);
                x = parentIndx;
            } else {
                break;
            }
        }
    }

    // Remove the smallest element (root)
    void pop() {
        heap[0] = heap.back();
        heap.pop_back();

        int x = 0;
        int n = heap.size();

        while (true) {
            int smallest = x;
            int left = 2 * x + 1;
            int right = 2 * x + 2;

            if (left < n && heap[left] < heap[smallest]) {
                smallest = left;
            }

            if (right < n && heap[right] < heap[smallest]) {
                smallest = right;
            }

            if (smallest == x) {
                break;
            }

            swap(heap[x], heap[smallest]);
            x = smallest;
        }
    }

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int num : nums) {
            push(num);

            if (heap.size() > k) {
                pop();
            }
        }
    }

    int add(int val) {
        push(val);

        if (heap.size() > k) {
            pop();
        }

        return heap[0];
    }
};