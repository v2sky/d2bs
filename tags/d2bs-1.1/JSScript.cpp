#include "JSScript.h"
#include "CDebug.h"
#include "Script.h"
#include "ScriptEngine.h"

#include "debugnew/debug_new.h"

JSAPI_PROP(script_getProperty)
{
	CDebug cDbg("script getProperty");

	JSContext* iterp = (JSContext*)JS_GetInstancePrivate(cx, obj, &script_class, NULL);
	Script* script = (Script*)JS_GetContextPrivate(iterp);

	if(!script)
		return JS_TRUE;

	switch(JSVAL_TO_INT(id))
	{
		case SCRIPT_FILENAME:
			*vp = STRING_TO_JSVAL(JS_InternString(cx, script->GetFilename()));
			break;
		case SCRIPT_GAMETYPE:
			*vp = script->GetState() == InGame ? INT_TO_JSVAL(0) : INT_TO_JSVAL(1);
			break;
		case SCRIPT_RUNNING:
			*vp = BOOLEAN_TO_JSVAL(script->IsRunning());
			break;
		case SCRIPT_THREADID:
			*vp = INT_TO_JSVAL(script->GetThreadId());
			break;
		default:
			break;
	}

	return JS_TRUE;
}

JSAPI_FUNC(script_getNext)
{
	CDebug cDbg("script getNext");

	JSContext* iterp = (JSContext*)JS_GetInstancePrivate(cx, obj, &script_class, NULL);
	if(JS_ContextIterator(ScriptEngine::GetRuntime(), &iterp) == NULL || !JS_GetContextPrivate(iterp))
		*rval = JSVAL_FALSE;
	else
	{
		JS_SetPrivate(cx, obj, iterp);
		*rval = JSVAL_TRUE;
	}

	return JS_TRUE;
}

JSAPI_FUNC(script_stop)
{
	CDebug cDbg("script stop");

	JSContext* iterp = (JSContext*)JS_GetInstancePrivate(cx, obj, &script_class, NULL);
	Script* script = (Script*)JS_GetContextPrivate(iterp);
	script->Stop();

	return JS_TRUE;
}

JSAPI_FUNC(script_pause)
{
	CDebug cDbg("script pause");

	JSContext* iterp = (JSContext*)JS_GetInstancePrivate(cx, obj, &script_class, NULL);
	Script* script = (Script*)JS_GetContextPrivate(iterp);
	script->Pause();

	return JS_TRUE;
}

JSAPI_FUNC(script_resume)
{
	CDebug cDbg("script resume");

	JSContext* iterp = (JSContext*)JS_GetInstancePrivate(cx, obj, &script_class, NULL);
	Script* script = (Script*)JS_GetContextPrivate(iterp);
	script->Resume();

	return JS_TRUE;	
}

JSAPI_FUNC(script_send)
{
	CDebug cDbg("script send");

	JSContext* iterp = (JSContext*)JS_GetInstancePrivate(cx, obj, &script_class, NULL);
	Script* script = (Script*)JS_GetContextPrivate(iterp);

	AutoRoot** args = new AutoRoot*[1];
	args[0] = new AutoRoot(argv[0]);

	// this event has to occur as such because it's not a broadcasted event, just a local one
	script->ExecEventAsync("scriptmsg", 1, args);

	return JS_TRUE;
}

JSAPI_FUNC(my_getScript)
{
	CDebug cDbg("getScript");

	JSContext* iterp = NULL;
	if(!JS_ContextIterator(ScriptEngine::GetRuntime(), &iterp))
		return JS_TRUE;

	JSObject* res = BuildObject(cx, &script_class, script_methods, script_props, iterp);

	if(!res)
		THROW_ERROR(cx, obj, "Failed to build the script object");
	*rval = OBJECT_TO_JSVAL(res);

	return JS_TRUE;
}
