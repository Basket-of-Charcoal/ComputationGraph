#pragma once

#define INFO(fmt, ...) \
    ;                  \
    printf("[INFO] " fmt, ##__VA_ARGS__);
#define ERROR(fmt, ...) \
    ;                   \
    printf("[ERROR] " fmt, ##__VA_ARGS__);
