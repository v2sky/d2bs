#pragma once

#include <windows.h>
#include <map>
#include <list>
#include <string>

#include "Script.h"

#if defined(__USE_SPIDERMONKEY__)
#pragma comment(lib, "spidermonkey.lib")
#elif defined(__USE_V8__)
#pragma comment(lib, "v8.lib")
#endif

#ifndef __SCRIPTENGINE_H__
#define __SCRIPTENGINE_H__

namespace botsys
{

typedef std::map<std::string, Script*> ScriptMap;

enum EngineState
{
	NotRunning,
	Starting,
	Started,
	Stopping,
	Stopped
};

class ScriptEngine
{
private:
	static CRITICAL_SECTION lock;
	static EngineState state;
	static ScriptMap scripts;
	static std::string scriptPath;
	static void* pData;

	// disable the default ctor, the copy ctor, and the assignment op
	ScriptEngine();
	~ScriptEngine();
	ScriptEngine(const ScriptEngine&);
	ScriptEngine& operator=(const ScriptEngine&);

public:
	static Script* Compile(std::string filename, bool recompile = false);
	static Script* Find(std::string filename)
	{
		return scripts.count(filename) ? scripts[filename] : NULL;
	}
	static Script* FindOrCompile(std::string filename, bool recompile = false)
	{
		Script* result = Find(filename);
		if(!result)
			result = Compile(filename, recompile);
		return result;
	}
	static void Release(Script* script)
	{
		script->End();
		scripts.erase(script->GetFilename());
		delete script;
	}

	static void* GetPrivateData(void) { return pData; }
	static void SetPrivateData(void* data) { EnterCriticalSection(&lock); pData = data; LeaveCriticalSection(&lock); }

	static void Startup(std::string path, unsigned long maxBytes);
	static void Shutdown(void);
};

}

#endif