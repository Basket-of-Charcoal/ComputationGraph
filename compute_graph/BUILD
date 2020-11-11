
common_cppflags = [
    "-std=c++14",
    "-g",
    '-O0',
    "-Wall",
    "-Wextra",
    "-Werror",
]

cc_binary(
    name = 'unit_test_all',
    srcs = [
        'test/test_all.cc',
        'src/base/graph.cc',
        'src/base/node.cc',
        'src/base/session.cc',
        'src/operation/operation.cc',
        'src/operation/operation_add.cc',
        'src/placeholder/placeholder.cc',
        'src/util/tensor.cc',
        'src/value/constant.cc'
    ],
    defs = ['UNIT_TEST'],
    incs = ['.'],
    extra_cppflags = common_cppflags,
)