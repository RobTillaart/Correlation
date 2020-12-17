//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2020-12-03
// PURPOSE: unit tests for the Correlation library
//          https://github.com/RobTillaart/
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// https://github.com/Arduino-CI/arduino_ci/blob/master/cpp/unittest/Assertion.h#L33-L42
// ----------------------------
// assertEqual(expected, actual)
// assertNotEqual(expected, actual)
// assertLess(expected, actual)
// assertMore(expected, actual)
// assertLessOrEqual(expected, actual)
// assertMoreOrEqual(expected, actual)
// assertTrue(actual)
// assertFalse(actual)
// assertNull(actual)
// assertNotNull(actual)

#include <ArduinoUnitTests.h>

#define assertEqualFloat(arg1, arg2, arg3)  assertOp("assertEqualFloat", "expected", fabs(arg1 - arg2), compareLessOrEqual, "<=", "actual", arg3)
#define assertEqualINF(arg)  assertOp("assertEqualINF", "expected", INFINITY, compareEqual, "==", "actual", arg)
#define assertEqualNAN(arg)  assertOp("assertEqualNAN", "expected", true, compareEqual, "==", "actual", isnan(arg))


#include "Correlation.h"



unittest_setup()
{
}

unittest_teardown()
{
}


unittest(test_constructor)
{
  Correlation C;
  assertEqual(0, C.count());
  assertEqual(20, C.size());
}


unittest(test_add_clear)
{
  Correlation C;

  C.add(2, 7);
  C.add(3, 9);
  C.add(4, 10);
  C.add(5, 14);
  C.add(6, 15);

  assertEqual(5, C.count());
  assertEqual(20, C.size());

  C.clear();
  assertEqual(0, C.count());
  assertEqual(20, C.size());
}

unittest_main()

// --------
