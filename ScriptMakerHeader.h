#include <iostream>
#include <algorithm>
#include <string>
#include <windows.h>
#include "tinyxml/tinyxml.h"

extern TiXmlDocument Doc;
extern TiXmlPrinter Printer;

extern std::string CMD, Opt;
extern std::string LoadedFileName;

extern std::string CategoryNameBuffer;
extern std::string FileNameBuffer;
extern std::string Extension;
extern std::string StringData;
extern bool EscapeStatus;

std::string RemoveSpace(const std::string& Str);
void CreateNewFile(const char* FileName);
void LoadFile(const char* FileName);
TiXmlElement* FindRoot();
TiXmlElement* FindCategory(const char* CategoryName);
const char* FindData(const char* CategoryName, const char* DataName);
void AddCategory(const char* CategoryName);
void AddStringData(const char* CategoryName, const char* DataName, const char* Value);
void AddCategoryFunc(const char* CategoryName);
void AddStringDataFunc(const char* CategoryName, const char* DataName, const char* Value);
