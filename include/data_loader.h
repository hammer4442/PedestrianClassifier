
#include <string>
#include <vector> 
#include <filesystem>
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
    Sample(filesystem::path ind_path);

    string name;
    vector<BndboxElement> bbs;
    bool pedestrian;


};

vector<Sample> positiveDataSet(int num_smaples);

vector<Sample> negativeDataSet(int num_smaples);

vector<Sample> createDataSet(int num_samples, float percent_positive);



#endif 


