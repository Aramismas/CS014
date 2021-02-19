//
//  main.cpp
//  JugProgram
//
//  Created by Aramis Masarati on 3/12/20.
//  Copyright © 2020 Aramis Masarati. All rights reserved.
//

#include <iostream>
#include "Jug.h"

int main() {
    {
       string solution;
       Jug head(3, 5, 4, 1, 2, 3, 4, 5, 6);
       if (head.solve(solution) != 1) {
          cout << "Error 3" << endl;
       }
       cout << solution << endl << endl;
    }
    {
       string solution;
       Jug head(3, 5, 4, 1, 1, 1, 1, 1, 2);
       if(head.solve(solution) != 1) {
          cout << "Error 3" << endl;
       }
       cout << solution << endl;
    }
    return 0;
}
