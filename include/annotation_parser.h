#include <tinyxml2.h>
#include "data_loader.h"
#ifndef ANNOTATION_PARSER_H
#define ANNOTATION_PARSER_H

vector<BndboxElement> annotation_parser(const std::string& path);

#endif 