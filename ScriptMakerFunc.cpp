#include "ScriptMakerHeader.h"

TiXmlDocument Doc;
TiXmlPrinter Printer;

std::string CMD, Opt;
std::string LoadedFileName;

std::string CategoryNameBuffer;
std::string FileNameBuffer;
std::string Extension = ".xml";
std::string StringData;
bool EscapeStatus;

std::string RemoveSpace(const std::string& Str) {
	std::string Result = Str;
	Result.erase(std::remove_if(Result.begin(), Result.end(), [](unsigned char Ch) {
		return std::isspace(Ch);
		}), Result.end());
	return Result;
}

void CreateNewFile(const char* FileName) {
	Doc.LinkEndChild(new TiXmlDeclaration("1.0", "", ""));
	Doc.LinkEndChild(new TiXmlElement("Script"));

	if (Doc.SaveFile(FileName)) {
		std::cout << "\n[Message] Created new script file \"" << Opt << "\" successfully.\n\n";
		Doc.LoadFile(FileName);
		LoadedFileName = FileName;
	}
	else
		std::cout << "\n[Message] Failed to create new script file \"" << Opt << "\".\n\n";
}

void LoadFile(const char* FileName) {
	if (Doc.LoadFile(FileName)) {
		std::cout << "[Message] Loaded script file \"" << Opt.c_str() << "\" successfully.\n\n";
		LoadedFileName = Opt;
	}
	else
		std::cout << "[Message] Failed to load script file \"" << Opt.c_str() << "\".\n\n";
}

TiXmlElement* FindRoot() {
	return Doc.RootElement();
}

TiXmlElement* FindCategory(const char* CategoryName) {
	return FindRoot()->FirstChildElement(CategoryName);
}

const char* FindData(const char* CategoryName, const char* DataName) {
	return FindCategory(CategoryName)->Attribute(DataName);
}

void AddCategory(const char* CategoryName) {
	FindRoot()->LinkEndChild(new TiXmlElement(CategoryName));
}

void AddStringData(const char* CategoryName, const char* DataName, const char* Value) {
	FindCategory(CategoryName)->SetAttribute(DataName, Value);
}

void AddCategoryFunc(const char* CategoryName) {
	TiXmlElement* Category = FindCategory(CategoryName);
	if (!Category) {
		AddCategory(CategoryName);
		std::cout << "[Message] Added New category \"" << CategoryName << "\" successfully.\n\n";
		Doc.SaveFile(LoadedFileName.c_str());
	}
	else
		std::cout << "[Message] Category \"" << CategoryName << "\" is already exists.\n\n";

	Doc.SaveFile(LoadedFileName.c_str());
}

void AddStringDataFunc(const char* CategoryName, const char* DataName, const char* Value) {
	AddStringData(CategoryName, DataName, Value);
	std::cout << "[Message] Added new Script line \"" << DataName << "\" successfully.\n\n";

	Doc.SaveFile(LoadedFileName.c_str());
}

