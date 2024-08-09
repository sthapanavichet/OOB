//Reorder.cpp - main function for reordering an array

#include <algorithm>
#include <iostream>
#include "Stack.h"

using namespace std;

void ReOrder(int newarr[], int arr[], int size) {
    Stack stack;
    Queue queue;
    int leftPtr = 0;
    int rightPtr = size-1;
    for(int i = 0; i < size; i++) {
        if(arr[i] > 0 ) {
            stack.push(arr[i]);
        }
        else if(arr[i] < 0) {
            queue.enqueue(arr[i]);
        }
        else if(arr[i] == 0){
            while(!queue.isEmpty()) {
                newarr[leftPtr++] = queue.front();
                queue.dequeue();
            }
            while(!stack.isEmpty()) {
                newarr[leftPtr++] = stack.top();
                stack.pop();
            }
            newarr[rightPtr--] = 0;
        }

    }
    while(!queue.isEmpty()) {
        newarr[leftPtr++] = queue.front();
        queue.dequeue();
    }
    while(!stack.isEmpty()) {
        newarr[leftPtr++] = stack.top();
        stack.pop();
    }
}

void mySort(int arr[], int size) {
    sort(arr, arr + size, greater<int>());
}

int main() {
    const int SIZE = 18;
    int array[] = { -3,2,-1,5,1,-4,0,11,12,13,-11,-12,0,-1,-2,6,8,7 };
    int newArray[SIZE] = { 0 };

    //Print out the original array
    std::cout << "array:    ";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    //Reorder this array in newArray
    ReOrder(newArray, array, SIZE);
    //Print out the new array
    std::cout << "newArray: ";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << newArray[i] << " ";
    }
    std::cout << std::endl;

    mySort(newArray, SIZE);
    //Print out the sorted new array
    std::cout << "newArray sorted: ";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << newArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}