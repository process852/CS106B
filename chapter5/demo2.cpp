/*
In statistics, a collection of data values is often referred to as a distribution. 
One of the primary goals of statistical analysis is to find ways to compress the 
complete set of data into summary statistics that express properties of the 
distribution as a whole. The most common statistical measure is the mean,
which is simply the traditional average. For the distribution x1, x2, x3, . . . , xn, 
the mean is usually represented by the symbol . Write a function
double mean(Vector<double> & data);
that returns the mean of the data in the vector.

Another common statistical measure is the standard deviation, which provides 
an indication of how much the values in a distribution x1, x2, x3, . . . , xn differ 
from the mean. In mathematical form, the standard deviation (!) is expressed 
as follows, at least if you are computing the standard deviation of a complete 
distribution as opposed to a sample:
The Greek letter sigma (!) indicates a summation of the quantity that follows, 
which in this case is the square of the difference between the mean and each 
individual data point. Write a function
double stddev(Vector<double> & data);
that returns the standard deviation of the data distribution.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double mean(vector<double> & data){
    double sum = 0.0;
    int count = data.size();
    for(auto& elem : data){
        sum += elem;
    }
    return sum / count;
}

double stddev(vector<double> & data){
    double dataMean = mean(data);
    int count = data.size();
    double sum = 0.0;
    for(auto& elem : data){
        sum += pow(dataMean - elem, 2);
    }
    return sqrt(sum / count);
}

int main(){
    vector<double> data = {1,2,3,4,5,6};
    cout << fixed << mean(data) << endl;
    cout << fixed << stddev(data) << endl;
    return 0;
}