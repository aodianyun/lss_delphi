/*
* 
* rtmpSDK 播放端接口说明
* 
*/



#pragma once

//typedef enum eMsgLevel{MSG_DEBUG=0, MSG_WARNING, MSG_ERR};

typedef bool(*OnRtmpPlayNotifyInJson_C)(const char* pszJson);

	/**
	 * 接    口：OnShowVideo
	 * 接口功能：第一次显示视频前触发
	 * 调    用：pszCmd { "cmd":"OnShowVideo", "params":{} }
	 **/

	/**
	 * 接    口：OnAudioPercent
	 * 接口功能：音频数据（百分比）回调，用于上层显示自定义音量条
	 * 参    数：uPercent	音频数据（处理后的）的百分比形式
	 * 调    用：pszCmd { "cmd":"OnAudioPercent", "params":{"uPercent":12} }
	 **/

	/**
	 * 接    口：OnRtmpPlayManagerMsg
	 * 接口功能：消息回调
	 * 参    数：MsgLev	消息级别 MSG_DEBUG=0, MSG_WARNING=1, MSG_ERR=2
	 *           pMsg	消息主体
	 *           pDetail消息详细说明
	 * 调    用：pszCmd { "cmd":"OnRtmpPlayManagerMsg", "params":{"MsgLev":1,"pMsg":"OnRtmpDead","pDetail":"NetConnection.Connect.Closed"} }
	 **/


	/**
	 * 接口：OnRtmpPlayManagerNetInfo
	 * 接口功能：上麦流信息回调
	 * 参    数：
	 *	unsigned int uPing;
	 *	unsigned int uVideoBitSum;
	 *	float			fVideoBitRate;
	 *	unsigned int uAudioBitSum;
	 *	float			fAudioBitRate;
	 *	unsigned int uDelay;
	 *	unsigned int uDiscardBytesSum;
	 *	unsigned int uVideoFrameSum;
	 *	unsigned int uVideoFrameRate;
	 *	unsigned int uAudioFrameSum;
	 *    
	 * 调    用：pszCmd { "cmd":"OnRtmpPlayManagerNetInfo", "params":{"uPing":15,"uVideoBitSum":90,...} }
	 **/

	/**
	 * 接口：OnRtmpPlayManagerComputerStatusInfo
	 * 接口功能：系统资源信息回调
	 * 参    数：
	 *	unsigned int uTotalPhys;
	 *	unsigned int uAvailPhys;
	 *	unsigned int uTotalVirtual;
	 *	unsigned int uAvailVirtual;
	 *	unsigned int uCPUClockSpeed;
	 *	unsigned int uCPUCores;
	 *	unsigned int uCPUUsage;
	 *	unsigned int uUpSpeed;
	 *	unsigned int uDownSpeed;
	 *	unsigned int uCurProcCPUUsage;
	 *	unsigned int uPublishPing;
	 *	unsigned int uAudioFrameSum;
	 *    
	 * 调    用：pszCmd { "cmd":"OnRtmpPlayManagerComputerStatusInfo", "params":{"uTotalPhys":2048,"uAvailPhys":1000,...} }
	 **/
	
	/**
	 * 接口：OnRtmpPlayManagerAVInfo
	 * 接口功能：音视频数据信息回调
	 * 参    数：
	 *	unsigned int uTotalBufTime;
	 *	unsigned int uAudioBufTime;
	 *	unsigned int uVideoBufTime;
	 *	unsigned int uVideoWidth;
	 *	unsigned int uVideoHeight;
	 *    
	 * 调    用：pszCmd { "cmd":"OnRtmpPlayManagerAVInfo", "params":{"uTotalBufTime":1000,"uAudioBufTime":200,...} }
	 **/

	/**
	 * 接口：OnRtmpPlayManagerPlayQuality
	 * 接口功能：播放质量信息回调
	 * 参    数：
	 *	unsigned int uShowVideoSucTime;
	 *	unsigned int uBufferEmptyCount;
	 *	unsigned int uBufferFullCount;
	 *	unsigned int uMaxPlayBuffer;
	 *	unsigned int uMinPlayBuffer;
	 *	unsigned int uAvgPlayBuffer;
	 *	float fTotalPlayTime;
	 *    
	 * 调    用：pszCmd { "cmd":"OnRtmpPlayManagerPlayQuality", "params":{"uShowVideoSucTime":3,"uBufferEmptyCount":4,...} }
	 **/

