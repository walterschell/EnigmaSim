#ifndef TEST_H
#define TEST_H
#include <iostream>
using std::cout;
#define ASSERT_EQUAL(EXPRESSION, EXPECTED) \
cout << "Testing that " << #EXPRESSION << " equals " << EXPECTED << ": "; \
if (EXPRESSION != EXPECTED) \
{ \
    failcount++; \
    cout << "FAIL Got: " << EXPRESSION << "\n"; \
} \
else \
{ \
    passcount++; \
    cout << "PASS\n"; \
}

#endif