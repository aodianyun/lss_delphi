/*
* 
* rtmpSDK ����˽ӿ�˵��
* 
*/

#pragma once
	/**
	 * ��    �ڣ�JSON�ص�ͳһ�ӿ� OnAudioPercent
	 * �ӿڹ��ܣ���Ƶ���ݣ��ٷֱȣ��ص��������ϲ���ʾ�Զ���������
	 * ��    ����uPercent	��Ƶ���ݣ������ģ��İٷֱ���ʽ
	 * ��    �ã�pszJson { "cmd":"OnAudioPercent", "params":{"uPercent":12} }
	 **/

	/**
	 * ��    �ڣ�JSON�ص�ͳһ�ӿ� OnShowVideo
	 * �ӿڹ��ܣ���Ƶ��ʾʱ����
	 * ��    �ã�pszJson { "cmd":"OnShowVideo", "params":{} }
	 **/

	/**
	 * ��    �ڣ�OnRtmpPublishManagerMsg
	 * �ӿڹ��ܣ���Ϣ�ص�
	 * ��    ����MsgLev	��Ϣ���� MSG_DEBUG=0, MSG_WARNING=1, MSG_ERR=2
	 *           pMsg	��Ϣ����
	 * ��    �ã�pszCmd { "cmd":"OnRtmpPublishManagerMsg", "params":{"MsgLev":1,"pMsg":"OnNotifyFail",} }
	 **/

	/**
	 * �ӿڣ�OnRtmpPublishManagerNetInfo
	 * �ӿڹ��ܣ���������Ϣ�ص�
	 * ��    ����
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
	 * ��    �ã�pszCmd { "cmd":"OnRtmpPublishManagerNetInfo", "params":{"uPing":15,"uVideoBitSum":90,...} }
	 **/

		/**
	 * �ӿڣ�OnRtmpPublishManagerComputerStatusInfo
	 * �ӿڹ��ܣ�ϵͳ��Դ��Ϣ�ص�
	 * ��    ����
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
	 * ��    �ã�pszCmd { "cmd":"OnRtmpPublishManagerComputerStatusInfo", "params":{"uTotalPhys":2048,"uAvailPhys":1000,...} }
	 **/


	/**
	 * �ӿڹ��ܣ�JSON�ص�ͳһ�ӿ�
	 * ��    ����pszJson	JSON��ʽ�ַ���
	 * �� �� ֵ���ɹ�/ʧ��
	 * ʾ    ����{ "cmd":"xxx", "params":{"x":true, "xx":12, "xxx":"abc"} }
	 **/
