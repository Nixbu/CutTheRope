#pragma once

/* 
 class Command
 The Command class is an abstract base class that defines a common interface for executing commands.
 It follows the Command pattern, allowing different commands to be executed through a uniform interface.
 */

class Command {
public:
	virtual void execute() = 0;
	virtual ~Command() = default;

private:

};