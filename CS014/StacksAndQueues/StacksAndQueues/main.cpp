//
//  main.cpp
//  StacksAndQueues
//
//  Created by Aramis Masarati on 1/27/20.
//  Copyright © 2020 Aramis Masarati. All rights reserved.
//

#include <iostream>
#include "WordLadder.h"

int main() {
    string dictFile, wordBegin, wordEnd, outFile;
    cout << "Enter the name of the dictionary file: ";
    cin >> dictFile;
    cout << endl;
    cout << "Enter the name of the output file: ";
    cin >> outFile;
    cout << endl;
    cout << "Enter the first word: ";
    cin >> wordBegin;
    cout << endl;
    while (wordBegin.size() != 5) {
       cout << "Word must have exactly 5 characters." << endl
          << "Please reenter the first word: ";
       cin >> wordBegin;
       cout << endl;
    }
    cout << "Enter the last word: ";
    cin >> wordEnd;
    cout << endl;
    while (wordEnd.size() != 5) {
       cout << "Word must have exactly 5 characters." << endl
          << "Please reenter the last word: ";
       cin >> wordEnd;
       cout << endl;
    }
    
     WordLadder wl(dictFile);
    
    wl.setOptimization(true);
     
    wl.outputLadder(wordBegin, wordEnd, outFile);
    
    cout << "Number of comparisons: " << wl.getComparisons() << endl;
    
    return 0;
}
