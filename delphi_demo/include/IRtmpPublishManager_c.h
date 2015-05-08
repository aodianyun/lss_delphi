/*
* 
* rtmpSDK 上麦端接口说明
* 
*/

#pragma once
	/**
	 * 接    口：JSON回调统一接口 OnAudioPercent
	 * 接口功能：音频数据（百分比）回调，用于上层显示自定义音量条
	 * 参    数：uPercent	音频数据（处理后的）的百分比形式
	 * 调    用：pszJson { "cmd":"OnAudioPercent", "params":{"uPercent":12} }
	 **/

	/**
	 * 接    口：JSON回调统一接口 OnShowVideo
	 * 接口功能：视频显示时触发
	 * 调    用：pszJson { "cmd":"OnShowVideo", "params":{} }
	 **/

	/**
	 * 接    口：OnRtmpPublishManagerMsg
	 * 接口功能：消息回调
	 * 参    数：MsgLev	消息级别 MSG_DEBUG=0, MSG_WARNING=1, MSG_ERR=2
	 *           pMsg	消息主体
	 * 调    用：pszCmd { "cmd":"OnRtmpPublishManagerMsg", "params":{"MsgLev":1,"pMsg":"OnNotifyFail",} }
	 **/

	/**
	 * 接口：OnRtmpPublishManagerNetInfo
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
	 * 调    用：pszCmd { "cmd":"OnRtmpPublishManagerNetInfo", "params":{"uPing":15,"uVideoBitSum":90,...} }
	 **/

		/**
	 * 接口：OnRtmpPublishManagerComputerStatusInfo
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
	 * 调    用：pszCmd { "cmd":"OnRtmpPublishManagerComputerStatusInfo", "params":{"uTotalPhys":2048,"uAvailPhys":1000,...} }
	 **/


	/**
	 * 接口功能：JSON回调统一接口
	 * 参    数：pszJson	JSON格式字符串
	 * 返 回 值：成功/失败
	 * 示    例：{ "cmd":"xxx", "params":{"x":true, "xx":12, "xxx":"abc"} }
	 **/
