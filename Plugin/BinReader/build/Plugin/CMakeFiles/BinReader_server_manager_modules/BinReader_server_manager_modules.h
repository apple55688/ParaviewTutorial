#ifndef BinReader_server_manager_modules_h
#define BinReader_server_manager_modules_h

#include "BinReader_server_manager_modules_data.h"
#include <string>
#include <vector>

inline void BinReader_server_manager_modules_initialize(std::vector<std::string>& xmls)
{
  (void)xmls;
  {
    char *init_string = BinReader_server_manager_modulesreadersGetInterfaces();
    xmls.emplace_back(init_string);
    delete [] init_string;
  }
}

#endif
