// Tencent is pleased to support the open source community by making Mars available.
// Copyright (C) 2016 THL A29 Limited, a Tencent company. All rights reserved.

// Licensed under the MIT License (the "License"); you may not use this file except in 
// compliance with the License. You may obtain a copy of the License at
// http://opensource.org/licenses/MIT

// Unless required by applicable law or agreed to in writing, software distributed under the License is
// distributed on an "AS IS" basis, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
// either express or implied. See the License for the specific language governing permissions and
// limitations under the License.

/*
 * app_logic.h
 *
 *  Created on: 2016/3/3
 *      Author: caoshaokun
 */

#ifndef APPCOMM_INTERFACE_APPCOMM_LOGIC_H_
#define APPCOMM_INTERFACE_APPCOMM_LOGIC_H_

#include <string>

#include "mars/app/app.h"
#include "mars/comm/comm_data.h"

class AutoBuffer;

namespace mars {
namespace app {

	class Callback {
	public:
		virtual ~Callback() {};
        
		// 1 代理服务器信息
        virtual bool GetProxyInfo(const std::string& _host, mars::comm::ProxyInfo& _proxy_info) { return false; }

// 2 获取App的文件路径
        virtual std::string GetAppFilePath() = 0;
        
// 3 获取用户账户信息 		
		virtual AccountInfo GetAccountInfo() = 0;

//    获取客户端版本号
		virtual unsigned int GetClientVersion() = 0;

//   获取设备信息 
		virtual DeviceInfo GetDeviceInfo() = 0;

	};

// 设置回调方法    
	void SetCallback(Callback* const callback);
}}


#endif /* APPCOMM_INTERFACE_APPCOMM_LOGIC_H_ */
