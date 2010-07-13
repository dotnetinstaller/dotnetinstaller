#include "stdafx.h"
#include "AxHTMLayout.h"
#include "Element.h"

json::value cvt_VARIANT_to_json_value(const VARIANT& tv)
{
    json::value rv;
    switch(tv.vt)
    {
      case VT_UI1: 
      case VT_I2:
      case VT_I4:
        {
          int v = tv.lVal;
          rv = json::value(v);
        } break;

      case VT_R4:
        {
          double v = tv.fltVal;
          rv = json::value(v);
        } break;
      case VT_R8:
        {
          double v = tv.dblVal;
          rv = json::value(v);
        } break;

      case VT_BOOL:
        {
          bool v = tv.boolVal != 0;
          rv = json::value(v);
        } break;

      case VT_BSTR:
        {
          LPCWSTR v = tv.bstrVal;
          rv = json::value(v);
        } break;
    }
    return rv;
}

VARIANT cvt_json_value_to_VARIANT(const json::value& tv)
{
    VARIANT rv;
    VariantInit(&rv);

    switch(tv.t)
    {
      case T_UNDEFINED:
        break;
      case T_BOOL:
        rv.vt = VT_BOOL;
        rv.boolVal = tv.get(false)?TRUE:FALSE;
        break;
      case T_INT:
        rv.vt = VT_I4;
        rv.lVal = tv.get(0);
        break;
      case T_FLOAT:
        rv.vt = VT_R8;
        rv.dblVal = tv.get(0.0);
        break;
      case T_STRING:
        {
        aux::wchars s = tv.get_chars();
        rv.vt = VT_BSTR;        
        rv.bstrVal = SysAllocStringLen(s.start, s.length);
        } break;
      //case json::value::V_ARRAY:
      //case json::value::V_MAP:
      default: assert(false);
    }
    return rv;
}
