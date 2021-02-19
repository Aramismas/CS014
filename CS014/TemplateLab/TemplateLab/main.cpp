//
//  main.cpp
//  TemplateLab
//
//  Created by Aramis Masarati on 1/22/20.
//  Copyright © 2020 Aramis Masarati. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdexcept>

using namespace std;
// creates a template which takes in any type of vector
template <typename T>
// finds and returns the in`dex with the minimum value from index to vals.size() in the vector
unsigned min_index(const vector<T> &vals, unsigned index);

template <typename T>
// sorts the elements from least to greatest using the min_index function
void selection_sort(vector<T> &vals);

template <typename T>
//returns the element with the given index and throws an exception if the passed in index is out of range
T getElement(vector<T> vals, unsigned index);

vector<char> createVector();

int main() {
    //Part A
    vector<string> list;
    list.push_back("hello");
    list.push_back("yes");
    list.push_back("no");
    list.push_back("neverever");
    selection_sort(list);
    for (unsigned i = 0; i < list.size(); i++) {
        cout << list.at(i) << " ";
    }
    cout << endl;
    vector<double> list1;
    list1.push_back(5.2);
    list1.push_back(6.78);
    list1.push_back(2.93);
    list1.push_back(10.78);
    selection_sort(list1);
    for (unsigned i = 0; i < list.size(); i++) {
        cout << list1.at(i) << " ";
    }
    cout << endl;
    vector<int> list2;
    list2.push_back(5);
    list2.push_back(6);
    list2.push_back(2);
    list2.push_back(10);
    selection_sort(list2);
    for (unsigned i = 0; i < list.size(); i++) {
        cout << list2.at(i) << " ";
    }
    cout << endl;
    //Part B
    try {
     srand(time(0));
     vector<char> vals = createVector();
     char curChar;
     int index;
     int numOfRuns = 10;
        while(--numOfRuns >= 0){
            cout << "Enter a number: " << endl;
            cin >> index;
            curChar = getElement(vals,index);
            cout << "Element located at " << index << ": is " << curChar << endl;
        }
    }
    catch (const std::out_of_range& excpt) {
        cout << excpt.what() << endl;
    }
    return 0;
}

vector<char> createVector() {
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

template <typename T>
unsigned min_index(const vector<T> &vals, unsigned index) {
    unsigned min = index;
    for (unsigned i = index+1; i < vals.size(); i++) {
        if (vals.at(i) < vals.at(min)) {
            min = i;
        }
    }
    return min;
}

template <typename T>
void selection_sort(vector<T> &vals) {
    unsigned min;
    T temp;
    for (unsigned i = 0; i < vals.size(); i++) {
        min = min_index(vals, i);
        temp = vals.at(i);
        vals.at(i) = vals.at(min);
        vals.at(min) = temp;
    }
}

template <typename T>
T getElement(vector<T> vals, unsigned index) {
    if (index < 0 || index > vals.size()) {
        throw out_of_range("out of range exception occured");
    }
    return vals.at(index);
}
