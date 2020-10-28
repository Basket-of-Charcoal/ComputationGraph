#pragma once

#define INFO(fmt, ...) \
    OUT("[INFO] ", fmt, ##__VA_ARGS__)
#define ERROR(fmt, ...) \
    OUT("[ERROR] ", fmt, ##__VA_ARGS__)

#define OUT(type, fmt, ...) \
    printf(type "%s:%d " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)