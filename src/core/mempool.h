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

#include <stdint.h>
#include <time.h>

#include "common/task.h"

#include "block.h"
#include "blockchainparams.h"
#include "transaction.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define FLUSH_MEMPOOL_TASK_DELAY 60

typedef struct MempoolEntry
{
  transaction_t *tx;
  uint32_t received_ts;
} mempool_entry_t;

int start_mempool(void);
int stop_mempool(void);

mempool_entry_t* init_mempool_entry(void);
int free_mempool_entry(mempool_entry_t *mempool_entry);

mempool_entry_t* get_mempool_entry_from_mempool(uint8_t *tx_hash);
transaction_t* get_tx_from_mempool(uint8_t *tx_hash);

int is_tx_in_mempool_nolock(transaction_t *tx);
int is_tx_in_mempool(transaction_t *tx);

int add_tx_to_mempool_nolock(transaction_t *tx);
int add_tx_to_mempool(transaction_t *tx);

int remove_tx_from_mempool_nolock(transaction_t *tx);
int remove_tx_from_mempool(transaction_t *tx);

transaction_t* pop_tx_from_mempool_nolock(void);
transaction_t* pop_tx_from_mempool(void);

uint64_t get_num_txs_in_mempool(void);

int fill_block_with_txs_from_mempool_nolock(block_t *block);
int fill_block_with_txs_from_mempool(block_t *block);

int clear_expired_txs_in_mempool_nolock(void);
int clear_expired_txs_in_mempool(void);

task_result_t flush_mempool(task_t *task, va_list args);

#ifdef __cplusplus
}
#endif
