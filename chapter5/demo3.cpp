/*
A histogram is a graphical way of displaying data by dividing the data into
separate ranges and then indicating how many data values fall into each range.
For example, given the set of exam scores
100, 95, 47, 88, 86, 92, 75, 89, 81, 70, 55, 80
a traditional histogram would have the following form:
The asterisks in the histogram indicate one score in the 40s, one score in the
50s, five scores in the 80s, and so forth.
When you generate histograms using a computer, however, it is much
easier to display them sideways on the page, as in this sample run:
Write a program that reads in a vector of integers from a data file and then
displays a histogram of those numbers, divided into the ranges 0–9, 10–19,
20–29, and so forth, up to the range containing only the value 100. Your
program should generate output that looks as much like the sample run as
possible.
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

void showHistogram(vector<int> & data){
    for(int i = 0; i <= 10; i++){
        cout << to_string(i) << "0s: " << string(data[i], '*') << endl;
    }
}
void histogram(vector<int> &data)
{
    vector<int> valueCount(11, 0);
    for (auto &elem : data)
    {
        int index = elem / 10;
        valueCount[index] += 1;
    }
    showHistogram(valueCount);
}

int main(){
    vector<int> fileData = {1,2,10,50,100,100, 45, 80, 95, 90, 96, 92};
    histogram(fileData);
    return 0;
}