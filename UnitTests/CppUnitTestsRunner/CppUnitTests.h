#pragma once

#ifdef CPPUNIT_TEST
 #undef CPPUNIT_TEST // will be redefined in HelperMacros
#endif

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/ui/text/TestRunner.h>

#include "CppUnitTestRunner.h"
#include "CppUnitTestFunctionExecTimer.h"
