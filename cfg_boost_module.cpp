#include <boost/python.hpp>
#include <string>
#include <iostream>
#include <iomanip>
#include "cfg_mgr.hpp"

bool json_parser(const std::string& str)
{
    CfgMgr::instance().Init(str.c_str());

    bool value0;
    if(CfgMgr::instance().Get("mongo", "Bool", value0))
    {
        std::cout << value0 << std::endl;
    }
    else
    {
        std::cout << "error" << std::endl;
    }

    int value1 = 0;
    if(CfgMgr::instance().Get("mongo", "Int", value1))
    {
        std::cout << value1 << std::endl;
    }
    else
    {
        std::cout << "error" << std::endl;
    }

    double value2 = 0.0;
    if(CfgMgr::instance().Get("mongo", "Double", value2))
    {
        std::cout << std::setiosflags(std::ios::fixed) << value2 << std::endl;
    }
    else
    {
        std::cout << "error" << std::endl;
    }

    std::string value3 = "";
    if(CfgMgr::instance().Get("mongo", "String", value3))
    {
        std::cout << value3 << std::endl;
    }
    else
    {
        std::cout << "error" << std::endl;
    }

    std::vector<bool> value8;
    if(CfgMgr::instance().Get("mongo", "BoolArray", value8))
    {
        std::for_each(value8.begin(), value8.end(), 
        [](const auto& e){ std::cout << e << " "; });
        std::cout << std::endl;
    }
    else
    {
        std::cout << "error" << std::endl;
    }

    std::vector<int> value4;
    if(CfgMgr::instance().Get("mongo", "IntArray", value4))
    {
        std::for_each(value4.begin(), value4.end(), 
        [](const auto& e){ std::cout << e << " "; });
        std::cout << std::endl;
    }
    else
    {
        std::cout << "error" << std::endl;
    }

    std::vector<double> value5;
    if(CfgMgr::instance().Get("mongo", "DoubleArray", value5))
    {
        std::for_each(value5.begin(), value5.end(),
        [](const auto& e){ std::cout << e << " "; });
        std::cout << std::endl;
    }
    else
    {
        std::cout << "error" << std::endl;
    }

    std::vector<std::string> value6;
    if(CfgMgr::instance().Get("mongo", "StringArray", value6))
    {
        std::for_each(value6.begin(), value6.end(),
        [](const auto& e){ std::cout << e << " "; });
        std::cout << std::endl;
    }
    else
    {
        std::cout << "error" << std::endl;
    }

    return true;
}

BOOST_PYTHON_MODULE(cfg_boost_module)
{
    using namespace boost::python;
    def("json_parser", json_parser);
}