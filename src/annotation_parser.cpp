#include <tinyxml2.h>
#include <iostream>
#include "annotation_parser.h"

using namespace tinyxml2;

vector<BndboxElement> annotation_parser(const std::string& path)
{
    vector<BndboxElement> nums;

    XMLDocument doc;
    
    // Make sure file loads correctly, if not return empty vector
    if (doc.LoadFile(path.c_str()) != XML_SUCCESS) {
        cout<<"File not loaded successfully";
        return nums;
    }
    // Make sure this is an annotation file, and find the annotation element
    XMLElement* annotation = doc.FirstChildElement("annotation");
    if (!annotation) return nums;

    // Loop for each object in the annotation file
    for (XMLElement* object = annotation->FirstChildElement("object");
         object != nullptr;
         object = object->NextSiblingElement("object")) 
    {
        // Only care if the object is a person 
        XMLElement* name = object->FirstChildElement("name");
            if (!name || std::string(name->GetText()) != "person")
                continue;

        // Access the box for the found perosn
        XMLElement* box = object->FirstChildElement("bndbox");
        if (!box) continue;
        
        // Get values from the annotation file
        int xmin = box->FirstChildElement("xmin")->IntText();
        int ymin = box->FirstChildElement("ymin")->IntText();
        int xmax = box->FirstChildElement("xmax")->IntText();
        int ymax = box->FirstChildElement("ymax")->IntText();

        BndboxElement bb;
        bb.path=path;
        bb.x1 = xmin;
        bb.y1 = ymin;
        bb.w = xmax - xmin;
        bb.h = ymax - ymin;
        

        if (bb.w > 0 && bb.h > 0) {
            nums.push_back(bb);
        }
    }

    return nums;
}