
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
    srcs = 'test/test_all.cpp',
    defs = ['UNIT_TEST'],
    incs = ['.'],
    extra_cppflags = common_cppflags,
)