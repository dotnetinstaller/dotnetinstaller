#pragma once

struct HTMLayoutBehaviorWeblink: public htmlayout::behavior
{
   HTMLayoutBehaviorWeblink();
   virtual void attached (HELEMENT he);
   virtual void detached (HELEMENT he);
   virtual BOOL on_event (HELEMENT he, HELEMENT target, BEHAVIOR_EVENTS type, UINT_PTR reason);
};
