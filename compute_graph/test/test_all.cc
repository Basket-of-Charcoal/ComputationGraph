#include "test/placeholder/placeholder_test.h"
#include "test/util/tensor_test.h"
#include "test/value/constant_test.h"

int main()
{
    placeholder_test();
    tensor_test();
    constant_test();
    return 0;
}