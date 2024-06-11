#pragma once

#include <exception>
#include <string>

class LevelNotFoundException : public std::exception
{
public:
	virtual const char* what() const noexcept override { return "Error! Level Not Found. Check the map."; };
private:
	
};