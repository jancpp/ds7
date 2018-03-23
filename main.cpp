/*
 Author: Jan Polzer
 File:   main.cpp
 Date:   3/12/2018
 */

#include "MinHeap.h"
#include "MaxHeap.h"
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
    // Check for correct terminal input
    std::string heaptype = argv[1];
    if ((argc != 3) && ((heaptype != "min") || (heaptype != "max")) ) {
        std::cout << "To run program type:\n ./Lab07 max data.txt for max heap\nor ./Lab07 min data.txt for min heap\n\n";
        return 0;
    }

    Heap *heap;
    if (heaptype == "min") {
        heap = new MinHeap();
    } else if (heaptype == "max") {
        heap = new MaxHeap();
    } else {
        std::cout << "Wrong heap type was entered. (min/max)\n";
        return 0;
    }

    int arrSize = 0;
    int number = -1;

    // Read data from a file into array
    std::ifstream inputFile;
    inputFile.open(argv[2]);
    if (!inputFile) {
        inputFile.close();
        std::cout << "Error reading the input file.\n";
        // delete heap;
        return 0;
    } else {
        while(inputFile >> number) {
            arrSize++;
        }
        int data[arrSize];
        std::cout << "Data.txt elements:";
        // inputFile.clear();
        // inputFile.seekg(0, std::ios::beg);
        for (int i=0; i<arrSize; i++) {
            inputFile >> number;
            std::cout << " " << number;
            data[i] = number;
        }
        inputFile.close();
        heap->buildheap(data, arrSize);
    }




    heap->levelorder(); //TODO

    // User interacation
    int choice = -1;

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
//                case 1:
//                std::cout << "Enter a number to be inserted: ";
//                std::cin >> inputkey;
//                if (!minHeap->insert(inputkey)) {
//                    std::cout <<" Failed to insert " << inputkey <<
//                    " into hash table with quadratic probing.\n";
//                }
//                break;
//                case 2:
//                if (minHeap->deletemin()) {
//                    std::cout << minHeap->findmin()->key() << " has been deleted from minHeap.\n";
//                }
//                break;
                //  // Reads data from a file
//                int size = 0;
//                int number = -1;
//            case 3:
//                if (minHeap->deletemin()) {
//                    std::cout << minHeap->findmin()->key() << " has been deleted from minHeap.\n";
//                }
//                break;
//                case 4:
//                if (minHeap->findmin() != nullptr) {
//                    std::cout << "min number in the minHeap is " << minHeap->findmin()->key() << " \n";
//                } else{
//                    std::cout << "minHeap is empty\n";
//                }
//                break;
//                case 5:
//                if (minHeap->findmax()) {
//                    std::cout << "max number in the minHeap is " << minHeap->findmax()->key() << " \n";
//                } else{
//                    std::cout << "minHeap is empty\n";
//                }
//                break;
//                case 6:
//                std::cout << "Enter a number to be found: ";
//                std::cin >> inputkey;
//                if (minHeap->find(inputkey)->key() == inputkey) {
//                    std::cout << minHeap->find(inputkey)->key() << " exists in the minHeap.\n";
//                } else {
//                    std::cout << inputkey << " does not exist in the minHeap.\n";
//                }
//                break;
//                case 7:
//                std::cout << "Enter a number to be deleted: ";
//                std::cin >> inputkey;
//                if (minHeap->delete(inputkey)) {
//                    std::cout << inputkey << " have been deleted from the minHeap.\n";
//                } else {
//                    std::cout << inputkey << " does not exist in the minHeap.\n";
//                }
//                break;
                case 6:
                heap->levelorder();
                break;
                case 7:
                std::cout << "Bye bye!\n";
                return (0);
            default:
                std::cout << "\nError: Wrong input.\n\n";
        }
    }

    // delete heap;
    return 0;
}
