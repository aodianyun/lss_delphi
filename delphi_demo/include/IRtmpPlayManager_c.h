/*
* 
* rtmpSDK ���Ŷ˽ӿ�˵��
* 
*/



#pragma once

//typedef enum eMsgLevel{MSG_DEBUG=0, MSG_WARNING, MSG_ERR};

typedef bool(*OnRtmpPlayNotifyInJson_C)(const char* pszJson);

	/**
	 * ��    �ڣ�OnShowVideo
	 * �ӿڹ��ܣ���һ����ʾ��Ƶǰ����
	 * ��    �ã�pszCmd { "cmd":"OnShowVideo", "params":{} }
	 **/

	/**
	 * ��    �ڣ�OnAudioPercent
	 * �ӿڹ��ܣ���Ƶ���ݣ��ٷֱȣ��ص��������ϲ���ʾ�Զ���������
	 * ��    ����uPercent	��Ƶ���ݣ������ģ��İٷֱ���ʽ
	 * ��    �ã�pszCmd { "cmd":"OnAudioPercent", "params":{"uPercent":12} }
	 **/

	/**
	 * ��    �ڣ�OnRtmpPlayManagerMsg
	 * �ӿڹ��ܣ���Ϣ�ص�
	 * ��    ����MsgLev	��Ϣ���� MSG_DEBUG=0, MSG_WARNING=1, MSG_ERR=2
	 *           pMsg	��Ϣ����
	 *           pDetail��Ϣ��ϸ˵��
	 * ��    �ã�pszCmd { "cmd":"OnRtmpPlayManagerMsg", "params":{"MsgLev":1,"pMsg":"OnRtmpDead","pDetail":"NetConnection.Connect.Closed"} }
	 **/


	/**
	 * �ӿڣ�OnRtmpPlayManagerNetInfo
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
	 * ��    �ã�pszCmd { "cmd":"OnRtmpPlayManagerNetInfo", "params":{"uPing":15,"uVideoBitSum":90,...} }
	 **/

	/**
	 * �ӿڣ�OnRtmpPlayManagerComputerStatusInfo
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
	 * ��    �ã�pszCmd { "cmd":"OnRtmpPlayManagerComputerStatusInfo", "params":{"uTotalPhys":2048,"uAvailPhys":1000,...} }
	 **/
	
	/**
	 * �ӿڣ�OnRtmpPlayManagerAVInfo
	 * �ӿڹ��ܣ�����Ƶ������Ϣ�ص�
	 * ��    ����
	 *	unsigned int uTotalBufTime;
	 *	unsigned int uAudioBufTime;
	 *	unsigned int uVideoBufTime;
	 *	unsigned int uVideoWidth;
	 *	unsigned int uVideoHeight;
	 *    
	 * ��    �ã�pszCmd { "cmd":"OnRtmpPlayManagerAVInfo", "params":{"uTotalBufTime":1000,"uAudioBufTime":200,...} }
	 **/

	/**
	 * �ӿڣ�OnRtmpPlayManagerPlayQuality
	 * �ӿڹ��ܣ�����������Ϣ�ص�
	 * ��    ����
	 *	unsigned int uShowVideoSucTime;
	 *	unsigned int uBufferEmptyCount;
	 *	unsigned int uBufferFullCount;
	 *	unsigned int uMaxPlayBuffer;
	 *	unsigned int uMinPlayBuffer;
	 *	unsigned int uAvgPlayBuffer;
	 *	float fTotalPlayTime;
	 *    
	 * ��    �ã�pszCmd { "cmd":"OnRtmpPlayManagerPlayQuality", "params":{"uShowVideoSucTime":3,"uBufferEmptyCount":4,...} }
	 **/

