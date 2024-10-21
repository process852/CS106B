/*
The figures in this book are created using PostScript®, a powerful graphics 
language developed by the Adobe Corporation in the early 1980s. PostScript 
programs store their data on a stack. Many of the operators available in the 
PostScript language have the effect of manipulating the stack in some way. 
You can, for example, invoke the pop operator, which pops the top element 
off the stack, or the exch operator, which swaps the top two elements.
One of the most interesting (and surprisingly useful) PostScript operators is 
the roll operator, which takes two arguments: n and k. The effect of 
applying roll(n, k) is to rotate the top n elements of a stack by k positions, 
where the general direction of the rotation is toward the top of the stack. More 
specifically, roll(n, k) has the effect of removing the top n elements, 
cycling the top element to the last position k times, and then replacing the 
reordered elements back on the stack. Figure 5-14 shows before and after 
pictures for three different examples of roll.
Write a function
void roll(Stack<char> & stack, int n, int k)
that implements the roll(n, k) operation on the specified stack. Your 
implementation should check that n and k are both nonnegative and that n is 
not larger than the stack size; if either of these conditions is violated, your 
implementation should call error with the message
roll: argument out of range
Note, however, that k can be larger than n, in which case the roll operation 
continues through more than a complete cycle. This case is illustrated in the 
final example in Figure 5-14, in which the top two elements on the stack are 
rolled four times, leaving the stack exactly as it started.
*/

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void roll(stack<char>& charStack, int n, int k){
    // n represents the numbers of to roll
    if(n > charStack.size() || (n < 0 || k < 0)){
        throw out_of_range("roll: argument out of range");
    }
    k = k % n;
    if(k == 0){
        return;
    }
    else{
        queue<char> charQueue;
        stack<char> charReverseStack;
        for(int i = 0; i < n; i++){
            charReverseStack.push(charStack.top());
            charStack.pop();
        }
        while(charReverseStack.size()){
            charQueue.push(charReverseStack.top());
            charReverseStack.pop();
        }
        int forwardCount = n - k;
        for(int i = 0; i < forwardCount; i++){
            char c = charQueue.front();
            charQueue.pop();
            charQueue.push(c);
        }
        while(charQueue.size()){
            charStack.push(charQueue.front());
            charQueue.pop();
        }
    }
}
void showStack(stack<char> charStack, bool firstCall = true){
    if(charStack.size() > 1){
        char c = charStack.top();
        charStack.pop();
        showStack(charStack, false);
        if(firstCall)
            cout << c << " Stack Top" << endl;
        else
            cout << c << " ";
    }
    else{
        cout << "Stack Bottom: " << charStack.top() << " ";
    }
}

void initStack(stack<char>& charStack, vector<char> charVector){
    for(int i = 0; i < charVector.size(); i++){
        charStack.push(charVector[i]);
    }
}
void clearStack(stack<char>& charStack){
    while(charStack.size()){
        charStack.pop();
    }
}
int main()
{
    stack<char> s;
    initStack(s, {'A', 'B', 'C', 'D'});
    showStack(s);
    roll(s, 4, 1);
    showStack(s);

    clearStack(s);
    initStack(s, {'A', 'B', 'C', 'D'});
    showStack(s);
    roll(s, 3, 2);
    showStack(s);

    clearStack(s);
    initStack(s, {'A', 'B', 'C', 'D'});
    showStack(s);
    roll(s, 2, 4);
    showStack(s);

    return 0;
}