typedef bool (*OnRtmpPublishNotifyInJson_C)(const char*);


	   /**
     * ��    �ڣ�JSON����ͳһ�ӿ� StartPublish
     * �ӿڹ��ܣ���������������
     * ��    �ã�pszCmd { "cmd":"StartPublish", "params":{} }
     * �ɹ����أ�ppszRes { "code":0, "data":{} }
     * ʧ�ܷ��أ�ppszRes { "code":1, "data":{} }
     **/

	    /**
     * ��    �ڣ�JSON����ͳһ�ӿ� StopPublish
     * �ӿڹ��ܣ�ֹͣ����
     * ��    �ã�pszCmd { "cmd":"StopPublish", "params":{} }
     * �ɹ����أ�ppszRes { "code":0, "data":{} }
     * ʧ�ܷ��أ�ppszRes { "code":1, "data":{} }
     **/	


	/**
	 * ��    �ڣ�JSON����ͳһ�ӿ� SetShowSpectrum
	 * �ӿڹ��ܣ������Ƿ���ʾ��ƵƵ��
	 * ��    �ã�pszCmd { "cmd":"SetShowSpectrum", "params":{"bShow":true} }
	 * �ɹ����أ�ppszRes { "code":0, "data":{} }
	 * ʧ�ܷ��أ�ppszRes { "code":1, "data":{"reason":"no."} }
	 **/

	/**
	 * ��    �ڣ�JSON����ͳһ�ӿ� GetSdkVersion
	 * �ӿڹ��ܣ���ȡ��ǰʹ�õ�SDK�汾��
	 * ��    �ã�pszCmd { "cmd":"GetSdkVersion", "params":{} }
	 * �ɹ����أ�ppszRes { "code":0, "data":{"version":"201407171636"} }
	 * ʧ�ܷ��أ�ppszRes { "code":1, "data":{"reason":"no version."} }
	 **/

	/**
	 * ��    �ڣ�JSON����ͳһ�ӿ� SetAutoCtrlBitrate
	 * �ӿڹ��ܣ������Ƿ����Զ���������ģʽ
	 * ��    �ã�pszCmd { "cmd":"SetAutoCtrlBitrate", "params":{"bAuto":true} }
	 * �ɹ����أ�ppszRes { "code":0, "data":{} }
	 * ʧ�ܷ��أ�ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * ��    �ڣ�JSON����ͳһ�ӿ� GetPlayerList
	 * �ӿڹ��ܣ���ȡ���ذ�װ�Ĳ������б������� StartPublish ֮ǰ���ã�
	 * ��    �ã�pszCmd { "cmd":"GetPlayerList", "params":{} }
	 * �ɹ����أ�ppszRes { "code":0, "data":{"player":["9158", "guagua"]} }
	 * ʧ�ܷ��أ�ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * ��    �ڣ�JSON����ͳһ�ӿ� SelectPlayerName
	 * �ӿڹ��ܣ�ѡ�񱳾����ֲ������������� StartPublish ֮ǰ���ã�
	 * ��    �ã�pszCmd { "cmd":"SelectPlayerName", "params":{"player":"9158"} }
	 * �ɹ����أ�ppszRes { "code":0, "data":{} }
	 * ʧ�ܷ��أ�ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * ��    �ڣ�JSON����ͳһ�ӿ� SetVBRQuality
	 * �ӿڹ��ܣ�����VBR��Ƶ��������ʹ��VBR������ SetPublishVideoPara ֮ǰ���ã�
	 * ��    �ã�pszCmd { "cmd":"SetVBRQuality", "params":{"Quality":50} }			Quality��Χ0-51   1-51����ԽС������Խ�á�Ϊ0��ʾ�̶�����ģʽ
	 * �ɹ����أ�ppszRes { "code":0, "data":{} }
	 * ʧ�ܷ��أ�ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * ��    �ڣ�JSON����ͳһ�ӿ� SetBframeCount
	 * �ӿڹ��ܣ�����B֡����ʹ�ñ����� SetPublishVideoPara ֮ǰ���ã�
	 * ��    �ã�pszCmd { "cmd":"SetBframeCount", "params":{"BframeCount":5} }		BframeCount ��Χ���ڵ���0������B֡�������һ�����������ǻ�������ʱ��
	 * �ɹ����أ�ppszRes { "code":0, "data":{} }
	 * ʧ�ܷ��أ�ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * ��    �ڣ�JSON����ͳһ�ӿ� GetCamList
	 * �ӿڹ��ܣ���ȡ����ͷ�б������� StartPublish ֮ǰ���ã�
	 * ��    �ã�pszCmd { "cmd":"GetCamList", "params":{} }
	 * �ɹ����أ�ppszRes { "code":0, "data":{"cameras":["cam1", "cam2"]} }
	 * ʧ�ܷ��أ�ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * ��    �ڣ�JSON����ͳһ�ӿ� GetMicList
	 * �ӿڹ��ܣ���ȡ����ͷ�б������� StartPublish ֮ǰ���ã�
	 * ��    �ã�pszCmd { "cmd":"GetMicList", "params":{} }
	 * �ɹ����أ�ppszRes { "code":0, "data":{"mics":["mic1", "mic2"]} }
	 * ʧ�ܷ��أ�ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * ��    �ڣ�JSON����ͳһ�ӿ� SetCam
	 * �ӿڹ��ܣ���������ͷID. �������� StartPublish ֮ǰ���ã�
	 * ��	 ����int uCamID ����ͷID
	 * ��    �ã�pszCmd { "cmd":"SetCam", "params":{"uCamID":0} }
	 * �ɹ����أ�ppszRes { "code":0, "data":{} }
	 * ʧ�ܷ��أ�ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * ��    �ڣ�JSON����ͳһ�ӿ� SetMic
	 * �ӿڹ��ܣ���������ͷID. �������� StartPublish ֮ǰ���ã�
	 * ��	 ����int uMicID ��˷�ID
	 * ��    �ã�pszCmd { "cmd":"SetMic", "params":{"uMicID":0} }
	 * �ɹ����أ�ppszRes { "code":0, "data":{} }
	 * ʧ�ܷ��أ�ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * ��    �ڣ�JSON����ͳһ�ӿ� CapStereo
	 * �ӿڹ��ܣ����û����������. �������� StartPublish ֮��StopPublish ֮ǰ���ã�
	 * ��	 ����bool bCapStereo,	true(����), false(���)
	 * ��    �ã�pszCmd { "cmd":"CapStereo", "params":{"bCapStereo":false} }
	 * �ɹ����أ�ppszRes { "code":0, "data":{} }
	 * ʧ�ܷ��أ�ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * ��    �ڣ�JSON����ͳһ�ӿ� SetPublishAudioPara
	 * �ӿڹ��ܣ�������Ƶ����.  �������� StartPublish ֮ǰ���ã�
	 * ��	 ����int iSampleRate,	������. (hz)
	 *			 int iChannels,		��Ƶͨ����.
	 *			 int iBitPerSample, ��Ƶ����λ��. (bit)
	 *			 int iBitRate,		����. (bps)   
	 *			 int iVolum,		����. (0-100)
	 *			 bool bMute			�Ƿ���. (true/false)
	 * ��    �ã�pszCmd { "cmd":"SetPublishAudioPara", "params":{"iSampleRate":44100, "iChannels":2,...} }
	 * �ɹ����أ�ppszRes { "code":0, "data":{} }
	 * ʧ�ܷ��أ�ppszRes { "code":1, "data":{} }
	 **/
	
	/**
	 * ��    �ڣ�JSON����ͳһ�ӿ� SetPublishStreamPara
	 * �ӿڹ��ܣ����÷�������Ϣ.  �������� StartPublish ֮ǰ���ã�
	 * ��	 ����const char *pServer,,	��������ַ.
	 *			 const char *pApp,		App string (different from other site).
	 *			 const char *pStream,	Stream
	 * ��    �ã�pszCmd { "cmd":"SetPublishStreamPara", "params":{"pServer":"rtmp://rtmp.aodianyun.com:1935", "pApp":"app","pStream": stream} }
	 * �ɹ����أ�ppszRes { "code":0, "data":{} }
	 * ʧ�ܷ��أ�ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * ��    �ڣ�JSON����ͳһ�ӿ� SetPublishVolum
	 * �ӿڹ��ܣ������豸��������.�������ڷ��������е��ã�
	 * ��	 ����int uVolum,	����.
	 *			 bool bMute		�Ƿ���
	 * ��    �ã�pszCmd { "cmd":"SetPublishVolum", "params":{"uVolum":80,"bMute":false} }
	 * �ɹ����أ�ppszRes { "code":0, "data":{} }
	 * ʧ�ܷ��أ�ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * ��    �ڣ�JSON����ͳһ�ӿ� SetPublishOtherPlayerVolum
	 * �ӿڹ��ܣ����ñ����������� .����������������е��ã�
	 * ��	 ����int uVolum,	����.
	 *			 bool bMute		�Ƿ���
	 * ��    �ã�pszCmd { "cmd":"SetPublishOtherPlayerVolum", "params":{"uVolum":80,"bMute":false} }
	 * �ɹ����أ�ppszRes { "code":0, "data":{} }
	 * ʧ�ܷ��أ�ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * ��    �ڣ�JSON����ͳһ�ӿ� EnableHookPlayer
	 * �ӿڹ��ܣ������������ֲ������������� StartPublish ֮��StopPublish ֮ǰ���ã�
	 * ��	 ����bool IsEnableHookPlayer,   true ����.
	 * ��    �ã�pszCmd { "cmd":"EnableHookPlayer", "params":{"IsEnableHookPlayer":false} }
	 * �ɹ����أ�ppszRes { "code":0, "data":{} }
	 * ʧ�ܷ��أ�ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * ��    �ڣ�JSON����ͳһ�ӿ� WhetherToRestartTargetProcess
	 * �ӿڹ��ܣ������������ֲ�����ʱ�Ƿ��������������̣������� StartPublish ֮ǰ���ã�
	 * ��	 ����bool isRestart,   true ����.
	 * ��    �ã�pszCmd { "cmd":"WhetherToRestartTargetProcess", "params":{"isRestart":false} }
	 * �ɹ����أ�ppszRes { "code":0, "data":{} }
	 * ʧ�ܷ��أ�ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * ��    �ڣ�JSON����ͳһ�ӿ� EnableLog
	 * �ӿڹ��ܣ�������־�������� StartPublish ֮��StartPublish ֮ǰ���ã�
	 * ��	 ����bool isEnableLog,   true ����.
	 * ��    �ã�pszCmd { "cmd":"EnableLog", "params":{"isEnableLog":false} }
	 * �ɹ����أ�ppszRes { "code":0, "data":{} }
	 * ʧ�ܷ��أ�ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * ��    �ڣ�JSON����ͳһ�ӿ� DetachHookDll
	 * �ӿڹ��ܣ���HookDll �˳����̿ռ䣨������ StartPublish ֮ǰ���ã�
	 * ��    �ã�pszCmd { "cmd":"DetachHookDll", "params":{} }
	 * �ɹ����أ�ppszRes { "code":0, "data":{} }
	 * ʧ�ܷ��أ�ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * ��    �ڣ�JSON����ͳһ�ӿ� SetClientUserID
	 * �ӿڹ��ܣ������û�ID���������������� StartPublish ֮ǰ���ã�
	 * ��	 ����const char *pszUserID,  �û�ID
	 * ��    �ã�pszCmd { "cmd":"SetClientUserID", "params":{"pszUserID":"12346"} }
	 * �ɹ����أ�ppszRes { "code":0, "data":{} }
	 * ʧ�ܷ��أ�ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * ��    �ڣ�JSON����ͳһ�ӿ� SetRecordFileFullName
	 * �ӿڹ��ܣ������û�ID���������������� StartPublish ֮ǰ���ã�
	 * ��	 ����const char *pszFileName,  �û�ID
	 * ��    �ã�pszCmd { "cmd":"SetRecordFileFullName", "params":{"pszFileName":"c:\\3.flv"} }
	 * �ɹ����أ�ppszRes { "code":0, "data":{} }
	 * ʧ�ܷ��أ�ppszRes { "code":1, "data":{} }
	 **/

		/**
	 * ��    �ڣ�JSON����ͳһ�ӿ� EnableRecordFile
	 * �ӿڹ��ܣ�����/�ر� ¼�ƹ��ܣ���������������е��ã�
	 * ��	 ����bool bEnable,  true ����
	 * ��    �ã�pszCmd { "cmd":"EnableRecordFile", "params":{"bEnable":false} }
	 * �ɹ����أ�ppszRes { "code":0, "data":{} }
	 * ʧ�ܷ��أ�ppszRes { "code":1, "data":{} }
	 **/

	/**
	 * �ӿڹ��ܣ�JSON����ͳһ�ӿ�
	 * ��    ����CreateRtmpPublishManager_c�ķ���ֵ
	 *			 pszCmd	JSON��ʽ����
	 *			 ppszRes JSON��ʽ���
	 * �� �� ֵ���ɹ�/ʧ��
	 * ʾ    ����pszCmd { "cmd":"xxx", "params":{"x":true, "xx":12, "xxx":"abc"} }
	 * ʾ    ����ppszRes { "code":0, "data":{"reason":"abc"} }
	 * ˵    ����code���� 0��success��1��fail
	 **/



