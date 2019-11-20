#ifndef __UTIL_HPP__
#define __UTIL_HPP__

//------------这个文件用来保存一些协助方法，与具体实习Web服务器没有直接关系

#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
#include<vector>

class Util
{
	public:
		//将字符串中的字符全部转换成小写字符
		static void StringToLower(std::string& s)
		{
			std::transform(s.begin(),s.end(),s.begin(),::tolower);
		}
		//将字符串中的字符全部转换成大写字符
		static void StringToUpper(std::string& s)
		{
			std::transform(s.begin(),s.end(),s.begin(),::toupper);
		}
		//字符串转整数
		static int StringToInt(std::string& s)
		{
			int ret = 0;
			std::stringstream ss(s);
			ss>>ret;
			return ret;
		}
        //整数转字符串
        static std::string IntToString(int n)
        {
            std::stringstream ss;
            ss<<n;
            return ss.str();
        }
        static std::string GetStateCode(int code)
        {
            switch(code)
            {
                case 200:
                    return "OK";
                case 404:
                    return "NOT FOUND";
                default:
                    return "UNKOWN";
            }
        }
		//将字符串中的子串打散，然后保存在vector中
		static void TransfromVector(std::string& s,std::vector<std::string>& v)
		{
			int start = 0;
			auto pos = s.find('\n');
			while(pos!=std::string::npos)
			{
				v.push_back(s.substr(start,pos-start));
				start = pos+1;
				pos = s.find('\n',start);
			}
		}
		//将一个字符串按“: ”构成key和value
		static void MakeKV(std::string& s,std::string& k,std::string& v)
		{
			auto pos = s.find(": ");
			if(pos == std::string::npos)
			{
				k="";
				v="";
				return ;
			}
			k = s.substr(0,pos);
			v = s.substr(pos+2);
		}
        
};



























#endif
