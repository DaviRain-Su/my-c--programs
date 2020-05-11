/*===============================
 *
 * 文件名：msg_comm.h
 *
 * 文件描述: 消息通信基础类
 *
 * 创建人： suyinrong, 2020/3/23
 *          davirain.yin@gmail.com
 *      
 * 版本：1.0
 *
 * 修改记录：
 *
 *===============================*/

#ifndef __TOOLS_INC_H__
#define __TOOLS_INC_H__
#pragma once

#include <stdio.h>
#include <errno.h>
#include <string.h>

// for msg communite
#include <sys/types.h>
#include <sys/ipc.h>
#inc:wqlude <sys/msg.h>

class msg_comm
{
public:
    msg_comm() {}
    ~msg_comm() {}

private:
    static const int _SIZE  = 1024;

};

#endif