typedef bool (*OnRtmpPublishNotifyInJson_C)(const char*);


	   /**
     * 接    口：JSON调用统一接口 StartPublish
     * 接口功能：发布流到服务器
     * 调    用：pszCmd { "cmd":"StartPublish", "params":{} }
     * 成功返回：ppszRes { "code":0, "data":{} }
     * 失败返回：ppszRes { "code":1, "data":{} }
     **/

	    /**
     * 接    口：JSON调用统一接口 StopPublish
     * 接口功能：停止发布
     * 调    用：pszCmd { "cmd":"StopPublish", "params":{} }
     * 成功返回：ppszRes { "code":0, "data":{} }
     * 失败返回：ppszRes { "code":1, "data":{} }
     **/	


	/**
	 * 接    口：JSON调用统一接口 SetShowSpectrum
	 * 接口功能：设置是否显示音频频谱
	 * 调    用：pszCmd { "cmd":"SetShowSpectrum", "params":{"bShow":true} }
	 * 成功返回：ppszRes { "code":0, "data":{} }
	 * 失败返回：ppszRes { "code":1, "data":{"reason":"no."} }
	 **/

	/**
	 * 接    口：JSON调用统一接口 GetSdkVersion
	 * 接口功能：获取当前使用的SDK版本号
	 * 调    用：pszCmd { "cmd":"GetSdkVersion", "params":{} }
	 * 成功返回：ppszRes { "code":0, "data":{"version":"201407171636"} }
	 * 失败返回：ppszRes { "code":1, "data":{"reason":"no version."} }
	 **/

	/**
	 * 接    口：JSON调用统一接口 SetAutoCtrlBitrate
	 * 接口功能：设置是否开启自动调整码率模式
	 * 调    用：pszCmd { "cmd":"SetAutoCtrlBitrate", "params":{"bAuto":true} }
	 * 成功返回：ppszRes { "code":0, "data":{} }
	 * 失败返回：ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * 接    口：JSON调用统一接口 GetPlayerList
	 * 接口功能：获取本地安装的播放器列表（必须在 StartPublish 之前调用）
	 * 调    用：pszCmd { "cmd":"GetPlayerList", "params":{} }
	 * 成功返回：ppszRes { "code":0, "data":{"player":["9158", "guagua"]} }
	 * 失败返回：ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * 接    口：JSON调用统一接口 SelectPlayerName
	 * 接口功能：选择背景音乐播放器（必须在 StartPublish 之前调用）
	 * 调    用：pszCmd { "cmd":"SelectPlayerName", "params":{"player":"9158"} }
	 * 成功返回：ppszRes { "code":0, "data":{} }
	 * 失败返回：ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * 接    口：JSON调用统一接口 SetVBRQuality
	 * 接口功能：设置VBR视频质量（若使用VBR必须在 SetPublishVideoPara 之前调用）
	 * 调    用：pszCmd { "cmd":"SetVBRQuality", "params":{"Quality":50} }			Quality范围0-51   1-51数字越小，质量越好。为0表示固定码率模式
	 * 成功返回：ppszRes { "code":0, "data":{} }
	 * 失败返回：ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * 接    口：JSON调用统一接口 SetBframeCount
	 * 接口功能：设置B帧（若使用必须在 SetPublishVideoPara 之前调用）
	 * 调    用：pszCmd { "cmd":"SetBframeCount", "params":{"BframeCount":5} }		BframeCount 范围大于等于0。增大B帧可以提高一点质量，但是会增大延时。
	 * 成功返回：ppszRes { "code":0, "data":{} }
	 * 失败返回：ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * 接    口：JSON调用统一接口 GetCamList
	 * 接口功能：获取摄像头列表（必须在 StartPublish 之前调用）
	 * 调    用：pszCmd { "cmd":"GetCamList", "params":{} }
	 * 成功返回：ppszRes { "code":0, "data":{"cameras":["cam1", "cam2"]} }
	 * 失败返回：ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * 接    口：JSON调用统一接口 GetMicList
	 * 接口功能：获取摄像头列表（必须在 StartPublish 之前调用）
	 * 调    用：pszCmd { "cmd":"GetMicList", "params":{} }
	 * 成功返回：ppszRes { "code":0, "data":{"mics":["mic1", "mic2"]} }
	 * 失败返回：ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * 接    口：JSON调用统一接口 SetCam
	 * 接口功能：设置摄像头ID. （必须在 StartPublish 之前调用）
	 * 参	 数：int uCamID 摄像头ID
	 * 调    用：pszCmd { "cmd":"SetCam", "params":{"uCamID":0} }
	 * 成功返回：ppszRes { "code":0, "data":{} }
	 * 失败返回：ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * 接    口：JSON调用统一接口 SetMic
	 * 接口功能：设置摄像头ID. （必须在 StartPublish 之前调用）
	 * 参	 数：int uMicID 麦克风ID
	 * 调    用：pszCmd { "cmd":"SetMic", "params":{"uMicID":0} }
	 * 成功返回：ppszRes { "code":0, "data":{} }
	 * 失败返回：ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * 接    口：JSON调用统一接口 CapStereo
	 * 接口功能：设置混音或者麦克. （必须在 StartPublish 之后，StopPublish 之前调用）
	 * 参	 数：bool bCapStereo,	true(混音), false(麦克)
	 * 调    用：pszCmd { "cmd":"CapStereo", "params":{"bCapStereo":false} }
	 * 成功返回：ppszRes { "code":0, "data":{} }
	 * 失败返回：ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * 接    口：JSON调用统一接口 SetPublishAudioPara
	 * 接口功能：设置音频参数.  （必须在 StartPublish 之前调用）
	 * 参	 数：int iSampleRate,	采样率. (hz)
	 *			 int iChannels,		音频通道数.
	 *			 int iBitPerSample, 音频采样位数. (bit)
	 *			 int iBitRate,		码率. (bps)   
	 *			 int iVolum,		音量. (0-100)
	 *			 bool bMute			是否静音. (true/false)
	 * 调    用：pszCmd { "cmd":"SetPublishAudioPara", "params":{"iSampleRate":44100, "iChannels":2,...} }
	 * 成功返回：ppszRes { "code":0, "data":{} }
	 * 失败返回：ppszRes { "code":1, "data":{} }
	 **/
	
	/**
	 * 接    口：JSON调用统一接口 SetPublishStreamPara
	 * 接口功能：设置发布流信息.  （必须在 StartPublish 之前调用）
	 * 参	 数：const char *pServer,,	服务器地址.
	 *			 const char *pApp,		App string (different from other site).
	 *			 const char *pStream,	Stream
	 * 调    用：pszCmd { "cmd":"SetPublishStreamPara", "params":{"pServer":"rtmp://rtmp.aodianyun.com:1935", "pApp":"app","pStream": stream} }
	 * 成功返回：ppszRes { "code":0, "data":{} }
	 * 失败返回：ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * 接    口：JSON调用统一接口 SetPublishVolum
	 * 接口功能：设置设备捕获音量.（可以在发布过程中调用）
	 * 参	 数：int uVolum,	音量.
	 *			 bool bMute		是否静音
	 * 调    用：pszCmd { "cmd":"SetPublishVolum", "params":{"uVolum":80,"bMute":false} }
	 * 成功返回：ppszRes { "code":0, "data":{} }
	 * 失败返回：ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * 接    口：JSON调用统一接口 SetPublishOtherPlayerVolum
	 * 接口功能：设置背景音乐音量 .（可以在上麦过程中调用）
	 * 参	 数：int uVolum,	音量.
	 *			 bool bMute		是否静音
	 * 调    用：pszCmd { "cmd":"SetPublishOtherPlayerVolum", "params":{"uVolum":80,"bMute":false} }
	 * 成功返回：ppszRes { "code":0, "data":{} }
	 * 失败返回：ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * 接    口：JSON调用统一接口 EnableHookPlayer
	 * 接口功能：开启背景音乐播放器（必须在 StartPublish 之后，StopPublish 之前调用）
	 * 参	 数：bool IsEnableHookPlayer,   true 启用.
	 * 调    用：pszCmd { "cmd":"EnableHookPlayer", "params":{"IsEnableHookPlayer":false} }
	 * 成功返回：ppszRes { "code":0, "data":{} }
	 * 失败返回：ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * 接    口：JSON调用统一接口 WhetherToRestartTargetProcess
	 * 接口功能：开启背景音乐播放器时是否重启播放器进程（必须在 StartPublish 之前调用）
	 * 参	 数：bool isRestart,   true 重启.
	 * 调    用：pszCmd { "cmd":"WhetherToRestartTargetProcess", "params":{"isRestart":false} }
	 * 成功返回：ppszRes { "code":0, "data":{} }
	 * 失败返回：ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * 接    口：JSON调用统一接口 EnableLog
	 * 接口功能：开启日志（必须在 StartPublish 之后，StartPublish 之前调用）
	 * 参	 数：bool isEnableLog,   true 开启.
	 * 调    用：pszCmd { "cmd":"EnableLog", "params":{"isEnableLog":false} }
	 * 成功返回：ppszRes { "code":0, "data":{} }
	 * 失败返回：ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * 接    口：JSON调用统一接口 DetachHookDll
	 * 接口功能：让HookDll 退出进程空间（必须在 StartPublish 之前调用）
	 * 调    用：pszCmd { "cmd":"DetachHookDll", "params":{} }
	 * 成功返回：ppszRes { "code":0, "data":{} }
	 * 失败返回：ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * 接    口：JSON调用统一接口 SetClientUserID
	 * 接口功能：发送用户ID到服务器（必须在 StartPublish 之前调用）
	 * 参	 数：const char *pszUserID,  用户ID
	 * 调    用：pszCmd { "cmd":"SetClientUserID", "params":{"pszUserID":"12346"} }
	 * 成功返回：ppszRes { "code":0, "data":{} }
	 * 失败返回：ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * 接    口：JSON调用统一接口 SetRecordFileFullName
	 * 接口功能：发送用户ID到服务器（必须在 StartPublish 之前调用）
	 * 参	 数：const char *pszFileName,  用户ID
	 * 调    用：pszCmd { "cmd":"SetRecordFileFullName", "params":{"pszFileName":"c:\\3.flv"} }
	 * 成功返回：ppszRes { "code":0, "data":{} }
	 * 失败返回：ppszRes { "code":1, "data":{} }
	 **/

		/**
	 * 接    口：JSON调用统一接口 EnableRecordFile
	 * 接口功能：开启/关闭 录制功能（可以在上麦过程中调用）
	 * 参	 数：bool bEnable,  true 开启
	 * 调    用：pszCmd { "cmd":"EnableRecordFile", "params":{"bEnable":false} }
	 * 成功返回：ppszRes { "code":0, "data":{} }
	 * 失败返回：ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * 接口功能：JSON调用统一接口
	 * 参    数：CreateRtmpPublishManager_c的返回值
	 *			 pszCmd	JSON格式命令
	 *			 ppszRes JSON格式结果
	 * 返 回 值：成功/失败
	 * 示    例：pszCmd { "cmd":"xxx", "params":{"x":true, "xx":12, "xxx":"abc"} }
	 * 示    例：ppszRes { "code":0, "data":{"reason":"abc"} }
	 * 说    明：code含义 0：success，1：fail
	 **/



