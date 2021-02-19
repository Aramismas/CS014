//
//  Patient.hpp
//  FinalQuestion4
//
//  Created by Aramis Masarati on 3/17/20.
//  Copyright © 2020 Aramis Masarati. All rights reserved.
//

#ifndef Patient_hpp
#define Patient_hpp

#include <stdio.h>
#include <string>
#include <fstream>

enum Urgency { Low,Med,High };

class Patient {
    private:
        int _patient_id;
        std::string _name;
        Urgency _urgency;
    public:
        Patient(int id,std::string name) : _patient_id(id),_name(name) { }

        Urgency urgency() const { return _urgency; }
        int patient_id() const { return _patient_id; }
        std::string name() const { return _name; }

        void urgency(int urgency) { _urgency = static_cast<Urgency>(urgency); }

        friend std::ostream& operator<<(std::ostream &,const Patient&);
};

#endif /* Patient_hpp */
