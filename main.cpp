#include "ScriptMakerHeader.h"

int main() { 
	while (!EscapeStatus) {
		std::cout << "[ Script Template Maker 1.2 ]\nIf you need help, enter command \"man\".\n";

		// show current loaded xml document
		if (!LoadedFileName.empty()) {
			std::cout << "-------------------------------------\n";
			std::cout << "Loaded file: \"" << LoadedFileName << "\"\n";
			std::cout << "-------------------------------------\n";
		}


		// enter command
		std::cout << "Enter command.\n>> ";
		getline(std::cin, CMD);
		
		
		// empty command error
		if (CMD.empty()) {
			system("CLS");
			std::cout << "[Message] You can't enter empty command.\n\n";
			continue;
		}


		// create new xml file
		if (CMD == "create") {
			system("CLS");
			
			std::cout << "Enter File Name.\n>> ";
			getline(std::cin, Opt);
				
			system("CLS");
			if (Opt.empty()) {
				std::cout << "[Message] You can't enter empty command.\n\n";
				continue;
			}
			if (Opt == "cancel") continue;

			FileNameBuffer = Opt;

			if (Opt.size() < Extension.size() || Opt.substr(Opt.size() - Extension.size()) != Extension)
				Opt += Extension;

			CreateNewFile(Opt.c_str());
		}


		// load xml file
		else if (CMD == "load") {
			system("CLS");
			
			if (!LoadedFileName.empty())
				std::cout << "[Message] Script file is already loaded.\n\n";

			else {
				std::cout << "Enter script file name.\n>> ";
				getline(std::cin, Opt);
				
				system("CLS");
				
				if (Opt.empty()) {
					std::cout << "[Message] You can't enter empty command.\n\n";
					continue;
				}
				if (Opt == "cancel") continue;
				
				LoadFile(Opt.c_str());
			}
		}
		
		
		// add category class
		else if (CMD == "add -c") {
			system("CLS");
			
			if(LoadedFileName.empty())
				std::cout << "[Message] Script file is not loaded.\n\n";
				
			else {
				std::cout << "Enter category name.\n>> ";
				getline(std::cin, Opt);
				Opt = RemoveSpace(Opt);
				
				system("CLS");
				
				if (Opt.empty()) {
					std::cout << "[Message] You can't enter empty command.\n\n";
					continue;
				}
				if (Opt == "cancel") continue;
				
				AddCategoryFunc(Opt.c_str());
			}
		}


		// add data item
		else if (CMD == "add -d") {
			system("CLS");
			
			if(LoadedFileName.empty())
				std::cout << "[Message] Script file is not loaded.\n\n";
				
			else {
				std::cout << "Enter category name.\n>> ";
				getline(std::cin, Opt);
				
				system("CLS");
				
				if (Opt.empty()) {
					std::cout << "[Message] You can't enter empty command.\n\n";
					continue;
				}
				if (Opt == "cancel") continue;
	
				CategoryNameBuffer = Opt;
	
				if (FindCategory(CategoryNameBuffer.c_str())) {
					std::cout << "Enter data name.\n>> ";
					getline(std::cin, Opt);
					Opt = RemoveSpace(Opt);
					
					system("CLS");
					
					if (Opt.empty()) {
						std::cout << "[Message] You can't enter empty command.\n\n";
						continue;
					}
					if (Opt == "cancel") continue;
					
					AddStringDataFunc(CategoryNameBuffer.c_str(), Opt.c_str(), "");
				}
				else
					std::cout << "[Message] Failed to find category \"" << CategoryNameBuffer << "\".\n\n";
			}
		}


		// view current loaded xml document
		else if (CMD == "view") {
			system("CLS");
			
			if (LoadedFileName.empty())
				std::cout << "[Message] Script file is not loaded.\n\n";
			else {
				Doc.Print();
				std::cout << "\n";
			}
		}


		// update current loaded xml document
		else if (CMD == "refresh") {
			system("CLS");
			
			if (LoadedFileName.empty())
				std::cout << "[Message] Script file is not loaded.\n\n";
			else {
				Doc.Clear();
				Doc.LoadFile(LoadedFileName.c_str());
				std::cout << "[Message] Updated script file \"" << LoadedFileName << "\".\n\n";
			}
		}


		// release current loaded xml document
		else if (CMD == "release") {
			system("CLS");
			
			if(LoadedFileName.empty())
				std::cout << "[Message] Script file is not loaded.\n\n";
			else {
				Doc.Clear();
				std::cout << "[Message] Released \"" << LoadedFileName << "\".\n\n";
				LoadedFileName.clear();
			}
		}


		// manual page
		else if (CMD == "man") {
			system("CLS");
			std::cout << "===================== [ Manual ] =====================\n";
			std::cout << "create  - Creates new script file.\n";
			std::cout << "load    - Loads script file.\n";
			std::cout << "add     - Adds new class in script file.\n";
			std::cout << "  -c      - Adds new category class in script file.\n";
			std::cout << "  -d      - Adds new data class in script file.\n";
			std::cout << "  (Parameter example: \"add -c\")\n";
			std::cout << "view    - Prints the entire body of the script file.\n";
			std::cout << "refresh - Updates the currently loaded file.\n";
			std::cout << "release - Releases loaded script file.\n";
			std::cout << "exit    - Ends program.\n\n";
		}
		
		
		// error command without parameter
		else if(CMD == "add") {
			system("CLS");
			std::cout << "[Message] you must enter parameter. If you need help with parameter, enter command \"man\".\n\n";
		}


		// end program
		else if (CMD == "exit")
			EscapeStatus = true;


		// unknown command
		else {
			system("CLS");
			std::cout << "[Message] Unknown command.\n\n";
		}
	}
}
