////////////////////////////////////////////
//  main.cpp
//  EX06_04
//  Created by Ivan Solodyankin on 11/17/18.
//  
//  Purpose: rebuild circle class using overload operators
//////////////////////////////
#include <iostream>
#include <string>
using namespace std;

class Circle 

{
    private:
        double radius;

    public:
        Circle()
        {
            radius = 1;
        }
        Circle (double newRadius)
        {
            radius = newRadius;
        }
        double getArea()
        {
            return radius * radius * 3.14159;
        }
        double getRadius()
        {
            return radius;
        }
        // get difference between two circle ojects
        Circle subtract(Circle &secCircle) 
        {
            double r = radius - secCircle.getRadius();
            return Circle(r);
        }
        // get circle values and return integers to compare 
        int compareTo(Circle &secCircle) 
        {
            Circle temp = subtract(secCircle);
            if(temp.getRadius() < 0) 
            {
                return -1;
            } 
            else if(temp.getRadius() == 0) 
            {
                return 0;
            } 
            else 
            {
                return 1;
            }
        }    

        friend bool operator<(Circle c1,Circle c2) 
        {
            return (c1.compareTo(c2) < 0);
        }
        friend bool operator<=(Circle c1,Circle c2) 
        {
            return (c1.compareTo(c2) <= 0);
        }
        friend bool operator>(Circle c1,Circle c2) 
        {
            return (c1.compareTo(c2) > 0);
        }
        friend bool operator>=(Circle c1,Circle c2) 
        {
            return (c1.compareTo(c2) >= 0);
        }
        friend bool operator==(Circle c1,Circle c2) 
        {
            return (c1.compareTo(c2) == 0);
        }
        friend bool operator!=(Circle c1,Circle c2) 
        {
            return (c1.compareTo(c2) != 0);
        }

};

int main()
{
    //create objects
    Circle c1(9.0);
    Circle c2(23.0);
    // get area of circle using getRadius function
    cout << "The area of the circle with a radius of " << c1.getRadius()
    << " is " << c1.getArea() << endl;
    cout << "The area of the circle with a radius of " << c2.getRadius()
    << " is " << c2.getArea() << endl;
    // checking < operator
    cout << "Is c1 is less than c2 (T/F)? " << (c1 < c2? "true" : "false") << endl;
    // checking <= operator
    cout << "Is c1 is less than or equal to c2 (T/F)? " << (c1 <= c2? "true" : "false") << endl;
    // checking > operator
    cout << "Is c1 is greater than c2 (T/F)? " << (c1 > c2? "true" : "false") << endl;
    // checking >= operator
    cout << "Is c1 is greater than or equal to c2 (T/F)? " << (c1 >= c2? "true" : "false") << endl;
    // check == operator
    cout << "Is c1 equal to c2 (T/F)? " << (c1 == c2? "true" : "false") << endl;
    // check != operator
    cout << "Is c1 NOT equalt to c2 (T/F)? " << (c1 != c2? "true" : "false") << endl;

    return 0;
}

