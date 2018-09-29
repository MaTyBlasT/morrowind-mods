
#include "stdafx.h"

#include "PatchCursorStealFix.h"

int hookRuntimePatch(lua_State* L) {
	return 0;
}

static const struct luaL_Reg RuntimePatch_functions[] = {
	{ "hook", hookRuntimePatch },
	{ "hookCursorStealFix", RunPatch::hookCursorStealFix },
	{ NULL, NULL }
};

extern "C" int __declspec(dllexport) luaopen_RuntimePatch(lua_State* L) {
	luaL_register(L, "RuntimePatch", RuntimePatch_functions);
	return 1;
}
