#include "lib.h"

bool writing_the_basics(const std::string &resource_name, int width, int height, int id_tile) {
	
	std::fstream file(resource_name, std::ios_base::out);
	if (!file.is_open())
		return 0;
	file
		<< "size_map" << std::endl
		<< width << std::endl
		<< height << std::endl;
	for (int i = 0; i < height; i++) {
		for (int ii = 0; ii < width; ii++){
			file << ii <<'='<< i << '*' << id_tile << '|';
		}
		file << std::endl;
	}
	//next comes the recording of the properties of objects.
	return 1;
}