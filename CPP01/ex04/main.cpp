#include <iostream>
#include <fstream>

void	replaceString( std::ifstream& ifs, std::ofstream& ofs,
						std::string oldString, std::string newString ) {

	size_t		pos;
	std::string	tmp;

	while (getline(ifs, tmp))
	{
		pos = tmp.find(oldString);
		while (pos != std::string::npos)
		{
			tmp.erase(pos, oldString.length());
			tmp.insert(pos, newString);
			pos = tmp.find(oldString, pos + newString.length());
		}
		ofs << tmp << std::endl;
	}
}

int		main (int ac, char **av) {

	if (ac != 4)
	{
		std::cout	<< "You must enter a file name, "
					<< "two strings, the second will replace the first\n";
		return (1);
	}

	std::string		fileName	= av[1];
	std::string		oldString	= av[2];
	std::string		newString	= av[3];

	if (oldString.empty())
	{
		std::cout	<< "Can't replace nothing by something" << std::endl;
		return (1);
	}

	std::ifstream	ifs(fileName.c_str());
	fileName += ".replace";
	std::ofstream	ofs(fileName.c_str());

	if (!ifs.is_open() || !ofs.is_open())
	{
		std::cout	<< "An error occured while opening one of the files" << std::endl;
		return (1);
	}

	replaceString(ifs, ofs, oldString, newString);
	ifs.close();
	ofs.close();

	return (0);
}