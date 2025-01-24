#pragma once

#include <Windows.h>

#include <fmt/core.h>
#include <iostream>
#include <stack>
#include <vector>
#include <map>

struct State {
	State();
	virtual ~State() = 0;
	
	virtual void update() = 0;
	virtual void render() = 0;
	
	virtual void checkInput();
	virtual void endState() = 0;
	
	char input;
	int st;
};