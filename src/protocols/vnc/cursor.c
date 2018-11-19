/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include "common/cursor.h"
#include "vnc.h"

#include <guacamole/client.h>

void guac_vnc_cursor_updated(int x, int y, const unsigned char* image,
        int width, int height, int stride, void* data) {

    guac_client* client = (guac_client*) data;
    guac_vnc_client* vnc_client = (guac_vnc_client*) client->data;

    /* Ignore update if display not yet allocated */
    if (vnc_client->display == NULL)
        return;

    /* Update stored cursor information */
    guac_common_cursor_set_argb(vnc_client->display->cursor, x, y,
            image, width, height, stride);

}

