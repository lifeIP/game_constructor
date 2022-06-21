#pragma once
class MapWork
{
public:
	bool writing_the_basics(const std::string& resource_name, int width, int height, int id_tile);
	bool writing_history(const std::string& resource_history_name, int coord_x, int coord_y, int id_tile);
	bool save_changes(const std::string& resource_name, const std::string& resource_history_name);
};

