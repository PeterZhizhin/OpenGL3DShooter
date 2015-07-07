#pragma once

#include <string>

#include "AbstractShader.h"

class BasicShader : public AbstractShader 
{
public:
	BasicShader();
private:
	virtual std::string getName();
};
