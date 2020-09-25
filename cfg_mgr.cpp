#include <iostream>
#include "cfg_mgr.hpp"

bool CfgMgr::Init(const char* jsonstr)
{
    if(dom_.Parse(jsonstr).HasParseError())
    {
        std::cout << "parse error" << std::endl;
        return false;
    }
    if(!dom_.IsObject())
    {
        std::cout << "is not object" << std::endl;
        return false;
    }
    return true;
}

bool CfgMgr::Get(const char* module, const char* str, bool& val)
{
    if(!dom_.HasMember(module))
    {
        std::cout << "has not member" << module << std::endl;
        return false;
    }

    if(!dom_[module].IsObject())
    {
        std::cout << "is not struct" << module << std::endl;
        return false;
    }

    const rapidjson::Value& object = dom_[module];

    if(!object.HasMember(str))
    {
        std::cout << "has not member" << str << std::endl;
        return false;
    }

    if(!object[str].IsBool())
    {
        std::cout << "is not bool" << str << std::endl;
        return false;
    }

    val = object[str].GetBool();
    return true;
}

bool CfgMgr::Get(const char* module, const char* str, int& val)
{
    if(!dom_.HasMember(module))
    {
        std::cout << "has not member" << module << std::endl;
        return false;
    }

    if(!dom_[module].IsObject())
    {
        std::cout << "is not struct" << module << std::endl;
        return false;
    }

    const rapidjson::Value& object = dom_[module];

    if(!object.HasMember(str))
    {
        std::cout << "has not member " << str << std::endl;
        return false;
    }

    if(!object[str].IsInt())
    {
        std::cout << "is not int" << str << std::endl;
        return false;
    }

    val = object[str].GetInt();
    return true;
}

bool CfgMgr::Get(const char* module, const char* str, double& val)
{
    if(!dom_.HasMember(module))
    {
        std::cout << "has not member" << module << std::endl;
        return false;
    }

    if(!dom_[module].IsObject())
    {
        std::cout << "is not struct" << module << std::endl;
        return false;
    }
    
    const rapidjson::Value& object = dom_[module];

    if(!object.HasMember(str))
    {
        std::cout << "has not member " << str << std::endl;
        return false;
    }

    if(!object[str].IsDouble())
    {
            std::cout << "is not double" << str << std::endl;
        return false;
    }

    val = object[str].GetDouble();
    return true;
}

bool CfgMgr::Get(const char* module, const char* str, std::string& val)
{
    if(!dom_.HasMember(module))
    {
        std::cout << "has not member" << module << std::endl;
        return false;
    }

    if(!dom_[module].IsObject())
    {
        std::cout << "is not struct" << module << std::endl;
        return false;
    }

    const rapidjson::Value& object = dom_[module];

    if(!object.HasMember(str))
    {
        std::cout << "has not member " << str << std::endl;
        return false;
    }

    if(!object[str].IsString())
    {
        std::cout << "is not string" << str << std::endl;
        return false;
    }

    val = object[str].GetString();
    return true;
}

bool CfgMgr::Get(const char* module, const char* str, std::vector<bool>& val)
{
    if(!dom_.HasMember(module))
    {
        std::cout << "has not member" << module << std::endl;
        return false;
    }

    if(!dom_[module].IsObject())
    {
        std::cout << "is not struct" << module << std::endl;
        return false;
    }

    const rapidjson::Value& object = dom_[module];

    if(!object.HasMember(str))
    {
        std::cout << "has not member" << str << std::endl;
        return false;
    }
    if(!object[str].IsArray())
    {
        std::cout << "is not array" << std::endl;
        return false;
    }

    const rapidjson::Value& array = object[str];
    val.clear();
    for(size_t i = 0; i < array.Size(); i++)
    {
        if(!array[i].IsBool())
        {
            std::cout << "array exist not bool value" << str << std::endl;
            val.clear();
            return false;
        }
        val.push_back(array[i].GetBool());
    }
    return true;
}

bool CfgMgr::Get(const char* module, const char* str, std::vector<int>& val)
{
    if(!dom_.HasMember(module))
    {
        std::cout << "has not member" << module << std::endl;
        return false;
    }

    if(!dom_[module].IsObject())
    {
        std::cout << "is not struct" << module << std::endl;
        return false;
    }

    const rapidjson::Value& object = dom_[module];

    if(!object.HasMember(str))
    {
        std::cout << "has not member " << str << std::endl;
        return false;
    }
    if(!object[str].IsArray())
    {
        std::cout << "is not array " << std::endl;
        return false;
    }

    const rapidjson::Value& array = object[str];
    val.clear();
    for(size_t i = 0; i < array.Size(); i++)
    {
        if(!array[i].IsInt())
        {
            std::cout << "array exist not int value" << str << std::endl;
            val.clear();
            return false;
        }
        val.push_back(array[i].GetInt());
    }
    return true;
}

bool CfgMgr::Get(const char* module, const char* str, std::vector<double>& val)
{
    if(!dom_.HasMember(module))
    {
        std::cout << "has not member" << module << std::endl;
        return false;
    }

    if(!dom_[module].IsObject())
    {
        std::cout << "is not struct" << module << std::endl;
        return false;
    }

    const rapidjson::Value& object = dom_[module];

    if(!object.HasMember(str))
    {
        std::cout << "has not member" << str << std::endl;
        return false;
    }
    if(!object[str].IsArray())
    {
        std::cout << "is not array" << std::endl;
        return false;
    }

    const rapidjson::Value& array = object[str];
    val.clear();
    for(size_t i = 0; i < array.Size(); i++)
    {
        if(!array[i].IsDouble())
        {
            std::cout << "array exist not double value" << str << std::endl;
            val.clear();
            return false;
        }
        val.push_back(array[i].GetDouble());
    }
    return true;
}

bool CfgMgr::Get(const char* module, const char* str, std::vector<std::string>& val)
{
    if(!dom_.HasMember(module))
    {
        std::cout << "has not member" << module << std::endl;
        return false;
    }

    if(!dom_[module].IsObject())
    {
        std::cout << "is not struct" << module << std::endl;
        return false;
    }

    const rapidjson::Value& object = dom_[module];

    if(!object.HasMember(str))
    {
        std::cout << "has not member" << str << std::endl;
        return false;
    }
    if(!object[str].IsArray())
    {
        std::cout << "is not array" << std::endl;
        return false;
    }

    const rapidjson::Value& array = object[str];
    val.clear();
    for(size_t i = 0; i < array.Size(); i++)
    {
        if(!array[i].IsString())
        {
            std::cout << "array exist not string value" << str << std::endl;
            val.clear();
            return false;
        }
        val.push_back(array[i].GetString());
    }
    return true;
}

