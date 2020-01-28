#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//linkedListSection

struct node
{
    int data;
    node *next; //pointer to node used store address of data types (node)
};

struct vertices
{
    int val;
    node **firstAddress;
};
//Generates new node and returns it's address
node *genNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->next = NULL;
    return temp; //returning newly allocated address
}

//This insertion takes O(n) time
void insertAtTail(node **head, int data)
{
    node *temp = *head;
    node *newTemp = genNode(data);
    if (*head == NULL)
    {
        *head = newTemp;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newTemp;
}

void printList(node **head)
{
    node *temp = *head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}

node **retAddress(vector<vertices> vertices, int data)
{
    for (auto i = vertices.begin(); i != vertices.end(); i++)
    {
        if ((*i).val == data)
            return (*i).firstAddress; //return address of given vertices point or simply the data
    }
}

//graphSection

//breadthFirstSearch
int count = 0;

bool checkQ(vector<int> q, int data)
{
    for (auto k = q.begin(); k != q.end(); ++k)
    {
        //if (*k == temp->data)
        if (*k == data)
            return false;
    }
    return true;
}
void breadthFirstSearch(vector<vertices> v, node **res, int x)
{
    vector<int> visited; // track of numbers which already were in queue
    queue<int> Q;
    node *temp;
    //node *temp = *retAddress(v,x);
    //Q.push((temp->data)); //starting point of breadthFirstSearch
    Q.push(x);
    visited.push_back(x);
    //mainIteration
    while (!Q.empty())
    {
        int foo = Q.front();
        Q.pop();
        //get the address of 
        temp = *retAddress(v,foo); 
        insertAtTail(res, foo); // inserting at res
        //visited.push_back(foo);
        while (temp != NULL)
        {
            if (checkQ(visited, temp->data))
            {
                Q.push(temp->data);
                visited.push_back(temp->data);
            }
            temp = temp->next;
        }
    }

/*
        links_of_foo = something;
        for (a in links_of_foo):
            if a in visited: continue
            Q.push(a);
        */
/* code */

// vector<int> q;
// node* temp = *row;
// while (temp != NULL){
//     if(checkQ) {
//     q.push_back((temp->data));
//     }
//     temp = temp->next;
// }
// insertAtTail(res,(*q.begin()));
// q.erase(q.begin());

//res[count] = q.begin();
//count += 1;
}

//depthFirstSearch

//SampleAdjacencyList
// Adjacency list of vertex 0 head->1->4

// Adjacency list of vertex 1 head->0->2->3->4

// Adjacency list of vertex 2 head->1->3

// Adjacency list of vertex 3 head->1->2->4

// Adjacency list of vertex 4 head->0->1->3



int main()
{
    //head = NULL;
    node *head = NULL;
    node *row[5];
    node *res = NULL;
    for (int i = 0; i < 5; i++)
        row[i] = NULL;

    vector<int> point;
    vector<vertices> v; //vertices with addresses
    int count = 0;
    point.push_back(0);
    point.push_back(1);
    point.push_back(2);
    point.push_back(3);
    point.push_back(4);
    for (auto i = point.begin(); i != point.end(); i++)
    {
        struct vertices a;
        a.val = *i;
        // if (count > 4)
        //     continue;
        a.firstAddress = &row[count];
        cout << a.firstAddress<<"\n";
        count++;
        v.push_back(a);
    }
    cout << "yoo addres sof 0"<<retAddress(v,0);
    insertAtTail(retAddress(v,0), 1);
    insertAtTail(retAddress(v, 0), 4);
    insertAtTail(retAddress(v, 1), 0);
    insertAtTail(retAddress(v, 1), 2);
    insertAtTail(retAddress(v, 1), 3);
    insertAtTail(retAddress(v, 1), 4);
    insertAtTail(retAddress(v, 2), 1);
    insertAtTail(retAddress(v, 2), 3);
    insertAtTail(retAddress(v, 3), 4);
    insertAtTail(retAddress(v, 3), 2);
    insertAtTail(retAddress(v, 3), 1);
    insertAtTail(retAddress(v, 4), 0);
    insertAtTail(retAddress(v, 4), 1);
    insertAtTail(retAddress(v, 4), 3);
    
    printList(retAddress(v, 0));
    
    breadthFirstSearch(v,&res, 0);
    cout<< "Printing bfs" << endl;
    printList(&res);

    // insertAtTail(&row[0], 4);
    // insertAtTail(&row[1], 0);
    // insertAtTail(&row[1], 2);
    // insertAtTail(&row[1], 3);
    // insertAtTail(&row[1], 4);
    // insertAtTail(&row[2], 1);
    // insertAtTail(&row[2], 3);
    // insertAtTail(&row[3], 4);
    // insertAtTail(&row[3], 2);
    // insertAtTail(&row[3], 1);
    // insertAtTail(&row[4], 0);
    // insertAtTail(&row[4], 1);
    // insertAtTail(&row[4], 3);
    // printList(&row[0]);
    // cout << "\n";
    // printList(&row[1]);
    // cout << "\n";
    // printList(&row[2]);
    // cout << "\n";
    // printList(&row[3]);
    // cout << "\n";
    // printList(&row[4]);
    // cout << "\n";

    // vector<int> vertices;
    // vertices.push_back(0);
    // vertices.push_back(1);
    // vertices.push_back(2);
    // cout << retAddress(vertices,1) << endl;
    // cout << retAddress(vertices,2)<<endl;
    // int *p;
    // int a=7;
    // p = &a;
    //cout << *p << " yo " <<p<<" yoo "<<&p<<"  yoooo "<<&a<<endl;
    

    return 0;
}
