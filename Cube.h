#include "VertexArray.h"
#include "VertexData.h"

#include <vector>

class Cube : public VertexArray 
{
private:
	static const std::vector<VertexData> getVertecies();
public:
	Cube();
};

