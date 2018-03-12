/*
Author: Jan Polzer
File:   main.cpp
Date:   3/12/2018
*/

#include "minHeap.h"
#include "maxHeap.h"
#include <fstream>
#include <iostream>

int main(int argc, char **argv) {

        minHeap *minHeap = nullptr;
        maxHeap *minHeap = nullptr;

        // Reads keys from a file
        int key = -1;
        std::ifstream inputFile;
        inputFile.open(argv[1]);
        if (!inputFile) {
                std::cout << "Error reading the input file.\n";
                inputFile.close();
        } else {
                minHeap  = new minHeap();
                while(inputFile >> key) {
                        minHeap->insert(key);
                }
        }
        inputFile.close();

        // User interacation
        int choice = -1;
        int inputkey = 0;

        while (choice != 5) {
                std::cout << "\n............................................\n\n";
                std::cout << "Please choose one of the following commands:\n\n";
                std::cout << "1- insert\n\n";
                std::cout << "2- deletemin\n\n";
                std::cout << "3- deletemax\n\n";
                std::cout << "4- findmin\n\n";
                std::cout << "5- findmax\n\n";
                std::cout << "6- find\n\n";
                std::cout << "7- delete\n\n";
                std::cout << "8- level order\n\n";
                std::cout << "9- exit\n\n";

                std::cout << "> ";
                std::cin >> choice;

                switch (choice) {
                        case 1:
                        std::cout << "Enter a number to be inserted: ";
                        std::cin >> inputkey;
                        if (!minHeap->insert(inputkey)) {
                                std::cout <<" Failed to insert " << inputkey <<
                                " into hash table with quadratic probing.\n";
                        }
                        break;
                        case 2:
                        if (minHeap->deletemin()) {
                                std::cout << minHeap->findmin()->key() << " has been deleted from minHeap.\n";
                        }
                        break;
                        case 3:
                        if (minHeap->deletemin()) {
                                std::cout << minHeap->findmin()->key() << " has been deleted from minHeap.\n";
                        }
                        break;
                        case 4:
                        if (minHeap->findmin() != nullptr) {
                                std::cout << "min number in the minHeap is " << minHeap->findmin()->key() << " \n";
                        } else{
                                std::cout << "minHeap is empty\n";
                        }
                        break;
                        case 5:
                        if (minHeap->findmax()) {
                                std::cout << "max number in the minHeap is " << minHeap->findmax()->key() << " \n";
                        } else{
                                std::cout << "minHeap is empty\n";
                        }
                        break;
                        case 6:
                        std::cout << "Enter a number to be found: ";
                        std::cin >> inputkey;
                        if (minHeap->find(inputkey)->key() == inputkey) {
                                std::cout << minHeap->find(inputkey)->key() << " exists in the minHeap.\n";
                        } else {
                                std::cout << inputkey << " does not exist in the minHeap.\n";
                        }
                        break;
                        case 7:
                        std::cout << "Enter a number to be deleted: ";
                        std::cin >> inputkey;
                        if (minHeap->delete(inputkey)) {
                                std::cout << inputkey << " have been deleted from the minHeap.\n";
                        } else {
                                std::cout << inputkey << " does not exist in the minHeap.\n";
                        }
                        break;
                        case 8:
                        std::cout << "level order: ";
                        minHeap->levelorder();
                        break;
                        case 9:
                        std::cout << "Bye bye!\n";
                        delete minHeap;
                        return (0);
                        default:
                        std::cout << "\nError: Wrong input.\n\n";
                }
        }
        delete minHeap;
        return (0);
}
