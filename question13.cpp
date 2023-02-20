#include<bits/stdc++.h>
using namespace std;
 
#define ARRAY_SIZE 100
#define LEFT_STACK 0
#define RIGHT_STACK 1
 
struct st {
    int array[ARRAY_SIZE];
    int top1, top2;
} st;
 
void initialize() {
    st.top1 = -1;
    st.top2 = ARRAY_SIZE;
}
  
void push(int stack, int num) {
    if(stack == LEFT_STACK) {
        if (st.top1 < st.top2-1) {
            st.top1++;
            st.array[st.top1] = num;
        } else {
            cout<<"Left Stack Full";
            return;
        }
    } else if(stack == RIGHT_STACK) {
       if (st.top1 < st.top2-1) {
           st.top2--;
           st.array[st.top2] = num;
       } else {
           cout<<"Right Stack Full";
           return;
       }
    }
}
  
int pop(int stack) {
    if(stack == LEFT_STACK) {
        if(st.top1 >= 0){
            return st.array[st.top1--];
 } else {
            cout<<"Left Stack is Empty";
            return INT_MIN;
 }
    } else if(stack == RIGHT_STACK) {
     if(st.top2 <= ARRAY_SIZE-1){
         return st.array[st.top2++];
 } else {
            cout<<"Right Stack is Empty";
            return INT_MIN;
 }
    }
}
  
int main() {
    initialize();
    /* Push element in left stack */
    push(LEFT_STACK, 2);
    push(LEFT_STACK, 4);
    push(LEFT_STACK, 6);
    /* Push element in right stack */
    push(RIGHT_STACK, 1);
    push(RIGHT_STACK, 3);
    push(RIGHT_STACK, 5);
    /*Pop Elements from left stack */
    cout<<"Pop from left stack : "<< pop(LEFT_STACK)<<endl;
    /*Pop Elements from right stack */
    cout<<"Pop from right stack : "<< pop(RIGHT_STACK)<<endl;
    return 0;
}