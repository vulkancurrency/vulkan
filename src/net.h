// Copyright (c) 2019, The Vulkan Developers.
//
// This file is part of Vulkan.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// You should have received a copy of the MIT License
// along with Vulkan. If not, see <https://opensource.org/licenses/MIT>.

#pragma once

#include <stdlib.h>
#include <stdint.h>

#include <gossip.h>

#include "task.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define RESYNC_CHAIN_TASK_DELAY 10

void net_set_gossip(pittacus_gossip_t *gossip);
pittacus_gossip_t* net_get_gossip(void);

void net_receive_data(void *context, pittacus_gossip_t *gossip, const pt_sockaddr_storage *recipient, pt_socklen_t recipient_len, const uint8_t *data, size_t data_size);
int net_send_data(pittacus_gossip_t *gossip, const uint8_t *data, size_t data_size);
int net_data_sendto(pittacus_gossip_t *gossip, const pt_sockaddr_storage *recipient, pt_socklen_t recipient_len, const uint8_t *data, size_t data_size);

int net_connect(const char *address, int port);
int net_open_connection(void);

int net_run_server(void);
void* net_run_server_threaded();

int net_start_server(int threaded, int seed_mode);
void net_stop_server(void);

task_result_t resync_chain(task_t *task, va_list args);

#ifdef __cplusplus
}
#endif
