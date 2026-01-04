#include <iostream>
#include "annotation_parser.h"
#include "data_loader.h"
#include <filesystem>
using namespace std;

int main()
{   
    
   vector<Sample> test = positiveDataSet(20);
   for(Sample s : test)
   {
        cout<< s.name<< endl;
        cout << s.bbs.size() << endl;
   }
   cout << test.size()<<endl;
    return 0;


}

// string directory_path = ".";
//     // cout << "Listing contents of directory: " << filesystem::absolute(directory_path) << endl;
//     // string data_path = directory_path +"/data/Train/Annotations";
//     string data_path="../data/Train/Annotations";
//     // cout<<filesystem::absolute(data_path);
//     int count=0;
//     try {
//         for (const auto& entry: filesystem::directory_iterator(data_path))
//         {
//             // filesystem::path ind_path = entry.path();
//             // cout<< ind_path.filename().string()<<endl;
//             // count++;
//             // vector<BndboxElement> um = annotation_parser(ind_path.string());
//             // if (count > 4)
//             // {
//             //     break;
//             // }
//             count++;
                
//         }

        
//     } catch (const filesystem::filesystem_error& e) 
//     {
//         std::cerr << "Filesystem error: " << e.what() << endl;
//     }
//     cout << count<< endl;