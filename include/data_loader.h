
#include <string>
#include <vector> 
#ifndef DATA_LOADER_H
#define DATA_LOADER_H

using namespace std;


// Stores the two points, each with two coordinates
struct BndboxElement
{
    public:
        string path;
        int x1, y1, w, h;
};

struct Sample
{
    // Constructors
    Sample();

    private:
        string name;
        vector<BndboxElement> bndbox;
    

};



#endif 


