/******************************************************************************
 * Copyright (c) Huawei Technologies Co., Ltd. 2018-2019. All rights reserved.
 * iSulad licensed under the Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2.
 * You may obtain a copy of Mulan PSL v2 at:
 *     http://license.coscl.org.cn/MulanPSL2
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
 * PURPOSE.
 * See the Mulan PSL v2 for more details.
 * Author: lifeng
 * Create: 2018-11-08
 * Description: provide container inspect definition
 ******************************************************************************/
#ifndef CMD_ISULA_INFORMATION_INSPECT_H
#define CMD_ISULA_INFORMATION_INSPECT_H

#include <stdbool.h>
#include <stddef.h>

#include "client_arguments.h"
#include "command_parser.h"

#ifdef __cplusplus
extern "C" {
#endif

#define INSPECT_OPTIONS(cmdargs)                                                            \
    {                                                                                       \
        CMD_OPT_TYPE_STRING,                                                                \
        false,                                                                              \
        "format",                                                                           \
        'f',                                                                                \
        &(cmdargs).format,                                                                  \
        "Format the output using the given go template",                                    \
        NULL                                                                                \
    },                                                                                      \
    {                                                                                       \
        CMD_OPT_TYPE_CALLBACK,                                                              \
        false,                                                                              \
        "time",                                                                             \
        't',                                                                                \
        &(cmdargs).time,                                                                    \
        "Seconds to wait for inspect timeout (default 120)",                                \
        command_convert_int                                                                 \
    },                                                                                      \
    {                                                                                       \
        CMD_OPT_TYPE_BOOL,                                                                  \
        false,                                                                              \
        "size",                                                                             \
        's',                                                                                \
        &(cmdargs).size,                                                                    \
        "Display total file sizes if the type is container (default 0)",                    \
        NULL                                                                                \
    },                                                                                      \
    {                                                                                       \
        CMD_OPT_TYPE_STRING,                                                                \
        false,                                                                              \
        "type",                                                                             \
        0,                                                                                  \
        &(cmdargs).inspect_type,                                                            \
        "Return JSON for specified type",                                                   \
        NULL                                                                                \
    }                                                                                       \

extern const char g_cmd_inspect_desc[];
extern const char g_cmd_inspect_usage[];
extern struct client_arguments g_cmd_inspect_args;
int cmd_inspect_main(int argc, const char **argv);

#ifdef __cplusplus
}
#endif

#endif // CMD_ISULA_INFORMATION_INSPECT_H
