#include "JSParty.h"
#include "D2Structs.h"
#include "D2Helpers.h"

JSBool party_getProperty(JSContext *cx, JSObject *obj, jsval id, jsval *vp)
{
	RosterUnit* pUnit = (RosterUnit*)JS_GetPrivate(cx, obj);

	if(!pUnit)
		return JS_TRUE;

	switch(JSVAL_TO_INT(id))
	{
		case PARTY_NAME:
			*vp = STRING_TO_JSVAL(JS_NewStringCopyZ(cx, pUnit->szName));
			break;
		case PARTY_X:
			*vp = INT_TO_JSVAL(pUnit->Xpos);
			break;
		case PARTY_Y:
			*vp = INT_TO_JSVAL(pUnit->Ypos);
			break;
		case PARTY_AREA:
			*vp = INT_TO_JSVAL(pUnit->dwLevelId);
			break;
		case PARTY_GID:
			*vp = INT_TO_JSVAL(pUnit->dwUnitId);
			break;
		case PARTY_LIFE:
			*vp = INT_TO_JSVAL(pUnit->dwPartyLife);
			break;
		case PARTY_CLASSID:
			*vp = INT_TO_JSVAL(pUnit->dwClassId);
			break;
		case PARTY_LEVEL:
			*vp = INT_TO_JSVAL(pUnit->wLevel);
			break;
		case PARTY_FLAG:
			*vp = INT_TO_JSVAL(pUnit->dwPartyFlags);
			break;
		case PARTY_ID:
			*vp = INT_TO_JSVAL(pUnit->wPartyId);
			break;
		default:
			break;
	}
	return JS_TRUE;
}

JSBool party_getNext(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
	if(!GameReady())
		return JS_TRUE;

	RosterUnit *pUnit = (RosterUnit*)JS_GetPrivate(cx, obj);

	if(!pUnit)
	{
		*rval = INT_TO_JSVAL(0);
		return JS_TRUE;
	}

	pUnit = pUnit->pNext;

	if(pUnit)
	{
		JS_SetPrivate(cx, obj, pUnit);
		*rval = OBJECT_TO_JSVAL(obj);
	}
	else
	{
		JS_ClearScope(cx, obj);
		if(JS_ValueToObject(cx, JSVAL_NULL, &obj))
			*rval = INT_TO_JSVAL(0);
	}
	
	return JS_TRUE;
}

