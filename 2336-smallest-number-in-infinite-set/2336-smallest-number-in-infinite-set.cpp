/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

class SmallestInfiniteSet {
private:
    int cur;
    bool is_popped[1002]; // Array to track elements up to 1000

public:
    SmallestInfiniteSet() {
        cur = 1;
        // Initialize all elements as not popped
        for (int i = 0; i < 1002; i++) {
            is_popped[i] = false;
        }
    }

    int popSmallest() {
        // Look for any number smaller than 'cur' that was added back (is_popped
        // is false)
        for (int i = 1; i < cur; i++) {
            if (!is_popped[i]) {
                is_popped[i] = true;
                return i;
            }
        }

        // If no added-back numbers are available, return cur and increment
        is_popped[cur] = true;
        int smallest = cur;
        cur++;
        return smallest;
    }

    void addBack(int num) {
        // Only add back if it is within constraints and currently marked as
        // popped
        if (num < cur && is_popped[num]) {
            is_popped[num] = false;
        }
    }
};
