/*
And the first one now
Will later be last
For the times they are a-changin’.
—Bob Dylan, “The Times They Are a-Changin’,” 1963
Following the inspiration from Bob Dylan’s song (which is itself inspired by 
Matthew 19:30), write a function
void reverseQueue(Queue<string> & queue);
that reverses the elements in the queue. Remember that you have no access to 
the internal representation of the queue and must therefore come up with an 
algorithm—presumably involving other structures—that accomplishes the 
task.
*/

#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void reverseQueue(queue<string> & q){
    stack<string> s;
    while(q.size()){
        s.push(q.front());
        q.pop();
    }

    while(s.size()){
        q.push(s.top());
        s.pop();
    }

}

int main(){
    vector<string> lines = {
        "And the first one now",
        "Will later be last",
        "For the times they are a-changin"
    };

    queue<string> q;
    for(auto item : lines){
        q.push(item); // 元素入队
    }
    reverseQueue(q);

    while(q.size()){
        cout << q.front() << endl;
        q.pop();
    }
    return 0;

}