#include <iostream>
#include <thread>

#include <boost/interprocess/file_mapping.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/regex.hpp>

using namespace std::literals;
namespace inp = boost::interprocess;

void lookForMatch(const std::string mask, const inp::mapped_region& region)
{
    boost::regex reg_ex(mask);
    boost::match_results<std::string::const_iterator> what;
    boost::match_flag_type flags = boost::match_default;
     std::string::const_iterator start, end;
   start = region.begin();
   end = file.end();
   while(boost::regex_search(start, end, what, expression, flags))
   {
   }
    // auto begin = mask.begin();
    // auto end = mask.end();
    // while (boost::regex_search(begin, end, results, reg_ex))
    // {
    //     std::cout << results[0] << std::endl;
    // }
}

int main(int argc, char** argv)
{
    inp::file_mapping file_map;
    const inp::mode_t mode = inp::read_only;

    // Убеждаемся в том, что файл существует и доступен для чтения
    try{
        file_map = std::move(inp::file_mapping("../file.txt", mode));

    }catch(inp::interprocess_exception& ex){
        std::cout << "Unable to create file map! EXCEPTION: " << ex.what() << std::endl;
    }

    // Определяем количестко ядер процессора
    const size_t processor_cores = std::thread::hardware_concurrency();
    
    // Формируем проекции участков файла на адресное пространство процесса
    try{
        for (size_t i = 0; i < 1; i++){
            inp::mapped_region region(file_map, mode, 0, 0);
            lookForMatch("ad", region);
        }
    }catch(inp::interprocess_exception& ex){
        std::cout << "Unable to create file projection! EXCEPTION: " << ex.what() << std::endl;
    }
    
    return 0;
}