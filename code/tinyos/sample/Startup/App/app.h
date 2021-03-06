/**
 * @brief tOS应用示例
 * @details
 *     tOS是一个小巧的嵌入式操作系统，为方便学习使用而开发。所有代码全部自行开发，本着简单易学的原则,
 * 所有设计尽可能采用比较简单的设计。在设计之初，选择了目前最常用的ARM Cortex-M3内核为目标内核进行
 * 设计，无论你使用的是哪一款具体的Cortex-M芯片，均可能很方便地进行移植。
 *     由于该RTOS主要用于教学，没有经过严格的验证测试，所以不保证可靠性和稳定性。再次说明，本系统主要用于
 * 学习理解RTOS的工作原理。如有Bug，欢迎访问我的博客：http://ilishutong.com
 *     本工程主要用于演示tOS各个模块如何使用。通过学习，你可以顺利地理解如何使用其它RTOS。
 *     如果你对tOS的实现原理和应用感兴趣，也欢迎访问我的博客，找到相关的配套教学视频。
 *
 * @author 01课堂 lishutong
 * @date 2017-06-01
 * @version 1.0
 * @copyright 版权所有，禁止用于商业用途
 */
#ifndef PROJECT_APP_H_H
#define PROJECT_APP_H_H

#include <stdio.h>
#include "tinyOS.h"
#include "hal.h"

#define TASK1_ENV_SIZE              512             // Task1的堆栈空间单元数
#define TASK2_ENV_SIZE              512             // Task2的堆栈空间单元数
#define TASK3_ENV_SIZE              512             // Task3的堆栈空间单元数
#define TASK4_ENV_SIZE              512             // Task4的堆栈空间单元数

#define TASK1_PRIO                   1              // Task1的任务优先级
#define TASK2_PRIO                   2              // Task2的任务优先级
#define TASK3_PRIO                   3              // Task3的任务优先级
#define TASK4_PRIO                   4              // Task4的任务优先级

// 各个任务
void task1Entry (void *param);

void task2Entry (void *param);

void task3Entry (void *param);

void task4Entry (void *param);

#endif //PROJECT_APP_H_H
