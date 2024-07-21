#include <stdio.h>
#include "pico/stdlib.h"
#include "tx_api.h"

#define THREAD_STACK_SIZE 1024
#define THREAD_PRIORITY 1

// ThreadX thread control block and stack
TX_THREAD thread_0;
uint8_t thread_0_stack[THREAD_STACK_SIZE];

// Thread entry function
void thread_0_entry(ULONG initial_input) {
    while (1) {
        printf("Hello from ThreadX!\n");
        tx_thread_sleep(100);
    }
}

int main() {
    stdio_init_all();
    printf("ThreadX Demo\n");
    tx_kernel_enter();
    return 0;
}

// Define what the initial system looks like
void tx_application_define(void *first_unused_memory) {
    // Create a thread
    tx_thread_create(&thread_0, "thread 0", thread_0_entry, 0,
                     thread_0_stack, THREAD_STACK_SIZE,
                     THREAD_PRIORITY, THREAD_PRIORITY, TX_NO_TIME_SLICE, TX_AUTO_START);
}
