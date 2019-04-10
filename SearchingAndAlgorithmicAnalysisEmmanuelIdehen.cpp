//
//  main.cpp
//  SearchBenchmarksEmmanuelIdehen
//
//  Created by Emmanuel Idehen on 4/9/19.
//  Copyright © 2019 Emmanuel Idehen. All rights reserved.
//  Submitted to Mr. Marcus Golden(CS204 Computer programming II)

/*
 
 problem:
 search for 39 in the list of intergers in the array below. what are the number of comparisons made on each search
 algorithm.
 
 Analysis
 
 Binary search:    n element, n/2 element, n/4 element ...... run time : 0(log2n)
 
 didvide the array(list) by 2 and compare the middle element with the key.
 since it's grater than the key, looks to the right half of the list
 divide the half by 2 and check if the middle is equal to the key
 divide the half into another half of 2 and check if the middle is = to the key.
 
 
 1, 3, 5, 9, 10, 11, 15, 17, 19, 13, 24, 25, 29, 31, 33, 37, 38, 39, 43, 45, 47, 51, 52, 53, 57, 59, 61
 
 33, 37, 38, 39, 43, 45, 47, 51, 52, 53, 57, 59, 61
 
 33, 37, 38, 39, 43, 45
 
 37, 38, 39 , 43
 
 39
 
 
 comaparisons made: 4
 
 
 
 
 Linear search : search through the list comparing one element at a time ...... run time : Big 0(n)
 
 comapare the key with first element, compare with secone element, continue till value entered equal key
 
 1, 3, 5, 9, 10, 11, 15, 17, 19, 13, 24, 25, 29, 31, 33, 37, 38, 39.
 
 Comparisons made: 17
 
 */




#include <iostream>
using namespace std;


//Linear Search
int linearSearch(int list[], int size, int num, int &x)
{
    int index = 0;            // Used as a subscript to search array
    int position = -1;        // Used to record the position of search value
    bool found = false;     // Flag to indicate if the value was found
    
    while(index < size && !found)
    {
        if (list[index] == num)    // If the value is found
        {
            found = true;            // Set the flag
            position = index;        // Record the value's subscript
        }
        index++;
        
        if (position == -1)
            x++;
    }
    return position;                // Return the position, or -1
}

//Binary Search
int binarySearch(int array[], int size, int num, int &y)
{
    int first = 0,                            // First array element
    last = size - 1,                    // Last array element
    middle,                                // Midpoint of search
    position = -1;                        // Position of search value
    bool found = false;                        // Flag
    
    while (!found && first <= last)
    {
        middle = (first + last) / 2;        // Calculate midpoint
        if (array[middle] == num)            // If value is found
        {
            found = true;
            position = middle;
        }
        else if (array[middle] > num)        // If value is in the lower half
            last = middle - 1;
        else
            first = middle + 1;                // If value is in the upper half
        if (position == -1)
            y++;
    }
    return position;
}


int main()
{
    const int SIZE = 27;
    int Array[SIZE] = {1, 3, 5, 9, 10, 11, 15, 17, 19, 23,
        24, 25, 29, 31, 33, 37,  38, 39, 43, 45, 47, 51, 52, 53, 57, 59, 61};
    
    int x(0), y = (0), key, //set the key
    xOutput,
    yOutput;
    
    cout << "Enter the number to search for: ";
    cin >> key;
    
    
    xOutput = linearSearch(Array, SIZE, key, x);
    
    yOutput = binarySearch(Array, SIZE, key, y);
    
    cout << "Number of comparisons made before finding the value: "<< key << endl;
    cout << "The linear Search: " << x << endl;
    cout << "The binary Search: " << y << endl;
    
    return 0;
}

/*
 test case
 
 Enter the number to search for: 39
 Number of comparisons made before finding the value: 39
 The linear Search: 17
 The binary Search: 4
 Program ended with exit code: 0
 
 
 
 
 
 
 */
