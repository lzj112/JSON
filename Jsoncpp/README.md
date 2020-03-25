# Jsoncpp的使用

- Jsoncpp中主要的类：

1. Json::Value：可以表示所有支持的类型，如：int , double ,string , object, array等。
其包含节点的：
类型判断(isNull,isBool,isInt,isArray,isMember,isValidIndex等),类型获取(type)
类型转换(asInt,asString等),节点获取(get,[]),节点比较(重载<,<=,>,>=,==,!=)
节点操作(compare,swap,removeMember,removeindex,append等)等函数。
2. Json::Reader：将文件流或字符串创解析到Json::Value中，主要使用parse函数
Json::Reader的构造函数还允许用户使用特性Features来自定义Json的严格等级。
3. Json::Writer：与JsonReader相反，将Json::Value转换成字符串流等，Writer类是一个纯虚类，并不能直接使用
我们使用 Json::Writer 的子类：Json::FastWriter(将数据写入一行,没有格式),Json::StyledWriter(按json格式化输出,易于阅读)

- JsonCpp使用注意点:

1.对不存在的键获取值会返回此类型的默认值。
2.通过key获取value时,要先判断value的类型,使用错误的类型获取value会导致程序中断。
3.获取json数组中某一项key的value应该使用value[arraykey][index][subkey]获取或循环遍历数组获取。
4.append函数功能是将Json::Value添加到数组末尾。
5.由于Jsoncpp解析非法json时，会自动容错成字符类型。对字符类型取下标时，会触发assert终止进程。
解决方法：启用严格模式，让非法的json解析时直接返回false，不自动容错。这样，在调用parse的时候就会返回false。
>Json::Reader *pJsonParser = new Json::Reader(Json::Features::strictMode());

- 判断json字符串中是否存在某键值的几种方法:
1. value.isMember("key");    //存在返回true,否则为false
2. value["sex"].isNull();    //为NULL返回1,否则为0

- 清空Json对象root中的数组
`root["array"].resize(0);`

- 删除Json对象
root.removeMember("key");


# 编译

- 使用`sudo apt-get install libjsoncpp-dev`安装jsoncpp

头文件在`/usr/include/jsoncpp/json`
静态库在`/usr/lib/x86_64-linux-gnu`
```
ubuntu@LZJ:/usr/lib/x86_64-linux-gnu$ ls | grep json
libfastjson.so.4
libfastjson.so.4.2.0
libjsoncpp.a
libjsoncpp.so
libjsoncpp.so.1
libjsoncpp.so.1.7.4
```
所以指定静态路径:
```
g++ use_jsoncpp.cc -L/usr/lib/x86_64-linux-gnu/ -ljsoncpp 
```

- 将头文件和源代码放进自己的项目

[源代码](https://github.com/open-source-parsers/jsoncpp)
需要的源码文件有目录/include/json/下的所有头文件，还有目录/src/lib_json/下的源文件
>/src/lib_json/ 目录下有个脚本不用,不知道现在作者管理项目目录了没