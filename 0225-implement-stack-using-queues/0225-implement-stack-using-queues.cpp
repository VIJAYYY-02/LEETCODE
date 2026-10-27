
class MyStack {
public:
    queue<int> q1, q2;
  // q1 main 
  // q2 temp 


    MyStack() {
    }

    void push(int x) {
        q2.push(x);  // push elemnt into temp queue 

        while (!q1.empty()) {   // if there is a elemnt in main push it to temp
            q2.push(q1.front()); // it wil creatr a stack effect of LIFO
            q1.pop();       
        }

        while (!q2.empty()) {
            q1.push(q2.front());   // THEN MOVE EVERTHING TO MAIN 
            q2.pop();
        }
    }

    int pop() {
        int x = q1.front();
        q1.pop();
        return x;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};