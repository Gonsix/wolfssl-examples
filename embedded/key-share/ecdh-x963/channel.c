/* channel.c
 *
 * Copyright (C) 2006-2020 wolfSSL Inc.
 *
 * This file is part of wolfSSL.
 *
 * wolfSSL is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * wolfSSL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1335, USA
 */

#include <string.h>
#include "channel.h"

static unsigned char msgBuff[2][CH_MAXLEN];
static int msgLen;
static int sendMsg = 0;
static int recvMsg = 0;

void sendMessage(unsigned char *msg, int len)
{
    memcpy(msgBuff[sendMsg], msg, len);
    msgLen = len;
    ++sendMsg;  // アリスとボブを切り替える
    sendMsg %= 2;
}

int recvMessage(unsigned char **msg)
{
    *msg = msgBuff[recvMsg]; // buffer から取り出す
    ++recvMsg;
    recvMsg %= 2;
    return msgLen;
}