extern "C" __declspec(dllexport) bool CallInJson(void* rtmp, const char* pszCmd, char** ppszRes);

    /*
    *   �ӿڹ���:       ������Ƶ����.  �������� StartPublish ֮ǰ���ã�
    *   ��    ��:   
	*		@rtmp					CreateRtmpPublishManager_c�ķ���ֵ
    *       @uWidth:                ��Ƶ��.    
    *       @uHeight:               ��Ƶ��.    
    *       @uFrameRate:            ��Ƶ֡��.   
    *       @uBitRate:              ����. (bps)   
    *       @hVideo:                ��Ƶ��ʾ���ھ��.       
    *   �� �� ֵ:                  ��
    */
extern "C" __declspec(dllexport) void SetPublishVideoPara(void* rtmp, int uWidth, int uHeight, int uFrameRate, int uBitRate, HWND hVideo, int uKeyFrameInterval);


	/*
	*	�ӿڹ���:		�����ӿ� (�{�������ӿ�֮ǰ����{��ԓ����)
	*	��    ��:		���{����ָ�
	*	�� �� ֵ:		void* ��������ӿڵĵ�һ������
	*/
extern "C" __declspec(dllexport) void * CreateRtmpPublishManager_c(OnRtmpPublishNotifyInJson_C pNotify);

	/*
	*	�ӿڹ���:		�h���ӿ� ������ʹ�ýӿڵĕr���{��ԓ����������ȴ棩
	*	��    ����		CreateRtmpPublishManager_c�ķ���ֵ	
	*	�� �� ֵ:		void
	*/
extern "C" __declspec(dllexport) void Release(void* rtmp);



extern "C" __declspec(dllexport) void DoTest(void* rtmp, HWND hVideo);