#include <iostream>
#include <string>
#include <stdexcept>


using namespace std;

template <typename T, typename Comparator = less<T>>
class heap {
    private:
        T* data;
        size_t _size;
        size_t _capacity;
        Comparator comparator;

        const size_t parent(size_t node) const {
            return (node + 1) / 2 - 1;
        }

        const size_t leftChild(size_t node) const {
            return (node + 1) * 2 - 1;
        }

        const size_t rightChild(size_t node) const {
            return (node + 1) * 2;
        }

        void swap(size_t idx1, size_t idx2) {
            T temp = data[idx1];
            data[idx1] = data[idx2];
            data[idx2] = temp;
        }

        // double the size of data
        void resize() {
            _capacity *= 2;
            T* newData = (T*) malloc(_capacity * sizeof(T));
            for (int idx = 0; idx < _size; ++idx) {
                newData[idx] = data[idx];
            }

            free(data);
            data = newData;
        }

        void floatUp(size_t node) {
            while (node > 0 && comparator(data[node], data[parent(node)])) {
                swap(node, parent(node));
                node = parent(node);
            }
        }

        void floatDown(size_t node) {
            while (true) {
                bool leftSwap = false, rightSwap = false;
                if (leftChild(node) < _size && comparator(data[leftChild(node)], data[node])) {
                    leftSwap = true;
                }
                if (rightChild(node) < _size && comparator(data[rightChild(node)], data[node])) {
                    rightSwap = true;
                }

                if ((leftSwap && rightSwap && comparator(data[leftChild(node)], data[rightChild(node)])) || (!rightSwap && leftSwap)) {
                    swap(node, leftChild(node));
                    node = leftChild(node);
                } else if (rightSwap) {
                    swap(node, rightChild(node));
                    node = rightChild(node);
                } else {
                    return;
                }
            }
        }

    public:
        heap(): _size(0), _capacity(5) {
            data = (T*) malloc(5 * sizeof(T));
        }

        ~heap() {
            free(data);
        }

        const size_t size() const {
            return _size;
        }

        void push(T val) {
            if (_size == _capacity) {
                resize();
            }

            data[_size] = val;
            floatUp(_size);
            _size++;
        }

        T pop() {
            if (_size == 0) {
                throw runtime_error("cannot pop from an empty heap");
            }
            T returnVal = data[0];
            data[0] = data[--_size];
            floatDown(0);

            return returnVal;
        }

        T top() const {
            if (_size == 0) {
                throw runtime_error("cannot query an empty heap");
            }
            return data[0];
        }

        string toString() {
            string ret = "";
            for (int idx = 0; idx < _size; ++idx) {
                ret += to_string(data[idx]) + ", ";
            }
            return ret;
        }
};


int main() {

    heap<int> minHeap;

    try {
        minHeap.pop();
        cout << "error expected" << endl;
    } catch (runtime_error err) {}

    minHeap.push(0);
    minHeap.push(20);
    minHeap.push(-2);
    minHeap.push(1);
    minHeap.push(5);
    minHeap.push(INT32_MAX);

    for (int idx = 0; idx < 6; ++idx) {
        int* expectedVals = new int[6] {-2, 0, 1, 5, 20, INT32_MAX};
        assert(minHeap.pop() == expectedVals[idx]);
    }
    try {
        minHeap.pop();
        cout << "error expected" << endl;
    } catch (runtime_error err) {}


    heap<int, greater<int>> maxHeap;
    maxHeap.push(0);
    maxHeap.push(20);
    maxHeap.push(INT32_MIN);
    maxHeap.push(-2);
    maxHeap.push(1);
    maxHeap.push(5);
    maxHeap.push(INT32_MAX);
    for (int idx = 0; idx < 6; ++idx) {
        int* expectedVals = new int[7] {INT32_MAX, 20, 5, 1, 0, -2, INT32_MIN};
        assert(maxHeap.pop() == expectedVals[idx]);
    }

    return 0;
}