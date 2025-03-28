/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
#include <string>
using namespace std;


struct Node{
    int data;
    struct Node *next;
};


void push(struct Node **head, int node_data){//** is the location of the pointer. ie location of location of value LOL 
    struct Node* newNode = new Node;
    newNode->data = node_data;
    newNode->next = (*head);
    (*head) = newNode;
}

void insert(struct Node *prev_node, int node_data){
    struct Node* newNode = new Node;
    newNode->data = node_data;
    newNode->next = prev_node->next;
    prev_node->next = newNode;
}

void append(struct Node**head, int node_data){
    struct Node* newNode = new Node;
    struct Node *last=*head;
    newNode->data = node_data;
    while(last->next != NULL) last = last->next;
    last->next = newNode;
}

void displayList(struct Node *node)
{
   //traverse the list to display each node
   while (node != NULL)
   {
      cout<<node->data<<"-->";
      node = node->next;
   }
 
    if(node== NULL)cout<<"null"; 
} 



int main(){
    int n,k;
    cin >> n >>k;
    string s;
    cin >> s;
    struct Node *head = NULL;
    for(int i =0;i<n;i++){
        append(&head, i);
    }
    for(int i =0;i<s.length();i++){
        if(s[i] == 'A'){
            int val = head->data;
            append(&head, val);
            
        }
        if(s[i] == 'B'){
            
        }
    }
}