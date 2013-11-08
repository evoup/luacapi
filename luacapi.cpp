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
	luaL_openlibs(L);//�򿪱�׼��
					 /*luaopen_base(L);
					 luaopen_string(L);
					 luaopen_table(L);
					 luaopen_math(L);
	luaopen_io(L);*/
	if(luaL_dofile(L,"test.lua")){
		MessageBox(NULL,"���ļ�ʧ��","info",MB_OK);
	}
	//lua_pcall(L, 0, 0, 0);
	
	lua_settop(L,0);//����ջ����
	lua_getglobal(L,"name");
	lua_getglobal(L,"age");
	if(!lua_isnumber(L,-1)){//ջ����1��ʼ
		MessageBox(NULL,"��������","",MB_OK);
	}
	if(!lua_isstring(L,-2)){//ջ����1��ʼ
		MessageBox(NULL,"�����ַ���","",MB_OK);
	}
	int age=(int)lua_tonumber(L,-1);
	string name=lua_tostring(L,-2);
	cout<<name.c_str()<<endl;
	cout<<age<<endl;


	//Ȼ���Ǵ浽lua,�������ܿ����������ź�����Ϳ���
	//lua_pushnumber(L,111);

//C++����LUA�ĺ���������ʵ��д��LUA�ﲻ��


	//������lua����c++��¶�����ĺ���������
	lua_getglobal(L,"testfun");
	if(!lua_isfunction(L,-1)){
		MessageBox(NULL,"���Ǻ���","",MB_OK);
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
