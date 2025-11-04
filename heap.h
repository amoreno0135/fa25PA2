//
// Created by Aaron Moreno on 11/3/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        if (size >= 64) {
            cerr << "Overflow" << endl;
            return;
        }

        data[size] = idx;
        ++size;

        upheap(size - 1, weightArr);
    }

    int pop(int weightArr[]) {
        // Replace root with last element, then call downheap()
        if (size == 0) {
            cerr << "Empty Heap" << endl;
            return -1;
        }

        int minIndex = data[0];

        data[0] = data[size - 1];
        size--;

        if (size > 0) {
            downheap(0, weightArr);
        }
        return minIndex;
    }

    void upheap(int pos, int weightArr[]) {
        while (pos > 0) {
            int parent = (pos - 1) / 2;

            if (weightArr[data[pos]] < weightArr[data[parent]]) {
                int temp = data[pos];
                data[pos] = data[parent];
                data[parent] = temp;

                pos = parent;
            } else {
                break;
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        while (true) {
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;
            int smallest = pos;

            if (left < size && weightArr[data[left]] < weightArr[data[smallest]]) {
                smallest = left;
            }

            if (right < size && weightArr[data[right]] < weightArr[data[smallest]]) {
                smallest = right;
            }

            if (smallest == pos) {
                break;
            }

            int temp = data[pos];
            data[pos] = data[smallest];
            data[smallest] = temp;

            pos = smallest;
        }
    }
};

#endif