#pragma once

#include <iostream>
#include <fstream>
#include <map>

#include <boost/filesystem.hpp>


class ReadFile
{
public:
    ReadFile() = default;
    void checkPath(std::string path, std::string filter);
    std::pair <std::map <char,std::size_t>, int> resultOfWork();

private:
    int m_countOfFilter = 0;
    std::map <char,std::size_t> m_countOfAllSymb;

private:
    void readIntoFile(std::string path, std::string filter);

};