extern "C" __declspec(dllexport) bool CallInJson(void* rtmp, const char* pszCmd, char** ppszRes);

    /*
    *   接口功能:       设置视频参数.  （必须在 StartPublish 之前调用）
    *   参    数:   
	*		@rtmp					CreateRtmpPublishManager_c的返回值
    *       @uWidth:                视频宽.    
    *       @uHeight:               视频高.    
    *       @uFrameRate:            视频帧率.   
    *       @uBitRate:              码率. (bps)   
    *       @hVideo:                视频显示窗口句柄.       
    *   返 回 值:                  无
    */
extern "C" __declspec(dllexport) void SetPublishVideoPara(void* rtmp, int uWidth, int uHeight, int uFrameRate, int uBitRate, HWND hVideo, int uKeyFrameInterval);


	/*
	*	接口功能:		創建接口 (調用其他接口之前必須調用該函數)
	*	参    数:		回調函數指針
	*	返 回 值:		void* 用於其他接口的第一個參數
	*/
extern "C" __declspec(dllexport) void * CreateRtmpPublishManager_c(OnRtmpPublishNotifyInJson_C pNotify);

	/*
	*	接口功能:		刪除接口 （不在使用接口的時候調用該函數，清理內存）
	*	参    数：		CreateRtmpPublishManager_c的返回值	
	*	返 回 值:		void
	*/
extern "C" __declspec(dllexport) void Release(void* rtmp);



extern "C" __declspec(dllexport) void DoTest(void* rtmp, HWND hVideo);