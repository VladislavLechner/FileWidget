#include "readfile.h"


void ReadFile::checkPath(std::string path, std::string filter)
{
    if (path.empty())
        throw std::runtime_error("Переданный путь пуст");
    else if (!boost::filesystem::exists(path))
        throw std::runtime_error("Неверный путь");
    else if (boost::filesystem::is_directory(path))
        throw std::runtime_error("Переданный путь указывает на директорию");
    else
        readIntoFile(path, filter);
}

std::pair<std::map<char, std::size_t>, int> ReadFile::resultOfWork()
{
    return {m_countOfAllSymb, m_countOfFilter};
}

void ReadFile::readIntoFile(std::string path, std::string filter)
{
    std::ifstream file(path);
    if (!file.is_open())
        throw std::runtime_error("Не удалось открыть файл");

    size_t sizeOfFilter = filter.size();

    while (!file.eof())
    {
        std::string temp;
        getline(file, temp);
        if (temp.empty() || temp.size() < sizeOfFilter)
            continue;
        for (const auto& it : temp)
        {
            ++m_countOfAllSymb[it];
        }
        for (size_t i = 0; i <= temp.size() - sizeOfFilter; ++i)
        {
            if (temp.substr(i, sizeOfFilter) == filter)
                ++m_countOfFilter;
            std::string t = temp.substr(i, sizeOfFilter);
        }
    }

    for (const auto& elem : m_countOfAllSymb)
    {
        std::cout << "Символ " << elem.first << " встречается ровно " << elem.second << " раз" << std::endl;
    }

    std::cout << std::endl << m_countOfFilter << std::endl;

    file.close();
}
