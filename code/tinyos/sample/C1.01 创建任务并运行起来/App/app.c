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
#include "tinyOS.h"
#include "app.h"
#include "hal.h"

static tTask task1;                     // 任务1结构
static tTask task2;                     // 任务2结构
static tTask task3;                     // 任务3结构
static tTask task4;                     // 任务4结构

static tTaskStack task1Env[TASK1_ENV_SIZE];     // 任务1的堆栈空间
static tTaskStack task2Env[TASK2_ENV_SIZE];     // 任务2的堆栈空间
static tTaskStack task3Env[TASK3_ENV_SIZE];     // 任务3的堆栈空间
static tTaskStack task4Env[TASK4_ENV_SIZE];     // 任务4的堆栈空间

int task1Flag;           // 用于指示任务运行状态的标志变量
int task2Flag;           // 用于指示任务运行状态的标志变量
int task3Flag;           // 用于指示任务运行状态的标志变量
int task4Flag;           // 用于指示任务运行状态的标志变量

void waitEvent (void) {
    xprintf("Wait event!\n");

    tTaskDelay(1);
}

void processEvent (void) {
    xprintf("Process event!\n");

}

void notifyOtherTask (void) {
    xprintf("Notify other task!\n");
}

/**
 * 任务的运行代码
 * @param param 任务初始运行参数
 */
void task1Entry (void *param) {
    for (;;) {
        waitEvent();
        processEvent();
        notifyOtherTask();
    }
}

/**
 * 任务的运行代码
 * @param param 任务初始运行参数
 */
void task2Entry (void *param) {
    for (;;) {
        task2Flag = 1;
        tTaskDelay(1);
        task2Flag = 0;
        tTaskDelay(1);
    }
}

/**
 * 任务的运行代码
 * @param param 任务初始运行参数
 */
void task3Entry (void *param) {
    for (;;) {
        task3Flag = 1;
        tTaskDelay(1);
        task3Flag = 0;
        tTaskDelay(1);
    }
}


/**
 * 任务的运行代码
 * @param param 任务初始运行参数
 */
void task4Entry (void *param) {
    for (;;) {
        task4Flag = 1;
        tTaskDelay(1);
        task4Flag = 0;
        tTaskDelay(1);
    }
}

/**
 * App的初始化
 */
void tInitApp (void) {
    halInit();

    tTaskInit(&task1, task1Entry, (void *) 0x0, TASK1_PRIO, task1Env, sizeof(task1Env));
    tTaskInit(&task2, task2Entry, (void *) 0x0, TASK2_PRIO, task2Env, sizeof(task2Env));
    tTaskInit(&task3, task3Entry, (void *) 0x0, TASK3_PRIO, task3Env, sizeof(task3Env));
    tTaskInit(&task4, task4Entry, (void *) 0x0, TASK4_PRIO, task4Env, sizeof(task4Env));
}