extern "C" __declspec(dllexport) bool CallInJson(void* rtmp, const char* pszCmd, char** ppszRes);
	/**
	 * ��    �ڣ�JSON����ͳһ�ӿ� GetSdkVersion
	 * �ӿڹ��ܣ���ȡ��ǰʹ�õ�SDK�汾��
	 * ��    �ã�pszCmd { "cmd":"GetSdkVersion", "params":{} }
	 * �ɹ����أ�ppszRes { "code":0, "data":{"version":"201407171636"} }
	 * ʧ�ܷ��أ�ppszRes { "code":1, "data":{"reason":"no version."} }
	 **/

	/**
	 * ��    �ڣ�JSON����ͳһ�ӿ� SetSYNBufTime
	 * �ӿڹ��ܣ����ò��Ż�����ʱ����
	 * ��    �ã�pszCmd { "cmd":"SetSYNBufTime", "params":{"dwDatalenOffset":1500, "dwMaxTimestampleInqueue":3000, "dwTimeCheckSynbuf":5000} }
	 * ���أ���
	 **/

	/**
	 * ��    �ڣ�JSON����ͳһ�ӿ� StartPlay
	 * �ӿڹ��ܣ���ʼ����
	 * ��    �ã�pszCmd { "cmd":"StartPlay", "params":{} }
	 * �ɹ����أ�ppszRes { "code":0, "data":{} }
	 * ʧ�ܷ��أ�ppszRes { "code":1, "data":{} }
	 **/
	
	/**
	 * ��    �ڣ�JSON����ͳһ�ӿ� StopPlay
	 * �ӿڹ��ܣ�ֹͣ����
	 * ��    �ã�pszCmd { "cmd":"StopPlay", "params":{} }
	 * �ɹ����أ�ppszRes { "code":0, "data":{} }
	 * ʧ�ܷ��أ�ppszRes { "code":1, "data":{} }
	 **/

	/**
	* ��    �ڣ�JSON����ͳһ�ӿ� GetAudioPlayDevList
	* �ӿڹ��ܣ���ȡ�����豸�б� �������� StartPlay ֮ǰ���ã�
	* ��    �ã�pszCmd { "cmd":"GetAudioPlayDevList", "params":{} }
	* �ɹ����أ�ppszRes { "code":0, "data":{"player":["dirsound", "guagua"]} }
	* ʧ�ܷ��أ�ppszRes { "code":1, "data":{} }
	**/

	/**
	* ��    �ڣ�JSON����ͳһ�ӿ� SetAudioPlayDev
	* �ӿڹ��ܣ����ò����豸ID �������� StartPlay ֮ǰ���ã�
	* ��	����int uDevID      (�����豸ID(count from 0))
	* ��    �ã�pszCmd { "cmd":"SetAudioPlayDev", "params":{"uDevID":1} }
	* �ɹ����أ�ppszRes { "code":0, "data":{} }
	* ʧ�ܷ��أ�ppszRes { "code":1, "data":{} }
	**/	

	/**
	* ��    �ڣ�JSON����ͳһ�ӿ� SetStreamInfo
	* �ӿڹ��ܣ����ò�������Ϣ �������� StartPlay ֮ǰ���ã�
	* ��	����const char *pURL, ��������ַ
	*			const char *pAppID, ��App����(���������֤���� AppID= AppID+"?"+key, if appID is "App" and key is "kkyoo", then here is "App?kkyoo")
	*			const char *pStreamID, Stream����
	* ��    �ã�pszCmd { "cmd":"SetStreamInfo", "params":{"pURL":rtmp://lssplay.aodianyun.com:1935,"pAppID":app,"pStreamID":stream} }
	* �ɹ����أ�ppszRes { "code":0, "data":{} }
	* ʧ�ܷ��أ�ppszRes { "code":1, "data":{} }
	**/	


	/**
	* ��    �ڣ�JSON����ͳһ�ӿ� SetAdPara
	* �ӿڹ��ܣ���������  �������ڲ��Ź����е��ã�
	* ��	����int uOutVolum,	����
	*			bool bMute		�Ƿ���
	* ��    �ã�pszCmd { "cmd":"SetAdPara", "params":{"uOutVolum":80,bMute:false} }
	* ���أ���
	**/	

	/**
	* ��    �ڣ�JSON����ͳһ�ӿ� SetClientUserID
	* �ӿڹ��ܣ������û�ID �������� StartPlay ֮ǰ���ã�
	* ��	����const char *pszUserID	�û�ID
	* ��    �ã�pszCmd { "cmd":"SetClientUserID", "params":{"pszUserID":"123456"} }
	* ���أ���
	**/	

	/**
	* ��    �ڣ�JSON����ͳһ�ӿ� SetRecordFileFullName
	* �ӿڹ��ܣ�����¼���ļ����������� StartPlay ֮ǰ���ã�
	* ��	����const char *pszFileName, ¼���ļ�·��
	* ��    �ã�pszCmd { "cmd":"SetRecordFileFullName", "params":{"pszFileName":"c:\\4.flv"} }
	* ���أ���
	**/	

	/**
	* ��    �ڣ�JSON����ͳһ�ӿ� EnableRecordFile
	* �ӿڹ��ܣ�����/�ر� ¼������Ƶ���ܣ������ڲ��Ź����е���
	* ��	����bool bEnable, �Ƿ���
	* ��    �ã�pszCmd { "cmd":"EnableRecordFile", "params":{"bEnable":false} }
	* ���أ���
	**/	

	/**
	 * �ӿڹ��ܣ�JSON����ͳһ�ӿ�
	 * ��    ����CreateRtmpPlayManager_c�ķ���ֵ
	 *			 pszCmd	JSON��ʽ����
	 *			 ppszRes JSON��ʽ���
	 * �� �� ֵ���ɹ�/ʧ��
	 * ʾ    ����pszCmd { "cmd":"xxx", "params":{"x":true, "xx":12, "xxx":"abc"} }
	 * ʾ    ����ppszRes { "code":0, "data":{"reason":"abc"} }
	 * ˵    ����code���� 0��success��1��fail
	 **/

extern "C" __declspec(dllexport) void SetVdDisplayWnd(void* rtmp, HWND hwnd);
	/*
	*	�ӿڹ���:		������Ƶ��ʾ���ھ��  �������� StartPlay ֮ǰ���ã�
	*	��    ����		CreateRtmpPlayManager_c�ķ���ֵ	
	*		@hwnd:		���ھ��
	*	�� �� ֵ:		void
	*/


extern "C" __declspec(dllexport) void * CreateRtmpPlayManager_c(OnRtmpPlayNotifyInJson_C pNotify);

	/*
	*	�ӿڹ���:		�����ӿ� (�{�������ӿ�֮ǰ����{��ԓ����)
	*	��    ��:		���{����ָ�
	*	�� �� ֵ:		void* ��������ӿڵĵ�һ������
	*/

extern "C" __declspec(dllexport) void Release(void* rtmp);

	/*
	*	�ӿڹ���:		�h���ӿ� ������ʹ�ýӿڵĕr���{��ԓ����������ȴ棩
	*	��    ����		CreateRtmpPlayManager_c�ķ���ֵ	
	*	�� �� ֵ:		void
	*/