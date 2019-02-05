#include <iostream>
#include <map>
#include <string>
#include <iostream>

//
// supporting tools and software
//
// Validate and test your json commands
// https://jsonlint.com/

// RapidJSON : lots and lots of examples to help you use it properly
// https://github.com/Tencent/rapidjson
//

// std::function
// std::bind
// std::placeholders
// std::map
// std::make_pair

#include <functional>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

using namespace rapidjson;
using namespace std;

bool g_done = false;

//
// TEST COMMANDS
//
auto help_command =
		R"(
 {
  "command":"help",
  "payload": {
    "usage":"Enter json command in 'command':'<command>','payload': { // json payload of arguments }"
  }
 }
)";

auto exit_command =
		R"(
 {
  "command":"exit",
  "payload": {
     "reason":"Exiting program on user request."
  }
 }
)";

auto create_command =
		R"(
{
 "command":"Create",
    "Name":"Ash",
	"Contact":1234,
	"Address":"s"
}
)";

auto for_equals_function =
		R"(
{
 "command":"Search",
    "Name":"Ash",
	"Contact":1234,
	"Address":"s"
}
)";

// Bonus Question: why did I type cast this?
typedef std::function<bool(rapidjson::Value &)> CommandHandler;

class Controller {
public:
	bool help(rapidjson::Value &json) {
		cout << "Controller::help: command: ";

		StringBuffer buffer;
		PrettyWriter<StringBuffer> writer(buffer);
		json.Accept(writer);

		string str = buffer.GetString();
		cout << str;

		return true;
	}

	bool exit(rapidjson::Value &json) {
		cout << "Controller::exit: command: \n";

		StringBuffer buffer;
		PrettyWriter<StringBuffer> writer(buffer);
		json.Accept(writer);

		string str = buffer.GetString();
		cout << str;

		g_done = true;
		return true;
	}

    CommandHandler search(string srchWhat){
      	return [srchWhat](rapidjson::Value & json){
      		cout << "searching " << srchWhat <<"---------\n";

      		StringBuffer buffer;
      		PrettyWriter<StringBuffer> writer(buffer);
      		json.Accept(writer);
			string s = buffer.GetString();

			if(s.find(srchWhat)){
    		  cout << "Found\n";
			}

			return true;
      	};
    }

	bool equals(rapidjson::Value & json) {
			cout << "equals running ---------\n";

			Document ToSearchIn;
			ToSearchIn.Parse(for_equals_function);

			//predefined json string
			StringBuffer buffer1;
			Writer<StringBuffer> writer1(buffer1);
			ToSearchIn.Accept(writer1);
			string otherString = buffer1.GetString();

			//passed rapidjson Value&
			StringBuffer buffer;
			Writer<StringBuffer> writer(buffer);
			json.Accept(writer);
			string inputjString = buffer.GetString();

			if(inputjString.compare(otherString)==0) {
				cout << "equals true";
				return true;

			}
			return false;
	}

	CommandHandler create(string name, int phno, string address) {
		return [=](rapidjson::Value & json) {
			cout << "creating---------\n";
			Document d;
			d.Parse(create_command);

			if (d.HasMember("Name") && d["Name"].IsString())
				d["Name"].SetString(name.c_str(),d.GetAllocator());
			if (d.HasMember("Contact") && d["Contact"].IsNumber())
				d["Contact"].SetInt(phno);
			if (d.HasMember("Address") && d["Address"].IsString())
				d["Address"].SetString(address.c_str(),d.GetAllocator());

			StringBuffer buffer;
			PrettyWriter<StringBuffer> writer(buffer);
			d.Accept(writer);
			cout << buffer.GetString();
			return true;
		};
	}



};

class CommandDispatcher {
public:
	CommandDispatcher() {
		command_handlers_ = new map<std::string, CommandHandler>;
		//command_handlers_.clear();
	}

	~CommandDispatcher() {
		delete command_handlers_;
		//command_handlers_.clear();
		// question why is it virtual? Is it needed in this case?
		//no, it is not needed in this case as there are is no derived class, thus it should not be declared as virtual here
	}

	bool addCommandHandler(std::string command, CommandHandler handler) {
		cout << "CommandDispatcher: addCommandHandler: " << command << std::endl;
		// check if command already exists, else
		if (command_handlers_->find(command) == command_handlers_->end())
			(*command_handlers_)[command] = handler;
		else
			cout << "duplicate command entered. Duplicate command not added\n";
		return true;
	}

	bool dispatchCommand(std::string command_json) {
		if(command_handlers_->find(command_json)==command_handlers_->end()){
			cout << "Invalid input. Please try again\n";
			return false;
		}

		CommandHandler cmd = command_handlers_->find(command_json)->second;
		Document d;

		if (command_json.compare("help") == 0)
			return cmd(d.Parse(help_command));
		else if (command_json.compare("exit") == 0)
			return cmd(d.Parse(exit_command));
		else if (command_json.compare("search") == 0)
			return cmd(d.Parse(for_equals_function));
		else if (command_json.compare("create") == 0)
			return cmd(d.Parse(create_command));
		else if (command_json.compare("equals") == 0)
			return cmd(d.Parse(for_equals_function));
		return true;
	}

private:
	std::map<std::string, CommandHandler> *command_handlers_;

	// Question: why delete these?
	/*Deleting is optional to avoid the usage of copy constructor and copy assignment operator.
	 If not deleted we must explicitly define its function to accept another object.
	 */

	// delete unused constructors
	CommandDispatcher(const CommandDispatcher&) = delete;
	CommandDispatcher& operator=(const CommandDispatcher&) = delete;

};

int main() {
	std::cout << "COMMAND DISPATCHER: STARTED" << std::endl;
	CommandDispatcher command_dispatcher;
	Controller controller;

	// add command handlers in Controller class to CommandDispatcher using addCommandHandler
	command_dispatcher.addCommandHandler("help",[&controller](rapidjson::Value & json) {
				return controller.help(json);												//controller.help returns a bool -- compatible with CommandHandler
			});

	command_dispatcher.addCommandHandler("exit",[&controller](rapidjson::Value & json) {
				return controller.exit(json);
			});

	command_dispatcher.addCommandHandler("equals",[&controller](rapidjson::Value & json) {
		return controller.equals(json);
			});

	command_dispatcher.addCommandHandler("create",controller.create("Ash", 541, "some Address"));	//controller.create returns a CommandHandler

	command_dispatcher.addCommandHandler("search", controller.search("search"));




	// command line interface for testing
	string command;
	while (!g_done) {
		cout << "\nEnter command : ";
		getline(cin, command);
		command_dispatcher.dispatchCommand(command);
	}

	std::cout << "\nCOMMAND DISPATCHER: ENDED\n";
	return 0;
}
