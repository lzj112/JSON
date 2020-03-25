#include <iostream>
#include <sstream>
#include <fstream>
#include <jsoncpp/json/json.h>
using namespace std;

//从字符串解析json
int ParseJsonFromString()  
{  
    const char* str = "{\"uploadid\": \"UP000000\",\"code\": 100,\"msg\": \"\",\"files\": \"\"}";  

    Json::Reader reader;  
    Json::Value root;  
    if (reader.parse(str, root))  // reader将Json字符串解析到root，root将包含Json里所有子元素   
    {  
        std::string upload_id = root["uploadid"].asString();  // 访问节点，upload_id = "UP000000"   
        int code = root["code"].asInt();    // 访问节点，code = 100   
    }  

    // 在json结构中插入json
    Json::Value arrayObj;   // 构建对象   
    Json::Value new_item, new_item1;  
    new_item["date"] = "2011-12-28";  
    new_item1["time"] = "22:30:36";  
    arrayObj.append(new_item);  // 插入数组成员   
    arrayObj.append(new_item1); // 插入数组成员   
    int file_size = root["files"].size();  
    for(int i = 0; i < file_size; ++i)  
        root["files"][i]["exifs"] = arrayObj;   // 插入原json中  

    // 转换为字符串（带格式）   
    std::string out = root.toStyledString();  
    // 输出无格式json字符串   
    Json::FastWriter writer;  
    std::string out2 = writer.write(root); 

    std::cout << out << std::endl;
    std::cout << out2 << std::endl;
}

//从文件解析json
Json::Value getJsonFromFile(const char* filename)
{
    // 解析json用Json::Reader   
    Json::Reader reader;  
    // Json::Value是一种很重要的类型，可以代表任意类型。如int, string, object, array...   
    Json::Value root;         

    std::ifstream is;  
    is.open (filename, std::ios::binary);    
    if (reader.parse(is, root))  
    {  
        std::string code;  
        if (!root["files"].isNull())     
        {
            code = root["uploadid"].asString();  
            cout << "root[\"uploadid\"]=" << code << endl;
        }
            
        // 访问节点，Return the member named key if it exist, defaultValue otherwise.   
        code = root.get("uploadid", "null").asString();  

        // 得到"files"的数组个数   
        int file_size = root["files"].size();  

        // 遍历数组   
        for(int i = 0; i < file_size; ++i)  
        {  
            Json::Value val_image = root["files"][i]["images"];  
            int image_size = val_image.size();  
            for(int j = 0; j < image_size; ++j)  
            {  
                std::string type = val_image[j]["type"].asString();  
                std::string url = val_image[j]["url"].asString();  
            }  
        }  
    }  
    is.close();  
    return root;  
}

//写入jaon到文件
void jsonWriteToFile()
{
    Json::FastWriter write;
    Json::Value root;

    Json::Value item;
    Json::Value arrayObj;
    item["book"] = "c++";
    item["food"] = "apple";
    item["music"] = "ddx";
    arrayObj.append(item);

    root["name"] = "dsw";
    root["age"]  = 18;
    root["like"] = arrayObj;    //注意:这里不能用append,append功能是将Json::Value添加到数组末尾

    auto str = root.toStyledString();
    std::cout << str << std::endl;

    std::ofstream ofss;
    ofss.open("out.json");
    ofss << str;
    ofss.close();
}

int main() 
{
    ParseJsonFromString();
    jsonWriteToFile();

    {
        //解析json
        Json::Value myjson = getJsonFromFile("test.json");  //利用上面的函数生成一个json。
        int num = myjson["num"].asInt();
        string str = myjson["name"].asString();
    }

    {
        //json数组
        Json::Value myjson = getJsonFromFile("test.json");//利用上面的函数生成一个json。
        int i = 0;
        Json::Value arr = myjson[i]; //获取arr数组的第一个元素
    }

    {
        //利用迭代器获取json的key。（有时候并不知道json的key，这个时候可以利用迭代器获取json的key）
        Json::Value myjson = getJsonFromFile("test.json");//利用上面的函数生成一个json。
        Json::Value::Members members(myjson.getMemberNames());
        for (Json::Value::Members::iterator it = members.begin(); it != members.end(); ++it)  {
        const std::string &key = *it;
        }
    }

    {
        //自己拼装Json数组，（有时候发往服务器的数据是一个json数据)
        Json::Value arr;
        for(int i = 0 ;i < 5;++i){
        Json::Value myjson = getJsonFromFile("test.json");//利用上面的函数生成一个json。
        arr.append(myjson);
        }

        //如果想让这个jsonArr有key。
        Json::Value arr2;
        arr2["array"] = arr;
    }
}