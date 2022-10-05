#include<iostream>
#include<map>
#include<list>
using namespace std;
enum color{WHITE,RED,BLUE};
class Node
{
public:
    char data;
    int color;
    bool is_visited;
    bool is_in_adjlist;

    Node(char val)
    {
        data=val;
        color=WHITE;
        is_visited=false;
        is_in_adjlist=false;
    }
};
class Compare_nodes
{
public:
    bool operator()(Node* temp_u,Node* temp_v)
    {
        return (temp_u->data < temp_v->data);
    }
};
class Graph
{
private:
    map<Node*,list<Node*>,Compare_nodes> adjlist;
    list<Node*> node_list;
    bool is_bipartitie=true;
    Node* find_node_in_list(char val)
    {
        Node* temp=NULL;
        for(auto i=node_list.begin();i!=node_list.end();i++)
        {
            if((*i)->data == val)
            {
                temp=*i;
                break;
            }
        }
        return temp;
    }
    void color_graph(Node* temp,int curr_color)
    {
        if(temp->color!=WHITE && temp->color!=curr_color)
        {
            is_bipartitie=false;
            return;
        }
        temp->color=curr_color;
        if(temp->is_visited==true)
        {
            return;
        }
        temp->is_visited=true;
        if(temp->is_in_adjlist==true)
        {
            list<Node*> &l=(adjlist.find(temp))->second;
            for(auto i=l.begin();i!=l.end();i++)
            {
                if(curr_color==RED)
                {
                    color_graph(*i,BLUE);
                }
                else
                {
                    color_graph(*i,RED);
                }
            }
        }
    }

public:
    void push_edge(char val_u,char val_v)
    {
        Node* temp_u=NULL;
        Node* temp_v=NULL;
        if(node_list.empty()==true)
        {
            temp_u=new Node(val_u);
            temp_v=new Node(val_v);
            node_list.push_back(temp_u);
            node_list.push_back(temp_v);

            adjlist[temp_u].push_back(temp_v);
            // adjlist[temp_v].push_back(temp_u);       //<--------
            temp_u->is_in_adjlist=true;                          //|------For undirected graphs
            // temp_v->is_in_adjlist=true;              //<--------
        }
        else
        {
            temp_u=find_node_in_list(val_u);
            temp_v=find_node_in_list(val_v);
            
            if(temp_u==NULL && temp_v==NULL)
            {
                temp_u=new Node(val_u);
                temp_v=new Node(val_v);
                node_list.push_back(temp_u);
                node_list.push_back(temp_v);
            }
            else if(temp_u!=NULL && temp_v==NULL)
            {
                temp_v=new Node(val_v);
                node_list.push_back(temp_v);
            }
            else if(temp_u==NULL && temp_v!=NULL)
            {
                temp_u=new Node(val_u);
                node_list.push_back(temp_u);
            }
            else
            {

            }
            adjlist[temp_u].push_back(temp_v);
            // adjlist[temp_v].push_back(temp_u);       //<--------
            temp_u->is_in_adjlist=true;                          //|------For undirected graphs
            // temp_v->is_in_adjlist=true;              //<--------

        }
    }
    void show_graph()
    {
        for(auto i=adjlist.begin();i!=adjlist.end();i++)
        {
            Node* temp_u=(*i).first;
            cout<<temp_u->data<<"("<<temp_u->color<<")"<<"-->";
            list<Node*> &l=(*i).second;
            for(auto j=l.begin();j!=l.end();j++)
            {
                Node* temp_v=*j;
                cout<<temp_v->data<<"("<<temp_v->color<<")"<<" ";
            }
            cout<<endl;
        }
    }
    void find_bipartite()
    {
        for(auto i=node_list.begin();i!=node_list.end();i++)
        {
            Node* temp=*i;
            if(temp->is_visited==false)
            {
                color_graph(temp,RED);
            }
        }
        if(is_bipartitie==true)
        {
            cout<<"The graph is bipartite"<<endl;
        }
        else
        {
            cout<<"The graph is not bipartite"<<endl;
        }
    }
};
int main()
{
    Graph obj;
    obj.push_edge('a','b');
    obj.push_edge('c','b');
    obj.push_edge('c','e');
    obj.push_edge('d','f');
    obj.push_edge('d','e');
    obj.push_edge('d','i');
    obj.push_edge('g','e');
    obj.push_edge('h','e');

    obj.show_graph();
    obj.find_bipartite();
    cout<<endl;
    obj.show_graph();
    
    // obj.push_edge('a','b');
    // obj.push_edge('b','c');
    // obj.push_edge('c','a');

    // obj.show_graph();
    // obj.find_bipartite();
    // cout<<endl;
    // obj.show_graph();
    return 0;
}