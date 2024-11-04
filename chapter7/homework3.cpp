/*
In the 18th century, the astronomer Johann Daniel Titius proposed a rule, later 
recorded by Johann Elert Bode, for calculating the distance from the sun to 
each of the planets known at that time. To apply that rule, which is now known
as the Titius-Bode Law, you begin by writing down the sequence
b1 = 1 b2 = 3 b3 = 6 b4 = 12 b5 = 24 b6 = 48 . . .
where each subsequent element in the sequence is twice the preceding one. It 
turns out that an approximate distance to the i
th planet can be computed from 
this series by applying the formula
The distance di is expressed in astronomical units (AU), which correspond to 
the average distance from the earth to the sun (approximately 93,000,000 
miles). Except for a disconcerting gap between Mars and Jupiter, the 
Titius-Bode law gives reasonable approximations for the distances to the seven 
planets known at the time:
Mercury 0.5 AU
Venus 0.7 AU
Earth 1.0 AU
Mars 1.6 AU
? 2.8 AU
Jupiter 5.2 AU
Saturn 10.0 AU
Uranus 19.6 AU
Concern about the gap in the sequence led astronomers to discover the asteroid 
belt, which they suggested might have been the remains of a planet that had 
once orbited the sun at distance specified by the missing entry in the table.
Write a recursive function getTitiusBodeDistance(k) that calculates 
the expected distance between the sun and the k
th planet, numbering outward 
from Mercury starting with 1. Test your function by writing a program that 
displays the distances to each of these planets in tabular form.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int getDouble(int k){
    if(k == 1) return 1;
    else if (k == 2) return 3;
    else return 2 * getDouble(k - 1);
}

float getTitiusBodeDistance(int k){
    return (4 + getDouble(k)) / 10.0f;
}

int main(){
    for(int i = 1; i < 9; i++){
        cout << fixed << setprecision(1) << getTitiusBodeDistance(i)  << " AU" << endl;
    }
    return 0;
}