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

    MinHeap *minheap = nullptr;
    MaxHeap *maxheap = nullptr;
    if (heaptype == "min") {
        minheap = new MinHeap();
        minheap->buildheap();
    } else if (heaptype == "max") {
        maxheap = new MaxHeap();
        maxheap->buildheap();
    } else {
        std::cout << "Wrong heap type was entered. (min/max)\n";
        return 0;
    }

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
                if (heaptype == "min") {
                    minheap->insert(inputkey);
                    minheap->levelorder();
                } else if (heaptype == "max") {
                    maxheap->insert(inputkey);
                    maxheap->levelorder();
                }
                break;
            case 2:
                if (heaptype == "min") {
                    minheap->deletemin();
                    minheap->levelorder();
                } else if (heaptype == "max") {
                    maxheap->deletemin();
                    maxheap->levelorder();
                }
                break;
            case 3:
            {
                if (heaptype == "min") {
                    int min = minheap->findmin();
                    if (min == -1) {
                        std::cout << "\nHeap is empty.\n";
                    } else {
                        std::cout << "\nMin value: " << min;
                    }
                } else if (heaptype == "max") {
                    int min = maxheap->findmin();
                    if (min == -1) {
                        std::cout << "\nHeap is empty.\n";
                    } else {
                        std::cout << "\nMin value: " << min;
                    }
                }
            }
                break;
            case 4:
                {
                    if (heaptype == "min") {
                        int max = minheap->findmax();
                        if (max == -1) {
                            std::cout << "\nHeap is empty.\n";
                        } else {
                            std::cout << "\nMax value: " << max;
                        }
                    } else if (heaptype == "max") {
                        int max = maxheap->findmax();
                        if (max == -1) {
                            std::cout << "\nHeap is empty.\n";
                        } else {
                            std::cout << "\nMax value: " << max;
                        }
                    }
                }
                break;
            case 5:
                if (heaptype == "min") {
                    minheap->deletemax();
                    minheap->levelorder();
                } else if (heaptype == "max") {
                    maxheap->deletemax();
                    maxheap->levelorder();
                }
                break;
            case 6:
                if (heaptype == "min") {
                    minheap->levelorder();
                } else if (heaptype == "max") {
                    maxheap->levelorder();
                }
                break;
            case 7:
                std::cout << "Bye bye!\n";
                return (0);
            case 10:
                if (heaptype == "min") {
                    minheap->insert(10);
                    minheap->levelorder();
                    minheap->insert(15);
                    minheap->levelorder();
                    minheap->insert(3);
                    minheap->levelorder();
                    minheap->insert(8);
                    minheap->levelorder();
                    minheap->insert(5);
                    minheap->levelorder();
                    minheap->insert(20);
                    minheap->levelorder();
                    minheap->insert(5);
                    minheap->levelorder();
                    minheap->insert(18);
                    minheap->levelorder();
                    minheap->insert(27);
                    minheap->levelorder();
                    minheap->insert(18);
                    minheap->levelorder();
                    minheap->insert(19);
                    minheap->levelorder();
                    minheap->insert(12);
                    minheap->levelorder();
                    minheap->insert(7);
                    minheap->levelorder();
                    minheap->insert(18);
                    minheap->levelorder();
                    minheap->insert(16);
                    minheap->levelorder();
                } else if (heaptype == "max") {
                    minheap->insert(10);
                    minheap->levelorder();
                    minheap->insert(15);
                    minheap->levelorder();
                    minheap->insert(3);
                    minheap->levelorder();
                    minheap->insert(8);
                    minheap->levelorder();
                    minheap->insert(5);
                    minheap->levelorder();
                    minheap->insert(20);
                    minheap->levelorder();
                    minheap->insert(5);
                    minheap->levelorder();
                    minheap->insert(18);
                    minheap->levelorder();
                    minheap->insert(27);
                    minheap->levelorder();
                    minheap->insert(18);
                    minheap->levelorder();
                    minheap->insert(19);
                    minheap->levelorder();
                    minheap->insert(12);
                    minheap->levelorder();
                    minheap->insert(7);
                    minheap->levelorder();
                    minheap->insert(18);
                    minheap->levelorder();
                    minheap->insert(16);
                    minheap->levelorder();
                }
            default:
                std::cout << "\nError: Wrong input.\n\n";
        }
    }
    return 0;
}
