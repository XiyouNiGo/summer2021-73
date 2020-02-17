/******************************************************************************
 * Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * iSulad licensed under the Mulan PSL v1.
 * You can use this software according to the terms and conditions of the Mulan PSL v1.
 * You may obtain a copy of Mulan PSL v1 at:
 *     http://license.coscl.org.cn/MulanPSL
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
 * PURPOSE.
 * See the Mulan PSL v1 for more details.
 * Author: lifeng
 * Create: 2020-02-14
 * Description: provide container unix mock
 ******************************************************************************/

#ifndef CONTAINER_UNIX_MOCK_H_
#define CONTAINER_UNIX_MOCK_H_

#include <gmock/gmock.h>
#include "container_unix.h"

class MockContainerUnix {
public:
    virtual ~MockContainerUnix() = default;
    MOCK_METHOD2(HasMountFor, bool(container_t *cont, const char *mpath));
    MOCK_METHOD1(ContainerUnref, void(container_t *cont));
};

void MockContainerUnix_SetMock(MockContainerUnix* mock);

#endif  // CONTAINER_UNIX_MOCK_H_