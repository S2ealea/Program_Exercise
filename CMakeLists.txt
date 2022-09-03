cmake_minimum_required(VERSION 3.21)
project(Program_Exercise C)

set(CMAKE_C_STANDARD 11)

include_directories(09_list/list)
include_directories(16_queue/array_queue)
include_directories(19_binary_tree)
include_directories(20_list_isPalindrome)

add_executable(Program_Exercise
        01_QQ_communication/client.c
        01_QQ_communication/server.c
        04_pointer_char_array/src.c
        05_pointer_fun_exchange_var/src.c
        06_pointer_string_month/src.c
        07_virtualdevice_tun/src.c
        08_webbenc_debug/webbech_debug.c
        09_list/list/list.c
        09_list/list/list.h
        09_list/list/main.c
        09_list/list_exercise/list-handy.c
        09_list/list_exercise/list.c
        09_list/singly_linked_list/singly_linked_list.c
        09_list/singly_linked_list/singly_linked_list_menu_driven.c
        10_thread/01_thread_create/linux_thread_create.c
        10_thread/02_thread_with_lock/linux_thread_with_lock.c
        11_swap_func/swap_src.c
        12_free_func/free_test.c
        13_macro_test/MACRO_test.c
        14_nextPrimeNumber/nextPrimeNumber.c
        15_list/dlist.c
        15_list/list.c
        16_queue/array_queue/array_queue.c
        16_queue/array_queue/array_queue.h
        16_queue/ArrayQueue.c
        16_queue/queue.c
        17_linked_stack/linked-stack.c
        18_hashtable/hashtable.c
        19_binary_tree/binarytree.c
        19_binary_tree/queue.c
        19_binary_tree/queue.h
        20_list_isPalindrome/LinkList.c
        20_list_isPalindrome/LinkList.h
        20_list_isPalindrome/main.c
        OpenSourceProjectExercise/Tinyhttpd/http.c
        OpenSourceProjectExercise/TypicalExercise100/exer001.c)

add_executable(exer001 OpenSourceProjectExercise/TypicalExercise100/exer001.c)