extern "C" __declspec(dllexport) bool CallInJson(void* rtmp, const char* pszCmd, char** ppszRes);
	/**
	 * 接    口：JSON调用统一接口 GetSdkVersion
	 * 接口功能：获取当前使用的SDK版本号
	 * 调    用：pszCmd { "cmd":"GetSdkVersion", "params":{} }
	 * 成功返回：ppszRes { "code":0, "data":{"version":"201407171636"} }
	 * 失败返回：ppszRes { "code":1, "data":{"reason":"no version."} }
	 **/

	/**
	 * 接    口：JSON调用统一接口 SetSYNBufTime
	 * 接口功能：设置播放缓冲延时设置
	 * 调    用：pszCmd { "cmd":"SetSYNBufTime", "params":{"dwDatalenOffset":1500, "dwMaxTimestampleInqueue":3000, "dwTimeCheckSynbuf":5000} }
	 * 返回：无
	 **/

	/**
	 * 接    口：JSON调用统一接口 StartPlay
	 * 接口功能：开始播放
	 * 调    用：pszCmd { "cmd":"StartPlay", "params":{} }
	 * 成功返回：ppszRes { "code":0, "data":{} }
	 * 失败返回：ppszRes { "code":1, "data":{} }
	 **/
	
	/**
	 * 接    口：JSON调用统一接口 StopPlay
	 * 接口功能：停止播放
	 * 调    用：pszCmd { "cmd":"StopPlay", "params":{} }
	 * 成功返回：ppszRes { "code":0, "data":{} }
	 * 失败返回：ppszRes { "code":1, "data":{} }
	 **/

	/**
	* 接    口：JSON调用统一接口 GetAudioPlayDevList
	* 接口功能：获取播放设备列表 （必须在 StartPlay 之前调用）
	* 调    用：pszCmd { "cmd":"GetAudioPlayDevList", "params":{} }
	* 成功返回：ppszRes { "code":0, "data":{"player":["dirsound", "guagua"]} }
	* 失败返回：ppszRes { "code":1, "data":{} }
	**/

	/**
	* 接    口：JSON调用统一接口 SetAudioPlayDev
	* 接口功能：设置播放设备ID （必须在 StartPlay 之前调用）
	* 参	数：int uDevID      (播放设备ID(count from 0))
	* 调    用：pszCmd { "cmd":"SetAudioPlayDev", "params":{"uDevID":1} }
	* 成功返回：ppszRes { "code":0, "data":{} }
	* 失败返回：ppszRes { "code":1, "data":{} }
	**/	

	/**
	* 接    口：JSON调用统一接口 SetStreamInfo
	* 接口功能：设置播放流信息 （必须在 StartPlay 之前调用）
	* 参	数：const char *pURL, 播放流地址
	*			const char *pAppID, 流App名称(如果启用验证，则 AppID= AppID+"?"+key, if appID is "App" and key is "kkyoo", then here is "App?kkyoo")
	*			const char *pStreamID, Stream名称
	* 调    用：pszCmd { "cmd":"SetStreamInfo", "params":{"pURL":rtmp://lssplay.aodianyun.com:1935,"pAppID":app,"pStreamID":stream} }
	* 成功返回：ppszRes { "code":0, "data":{} }
	* 失败返回：ppszRes { "code":1, "data":{} }
	**/	


	/**
	* 接    口：JSON调用统一接口 SetAdPara
	* 接口功能：设置音量  （可以在播放过程中调用）
	* 参	数：int uOutVolum,	音量
	*			bool bMute		是否静音
	* 调    用：pszCmd { "cmd":"SetAdPara", "params":{"uOutVolum":80,bMute:false} }
	* 返回：无
	**/	

	/**
	* 接    口：JSON调用统一接口 SetClientUserID
	* 接口功能：设置用户ID （必须在 StartPlay 之前调用）
	* 参	数：const char *pszUserID	用户ID
	* 调    用：pszCmd { "cmd":"SetClientUserID", "params":{"pszUserID":"123456"} }
	* 返回：无
	**/	

	/**
	* 接    口：JSON调用统一接口 SetRecordFileFullName
	* 接口功能：设置录制文件名（必须在 StartPlay 之前调用）
	* 参	数：const char *pszFileName, 录制文件路径
	* 调    用：pszCmd { "cmd":"SetRecordFileFullName", "params":{"pszFileName":"c:\\4.flv"} }
	* 返回：无
	**/	

	/**
	* 接    口：JSON调用统一接口 EnableRecordFile
	* 接口功能：开启/关闭 录制音视频功能（可以在播放过程中调用
	* 参	数：bool bEnable, 是否开启
	* 调    用：pszCmd { "cmd":"EnableRecordFile", "params":{"bEnable":false} }
	* 返回：无
	**/	

	/**
	 * 接口功能：JSON调用统一接口
	 * 参    数：CreateRtmpPlayManager_c的返回值
	 *			 pszCmd	JSON格式命令
	 *			 ppszRes JSON格式结果
	 * 返 回 值：成功/失败
	 * 示    例：pszCmd { "cmd":"xxx", "params":{"x":true, "xx":12, "xxx":"abc"} }
	 * 示    例：ppszRes { "code":0, "data":{"reason":"abc"} }
	 * 说    明：code含义 0：success，1：fail
	 **/

extern "C" __declspec(dllexport) void SetVdDisplayWnd(void* rtmp, HWND hwnd);
	/*
	*	接口功能:		设置视频显示窗口句柄  （必须在 StartPlay 之前调用）
	*	参    数：		CreateRtmpPlayManager_c的返回值	
	*		@hwnd:		窗口句柄
	*	返 回 值:		void
	*/


extern "C" __declspec(dllexport) void * CreateRtmpPlayManager_c(OnRtmpPlayNotifyInJson_C pNotify);

	/*
	*	接口功能:		創建接口 (調用其他接口之前必須調用該函數)
	*	参    数:		回調函數指針
	*	返 回 值:		void* 用於其他接口的第一個參數
	*/

extern "C" __declspec(dllexport) void Release(void* rtmp);

	/*
	*	接口功能:		刪除接口 （不在使用接口的時候調用該函數，清理內存）
	*	参    数：		CreateRtmpPlayManager_c的返回值	
	*	返 回 值:		void
	*/