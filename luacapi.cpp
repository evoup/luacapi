// luacapi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <string>
#include <iostream.h>
extern "C"
{
#include  "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}
#pragma comment (lib,"lua51.lib")
using namespace std;
int main(int argc, char* argv[])
{
	lua_State* L=luaL_newstate();
	luaL_openlibs(L);//打开标准库
					 /*luaopen_base(L);
					 luaopen_string(L);
					 luaopen_table(L);
					 luaopen_math(L);
	luaopen_io(L);*/
	if(luaL_dofile(L,"test.lua")){
		MessageBox(NULL,"打开文件失败","info",MB_OK);
	}
	//lua_pcall(L, 0, 0, 0);
	
	lua_settop(L,0);//重置栈索引
	lua_getglobal(L,"name");
	lua_getglobal(L,"age");
	if(!lua_isnumber(L,-1)){//栈顶从1开始
		MessageBox(NULL,"不是整数","",MB_OK);
	}
	if(!lua_isstring(L,-2)){//栈顶从1开始
		MessageBox(NULL,"不是字符串","",MB_OK);
	}
	int age=(int)lua_tonumber(L,-1);
	string name=lua_tostring(L,-2);
	cout<<name.c_str()<<endl;
	cout<<age<<endl;


	//然后是存到lua,不过可能看不出来，放函数里就可以
	//lua_pushnumber(L,111);

//C++调用LUA的函数，函数实现写在LUA里不错！


	//再来是lua调用c++暴露出来的函数有用吗？
	lua_getglobal(L,"testfun");
	if(!lua_isfunction(L,-1)){
		MessageBox(NULL,"不是函数","",MB_OK);
	}
	lua_call(L,0,1);
	string str=lua_tostring(L,-1);
MessageBox(NULL,str.c_str(),"",MB_OK);
	//	printf("Hello World!\n");
	lua_close(L);
	return 0;
}

/*string testfun(){
	string ss="hello from cpp";
return ss;
}*/
