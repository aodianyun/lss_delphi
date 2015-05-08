unit typdef;

interface

type
  TCallBackFun=function(const pszJson:PChar):Boolean; cdecl;
  TCallInJson=function(rtmp:Pointer;const pszCmd:PChar;ppszRes:PPChar):Boolean; cdecl;
  TCreateRtmpPublish=function(fn:TCallBackFun):Pointer; cdecl;
  TSetPublishVideoPara=procedure(rtmp:Pointer;uWidth:Integer;uHeight:Integer;uFrameRate:Integer;uBitRate:Integer;hVideo:THandle;uKeyFrameInterval:Integer); cdecl;
  TRealease=procedure(rtmp:Pointer); cdecl;
  TDoTest=procedure(rtmp:Pointer;hVideo:THandle);cdecl;
  THandle=Integer;
implementation

end.
