/*
 Author: Jan Polzer
 File:   main.cpp
 Date:   3/12/2018
 */

#include "MinHeap.h"
#include "MaxHeap.h"
#include <iostream>
#include <string>

int main(int argc, char **argv) {
    // Check for correct terminal input
    std::string heaptype = argv[1];
    if ((argc != 2) && ((heaptype != "min") || (heaptype != "max")) ) {
        std::cout << "To run program type:\n ./Lab07 max for max heap\nor ./Lab07 min for min heap\n\n";
        return 0;
    }

    MinHeap *heap = nullptr;
    if (heaptype == "min") {
        heap = new MinHeap();
    } else if (heaptype == "max") {
//        heap = new MaxHeap();
    } else {
        std::cout << "Wrong heap type was entered. (min/max)\n";
        return 0;
    }

    heap->buildheap();
    heap->levelorder(); //TODO remove

    // User interacation
    int choice = -1;
    int inputkey = -1;

    while (choice != 7) {
        std::cout << "\n............................................\n\n";
        std::cout << "Please choose one of the following commands:\n\n";
        std::cout << "1- insert\n\n";
        std::cout << "2- delete min\n\n";
        std::cout << "3- find min\n\n";
        std::cout << "4- find max\n\n";
        std::cout << "5- delete max\n\n";
        std::cout << "6- level order\n\n";
        std::cout << "7- exit\n\n";

        std::cout << "> ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter a number to be inserted: ";
                std::cin >> inputkey;
                heap->insert(inputkey);
                heap->levelorder();
                break;
            case 2:
                heap->deletemin();
                heap->levelorder();
                break;
            case 3:
            {
                int min = heap->findmin();
                if (min == -1) {
                    std::cout << "\nHeap is empty.\n";
                } else {
                    std::cout << "\nMin value: " << min;
                }
            }
                break;
            case 4:
                {
                    int max = heap->findmax();
                    if (max == -1) {
                        std::cout << "\nHeap is empty.\n";
                    } else {
                        std::cout << "\nMax value: " << max;
                    }
                }
                break;
            case 5:
                heap->deletemax();
                heap->levelorder();
                break;
            case 6:
                heap->levelorder();
                break;
            case 7:
                std::cout << "Bye bye!\n";
                 delete heap;
                return (0);
            default:
                std::cout << "\nError: Wrong input.\n\n";
        }
    }

      delete heap;
    return 0;
}
