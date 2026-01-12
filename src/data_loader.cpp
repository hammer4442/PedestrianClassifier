#include "data_loader.h"
#include "annotation_parser.h"
#include <filesystem>
#include <string>
#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>


using namespace std;

// This is used to create positive smaples that have on the file location
Sample::Sample(filesystem::path ind_path)
{
    bbs=annotation_parser(ind_path.string());
    name=ind_path.filename().string();
    name.erase(name.length()-4);
    pedestrian=true;
}

vector<Sample> positiveDataSet(int num_smaples)
{   

    vector<Sample> ret;

    // Generate a seeder to create a number of unique samples that are random everytime
    std::vector<int> seeder;
    for(int i=0; i<614; i++)      
        seeder.push_back(i);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(seeder.begin(), seeder.end(), std::default_random_engine(seed));
    seeder.resize(num_smaples);


    string data_path="../data/Train/Annotations";
    int count =0;
    try {
        for (const auto& entry: filesystem::directory_iterator(data_path))
        {
            // Is the element in the corresponding seeder
            vector<int>::iterator it = std::find(seeder.begin(), seeder.end(), count);
            if (it != seeder.end())
            {
                filesystem::path ind_path = entry.path();
                Sample s=Sample(ind_path);
                // Make sure that there is a pedestrian in the image
                if (s.bbs.size() > 0)
                {
                    ret.push_back(s);
                }
            }
            count++;

                
        }

        
    } catch (const filesystem::filesystem_error& e) 
    {
        std::cerr << "Filesystem error: " << e.what() << endl;
    }
    return ret;
}

vector<Sample> negativeDataSet(int num_smaples)
{
    return vector<Sample>();
}
