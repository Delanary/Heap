//
// Created by fedor on 5/19/2020.
//
#include <vector>
#include <iostream>

#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H

#endif //HEAP_HEAP_H


template<typename T>
struct Node {
    size_t index;
    long long key;
    T value;

    Node(size_t index, long long key, T value) : index(index), key(key), value(value) {};
};

template<typename T>
class Heap {
private:
    std::vector<Node<T>> vec;


    long long Parent(long long node) {
        if (node != 0) {
            return floor((node - 1) / 2);
        }
        throw "Parent node has no parent!";
    }

    long long Left(long long node) {
        return 2 * node + 1;
    }

    long long Right(long long node) {
        return 2 * node + 2;
    }

    void Heapify_up(long long index) {
        if (index > 0 && vec[index].key > vec[Parent(index)].key) {
            std::swap(vec[Parent(index)], vec[index]);
            Heapify_up(Parent(index));
        }
    }

    void Heapify_down(long long index) {
        long long l = Left(index);
        long long r = Right(index);
        long long child;
        if (l < vec.size()) {
            if (r < vec.size() && vec[l].key < vec[r].key) {
                child = r;
            } else {
                child = l;
            }
            if (child != -1 && vec[child].key > vec[index].key) {
                std::swap(vec[child], vec[index]);
                Heapify_down(child);
            }
        }
    };

public:
    void insert(long long key, T value = T()) {
        vec.push_back(Node<T>(vec.size(), key, value));
        Heapify_up(vec.size() - 1);
    }

    void increase_key(size_t index, long long key) {
        if (key > vec[index].key) {
            vec[index].key = key;
            Heapify_up(index);
        }
    }

    std::pair<long long, T> extract_max() {
        std::swap(vec[0], vec[vec.size() - 1]);
        auto temp = vec[vec.size() - 1];
        vec.pop_back();
        std::pair<long long, T> ans{temp.key, temp.value};
        Heapify_down(0);
        return ans;
    }

    void print() {
        for (int i = 0; i < vec.size(); ++i) {
            std::cout << vec[i].key << ' ';
        }
    }
};
