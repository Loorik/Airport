#pragma once
#include <vector>
#include <string>
class StateAbb
{
public:
	StateAbb() {}
	void setStateAbbs(std::vector<std::pair<std::string, std::string>> s) {stateAbbs = s; }
	std::vector<std::pair<std::string, std::string>> getStateAbbs() const { return stateAbbs; }
private:
	std::vector<std::pair<std::string, std::string>> stateAbbs;
};