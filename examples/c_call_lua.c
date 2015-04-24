#include <lua.h>
#include <lauxlib.h>
#include <lstate.h>

int main() {
    lua_State *L = luaL_newstate();

    if (luaL_dofile(L, "examples/c_call_lua.lua") != LUA_OK) {
        printf("luaL_loadfile() exception: %s\n", lua_tostring(L, -1));
        return -1;
    }

    lua_getglobal(L, "sum");
    lua_pushnumber(L, 1.0);
    lua_pushnumber(L, 2.0);

    if (lua_pcall(L, 2, 1, 0) != LUA_OK) {
        printf("call function error: %s\n", lua_tostring(L, -1));
        return -1;
    }
    int isnum = 0;
    LUA_NUMBER sum = lua_tonumberx(L, -1, &isnum);

    if (!isnum) {
        printf("function mush return a number\n");
    } else {
        printf("sum: %.2f\n", sum);
    }
    lua_pop(L, 1);
    lua_close(L);
    return 0;
}