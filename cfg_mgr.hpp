#pragma once
#include <boost/noncopyable.hpp>
#include <string>
#include <vector>
#include "rapidjson/document.h"

class CfgMgr : private boost::noncopyable
{
public:
    static CfgMgr& instance()
    {
        static CfgMgr ins;
        return ins;
    }
    bool Init(const char* jsonstr);
    bool Get(const char* module, const char* field, bool& val);
    bool Get(const char* module, const char* field, int& val);
    bool Get(const char* module, const char* field, double& val);
    bool Get(const char* module, const char* field, std::string& val);
    bool Get(const char* module, const char* field, std::vector<bool>& val);
    bool Get(const char* module, const char* field, std::vector<int>& val);
    bool Get(const char* module, const char* field, std::vector<double>& val);
    bool Get(const char* module, const char* field, std::vector<std::string>& val);

private:
     rapidjson::Document dom_;
};