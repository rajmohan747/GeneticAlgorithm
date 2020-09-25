// C++ program to print connected components in 
// an undirected graph 
#include<iostream> 
#include <iostream>
#include <ros/ros.h>
#include <list> 
#include "nav_msgs/OccupancyGrid.h"
#include "geometry_msgs/Pose.h"
#include <vector>

using namespace std; 
  
// Graph class represents a undirected graph 
// using adjacency list representation 
class Graph 
{ 
    int V;    // No. of vertices 
  
    // Pointer to an array containing adjacency lists 
    list<int> *adj; 
  
    // A function used by DFS 
    void DFSUtil(int v, bool visited[]); 
public: 
    Graph(int V);   // Constructor 
    ~Graph(); 
    void addEdge(int v, int w); 
    void connectedComponents(); 
}; 
  
// Method to print connected components in an 
// undirected graph 
void Graph::connectedComponents() 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for(int v = 0; v < V; v++) 
        visited[v] = false; 
  
    for (int v=0; v<V; v++) 
    { 
        if (visited[v] == false) 
        { 
            // print all reachable vertices 
            // from v 
            DFSUtil(v, visited); 
  
            cout << "\n"; 
        } 
    } 
    delete[] visited; 
} 
  
void Graph::DFSUtil(int v, bool visited[]) 
{ 
    // Mark the current node as visited and print it 
    visited[v] = true; 
    cout << v << " "; 
  
    // Recur for all the vertices 
    // adjacent to this vertex 
    list<int>::iterator i; 
    for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        if(!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
Graph::~Graph() 
{ 
    delete[] adj; 
} 
  
// method to add an undirected edge 
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v); 
} 
  
// Driver program to test above 
int main(int argc, char** argv)
{

    ros::init(argc, argv, "graph_generation");
    ros::NodeHandle nh;   
    ros::Rate rate(1);

    ros::Publisher grid_pub = nh.advertise<nav_msgs::OccupancyGrid>("grids", 1000);

    nav_msgs::OccupancyGrid occupancy;
    geometry_msgs::Pose pose_;

    Graph g(16); // 5 vertices numbered from 0 to 4 
    // g.addEdge(1, 0); 
    // g.addEdge(2, 3); 
    // g.addEdge(3, 4); 
    // g.addEdge(1, 4); 

    for(int i=0; i< 4; i++)
    {
        g.addEdge(4*i, 4*i + 1); 
        g.addEdge(4*i + 1, 4*i + 2); 
        g.addEdge(4*i + 2, 4*i + 3); 
        //g.addEdge(1, 4);   
    }

    for(int i=0; i< 3; i++)
    {
        g.addEdge(4*i, 4*i + 4); 
        g.addEdge(4*i + 1, 4*i + 5); 
        g.addEdge(4*i + 2, 4*i + 6); 
        g.addEdge(4*i + 3, 4*i + 7); 
        //g.addEdge(1, 4);   
    }

    cout << "Following are connected components \n"; 
    g.connectedComponents(); 

   std::vector<int> data_;
   for(int i =0; i < 4; i++)
   {
       int x = 100;
       data_.push_back(x);
   }
   int data[4] = {2,2,2,2};

   // int data_[16] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};
        occupancy.header.stamp = ros::Time::now();
        occupancy.header.frame_id = "map";
        occupancy.info.resolution = 1;
        occupancy.info.width = 5;
        occupancy.info.height = 5;
        occupancy.info.origin.position.x =0.0;
        occupancy.info.origin.position.y =0.0;
        occupancy.info.origin.orientation.z =0.0;
        occupancy.info.origin.orientation.w =1.0;
        for(int i =0; i < 25; i++)
        {
            int x = 100;
            if(i%20 == 0)
            {
                x =0;
            }
            
            occupancy.data.push_back(x);
        }
            
    while(ros::ok())
    {  

        grid_pub.publish(occupancy);
        rate.sleep();
        ros::spinOnce();
    }
    ros::shutdown();
    return 0;
} 