#include <iostream>
#include "heap.h"
int main() {
    Heap<int> heap;
    int n, comma, key;
    std::cin >> n;
    for (int i = 0; i < n; ++i){
        std::cin >> comma;
        if (comma == 0) {
            std::cin >> key;
            heap.insert(key);
        } else {
            std::cout << heap.extract_max().first << '\n';
        }
    }
    return 0;
}
