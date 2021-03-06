/** This algorithm consists of adjacency matrix based implementation **/
/** Graph is weighted and undirected having only positive weighted edge **/


/** Algorithm has been Taken from a Paper Published Under, 
    International Journal of Scientific and Research Publications as Volume 4, Issue 9 on September 2014. ISSN 2250-3153
    Minimum Cost Spanning Tree using Matrix Algorithm By Dr.D vijayalakshmir, R.kalaivani
    Link to the Paper:  http://www.ijsrp.org/research-paper-0914/ijsrp-p3319.pdf
**/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <climits>

using namespace std;
/** 
   We have to restrict our nodes constaints because of
   the memory consumption in the representation of the graph
   as in this algorithm the graph is represented using adjacency list 
**/
#define maxx 1004

/** Original adjacency matrix of the graph **/
int matrix[maxx][maxx];
int nodes;
int weight;
int edges;

/** our required minimum spanning tree **/
vector<pair<int, pair<int,int> > > MST;

/** calculated weight of MST **/
long long MST_weight;

/** parent and rank array for finding cycles **/
int parent[maxx];
int rank_[maxx];

/** Initialize our graph **/
void init() {
    for(int i = 0; i < nodes; i++) {
        parent[i] = i;
        rank_[i] = 1;
    }
    for(int i = 0; i < nodes; i++) {
        for(int j = 0; j < nodes; j++) {
            matrix[i][j] = 0;
        }
    }
}

/** for finding root node of this component **/
int find_root(int random) {
    while(parent[random] != random) {
        parent[random] = parent[parent[random]];
        random = parent[random];
    }
    return random;
}

/** For merging two components **/
void _merge(int a, int b) {
    int root1 = find_root(a);
    int root2 = find_root(b);

    if(root1 == root2) {
        return;
    }

    if(rank_[root1] > rank_[root2]) {
        parent[root1] = root2;
        rank_[root2] += rank_[root1];
    } else {
        parent[root2] = root1;
        rank_[root1] += rank_[root2];
    }
}

/** 
    For finding the next minimum weighted edge
    It may return an edge which is creating cycle
    with our current Minimum spanning tree.
**/
pair<long long,pair<int,int> > find_next_minimum() {
    pair<int, pair<int,int> > p;
    int weigh = INT_MAX;
    int x,y;

    /** Find the minimum edge from the remaining edges left to consider **/
    for(int i = 0; i < nodes; i++) {
        for(int j = 0; j < nodes; j++) {
            if( matrix[i][j] != 0 ) {
                if( weigh > matrix[i][j] ) {
                    weigh = matrix[i][j];
                    x = i;
                    y = j;
                }
            }
        }
    }

    /** if we runs out of edges **/
    if( weigh == INT_MAX ) {
        p = make_pair(0, make_pair(0,0));
        return p;
    }

    p = make_pair(weigh, make_pair(x,y));
    return p;
}

int main() {
    int x , y;

    /** input total nodes **/
    printf("Total nodes in the graph: ");
    scanf("%d", &nodes);
    putchar('\n');

    /** Input total edges **/
    printf("Total edges in the graph: ");
    scanf("%d", &edges);
    putchar('\n');

    /** initialize the graph **/
    init();

    pair<int, pair<int,int> > p;

    printf("Give the original edges in the graph: \n");

    for(int i = 0; i < edges; i++) {
        /** both the vertices attached to the edge and weight of that edge **/
        scanf("%d %d %d", &x, &y, &weight);
        /** set both the indexes to the provided weight **/
        matrix[x][y] = weight;
        matrix[y][x] = weight;
    }
    
    int total_marked = 0;
    MST_weight = 0LL;

    int ff,ss;

    /** processing all the edges of the graph **/
    while(1) {
        p = find_next_minimum();

        /** If we runs out of all the edges then we are done **/
        if( p.first == 0 ) {
            break;
        }
        
        ff = p.second.first;
        ss = p.second.second;

        int root1 = find_root(ff);
        int root2 = find_root(ss);

        /** If this edge is creating a cycle, Ignore this edge **/ 
        if(root1 == root2) {
            matrix[ff][ss] = 0;
            matrix[ss][ff] = 0;
            continue;
        }

        /** add this edge in our Minimum spanning tree **/
        p = make_pair(matrix[ff][ss], make_pair(ff,ss));
        MST.push_back(p);

        MST_weight += matrix[ff][ss];

        /** Clear the edge **/
        matrix[ff][ss] = 0;
        matrix[ss][ff] = 0;

        _merge(ff, ss);
    }

    /** print the edges of our Minimum spanning tree and the obtained weight **/
    printf("MST weight is : %lld\n", MST_weight);

    printf("All the edges\n");
    for(int i = 0; i < MST.size(); i++) {
        p = MST[i];
        printf("%d %d %d\n", p.second.first, p.second.second, p.first);
    }

    return 0;
}
