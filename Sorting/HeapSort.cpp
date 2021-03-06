/*
    Heap sort
    ---------
    A comparison-based sorting algorithm that uses an array-implemented heap to
    sort a list of integers.

    Time complexity
    ---------------
    O(N * log(N)), where N is the number of elements.

    Space complexity
    ----------------
    O(1).
*/

#include <iostream>
#include <vector>

#include "SortingUtils.hpp"

using namespace std;

void heapify(vector<int>& heap, int parent, const int last) {
    // creates a max heap from a vector of integers

    int child = parent*2 + 1;
    while (child <= last) {    // travel down the children
        if (child + 1 <= last and heap[child + 1] > heap[child])
            child++;    // child is now the larger of its siblings
        
        if (heap[parent] < heap[child])
            swap(heap[parent], heap[child]);    // if the parent is smaller, swap it with its child
        
        parent = child;
        child = parent*2 + 1;
    }
}

void heap_sort(vector<int>& heap, const int size, const bool to_show_state) {
    // remove the largest node, replace it with the last node, and re-heapify the heap

    if (to_show_state)
        cout << "\nPerforming heap sort on the heap...\n";

    int last = size - 1;
    while (last >= 0) {
        swap(heap[0], heap[last]);
        last--;
        heapify(heap, 0, last);

        if (to_show_state)
            display_state(heap);
    }
}

void make_heap(vector<int>& heap, const int size, const bool to_show_state) {
    /*
        makes an ordered heap by heapifying from highest indexed non-leaf node (curr_node)
        to the top node (index[0])
    */

    if (to_show_state)
        cout << "\nMaking initial heap...\n";

    for (int curr_node = (size/2) - 1; curr_node >= 0; curr_node--) {
        heapify(heap, curr_node, size);

        if (to_show_state)
            display_state(heap);
    }

    if (to_show_state)
        cout << "Initial heap has been made.\n";
}

int main() {
    size_t size;
    get_input_size(size);

    vector<int> values(size);
    get_input_values(values, size);

    int order;
    string order_text;
    get_order(order, order_text);

    bool to_show_state;
    get_whether_to_show_state(to_show_state);

    make_heap(values, size, to_show_state);
    heap_sort(values, size, to_show_state);
    if (order == -1)    // descending
        reverse(values.begin(), values.end());

    cout << "\nThe values in " << order_text << " order are:\n";
    display_state(values);

    return 0;
}
