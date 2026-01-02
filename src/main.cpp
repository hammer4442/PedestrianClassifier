#include <iostream>
#include "annotation_parser.h"
#include <filesystem>
using namespace std;

int main()
{   
    string directory_path = ".";
    cout << "Listing contents of directory: " << filesystem::absolute(directory_path) << endl;
    // string data_path = directory_path +"/data/Train/Annotations";
    string data_path="../data/Train/Annotations";
    cout<<filesystem::absolute(data_path);
    int count=0;
    try {
        for (const auto& entry: filesystem::directory_iterator(data_path))
        {
            filesystem::path ind_path = entry.path();
            cout<< ind_path.filename().string()<<endl;
            count++;
            vector<BndboxElement> um = annotation_parser(ind_path.string());
            if (count > 4)
            {
                break;
            }
                
        }

        
    } catch (const filesystem::filesystem_error& e) 
    {
        std::cerr << "Filesystem error: " << e.what() << endl;
    }
    // try {
    //     // Iterate over the entries in the directory
    //     for (const auto& entry : filesystem::directory_iterator(directory_path)) {
    //         // 'entry' is a std::filesystem::directory_entry object
    //         filesystem::path path = entry.path();
    //         std::cout << path.filename().string() << std::endl;

    //     }

    // string ex_path ="../data/Test/Annotations/crop_000010.xml";
    // annotation_parser(ex_path);
    // cout<<"yes";
    return 0;


}