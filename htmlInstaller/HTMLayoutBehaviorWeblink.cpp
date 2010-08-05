#include "StdAfx.h"
#include "HTMLayoutBehaviorWeblink.h"

using namespace htmlayout;

HTMLayoutBehaviorWeblink::HTMLayoutBehaviorWeblink() 
	: behavior(HANDLE_BEHAVIOR_EVENT, "weblink")
{

}

void HTMLayoutBehaviorWeblink::attached(HELEMENT he) 
{
}

void HTMLayoutBehaviorWeblink::detached(HELEMENT he) 
{
}

BOOL HTMLayoutBehaviorWeblink::on_event(HELEMENT he, HELEMENT target, BEHAVIOR_EVENTS type, UINT_PTR reason)
{
	dom::element e = he;

	switch( type )
	{
	case HYPERLINK_CLICK:
	case HYPERLINK_CLICK | HANDLED:
		DVLib::ShellCmd(e.get_attribute("href"));
		return true;
	}
	
	return false;
}

HTMLayoutBehaviorWeblink weblink_instance;
