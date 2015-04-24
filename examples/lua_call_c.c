//
// Created by 王阳 on 15/4/24.
//

LUALIB_API int luaopen_lua_call_c(lua_State *L);

static int incr(L) {
    int x = lua_tonumber(L, 1);
    lua_pushnumber(L, x + 1);
    return 1;
}

LUALIB_API int luaopen_lua_call_c(lua_State *L) {
    lua_register(L, "incr", incr);
    return 1;
}